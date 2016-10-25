package com.ts02.sigtrac.healthcare;


/**
 * Created by Samara on 18/10/2016.

 */
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class LoginActivity extends AppCompatActivity {

    Button login;
    EditText email,password;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        login=(Button)findViewById(R.id.login);
        email=(EditText)findViewById(R.id.email);
        password=(EditText)findViewById(R.id.password);


        login.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(email.getText().toString().equals("ts02@gmail.com") && password.getText().toString().equals("12345")) {
                    Toast.makeText(getApplicationContext(), "Redirecionando...",Toast.LENGTH_SHORT).show();
                    Intent intent = new Intent(LoginActivity.this,MainActivity.class);
                    startActivity(intent);
                }
                else{
                    Toast.makeText(getApplicationContext(), "Erro no email ou senha",Toast.LENGTH_SHORT).show();
                }
            }
        });
    }
}
