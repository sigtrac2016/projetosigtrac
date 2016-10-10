package com.takeiji.takamura.sigtrac;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;

import org.w3c.dom.Text;

import java.util.ArrayList;

public class SendAlertActivity extends AppCompatActivity {

    // ToSend
    private String departament = "";
    private String type = "";

    // ListView
    private TextView mTitle;
    private TextView mDepartmentName;
    private ListView mListView;
    private ArrayList<String> mListElements;
    private ArrayAdapter mAdapter;
    private AdapterView.OnItemClickListener clickListener;

    // Menu 1
    private final String M1_DEFESA_CIVIL = "Defesa Civil";
    private final String M1_BOMBEIROS = "Corpo de bombeiros";
    private final String M1_POLICIA = "Departamento de Polícia";
    private final String M1_SAUDE = "Divisão de Saude Pública";

    // Menu 2
    private final String M2_INCENDIO = "Incêndio";
    private final String M2_AFOGAMENTO = "Afogamento";
    private final String M2_QUIMICA = "Química";
    private final String M2_OUTRO = "Outro";

    // Menu 3
    private final String M3_TRANSITO = "Transito";
    private final String M3_ASSALTO = "Assalto";
    private final String M3_OBJSUSPEITO = "Objeto suspeito";
    private final String M3_TERRORISTMO = "Terrorismo";
    private final String M3_OUTRO = "Outro";

    // Menu 4
    private final String M4_AMBULANCIA = "Ambuläncia";
    private final String M4_ACIDENTE = "Acidente";
    private final String M4_OUTRO = "Outro";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_send_alert);
        getSupportActionBar().hide();

        // Loading UI elements
        mListView = (ListView) findViewById(R.id.listAlert);
        mTitle = (TextView) findViewById(R.id.alertTitle);
        mDepartmentName = (TextView) findViewById(R.id.departmentTitle);

        // Creating the list that will be used to populate the list view
        mListElements = new ArrayList<>();

        // Creating the list adapter
        mAdapter = new ArrayAdapter(this, android.R.layout.simple_list_item_1, mListElements);
        mListView.setAdapter(mAdapter);

        // Creating listener
        setClickListener();
        mListView.setOnItemClickListener(clickListener);

        // Start...
        populateListWithDepartments();
    }

    private void populateListWithDepartments() {
        mListElements.clear();
        mListElements.add(M1_DEFESA_CIVIL);
        mListElements.add(M1_BOMBEIROS);
        mListElements.add(M1_POLICIA);
        mListElements.add(M1_SAUDE);
        mAdapter.notifyDataSetChanged();
    }

    private void populateListWithType(String department) {
        mListElements.clear();
        mTitle.setText("Selecionar o tipo de alerta");
        mDepartmentName.setText(department);
        switch(department) {
            case M1_BOMBEIROS:
                mListElements.add(M2_INCENDIO);
                mListElements.add(M2_AFOGAMENTO);
                mListElements.add(M2_QUIMICA);
                mListElements.add(M2_OUTRO);
                break;
            case M1_POLICIA:
                mListElements.add(M3_TRANSITO);
                mListElements.add(M3_ASSALTO);
                mListElements.add(M3_OBJSUSPEITO);
                mListElements.add(M3_TERRORISTMO);
                mListElements.add(M3_OUTRO);
                break;
            case M1_SAUDE:
                mListElements.add(M4_AMBULANCIA);
                mListElements.add(M4_ACIDENTE);
                mListElements.add(M4_OUTRO);
                break;
        }
        mAdapter.notifyDataSetChanged();
    }

    private void setClickListener() {
        clickListener = new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                switch(mListElements.get(position)) {
                    case M1_BOMBEIROS:
                    case M1_DEFESA_CIVIL:
                    case M1_POLICIA:
                    case M1_SAUDE:
                        departament = mListElements.get(position);
                        populateListWithType(departament);
                        break;
                    default:
                        type = mListElements.get(position);
                        sendAlert();
                }
            }
        };
    }

    public void sendAlert() {
        //TODO: ...
    }
}
