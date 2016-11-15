package com.takeiji.takamura.sigtrac;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

import org.json.JSONException;
import org.json.JSONObject;

public class RegistroVitima2Activity extends AppCompatActivity {

    // REGISTRO que sera enviado
    private boolean deambulando;
    private int respiracao;
    private boolean viasAereas;
    private String preenchimentoCapilar;
    private boolean pulsoRadial;
    private boolean cumpreOrdens;

    private String cor;
    private String RFID;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getSupportActionBar().hide();
        setContentView(R.layout.activity_registro_vitima2);

        Intent intent = getIntent();

        deambulando = intent.getStringExtra("DEAMBULANDO").equals("true");
        respiracao  = Integer.valueOf(intent.getStringExtra("RESPIRACAO"));
        viasAereas  = intent.getStringExtra("AEREA").equals("true");
        preenchimentoCapilar = intent.getStringExtra("CAPILAR");
        pulsoRadial = intent.getStringExtra("PULSO").equals("true");
        cumpreOrdens = intent.getStringExtra("ORDENS").equals("true");

    }

    // CORES
    public void corPreta(View view) { cor = "PRETA"; }
    public void corVerde(View view) { cor = "VERDE"; }
    public void corAmarela(View view) { cor = "AMARELA"; }
    public void corVermelha(View view) { cor = "VERMELHA"; }

    /*
    * Botoes
    * */

    public void enviar(View view) {
        JSONObject json = new JSONObject();
        try {
            json.put("deambulando", String.valueOf(deambulando));
            json.put("respiracao", String.valueOf(respiracao));
            json.put("respiraViasAereas", String.valueOf(viasAereas));
            json.put("preenchimentoCapilar", preenchimentoCapilar);
            json.put("pulsoRadial", String.valueOf(pulsoRadial));
            json.put("cumpreOrdens", String.valueOf(cumpreOrdens));
            json.put("cor", cor);

            Log.v("TESTE", json.toString());
            //http://posttestserver.com/ -> SERVER para testar post requests
            new SendJSON().execute("http://posttestserver.com/post.php", json.toString());

        } catch (JSONException er) {
            Log.v("REGISTRO", "ERRO na criacao do JSON");
        }
    }

    public void cancelar(View view) {

    }

}
