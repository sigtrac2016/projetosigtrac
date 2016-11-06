package com.takeiji.takamura.sigtrac;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

public class EnviarFotoActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getSupportActionBar().hide();
        setContentView(R.layout.activity_enviar_foto);
    }
}
