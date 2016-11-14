package com.takeiji.takamura.sigtrac;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class RegistroVitimaActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getSupportActionBar().hide();
        setContentView(R.layout.activity_registro_vitima);
    }

    /*
    * Botoes
    * */

    public void enviar(View view) {
        Intent intent = new Intent(this, RegistroVitima2Activity.class);
        startActivity(intent);
    }

    public void cancelar(View view) {

    }
}
