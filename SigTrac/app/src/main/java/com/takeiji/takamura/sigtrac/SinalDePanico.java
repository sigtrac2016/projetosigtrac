package com.takeiji.takamura.sigtrac;

import android.content.Context;
import android.location.Location;
import android.util.Log;
import android.widget.Toast;

public class SinalDePanico {

    private Context context;

    private String CPF;
    private Location location;
    private boolean usuarioRestrito;

    public SinalDePanico(Context context, String cpf, Location location, boolean restrito) {
        this.context = context;
        this.CPF = cpf;
        this.location = location;
        this.usuarioRestrito = restrito;
    }

    public void enviar() {
        String l = "Lat: indisponivel\nLong: indisponivel";
        if(this.location != null) {
            l = "Lat: " + String.valueOf(location.getLatitude()) + "\nLong: " + String.valueOf(location.getLongitude());
        }
        String example = "CPF: " + this.CPF + "\nLocalizacao: " + l + (usuarioRestrito ? "\nRESTRITO" : "\nCOMUM");
        Toast.makeText(context, example, Toast.LENGTH_LONG).show();


        // Teste
        Log.v("TESTE", "TESTEAPI");
        CallAPI api = new CallAPI();
        api.execute("http://takeiji.netsoc.ie/sigtrac.json");
    }
}
