package com.ts02.sigtrac.healthcare;

/**
 * Created by Samara on 18/10/2016.

 */
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.Spinner;

import java.util.Dictionary;
import java.util.Hashtable;

import static android.R.attr.checked;

public class VictimActivity extends AppCompatActivity {

    EditText code_victim,name_victim,num_doc_victim;


    Dictionary dict = new Hashtable();

    Bundle extras;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_victim);

        extras = getIntent().getExtras();

        dict.put(1,extras.getString("unit_responsiveness"));
        dict.put(2,extras.getString("situation"));
        dict.put(3,extras.getString("lat_lon"));




        Button btn = (Button) findViewById(R.id.callMedia);
        btn.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                checkBoxVictim();
                Intent intent = new Intent(VictimActivity.this,MediaActivity.class);

                code_victim = (EditText)findViewById(R.id.code_victim);

                dict.put(4, code_victim.getText().toString());

                //dict.put(5, name_victim.getText().toString());

                //dict.put(6, num_doc_victim.getText().toString());

                dict.put(7, checkBoxVictim().toString());

                intent.putExtra("dic", dict.toString());

                startActivity(intent);
            }
        });

    }



    public String checkBoxVictim() {
        String check_box_victim = "";
        CheckBox check_box_head = (CheckBox) findViewById(R.id.check_box_head);
        if(check_box_head.isChecked()){
            check_box_victim += "head;";
        }

        CheckBox check_box_body = (CheckBox) findViewById(R.id.check_box_body);
        if(check_box_body.isChecked()){
            check_box_victim += "body;";
        }

        CheckBox check_box_mid = (CheckBox) findViewById(R.id.check_box_mid);
        if(check_box_mid.isChecked()){
            check_box_victim += "mid;";
        }

        CheckBox check_box_mie = (CheckBox) findViewById(R.id.check_box_mie);
        if(check_box_mie.isChecked()){
            check_box_victim += "mie;";
        }

        CheckBox check_box_msd = (CheckBox) findViewById(R.id.check_box_msd);
        if(check_box_msd.isChecked()){
            check_box_victim += "msd;";
        }

        CheckBox check_box_mse = (CheckBox) findViewById(R.id.check_box_mse);
        if(check_box_mse.isChecked()){
            check_box_victim += "mse;";
        }
        return check_box_victim;
    }
}

