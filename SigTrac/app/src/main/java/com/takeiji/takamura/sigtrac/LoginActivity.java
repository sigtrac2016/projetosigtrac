package com.takeiji.takamura.sigtrac;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.annotation.TargetApi;
import android.content.Context;
import android.content.Intent;
import android.support.design.widget.TextInputLayout;
import android.support.v7.app.AppCompatActivity;

import android.os.AsyncTask;

import android.os.Build;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.WindowManager;
import android.widget.AutoCompleteTextView;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.Toast;

import java.util.InputMismatchException;

/**
 * A login screen that offers login via email/password.
 */
public class LoginActivity extends AppCompatActivity {

    /**
     * A dummy authentication store containing known user names and passwords.
     * TODO: remove after connecting to a real authentication system.
     */
    private static final String[] DUMMY_CREDENTIALS = new String[]{
            "39079933813:123456:Milton", "04117674374:111111:Jose"
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

        this.getWindow().setSoftInputMode(WindowManager.LayoutParams.SOFT_INPUT_STATE_ALWAYS_HIDDEN);
    }

    /**
     * This method handles the visibility of the password field
     */
    public void onCheckBoxClicked(View view) {
        boolean checked = ((CheckBox) view).isChecked();
        if(checked)
            mPasswordField.setVisibility(View.VISIBLE);
        else {
            mPasswordField.setVisibility(View.INVISIBLE);
            mPasswordView.setText("");
        }
    }

    /**
     *  Life cycle method. Every time the user returns to the login page,
     * the user must do the login again.
     */
    @Override
    protected void onResume() {
        super.onResume();
        if(mCheckBox.isChecked())
            mPasswordField.setVisibility(View.VISIBLE);
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
            mAuthTask = new UserLoginTask(cpf, password, this);
            mAuthTask.execute((Void) null);
        }
    }

    /**
     * Checks if the CPF is valid
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

        if(isCPF(cpf))
            return true;
        return false;
    }

    /**
     * Checks if a CPF is really a valid CPF
     * http://www.devmedia.com.br/validando-o-cpf-em-uma-aplicacao-java/22097
     */
    private boolean isCPF(String CPF) {
        // considera-se erro CPFs formados por uma sequencia de numeros iguais
        if (CPF.equals("00000000000") || CPF.equals("11111111111") || CPF.equals("22222222222") || CPF.equals("33333333333") ||
                CPF.equals("44444444444") || CPF.equals("55555555555") || CPF.equals("66666666666") || CPF.equals("77777777777") ||
                CPF.equals("88888888888") || CPF.equals("99999999999") || (CPF.length() != 11))
            return false;

        char dig10, dig11;
        int sm, i, r, num, peso;

        try {
            // Calculo do 1o. Digito Verificador
            sm = 0;
            peso = 10;
            for (i=0; i<9; i++) {
                num = (int)(CPF.charAt(i) - 48);
                sm = sm + (num * peso);
                peso = peso - 1;
            }

            r = 11 - (sm % 11);
            if ((r == 10) || (r == 11))
                dig10 = '0';
            else
                dig10 = (char)(r + 48);


            // Calculo do 2o. Digito Verificador
            sm = 0;
            peso = 11;
            for(i=0; i<10; i++) {
                num = (int)(CPF.charAt(i) - 48);
                sm = sm + (num * peso);
                peso = peso - 1;
            }

            r = 11 - (sm % 11);
            if ((r == 10) || (r == 11))
                dig11 = '0';
            else
                dig11 = (char)(r + 48);

            // Verifica se os digitos calculados conferem com os digitos informados.
            if ((dig10 == CPF.charAt(9)) && (dig11 == CPF.charAt(10)))
                return true;
            else
                return false;
        } catch (InputMismatchException erro) {
            return false;
        }

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

        private String mCPF;
        private String mPassword;
        private String mName;
        private Context mContext;

        UserLoginTask(String cpf, String password, Context context) {
            mContext = context;
            mCPF = cpf;
            mPassword = password;
        }

        public void reset() {
            this.mCPF = "";
            this.mPassword = "";
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
                    mName = pieces[2];
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
                // start Restricted users activity
                Intent intent = new Intent(this.mContext, UserActivity.class);
                intent.putExtra("CPF", this.mCPF);
                intent.putExtra("NOME", this.mName);
                startActivity(intent);
            } else {
                // Restrict access
                if(mCheckBox.isChecked()) {
                    Toast toast = Toast.makeText(getApplicationContext(), "Acesso Negado!", Toast.LENGTH_SHORT);
                    toast.show();
                    mPasswordView.setError(getString(R.string.error_incorrect_password));
                    mPasswordView.requestFocus();
                }
                // General access
                else {
                    Intent intent = new Intent(this.mContext, UserActivity.class);
                    intent.putExtra("CPF", this.mCPF);
                    intent.putExtra("NOME", "-1");
                    startActivity(intent);
                }
            }
        }

        @Override
        protected void onCancelled() {
            mAuthTask = null;
            showProgress(false);
        }

    }
}

