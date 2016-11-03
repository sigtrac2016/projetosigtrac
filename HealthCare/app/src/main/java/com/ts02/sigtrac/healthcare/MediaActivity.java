package com.ts02.sigtrac.healthcare;


/**
 * Created by Samara on 18/10/2016.

 */

import android.content.ContentValues;
import android.content.Intent;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.media.MediaPlayer;
import android.media.MediaRecorder;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.Toast;

import java.io.ByteArrayOutputStream;
import java.io.IOException;

public class MediaActivity extends AppCompatActivity {

    private static final String KEY_NAME = "";
    private static final String KEY_IMAGE = "";
    private static final String DB_TABLE = "table_infos";
    Button b1,b2;
    ImageView iv;


    Button play,stop,record;
    private MediaRecorder myAudioRecorder;
    private String outputFile = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_media);

        b1=(Button)findViewById(R.id.getImage);
        iv=(ImageView)findViewById(R.id.imageView);

        b1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(android.provider.MediaStore.ACTION_IMAGE_CAPTURE);
                startActivityForResult(intent, 0);
            }
        });


        play=(Button)findViewById(R.id.play);
        stop=(Button)findViewById(R.id.stop);
        record=(Button)findViewById(R.id.record);

        stop.setEnabled(false);
        play.setEnabled(false);
        outputFile = Environment.getExternalStorageDirectory().getAbsolutePath() + "/recording.3gp";;

        myAudioRecorder=new MediaRecorder();

        //myAudioRecorder.setAudioSource(MediaRecorder.AudioSource.MIC);
        //myAudioRecorder.setOutputFormat(MediaRecorder.OutputFormat.THREE_GPP);
        //myAudioRecorder.setAudioEncoder(MediaRecorder.OutputFormat.AMR_NB);
        //myAudioRecorder.setOutputFile(outputFile);

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
                Toast.makeText(getApplicationContext(), "Informações salvas com sucesso!",Toast.LENGTH_SHORT).show();
                Intent intent = new Intent(MediaActivity.this,MainActivity.class);
                startActivity(intent);

            }
        });





    }


    public void addEntry( String name, byte[] image) throws SQLiteException {
        SQLiteDatabase database = this.getWritableDatabase();
        ContentValues cv = new ContentValues();
        cv.put(KEY_NAME,    name);
        cv.put(KEY_IMAGE,   image);
        database.insert( DB_TABLE, null, cv );
    }


    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        // TODO Auto-generated method stub
        super.onActivityResult(requestCode, resultCode, data);

        Bitmap bp = (Bitmap) data.getExtras().get("data");
        iv.setImageBitmap(bp);

        System.out.println(bp);

        //byte[] teste = getBytes(bp);
        //addEntry("teste",teste);

    }

    private byte[] getBytes(Bitmap bp) {
        ByteArrayOutputStream stream = new ByteArrayOutputStream();
        Bitmap bitmap = null;
        bitmap.compress(Bitmap.CompressFormat.PNG, 0, stream);
        return stream.toByteArray();
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

    public SQLiteDatabase getWritableDatabase() {
        SQLiteDatabase writableDatabase = null;
        return writableDatabase;
    }

    
        // convert from byte array to bitmap
        public Bitmap getImage(byte[] image) {
            return BitmapFactory.decodeByteArray(image, 0, image.length);
        }
}
