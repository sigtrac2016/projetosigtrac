package com.ts02.sigtrac.healthcare;


/**
 * Created by Samara on 18/10/2016.

 */

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.Spinner;

public class MainActivity extends AppCompatActivity {

    private String array_unit[];
    private String array_situation[];

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Spinner spinner1 = (Spinner) findViewById(R.id.unit_responsiveness);
        ArrayAdapter<String> unit_responsiveness;
        array_unit=new String[6];
        array_unit[0]="Selecione uma Unidade PA";
        array_unit[1]="Região Central";
        array_unit[2]="Região Norte";
        array_unit[3]="Região Oeste";
        array_unit[4]="Região Leste";
        array_unit[5]="Região Sul";
        Spinner s1 = (Spinner) findViewById(R.id.unit_responsiveness);
        unit_responsiveness = new ArrayAdapter(this,
                android.R.layout.simple_spinner_item, array_unit);
        s1.setAdapter(unit_responsiveness);


       Spinner spinner2 = (Spinner) findViewById(R.id.situation);
        ArrayAdapter<String> situation;
        array_situation=new String[3];
        array_situation[0]="Selecione uma Situação";
        array_situation[1]="Disponível para ocorrência";
        array_situation[2]="Indisponível para ocorrência";
        Spinner s2 = (Spinner) findViewById(R.id.situation);
        situation = new ArrayAdapter(this,
                android.R.layout.simple_spinner_item, array_situation);
        s2.setAdapter(situation);

        Button ocurrence = (Button) findViewById(R.id.start_occurrence);
        ocurrence.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this,VictimActivity.class);
                startActivity(intent);

            }
        });
    }
}
