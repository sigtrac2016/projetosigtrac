package com.takeiji.takamura.sigtrac;

import java.sql.Timestamp;

public class JsonModel {
    public JsonModel(int id, String titulo, char segmento, String descricao, double latitude,
                     double longitude, String[] fotos, String status,  Timestamp data_hora){
        this.id = id;
        this.titulo = titulo;
        this.segmento = segmento;
        this.descricao = descricao;
        this.latitude = latitude;
        this.longitude = longitude;
        this.fotos = new String[fotos.length];
        for(int i = 0; i < fotos.length; i++)
            this.fotos[i] = fotos[i];
        this.status = status;
        this.data_hora = new Timestamp(data_hora.getTime());
    }
    private int id; //gerado pelo bd
    private String titulo; // string vazia ou nao
    private char segmento; // char com a letra referente ao segmento
    private String descricao; // string vazia ou nao
    private double latitude;
    private double longitude;
    private String[] fotos; // array de strings, vazio ou contendo URL das fotos
    private String status; // nao-iniciado, iniciado, cancelado, reforcos, finalizado
    private Timestamp data_hora; // formato padrão de timestamp

    public int getid(){ return id ; }
    public String gettitulo(){ return titulo ; }
    public char getsegmento(){ return segmento ; }
    public String getdescricao(){ return descricao ; }
    public double getilatitude(){ return latitude ; }
    public double getilongitude(){ return longitude ; }
    public String[] getfotos(){ return fotos ; }
    public String getstatus(){ return status ; }
    public Timestamp getdata_hora() {return data_hora; }

}
