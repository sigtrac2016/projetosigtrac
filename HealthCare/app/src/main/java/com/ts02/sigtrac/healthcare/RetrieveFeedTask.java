package com.ts02.sigtrac.healthcare;

import android.os.AsyncTask;

import com.google.api.client.http.HttpRequest;
import com.google.api.client.http.HttpResponse;

/**
 * Created by natan on 11/6/2016.
 */

class RetrieveFeedTask extends AsyncTask<HttpRequest, Void, HttpResponse> {

    private Exception exception;

    protected HttpResponse doInBackground(HttpRequest... httpRequests) {
        try {
            HttpResponse response = httpRequests[0].execute();


            return response;
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