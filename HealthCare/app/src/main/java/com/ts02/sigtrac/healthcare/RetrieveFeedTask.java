package com.ts02.sigtrac.healthcare;

import android.os.AsyncTask;
import android.util.Log;

import com.google.api.client.http.HttpRequest;
import com.google.api.client.http.HttpResponse;

/**
 * Created by natan on 11/6/2016.
 */

class RetrieveFeedTask extends AsyncTask<HttpRequest, Void, PlacesList> {

    private Exception exception;

    protected PlacesList doInBackground(HttpRequest... httpRequests) {
        try {
            PlacesList places = null;
            HttpResponse response = httpRequests[0].execute();
            if(true) {
                Log.d("API CLIENT", response.statusMessage);
                Log.d("API CLIENT", response.parseAsString());
            }else {
                places = response.parseAs(PlacesList.class);
                Log.d("API CLIENT", "STATUS = " + places.status);
                for (Object place : places.results) {
                    Log.d("API CLIENT", (String) place);
                }
            }
            return places;
        } catch (Exception e) {
            this.exception = e;

            return null;
        }
    }

    protected void onPostExecute() {
        // TODO: check this.exception
        // TODO: do something with the feed
    }


}