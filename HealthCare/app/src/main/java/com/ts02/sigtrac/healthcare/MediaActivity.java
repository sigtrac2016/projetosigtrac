package com.ts02.sigtrac.healthcare;


/**
 * Created by Samara on 18/10/2016.

 */

import android.content.ContentValues;
import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.content.pm.PackageManager;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.media.MediaPlayer;
import android.media.MediaRecorder;
import android.os.AsyncTask;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Base64;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.HttpURLConnection;
import java.net.URL;

public class MediaActivity extends AppCompatActivity {

    Button b1,b2;
    ImageView iv;


    Button play,stop,record;
    private MediaRecorder myAudioRecorder;
    private String outputFile = null;
    String dic;

    WebService wb = new WebService();

    String codigo_vitima = "ts02",nome_vitma ="nome_vitma", numero_documento ="405750535", lat="23.123", lon ="-23.123", foto="",
            audio = "", socorrista = "socorrista", unidade_pa = "Região Leste", detalhes_atendimento ="body";



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_media);
        Bundle extras = getIntent().getExtras();
        dic = extras.getString("dic");
        String[] infos = dic.split(",");

        /*codigo_vitima = infos[0].split("=")[1];
        unidade_pa    = infos[1].split("=")[1];
        detalhes_atendimento = infos[2].split("=")[1];
        socorrista = "ts02";*/





        //Imagem
        b1=(Button)findViewById(R.id.getImage);
        iv=(ImageView)findViewById(R.id.imageView);
        b1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(android.provider.MediaStore.ACTION_IMAGE_CAPTURE);
                startActivityForResult(intent, 0);
            }
        });
        //Audio
        play=(Button)findViewById(R.id.play);
        stop=(Button)findViewById(R.id.stop);
        record=(Button)findViewById(R.id.record);

        stop.setEnabled(false);
        play.setEnabled(false);
        outputFile = Environment.getExternalStorageDirectory().getAbsolutePath() + "/recording.3gp";;

        myAudioRecorder = new MediaRecorder();
        myAudioRecorder.setAudioSource(MediaRecorder.AudioSource.MIC);
        myAudioRecorder.setOutputFormat(MediaRecorder.OutputFormat.THREE_GPP);
        myAudioRecorder.setAudioEncoder(MediaRecorder.OutputFormat.AMR_NB);
        myAudioRecorder.setOutputFile(outputFile);

        record.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    myAudioRecorder.prepare();
                    myAudioRecorder.start();
                }

                catch (IllegalStateException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }

                catch (IOException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                } catch (Exception e) {
                    e.printStackTrace();
                }

                record.setEnabled(false);
                stop.setEnabled(true);

                Toast.makeText(getApplicationContext(), "Gravação Iniciada", Toast.LENGTH_LONG).show();
            }
        });

        stop.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                myAudioRecorder.stop();
                myAudioRecorder.release();
                myAudioRecorder  = null;

                stop.setEnabled(false);
                play.setEnabled(true);

                Toast.makeText(getApplicationContext(), "O áudio gravado com sucesso",Toast.LENGTH_LONG).show();
            }
        });

        play.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) throws IllegalArgumentException,SecurityException,IllegalStateException {
                MediaPlayer m = new MediaPlayer();
                try {
                    m.setDataSource(outputFile);



                    audio = getEncoded64Audio();



                }

                catch (IOException e) {
                    e.printStackTrace();
                }

                try {
                    m.prepare();
                }

                catch (IOException e) {
                    e.printStackTrace();
                }

                m.start();
                Toast.makeText(getApplicationContext(), "Reprodução do áudio", Toast.LENGTH_LONG).show();
            }
        });


        Button cancel = (Button) findViewById(R.id.cancel);
        cancel.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MediaActivity.this,MainActivity.class);
                startActivity(intent);

            }
        });

        Button map = (Button) findViewById(R.id.map);
        map.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MediaActivity.this,MapsActivity.class);
                startActivity(intent);

            }
        });


        Button save = (Button) findViewById(R.id.save);
        save.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {


                new MediaActivity.Connection().execute();

                Toast.makeText(getApplicationContext(), "Informações salvas com sucesso!",Toast.LENGTH_SHORT).show();
                Intent intent = new Intent(MediaActivity.this,MainActivity.class);
                startActivity(intent);

            }
        });
    }


    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        // TODO Auto-generated method stub
        super.onActivityResult(requestCode, resultCode, data);

        Bitmap bp = (Bitmap) data.getExtras().get("data");

        foto = getEncoded64ImageStringFromBitmap(bp);

        iv.setImageBitmap(bp);

    }


    @Override
    protected void onDestroy() {
        super.onDestroy();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.

        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }


    private class Connection extends AsyncTask {
        @Override
        protected Object doInBackground(Object... arg0) {
            StringBuilder tokenUri=new StringBuilder("lat_lon=");
            tokenUri.append("false");
            tokenUri.append("&codigo_vitima=");
            tokenUri.append(codigo_vitima);
            tokenUri.append("&nome_vitma=");
            tokenUri.append(nome_vitma);
            tokenUri.append("&numero_documento=");
            tokenUri.append(numero_documento);
            tokenUri.append("&lat=");
            tokenUri.append(lat);
            tokenUri.append("&lon=");
            tokenUri.append(lon);
            tokenUri.append("&foto=");
            tokenUri.append(foto);
            tokenUri.append("&audio=");
            tokenUri.append(audio);
            tokenUri.append("&socorrista=");
            tokenUri.append(socorrista);
            tokenUri.append("&unidade_pa=");
            tokenUri.append(unidade_pa);
            tokenUri.append("&detalhes_atendimento=");
            tokenUri.append(detalhes_atendimento);

            /*
            try {
                wb.post(tokenUri);
            } catch (Exception e) {
                e.printStackTrace();
            }*/

            //StringBuilder tokenUri=new StringBuilder("audio=");
            //tokenUri.append(outputFile);
            try {
                wb.post(tokenUri);
            } catch (Exception e) {
                e.printStackTrace();
            }
            return null;
        }
    }


    public String getEncoded64ImageStringFromBitmap(Bitmap bitmap) {
        ByteArrayOutputStream stream = new ByteArrayOutputStream();
        bitmap.compress(Bitmap.CompressFormat.JPEG, 70, stream);
        byte[] byteFormat = stream.toByteArray();
        // get the base 64 string
        String imgString = Base64.encodeToString(byteFormat, Base64.NO_WRAP);
        return imgString;
    }



    public String getEncoded64Audio(){
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        FileInputStream fis = null;
        String imgString = null;
        try {
            fis = new FileInputStream(new File(outputFile));
            byte[] buf = new byte[1024];
            int n;
            while (-1 != (n = fis.read(buf)))
                baos.write(buf, 0, n);
            byte[] videoBytes = baos.toByteArray();
            imgString = Base64.encodeToString(videoBytes, Base64.NO_WRAP);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

        return  imgString;

    }



}
