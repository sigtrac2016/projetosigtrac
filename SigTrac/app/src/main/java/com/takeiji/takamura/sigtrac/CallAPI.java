package com.takeiji.takamura.sigtrac;

import android.os.AsyncTask;
import android.util.Log;

import org.apache.commons.io.IOUtils;

import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;

/**
 * Classe criada baseado em um post do StackOverlfow
 * Sending POST data in Android
 */
public class CallAPI extends AsyncTask<String, String, String> {

    public CallAPI() {

    }

    @Override
    protected void onPreExecute() {
        super.onPreExecute();
    }

    @Override
    protected String doInBackground(String... params) {

        String urlString = params[0];
        Log.v("TESTE", urlString);

        String resultToDisplay = "";

        InputStream in = null;
        try {
            URL url = new URL(urlString);
            HttpURLConnection urlConnection = (HttpURLConnection) url.openConnection();
            in = new BufferedInputStream(urlConnection.getInputStream());
        } catch (Exception e) {
            Log.v("AQUI", "TESTE");
            System.out.println(e.getMessage());
            return e.getMessage();
        }

        try {
            Log.v("AQUI2", "TESTE");
            resultToDisplay = IOUtils.toString(in, "UTF-8");
        } catch (IOException e) {
            e.printStackTrace();
        }
        Log.v("AQUI3", resultToDisplay);
        return resultToDisplay;
    }

    @Override
    protected void onPostExecute(String result) {

    }
}
