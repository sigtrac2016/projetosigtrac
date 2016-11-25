#include "kcg_types.h"

#include <stdio.h>
#include <winsock2.h>
 
#pragma comment(lib,"ws2_32.lib") //Winsock Library

kcg_int Operator2(void){
    /*
    WSADATA wsa;
    SOCKET s , new_socket;
    struct sockaddr_in server , client;
    int c;
    char *message;
 
    //printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        //printf("Failed. Error Code : %d",WSAGetLastError());
        return 1;
    }
     
    //printf("Initialised.\n");
     
    //Create a socket
    if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        //printf("Could not create socket : %d" , WSAGetLastError());
        return 2;
    }
 
    //printf("Socket created.\n");
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 5000 );

    int optval = 1;
    setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);
     
    //Bind
    if( bind(s ,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR)
    {
        //printf("Bind failed with error code : %d" , WSAGetLastError());
        //exit(EXIT_FAILURE);
        return WSAGetLastError();
    }
     
    //puts("Bind done");
 
    //Listen to incoming connections
    listen(s , 3);
     
    //Accept and incoming connection
    //puts("Waiting for incoming connections...");
     
    c = sizeof(struct sockaddr_in);
     
    if( (new_socket = accept(s , (struct sockaddr *)&client, &c)) != INVALID_SOCKET )
    {
        //puts("Connection accepted");
         
        //Reply to the client
        //message = "Hello Client , I have received your connection. But I have to go now, bye\n";
        //send(new_socket , message , strlen(message) , 0);
        //return 4;
    }
     
    if (new_socket == INVALID_SOCKET)
    {
        //printf("accept failed with error code : %d" , WSAGetLastError());
        return 5;
    }

    int iResult = 0;
    char sendbuf[16];
    do {

        iResult = recv(new_socket, sendbuf, 16, 0);
        if ( iResult > 0 ){
            //printf("Bytes received: %d\n", iResult);
        	send(new_socket, sendbuf, strlen(sendbuf) , 0);
            return 6;
        }
        else if ( iResult == 0 )
            //printf("Connection closed\n");
            continue;
        else
            //printf("recv failed: %d\n", WSAGetLastError());
            continue;

    } while( iResult > 0 );
 
    closesocket(s);
    WSACleanup();
    */
    return 0;
}