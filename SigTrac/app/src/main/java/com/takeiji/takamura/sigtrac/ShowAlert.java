package com.takeiji.takamura.sigtrac;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class ShowAlert extends AppCompatActivity {

    // User
    private boolean usuarioRestrito = true;

    // Alerts
    private String titulo;
    private String descricao;
    private String data;

    // UI Elements
    private TextView tituloLabel;
    private TextView dataLabel;
    private TextView descricaoLabel;

    private TextView resolverTitleLabel;
    private EditText resolverEditText;
    private Button   resolverBtn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getSupportActionBar().hide();
        setContentView(R.layout.activity_show_alert);

        // Getting the name and CPF
        Intent intent = getIntent();
        titulo = intent.getStringExtra("TITULO");
        descricao = intent.getStringExtra("DESCRICAO");
        data = intent.getStringExtra("DATA");


        // Loading UI Elements
        tituloLabel = (TextView) findViewById(R.id.alertaTituloID);
        dataLabel = (TextView) findViewById(R.id.alertaDataID);
        descricaoLabel = (TextView) findViewById(R.id.alertaDescricaoID);
        resolverTitleLabel = (TextView) findViewById(R.id.resolverTitleID);
        resolverEditText = (EditText) findViewById(R.id.editAlertaID);
        resolverBtn = (Button) findViewById(R.id.resolverAlertaBtnID);

        // Setting text
        tituloLabel.setText(titulo);
        dataLabel.setText(data);
        descricaoLabel.setText(descricao);

        if(intent.getStringExtra("USUARIO").equals("comum")) {
            usuarioRestrito = false;
        }

        if(!usuarioRestrito) {
            resolverBtn.setVisibility(View.INVISIBLE);
            resolverEditText.setVisibility(View.INVISIBLE);
            resolverTitleLabel.setVisibility(View.INVISIBLE);
        }

    }

    public void resolverAlerta(View view) {
        String resolucao = resolverEditText.getText().toString();
        Toast.makeText(ShowAlert.this, "Resolucao enviada", Toast.LENGTH_SHORT).show();
        //TODO enviar alerta
        finish();
    }
}
