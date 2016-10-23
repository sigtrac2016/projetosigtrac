package com.takeiji.takamura.sigtrac;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.List;

public class AlertsListActivity extends AppCompatActivity {

    // ListView
    private List<String> mListElements;
    private ListView mListView;
    private ArrayAdapter mAdapter;
    private AdapterView.OnItemClickListener clickListener;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getSupportActionBar().hide();
        setContentView(R.layout.activity_alerts_list);

        // Loading UI elements
        mListView = (ListView) findViewById(R.id.alertsListID);

        // Creating the list that will be used to populate the list view
        mListElements = new ArrayList<>();

        // Creating the adapter
        mAdapter = new ArrayAdapter(this, android.R.layout.simple_list_item_1, mListElements);
        mListView.setAdapter(mAdapter);

        // Creating listener
        setClickListener();
        mListView.setOnItemClickListener(clickListener);

        // Request alerts from the backend
        requestAlerts();

    }

    // Request alerts from the backend
    private void requestAlerts() {
        mListElements.clear();
        mListElements.add("Afogamento");
        mListElements.add("Terrorismo");
        mListElements.add("Incêndio");
        mListElements.add("Enchente");
        mListElements.add("Desmonoramento");
    }

    private void setClickListener() {
        clickListener = new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                // TODO: get the alert, start a new activity, show info
            }
        };
    }
}
