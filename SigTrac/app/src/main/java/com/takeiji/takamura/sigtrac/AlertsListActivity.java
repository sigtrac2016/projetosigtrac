package com.takeiji.takamura.sigtrac;

import android.content.Context;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.List;

public class AlertsListActivity extends AppCompatActivity {

    // Context
    private Context context;

    // Alerts
    private List<Alerta> alertas;

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
        context = getApplicationContext();
        alertas = new ArrayList<>();
        requestAlerts();

    }

    @Override
    protected void onResume() {
        super.onResume();
        requestAlerts();
    }

    // Request alerts from the backend
    private void requestAlerts() {

        alertas.clear();
        alertas.add(new Alerta("Afogamento", "Criança se afogando na praia", "11/08/2016"));
        alertas.add(new Alerta("Terroristmo", "Bomba no aeroporto", "17/02/2016"));
        alertas.add(new Alerta("Incêndio", "Fogo alto na Dutra", "24/04/2016"));
        alertas.add(new Alerta("Enchente", "Água no joelho", "11/01/2016"));
        alertas.add(new Alerta("Desmoronamento", "Morro do Pardal", "22/05/2015"));
        alertas.add(new Alerta("Atentado no Vale", "Policia Civil ja se dirigiu ao local", "28/10/2016"));
        alertas.add(new Alerta("Desmaio no shopping", "Ambulância ja se dirigiu ao local", "22/10/2016"));

        // Filling list
        mListElements.clear();
        for(Alerta alerta : alertas) {
            mListElements.add(alerta.titulo);
        }

        mAdapter.notifyDataSetChanged();
    }

    private void setClickListener() {
        clickListener = new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Alerta alerta = alertas.get(position);
                Intent intent = new Intent(context, ShowAlert.class);
                intent.putExtra("TITULO", alerta.titulo);
                intent.putExtra("DESCRICAO", alerta.descricao);
                intent.putExtra("DATA", alerta.data);
                startActivity(intent);
            }
        };
    }
}
