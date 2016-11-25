package com.ts02.sigtrac.healthcare;


/**
 * Created by Samara on 18/10/2016.

 */

import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.net.ConnectivityManager;
import android.os.AsyncTask;
import android.provider.Settings;
import android.support.v4.app.ActivityCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.Spinner;
import android.widget.Toast;


import java.net.*;
import java.io.*;

public class MainActivity extends AppCompatActivity implements LocationListener {

    public String array_unit[];
    public String array_situation[];
    Spinner spinner1;
    Spinner spinner2;


    private LocationManager locationManager;

    String lat = "";
    String lon = "";
    String code = "ts02";

    WebService wb = new WebService();



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        spinner1 = (Spinner) findViewById(R.id.unit_responsiveness);
        ArrayAdapter<String> unit_responsiveness;
        array_unit = new String[6];
        array_unit[0] = "Selecione uma Unidade PA";
        array_unit[1] = "Região Central";
        array_unit[2] = "Região Norte";
        array_unit[3] = "Região Oeste";
        array_unit[4] = "Região Leste";
        array_unit[5] = "Região Sul";
        Spinner s1 = (Spinner) findViewById(R.id.unit_responsiveness);
        unit_responsiveness = new ArrayAdapter(this,
                android.R.layout.simple_spinner_item, array_unit);
        s1.setAdapter(unit_responsiveness);


        spinner2 = (Spinner) findViewById(R.id.situation);
        ArrayAdapter<String> situation;
        array_situation = new String[3];
        array_situation[0] = "Selecione uma Situação";
        array_situation[1] = "Disponível para ocorrência";
        array_situation[2] = "Indisponível para ocorrência";
        Spinner s2 = (Spinner) findViewById(R.id.situation);
        situation = new ArrayAdapter(this,
                android.R.layout.simple_spinner_item, array_situation);
        s2.setAdapter(situation);

        Button ocurrence = (Button) findViewById(R.id.start_occurrence);
        ocurrence.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {

                Intent intent = new Intent(MainActivity.this, VictimActivity.class);
                intent.putExtra("unit_responsiveness",spinner1.getSelectedItem().toString());
                intent.putExtra("situation",spinner2.getSelectedItem().toString());
                intent.putExtra("lat_lon",lat+","+lon);

                startActivity(intent);
                //checkInternetConenction();
            }
        });


        locationManager = (LocationManager) getSystemService(Context.LOCATION_SERVICE);
        if (ActivityCompat.checkSelfPermission(this, android.Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED && ActivityCompat.checkSelfPermission(this, android.Manifest.permission.ACCESS_COARSE_LOCATION) != PackageManager.PERMISSION_GRANTED) {
            // TODO: Consider calling
            //    ActivityCompat#requestPermissions
            // here to request the missing permissions, and then overriding
            //   public void onRequestPermissionsResult(int requestCode, String[] permissions,
            //                                          int[] grantResults)
            // to handle the case where the user grants the permission. See the documentation
            // for ActivityCompat#requestPermissions for more details.
            return;
        }
        locationManager.requestLocationUpdates(LocationManager.GPS_PROVIDER, 2000, 1, this);


    }

    @Override
    public void onLocationChanged(Location location) {
        String lat_lon = "lat:" + location.getLatitude()
                + "  lon: " + location.getLongitude();

        lat = String.valueOf(location.getLatitude());
        lon = String.valueOf(location.getLongitude());

        //Toast.makeText(getApplicationContext(), lat_lon,Toast.LENGTH_SHORT).show();

        //new Connection().execute();
    }

    @Override
    public void onStatusChanged(String s, int i, Bundle bundle) {

    }

    @Override
    public void onProviderEnabled(String s) {
        Toast.makeText(getBaseContext(), "Gps is turned on!! ",
                Toast.LENGTH_SHORT).show();
    }

    @Override
    public void onProviderDisabled(String s) {
        Intent intent = new Intent(Settings.ACTION_LOCATION_SOURCE_SETTINGS);
        startActivity(intent);
        Toast.makeText(getBaseContext(), "Gps is turned off!! ",
                Toast.LENGTH_SHORT).show();
    }




    private boolean checkInternetConenction() {
        // get Connectivity Manager object to check connection
        ConnectivityManager connec
                =(ConnectivityManager)getSystemService(getBaseContext().CONNECTIVITY_SERVICE);

        // Check for network connections
        if ( connec.getNetworkInfo(0).getState() ==
                android.net.NetworkInfo.State.CONNECTED ||
                connec.getNetworkInfo(0).getState() ==
                        android.net.NetworkInfo.State.CONNECTING ||
                connec.getNetworkInfo(1).getState() ==
                        android.net.NetworkInfo.State.CONNECTING ||
                connec.getNetworkInfo(1).getState() == android.net.NetworkInfo.State.CONNECTED ) {
            Toast.makeText(this, " Connected ", Toast.LENGTH_LONG).show();
            return true;
        }else if (
                connec.getNetworkInfo(0).getState() ==
                        android.net.NetworkInfo.State.DISCONNECTED ||
                        connec.getNetworkInfo(1).getState() ==
                                android.net.NetworkInfo.State.DISCONNECTED  ) {
            Toast.makeText(this, " Not Connected ", Toast.LENGTH_LONG).show();
            return false;
        }
        return false;
    }

    private class Connection extends AsyncTask {
        @Override
        protected Object doInBackground(Object... arg0) {
            StringBuilder tokenUri = new StringBuilder("lat_lon=");
            tokenUri.append("true");
            tokenUri.append("&lat=");
            tokenUri.append(lat);
            tokenUri.append("&lon=");
            tokenUri.append(lon);
            tokenUri.append("&code=");
            tokenUri.append(code);

            try {
                wb.post(tokenUri);
            } catch (Exception e) {
                e.printStackTrace();
            }
            return null;
        }

    }


}
