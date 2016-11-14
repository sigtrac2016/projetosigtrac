package com.takeiji.takamura.sigtrac;

import android.Manifest;
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class UserActivity extends AppCompatActivity {

    private boolean usuarioRestrito = true;

    private String CPF;
    private String Name;
    private boolean bombeiros;

    private TextView mTitle;
    private Button mBuscaButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_user);
        getSupportActionBar().hide();

        // Getting the name and CPF
        Intent intent = getIntent();
        CPF = intent.getStringExtra("CPF");
        Name = intent.getStringExtra("NOME");
        bombeiros = intent.getStringExtra("BOMBEIROS").equals("true");

        if(Name.equals("-1"))
            usuarioRestrito = false;

        // Loading UI elements
        mTitle = (TextView) findViewById(R.id.title_restrictedUsers);
        mBuscaButton = (Button) findViewById(R.id.buscaButton);

        if(bombeiros) {
            mBuscaButton.setVisibility(View.VISIBLE);
        } else {
            mBuscaButton.setVisibility(View.INVISIBLE);
        }

        // Setting welcome text
        if(usuarioRestrito)
            mTitle.setText("Bem-vindo " + this.Name);
        else
            mTitle.setText("Bem-vindo");
    }

    // It sends the CPF, phone number, position and a flag (restricted user/common user)
    public void emitAlertSignal(View view) {
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setMessage("Deseja enviar sinal de pânico?").setTitle("Emergencia");
        builder.setPositiveButton("Sim", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                Location location = getLocation();
                SinalDePanico sinal = new SinalDePanico(getApplicationContext(), CPF, location, usuarioRestrito);
                sinal.enviar();
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


    public void verificarAlertas(View view) {
        Intent intent = new Intent(this, AlertsListActivity.class);
        if(usuarioRestrito)
            intent.putExtra("TIPO", "restrito");
        else
            intent.putExtra("TIPO", "comum");
        startActivity(intent);
    }

    public void enviarAlerta(View view) {
        Intent intent = new Intent(this, SendAlertActivity.class);
        startActivity(intent);
    }

    public void buscaClicked(View view) {
        Intent intent = new Intent(this, RegistroVitimaActivity.class);
        startActivity(intent);
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

}
