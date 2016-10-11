package com.takeiji.takamura.sigtrac;

import android.Manifest;
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
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
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setMessage("Deseja enviar sinal de pânico?").setTitle("Emergencia");
        builder.setPositiveButton("Sim", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                Log.e("TEST", "SIM");
                // TODO: ...
            }
        });
        builder.setNegativeButton("Nao", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {

            }
        });
        AlertDialog dialog = builder.create();
        dialog.show();
    }


    public void verificarAlertas(View view) {
        // TODO: ...
    }

    public void enviarAlerta(View view) {
        Intent intent = new Intent(this, SendAlertActivity.class);
        startActivity(intent);
    }
}
