package com.takeiji.takamura.sigtrac;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.annotation.TargetApi;
import android.support.design.widget.TextInputLayout;
import android.support.v7.app.AppCompatActivity;

import android.os.AsyncTask;

import android.os.Build;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.AutoCompleteTextView;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.Toast;

/**
 * A login screen that offers login via email/password.
 */
public class LoginActivity extends AppCompatActivity {

    /**
     * A dummy authentication store containing known user names and passwords.
     * TODO: remove after connecting to a real authentication system.
     */
    private static final String[] DUMMY_CREDENTIALS = new String[]{
            "39079933813:123456", "11111111111:111111"
    };
    /**
     * Keep track of the login task to ensure we can cancel it if requested.
     */
    private UserLoginTask mAuthTask = null;

    // UI references.
    private AutoCompleteTextView mCPFView;
    private EditText mPasswordView;
    private View mProgressView;
    private View mLoginFormView;
    private TextInputLayout mPasswordField;
    private CheckBox mCheckBox;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);
        getSupportActionBar().hide(); // removes the action bar

        // Set up the login form.
        mCPFView = (AutoCompleteTextView) findViewById(R.id.cpf);
        mCheckBox = (CheckBox) findViewById(R.id.checkBoxID);
        mPasswordView = (EditText) findViewById(R.id.password);

        Button mCPFSignInButton = (Button) findViewById(R.id.cpf_sign_in_button);
        mCPFSignInButton.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View view) {
                attemptLogin();
            }
        });

        mPasswordField = (TextInputLayout) findViewById(R.id.passwordViewID);
        mLoginFormView = findViewById(R.id.login_form);
        mProgressView = findViewById(R.id.login_progress);
    }

    /**
     * This method handles the visibility of the password field
     */
    public void onCheckBoxClicked(View view) {
        boolean checked = ((CheckBox) view).isChecked();
        if(checked)
            mPasswordField.setVisibility(View.VISIBLE);
        else
            mPasswordField.setVisibility(View.INVISIBLE);
    }


    /**
     * Attempts to sign in or register the account specified by the login form.
     * If there are form errors (invalid cpf, missing fields, etc.), the
     * errors are presented and no actual login attempt is made.
     */
    private void attemptLogin() {
        if (mAuthTask != null) {
            return;
        }

        // Reset errors.
        mCPFView.setError(null);
        mPasswordView.setError(null);

        // Store values at the time of the login attempt.
        String cpf = mCPFView.getText().toString();
        String password = mPasswordView.getText().toString();

        boolean cancel = false;
        View focusView = null;

        // Check for a valid password, if the user entered one.
        if (!TextUtils.isEmpty(password) && !isPasswordValid(password)) {
            mPasswordView.setError(getString(R.string.error_invalid_password));
            focusView = mPasswordView;
            cancel = true;
        }

        // Check for a valid email address.
        if (TextUtils.isEmpty(cpf)) {
            mCPFView.setError(getString(R.string.error_field_required));
            focusView = mCPFView;
            cancel = true;
        } else if (!isCPFValid(cpf)) {
            mCPFView.setError(getString(R.string.error_invalid_cpf));
            focusView = mCPFView;
            cancel = true;
        }

        if (cancel) {
            // There was an error; don't attempt login and focus the first
            // form field with an error.
            focusView.requestFocus();
        } else {
            // Show a progress spinner, and kick off a background task to
            // perform the user login attempt.
            showProgress(true);
            mAuthTask = new UserLoginTask(cpf, password);
            mAuthTask.execute((Void) null);
        }
    }

    /**
     * Checks if the CPF is valid
     * ToDo: Apply the real test
     */
    public boolean isCPFValid(String cpf) {
        // Removing '.', '-' and '/'
        cpf = cpf.replaceAll("\\.", "");
        cpf = cpf.replaceAll("\\-", "");
        cpf = cpf.replaceAll("\\/", "");

        // Only numbers are allowed
        String regex = "[0-9]+";
        if(!cpf.matches(regex))
            return false;

        if(cpf.length() > 12 || cpf.length() < 10)
            return false;

        // TO DO: Apply the real method of CPF testing

        return true;
    }

    /**
     * Checks if the password is valid
     * Atm: Checks only the length
     */
    public boolean isPasswordValid(String password) {
        return password.length() >= 6;
    }

    /**
     * Shows the progress UI and hides the login form.
     */
    @TargetApi(Build.VERSION_CODES.HONEYCOMB_MR2)
    private void showProgress(final boolean show) {
        // On Honeycomb MR2 we have the ViewPropertyAnimator APIs, which allow
        // for very easy animations. If available, use these APIs to fade-in
        // the progress spinner.
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB_MR2) {
            int shortAnimTime = getResources().getInteger(android.R.integer.config_shortAnimTime);

            mLoginFormView.setVisibility(show ? View.GONE : View.VISIBLE);
            mLoginFormView.animate().setDuration(shortAnimTime).alpha(
                    show ? 0 : 1).setListener(new AnimatorListenerAdapter() {
                @Override
                public void onAnimationEnd(Animator animation) {
                    mLoginFormView.setVisibility(show ? View.GONE : View.VISIBLE);
                }
            });

            mProgressView.setVisibility(show ? View.VISIBLE : View.GONE);
            mProgressView.animate().setDuration(shortAnimTime).alpha(
                    show ? 1 : 0).setListener(new AnimatorListenerAdapter() {
                @Override
                public void onAnimationEnd(Animator animation) {
                    mProgressView.setVisibility(show ? View.VISIBLE : View.GONE);
                }
            });
        } else {
            // The ViewPropertyAnimator APIs are not available, so simply show
            // and hide the relevant UI components.
            mProgressView.setVisibility(show ? View.VISIBLE : View.GONE);
            mLoginFormView.setVisibility(show ? View.GONE : View.VISIBLE);
        }
    }


    /**
     * Represents an asynchronous login/registration task used to authenticate
     * the user.
     */
    public class UserLoginTask extends AsyncTask<Void, Void, Boolean> {

        private final String mCPF;
        private final String mPassword;

        UserLoginTask(String cpf, String password) {
            mCPF = cpf;
            mPassword = password;
            Log.v("LOGIN", "I am receiving " + mCPF + " and " + mPassword);
        }

        @Override
        protected Boolean doInBackground(Void... params) {
            // TODO: attempt authentication against a network service.

            try {
                // Simulate network access.
                Thread.sleep(2000);
            } catch (InterruptedException e) {
                return false;
            }

            for (String credential : DUMMY_CREDENTIALS) {
                String[] pieces = credential.split(":");
                if (pieces[0].equals(mCPF)) {
                    // Account exists, return true if the password matches.
                    return pieces[1].equals(mPassword);
                }
            }

            // TODO: register the new account here.
            return false;
        }

        @Override
        protected void onPostExecute(final Boolean success) {
            mAuthTask = null;
            showProgress(false);

            if (success) {
                Toast toast = Toast.makeText(getApplicationContext(), "Acesso Liberado!", Toast.LENGTH_SHORT);
                // New screen
            } else {
                Toast toast = Toast.makeText(getApplicationContext(), "Acesso Negado!", Toast.LENGTH_SHORT);
                mPasswordView.setError(getString(R.string.error_incorrect_password));
                mPasswordView.requestFocus();
            }
        }

        @Override
        protected void onCancelled() {
            mAuthTask = null;
            showProgress(false);
        }

    }
}

