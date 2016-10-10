package com.takeiji.takamura.sigtrac;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

public class CommonUserActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_common_user);
        getSupportActionBar().hide();
    }
}
