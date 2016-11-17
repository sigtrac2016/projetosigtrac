package com.takeiji.takamura.sigtrac;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

public class RegistroVitimaActivity extends AppCompatActivity {

    // parte do REGISTRO que sera enviado na proxima tela
    private boolean deambulando = false;
    private boolean viasAereas = false;
    private boolean pulsoRadial = false;
    private boolean cumpreOrdens = false;

    // UI
    private EditText mRespiracao;
    private EditText mCapilar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getSupportActionBar().hide();
        setContentView(R.layout.activity_registro_vitima);

        mRespiracao = (EditText) findViewById(R.id.vitimaRespiracao);
        mCapilar = (EditText) findViewById(R.id.vitimaCapilar);

        // Default
        mRespiracao.setText("30");
        mCapilar.setText("Normal");
    }

    // DEAMBULANDO
    public void deambulandoSim(View view) {
        deambulando = true;
    }

    public void deambulandoNao(View view) {
        deambulando = false;
    }

    // RESPIRA VIAS AEREAS

    public void viasAereasSim(View view) {
        viasAereas = true;
    }

    public void viasAereasNao(View view) {
        viasAereas = false;
    }

    // Pulso Radial
    public void pulsoSim(View view) {
        pulsoRadial = true;
    }

    public void pulsoNao(View view) {
        pulsoRadial = false;
    }

    // Cumpre Ordens
    public void cumpreSim(View view) {
        cumpreOrdens = true;
    }

    public void cumpreNao(View view) {
        cumpreOrdens = false;
    }

    /*
    * Botoes
    * */

    public void enviar(View view) {
        Intent intent = new Intent(this, RegistroVitima2Activity.class);

        intent.putExtra("DEAMBULANDO", String.valueOf(deambulando));
        intent.putExtra("RESPIRACAO", mRespiracao.getText().toString());
        intent.putExtra("AEREA", String.valueOf(viasAereas));
        intent.putExtra("CAPILAR", mCapilar.getText().toString());
        intent.putExtra("PULSO", String.valueOf(pulsoRadial));
        intent.putExtra("ORDENS", String.valueOf(cumpreOrdens));

        startActivity(intent);
        finish();
    }

    public void cancelar(View view) {
        finish();
    }
}
