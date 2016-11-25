/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe 
** Generation date: 2016-10-26T17:04:48
*************************************************************$ */
#ifndef _KCG_IMPORTED_FUNCTIONS_H_
#define _KCG_IMPORTED_FUNCTIONS_H_

#include "kcg_types.h"

//Cliente MQTT utilizando biblioteca Paho

#include <Windows.h>
#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <time.h>
#include "MQTTClient.h"

#define ADDRESS     "iot.eclipse.org:1883" //"52.67.204.136:1883"
#define CLIENTID    "Police"
#define TOPIC       "sigtrac/ts04/panic"
#define PAYLOAD     " "
#define QOS         1
#define TIMEOUT     10000L

//Instancia handles da biblioteca Paho
MQTTClient client;
MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
MQTTClient_deliveryToken token;
MQTTClient_message pubmsg = MQTTClient_message_initializer;

int 	id = 0;
float 	latitude = 0.0, longitude = 0.0;
char 	segmento = 'P';
char	titulo[50] = " ", descricao[150]  = " ", status[16]  = " ";
char    strJson[300] = " ";

int mqtt_inicializado = 0;

int publishMQTT(char *topic, char *payload)	//Envia mensagem formatada MQTT
{
	int rc;
	pubmsg.payload = payload;
    pubmsg.payloadlen = strlen(payload);
    pubmsg.qos = QOS;
    pubmsg.retained = 0;
    MQTTClient_publishMessage(client, topic, &pubmsg, &token);
    printf("Waiting for up to %d seconds for publication of %s\n"
            "on topic %s for client with ClientID: %s\n",
            (int)(TIMEOUT/1000), PAYLOAD, topic, CLIENTID);
    rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);
    printf("Message with delivery token %d delivered\n", token);
	return rc;
}

int openClientMQTT()	//Inicia cliente MQTT 
{
	int rc;
	MQTTClient_create(&client, ADDRESS, CLIENTID,
        MQTTCLIENT_PERSISTENCE_NONE, NULL);
	conn_opts.keepAliveInterval = 20;
	conn_opts.cleansession = 1;

	if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
	{
	printf("Failed to connect, return code %d\n", rc);
	exit(-1);
	}
	else printf("Conected to %s\n", ADDRESS);
	printf("\nPress button to send message");

	return rc;
}

void buildJson() {	//Monta paylaod em JSON
    time_t timer;
    char timeBuffer[26];
    struct tm* tm_info;

    time(&timer);
    tm_info = localtime(&timer);    //Lê o timestamp
    strftime(timeBuffer, 26, "%Y-%m-%d %H:%M:%S", tm_info); //Formata o timestamp

    char *p = &strJson[0];

    p += sprintf(p, "{\"id\":%i", id);
    p += sprintf(p, ",\"titulo\":\"%s\"", titulo);
    p += sprintf(p, ",\"segmento\":\"%c\"", segmento);
    p += sprintf(p, ",\"descricao\":\"%s\"", descricao);
    p += sprintf(p, ",\"lat\":%f", latitude);
    p += sprintf(p, ",\"long\":%f", longitude);
    p += sprintf(p, ",\"status\":\"%s\"", status);
    p += sprintf(p, ",\"data_hora\":\"%s\"", timeBuffer);
    p += sprintf(p, "}");
}

int closeClientMQTT()
{
	int rc;
	rc = MQTTClient_disconnect(client, 10000);
    	MQTTClient_destroy(&client);
	return rc;
}

#ifndef PublishMQTT

 kcg_int PublishMQTT(kcg_bool Send, kcg_char Titulo[50], kcg_char Segmento,
                     kcg_char Descricao[150], kcg_real Latitude, kcg_real Longitude, kcg_char Status[16])
 {
	int Mqttstatus = 1;

 	if(Send == 1)	//Só envia quando receber 1 da aplicação SCADE
	{
		memcpy(strJson, " ", strlen(strJson));
		sprintf(titulo,"%s",Titulo);
		segmento = (char)Segmento;
		sprintf(descricao,"%s",Descricao);
		latitude = (long)Latitude;
		longitude = (long)Longitude;
		sprintf(status,"%s",Status);
		buildJson();
		openClientMQTT();
		Mqttstatus = publishMQTT(TOPIC, strJson);	//Publica string em MQTT no tópico desejado
		closeClientMQTT();
	}

    return Mqttstatus;	
 }
#endif


#endif /* _KCG_IMPORTED_FUNCTIONS_H_ */
/* $**************** KCG Version 6.4 (build i21) ****************
** kcg_imported_functions.h
** Generation date: 2016-10-26T17:04:48
*************************************************************$ */

