package com.takeiji.takamura.sigtrac;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class ShowAlert extends AppCompatActivity {

    private String titulo;
    private String descricao;
    private String data;

    // UI Elements
    private TextView tituloLabel;
    private TextView dataLabel;
    private TextView descricaoLabel;

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

        // Setting text
        tituloLabel.setText(titulo);
        dataLabel.setText(data);
        descricaoLabel.setText(descricao);
    }
}
