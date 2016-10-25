package com.ts02.sigtrac.healthcare;

/**
 * Created by Samara on 18/10/2016.

 */
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class VictimActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_victim);

        Button btn = (Button) findViewById(R.id.callMedia);
        btn.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                Intent intent = new Intent(VictimActivity.this,MediaActivity.class);
                startActivity(intent);

            }
        });

    }
}
