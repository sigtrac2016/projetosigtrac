package com.takeiji.takamura.sigtrac;

import android.Manifest;
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.pm.PackageManager;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import org.w3c.dom.Text;

import java.util.ArrayList;

public class SendAlertActivity extends AppCompatActivity {

    // ToSend
    private String departament = "";
    private String type = "";
    private String descricao = "";
    private Location localizacao = null;

    // Descricao do alerta
    private EditText mEditText;
    private Button mButton;

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

    // Menu 5
    private final String M5_RIO = "Nivel de água: Rio";
    private final String M5_MAR = "Nível de água: Mar";
    private final String M5_CHUVA = "Nível de água: Chuva";
    private final String M5_REPRESA = "Nivel de água: Represa";
    private final String M5_AGUAOUTRA = "Nível de água: Outro";
    private final String M5_DESABAMENTO = "Desabamento";
    private final String M5_OUTRO = "Outro";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_send_alert);
        getSupportActionBar().hide();

        // Loading UI elements
        mListView = (ListView) findViewById(R.id.listAlert);
        mTitle = (TextView) findViewById(R.id.alertTitle);
        mDepartmentName = (TextView) findViewById(R.id.departmentTitle);
        mEditText = (EditText) findViewById(R.id.editTextID);
        mButton = (Button) findViewById(R.id.buttonAlertaEnviarID);

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
            case M1_DEFESA_CIVIL:
                mListElements.add(M5_RIO);
                mListElements.add(M5_MAR);
                mListElements.add(M5_CHUVA);
                mListElements.add(M5_REPRESA);
                mListElements.add(M5_AGUAOUTRA);
                mListElements.add(M5_DESABAMENTO);
                mListElements.add(M5_OUTRO);
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
                        setView("DESC");
                }
            }
        };
    }

    public void createDialogBox(View view) {
        // Pegando localizacao
        this.localizacao = getLocation();
        String l = "Lat: indisponivel\nLong: indisponivel";
        if(this.localizacao != null) {
            l = "Lat: " + String.valueOf(localizacao.getLatitude()) + "\nLong: " + String.valueOf(localizacao.getLongitude());
        }

        this.descricao = mEditText.getText().toString();
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setMessage("Dep.: " + this.departament + "\nTipo: " + this.type + "\nDesc.: " + this.descricao + "\nLocalizacao:\n" + l +"\nDeseja enviar este alerta?").setTitle("Alerta");
        builder.setPositiveButton("Sim", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                sendAlert();
                finish();
            }
        });
        builder.setNegativeButton("Nao", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {

            }
        });
        AlertDialog dialog = builder.create();
        dialog.show();
    }

    private void setView(String view) {
        switch(view) {
            case "LISTA":
                mDepartmentName.setText(this.departament);
                mEditText.setVisibility(View.INVISIBLE);
                mListView.setVisibility(View.VISIBLE);
                mButton.setVisibility(View.INVISIBLE);
                break;
            case "DESC":
                mDepartmentName.setText("Descricao:");
                mEditText.setVisibility(View.VISIBLE);
                mListView.setVisibility(View.INVISIBLE);
                mButton.setVisibility(View.VISIBLE);
                break;
        }
    }

    private void sendAlert() {
        Toast.makeText(SendAlertActivity.this, "Alerta enviado para a central de comando.", Toast.LENGTH_LONG).show();
        // Criando o alerta: departamento, tipo, descricao e localizacao

        //TODO: ...
    }

    private Location getLocation() {

        LocationListener locationListener = null;
        Location currentLocation = null;

        try {
            Context context = getApplicationContext();

            if(ContextCompat.checkSelfPermission(context, Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED) {
                LocationManager locationManager = (LocationManager) context.getSystemService(Context.LOCATION_SERVICE);

                locationListener = new AlertaLocationListener(context);
                locationManager.requestLocationUpdates(LocationManager.GPS_PROVIDER, 0, 0, locationListener);

                currentLocation = locationManager.getLastKnownLocation(LocationManager.GPS_PROVIDER);
            }
        } catch (Exception ex) {
            Toast.makeText(getApplicationContext(), "Serviço GPS indisponivel", Toast.LENGTH_SHORT).show();
        }

        if(currentLocation == null) {
            Toast.makeText(getApplicationContext(), "Serviço GPS indisponivel", Toast.LENGTH_SHORT);
        }
        return currentLocation;
    }

    /**
     * Life Cycle
     * */
    @Override
    protected void onPause() {
        super.onPause();
        finish();
    }

    @Override
    protected void onResume() {
        super.onResume();
        setView("LISTA");
    }
}
