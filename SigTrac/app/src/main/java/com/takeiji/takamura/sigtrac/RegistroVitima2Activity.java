package com.takeiji.takamura.sigtrac;

import android.Manifest;
import android.app.DatePickerDialog;
import android.app.TimePickerDialog;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.CheckBox;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.TimePicker;
import android.widget.Toast;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.Calendar;
import java.util.TimeZone;

public class RegistroVitima2Activity extends AppCompatActivity {

    // REGISTRO que sera enviado
    private boolean deambulando;
    private int respiracao;
    private boolean viasAereas;
    private String preenchimentoCapilar;
    private boolean pulsoRadial;
    private boolean cumpreOrdens;

    private String cor;
    private String RFID;
    private int mDay, mMonth, mYear;
    private int mHour, mMinute;

    // UI Elements
    private EditText mDataEditText;
    private EditText mHoraEditText;
    private CheckBox mVitimaCheckBox;
    private EditText mVitimaLongitude;
    private EditText mVitimaLatitude;
    private EditText mVitimaRFID;
    private EditText mVitimaComentario;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getSupportActionBar().hide();
        setContentView(R.layout.activity_registro_vitima2);

        Intent intent = getIntent();

        deambulando = intent.getStringExtra("DEAMBULANDO").equals("true");
        respiracao  = Integer.valueOf(intent.getStringExtra("RESPIRACAO"));
        viasAereas  = intent.getStringExtra("AEREA").equals("true");
        preenchimentoCapilar = intent.getStringExtra("CAPILAR");
        pulsoRadial = intent.getStringExtra("PULSO").equals("true");
        cumpreOrdens = intent.getStringExtra("ORDENS").equals("true");

        mDataEditText = (EditText) findViewById(R.id.quandoTEXT);
        mHoraEditText = (EditText) findViewById(R.id.horaTEXT);
        mVitimaCheckBox = (CheckBox) findViewById(R.id.vitimaCheckBox);
        mVitimaLongitude = (EditText) findViewById(R.id.vitimaLongitude);
        mVitimaLatitude = (EditText) findViewById(R.id.vitimaLatitude);
        mVitimaRFID = (EditText) findViewById(R.id.vitimaRFID);
        mVitimaComentario = (EditText) findViewById(R.id.vitimaComentario);

    }

    // Quando
    public void quandoClicked(View view) {
        Calendar calendar = Calendar.getInstance(TimeZone.getDefault());

        DatePickerDialog dialog = new DatePickerDialog(this, new DatePickerDialog.OnDateSetListener() {
            @Override
            public void onDateSet(DatePicker view, int year, int monthOfYear, int dayOfMonth) {
                mYear = year;
                mDay = dayOfMonth;
                mMonth = monthOfYear;
                mDataEditText.setText(new StringBuilder().append(mDay).append("/").append(mMonth).append("/")
                        .append(mYear).toString());
            }
        }, calendar.get(Calendar.YEAR),
                calendar.get(Calendar.MONTH), calendar.get(Calendar.DAY_OF_MONTH));
        dialog.show();
    }

    public void horaClicked(View view) {
        Calendar calendar = Calendar.getInstance(TimeZone.getDefault());

        TimePickerDialog dialog = new TimePickerDialog(this, new TimePickerDialog.OnTimeSetListener() {
            @Override
            public void onTimeSet(TimePicker view, int hourOfDay, int minute) {
                mHour = hourOfDay;
                mMinute = minute;
                mHoraEditText.setText(new StringBuilder().append(mHour).append(":").append(mMinute));
            }
        }, calendar.get(Calendar.HOUR_OF_DAY), calendar.get(Calendar.MINUTE), true);
        dialog.show();
    }

    // CORES
    public void corPreta(View view) { cor = "PRETA"; }
    public void corVerde(View view) { cor = "VERDE"; }
    public void corAmarela(View view) { cor = "AMARELA"; }
    public void corVermelha(View view) { cor = "VERMELHA"; }

    // Posicao
    public void setarPosicaoAtual(View view) {
        if(mVitimaCheckBox.isChecked()) {
            Location location = getLocation();
            if (location != null) {
                mVitimaLatitude.setText(String.valueOf(location.getLatitude()));
                mVitimaLongitude.setText(String.valueOf(location.getLongitude()));
            } else {
                Toast toast = Toast.makeText(this, "GPS indisponivel", Toast.LENGTH_SHORT);
                toast.show();
            }
        }
    }

    /*
    * Botoes
    * */

    public void enviar(View view) {
        JSONObject json = new JSONObject();
        try {
            json.put("deambulando", String.valueOf(deambulando));
            json.put("respiracao", String.valueOf(respiracao));
            json.put("respiraViasAereas", String.valueOf(viasAereas));
            json.put("preenchimentoCapilar", preenchimentoCapilar);
            json.put("pulsoRadial", String.valueOf(pulsoRadial));
            json.put("cumpreOrdens", String.valueOf(cumpreOrdens));

            json.put("cor", cor);
            json.put("rfid", mVitimaRFID.getText().toString());
            json.put("horario", mHoraEditText.getText().toString());
            json.put("data", mDataEditText.getText().toString());
            json.put("latitude", mVitimaLatitude.getText().toString());
            json.put("longitude", mVitimaLongitude.getText().toString());
            json.put("comentarios", mVitimaComentario.getText().toString());

            Log.v("TESTE", json.toString());
            //http://posttestserver.com/ -> SERVER para testar post requests
            new SendJSON().execute("http://posttestserver.com/post.php", json.toString());

        } catch (JSONException er) {
            Log.v("REGISTRO", "ERRO na criacao do JSON");
        }
    }

    public void cancelar(View view) {

    }

    // GPS

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
