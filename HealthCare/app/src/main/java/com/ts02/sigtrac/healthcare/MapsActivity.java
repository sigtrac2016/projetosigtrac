package com.ts02.sigtrac.healthcare;

import android.content.pm.PackageManager;
import android.location.Criteria;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.net.Uri;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v4.app.ActivityCompat;
import android.support.v4.app.FragmentActivity;
import android.util.Log;

import com.google.android.gms.appindexing.Action;
import com.google.android.gms.appindexing.AppIndex;
import com.google.android.gms.appindexing.Thing;
import com.google.android.gms.common.api.GoogleApiClient;
import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.MapView;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.MarkerOptions;
import com.google.api.client.googleapis.GoogleHeaders;
import com.google.api.client.http.GenericUrl;
import com.google.api.client.http.HttpRequest;
import com.google.api.client.http.HttpRequestFactory;
import com.google.api.client.http.HttpRequestInitializer;
import com.google.api.client.http.HttpResponseException;
import com.google.api.client.http.HttpTransport;
import com.google.api.client.http.apache.ApacheHttpTransport;
import com.google.api.client.http.json.JsonHttpParser;
import com.google.api.client.json.jackson.JacksonFactory;

public class MapsActivity extends FragmentActivity implements OnMapReadyCallback {

    private GoogleMap mMap;
    //private static final String API_KEY = "AIzaSyDirNigz--247ox9psR7SJad_WK3Hd1Z48";
    private static final String API_KEY = "AIzaSyA1zhIj-Eze7ts6K8AsNPBk2mxI8jbbObM";
    private static final String PLACES_SEARCH_URL = "https://maps.googleapis.com/maps/api/place/search/json?";
    private static final boolean PRINT_AS_STRING = false;
    private static final HttpTransport transport = new ApacheHttpTransport();
    private MapView mapView;
    //private GoogleMap googleMap;
    /**
     * ATTENTION: This was auto-generated to implement the App Indexing API.
     * See https://g.co/AppIndexing/AndroidStudio for more information.
     */
    private GoogleApiClient client;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_maps);
        // Obtain the SupportMapFragment and get notified when the map is ready to be used.
        SupportMapFragment mapFragment = (SupportMapFragment) getSupportFragmentManager()
                .findFragmentById(R.id.map);
        mapFragment.getMapAsync(this);

        try {
            performSearch();
        } catch (Exception e) {
            e.printStackTrace();
        }
        // ATTENTION: This was auto-generated to implement the App Indexing API.
        // See https://g.co/AppIndexing/AndroidStudio for more information.
        client = new GoogleApiClient.Builder(this).addApi(AppIndex.API).build();
    }


    public static HttpRequestFactory createRequestFactory(final HttpTransport transport) {

        return transport.createRequestFactory(new HttpRequestInitializer() {
            public void initialize(HttpRequest request) {
                GoogleHeaders headers = new GoogleHeaders();
                headers.setApplicationName("Google-Places-DemoApp");
                request.headers=headers;
                JsonHttpParser parser = new JsonHttpParser();
                parser.jsonFactory = new JacksonFactory();
                request.addParser(parser);
            }
        });
    }
    public void performSearch() throws Exception {
        SupportMapFragment mapFragment = (SupportMapFragment) getSupportFragmentManager()
                .findFragmentById(R.id.map);



        try {
            Log.d("API CLIENT","Perform Search ....");
            Log.d("API CLIENT","-------------------");
            HttpRequestFactory httpRequestFactory = createRequestFactory(transport);
            HttpRequest request = httpRequestFactory.buildGetRequest(new GenericUrl(PLACES_SEARCH_URL));
            request.url.put("key", API_KEY);

            double lat = -23.210664;
            double lng = -45.875646;
            request.url.put("location", String.valueOf(lat) + "," +  String.valueOf(lng) );
            request.url.put("radius", 500);
            request.url.put("sensor", "false");
            Log.d("API CLIENT", request.url.toString());
            AsyncTask<HttpRequest, Void, PlacesList> response = new RetrieveFeedTask().execute(request);
            for (int i = 0 ; i < 10000000 ; i++){

            }
            response.get();
            //Toast.makeText(this , response.toString() , Toast.LENGTH_LONG);

            //if ( response == null) {
            //    Log.d("GOOGLE API","NAO ESTA RESPONDENDO");
            //}
            /*if (PRINT_AS_STRING) {
                Log.d("API CLIENT", response.get().statusMessage);
                Log.d("API CLIENT", response.get().parseAsString());
            } else {

                PlacesList places = response.get().parseAs(PlacesList.class);
                Log.d("API CLIENT", "STATUS = " + places.status);
                for (Object place : places.results) {
                    Log.d("API CLIENT", (String) place);
                }
            }*/


        } catch (HttpResponseException e) {
            Log.d("API CLIENT",e.response.parseAsString());
            throw e;
        }
    }

    /**
     * Manipulates the map once available.
     * This callback is triggered when the map is ready to be used.
     * This is where we can add markers or lines, add listeners or move the camera. In this case,
     * we just add a marker near Sydney, Australia.
     * If Google Play services is not installed on the device, the user will be prompted to install
     * it inside the SupportMapFragment. This method will only be triggered once the user has
     * installed Google Play services and returned to the app.
     */
    @Override
    public void onMapReady(GoogleMap googleMap) {
        mMap = googleMap;
        // mapFragment.getMapAsync(this);
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
        mMap.setMyLocationEnabled(true);
        LocationManager locationManager = (LocationManager) getSystemService(LOCATION_SERVICE);
        Criteria criteria = new Criteria();
        String bestProvider = locationManager.getBestProvider(criteria, true);
        Location location = locationManager.getLastKnownLocation(bestProvider);

        //if (location != null) {
        //   onLocationChanged(location);
        //}
        locationManager.requestLocationUpdates(bestProvider, 20000, 0, new LocationListener() {
            @Override
            public void onLocationChanged(Location location) {
                LatLng ita = new LatLng(location.getLatitude(), location.getLongitude());
                //double lat = -23.210664;
                //double lng = -45.875646;
                //LatLng ita = new LatLng(-23.2106637, -45.8778349);
                mMap.addMarker(new MarkerOptions().position(ita).title("Localização atual"));
                mMap.moveCamera(CameraUpdateFactory.newLatLng(ita));
                mMap.getMaxZoomLevel();
            }

            @Override
            public void onStatusChanged(String s, int i, Bundle bundle) {

            }

            @Override
            public void onProviderEnabled(String s) {

            }

            @Override
            public void onProviderDisabled(String s) {

            }
        });
        // Add a marker in Sydney and move the camera
        LatLng ita = new LatLng(location.getLatitude(), location.getLongitude());
        //double lat = -23.210664;
        //double lng = -45.875646;
        //LatLng ita = new LatLng(-23.2106637, -45.8778349);
        mMap.addMarker(new MarkerOptions().position(ita).title("Localização atual"));
        mMap.moveCamera(CameraUpdateFactory.newLatLng(ita));
        mMap.getMaxZoomLevel();

    }

    /**
     * ATTENTION: This was auto-generated to implement the App Indexing API.
     * See https://g.co/AppIndexing/AndroidStudio for more information.
     */
    public Action getIndexApiAction() {
        Thing object = new Thing.Builder()
                .setName("Maps Page") // TODO: Define a title for the content shown.
                // TODO: Make sure this auto-generated URL is correct.
                .setUrl(Uri.parse("http://[ENTER-YOUR-URL-HERE]"))
                .build();
        return new Action.Builder(Action.TYPE_VIEW)
                .setObject(object)
                .setActionStatus(Action.STATUS_TYPE_COMPLETED)
                .build();
    }

    @Override
    public void onStart() {
        super.onStart();

        // ATTENTION: This was auto-generated to implement the App Indexing API.
        // See https://g.co/AppIndexing/AndroidStudio for more information.
        client.connect();
        AppIndex.AppIndexApi.start(client, getIndexApiAction());
    }

    @Override
    public void onStop() {
        super.onStop();

        // ATTENTION: This was auto-generated to implement the App Indexing API.
        // See https://g.co/AppIndexing/AndroidStudio for more information.
        AppIndex.AppIndexApi.end(client, getIndexApiAction());
        client.disconnect();
    }
}
