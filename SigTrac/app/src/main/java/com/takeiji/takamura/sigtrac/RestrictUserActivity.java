package com.takeiji.takamura.sigtrac;

import android.Manifest;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.telephony.TelephonyManager;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import org.w3c.dom.Text;

import java.util.ArrayList;
import java.util.List;

public class RestrictUserActivity extends AppCompatActivity {

    private String CPF;
    private String Name;

    private TextView mTitle;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_restrict_user);
        getSupportActionBar().hide();

        // Getting the name and CPF
        Intent intent = getIntent();
        CPF = intent.getStringExtra("CPF");
        Name = intent.getStringExtra("NOME");

        // Loading UI elements
        mTitle = (TextView) findViewById(R.id.title_restrictedUsers);

        // Setting welcome text
        mTitle.setText("Bem-vindo " + this.Name);
    }

    // It sends the CPF, phone number, position and a flag (restricted user/common user)
    public void emitAlertSignal(View view) {
        // TODO: ...
    }


    public void verificarAlertas(View view) {

    }

    public void enviarAlerta(View view) {
        Intent intent = new Intent(this, SendAlertActivity.class);
        startActivity(intent);
    }
}
