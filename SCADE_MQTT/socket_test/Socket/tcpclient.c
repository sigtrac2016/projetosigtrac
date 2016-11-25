#include "kcg_types.h"
#include <string.h>

kcg_int TestString(kcg_char testStr[20]){
	if (strcmp("success", testStr))
		return 1;
	else
		return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <sys/types.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <netdb.h>
// #include <mhash.h>
// #include <sys/time.h>
// #include <time.h>

// #define MAX_LINE 1024

// int
// main(int argc, char * argv[])
// {
// 	FILE *fp;
// 	struct hostent *hp;
// 	struct sockaddr_in sin;
// 	char *host;
// 	char server_buf[MAX_LINE];
// 	char file_buf[MAX_LINE];
// 	int s;
// 	int svrport;
// 	int len, file_len, file_chunk_len;
// 	char* filename;
// 	struct timeval detail_time_send;
// 	struct timeval detail_time_recv;
// 	double send_time;
// 	double recv_time;
// 	double diff_time;

// 	/* Interpret arguments from command line */
// 	if (argc == 4) {
// 		host = argv[1];
		
// 		svrport = atoi(argv[2]);
		
// 		filename = calloc(strlen(argv[3]) + 1, sizeof(char));
// 		strcpy(filename, argv[3]);
// 		printf("%s\n", filename);
// 	}
// 	else {
// 		fprintf(stderr, "usage: invalid arguments\n");
// 		exit(1);
// 	}

// 	//printf("2\n");
// 	/* translate host name into peer's IP address */
// 	hp = gethostbyname(host);
// 	if (!hp) {
// 		fprintf(stderr, "simplex-talk: unknown host: %s\n", host);
// 		exit(1);
// 	}

// 	//printf("3\n");
// 	/* build address data structure */
// 	bzero((char *)&sin, sizeof(sin));
// 	sin.sin_family = AF_INET;
// 	bcopy(hp->h_addr, (char *)&sin.sin_addr, hp->h_length);
// 	sin.sin_port = htons(svrport);

// 	/* active open */
// 	if ((s = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
// 		perror("simplex-talk: socket"); exit(1);
// 	}

// 	//printf("4\n");
// 	if (connect(s, (struct sockaddr *)&sin, sizeof(sin)) < 0){
// 		perror("simplex-talk: connect");
// 		close(s);
// 		exit(1);
// 	}

// 	bzero((char *)&server_buf, sizeof(server_buf));

// 	/* Make file request for the server */
// 	len = strlen(filename) + 1;
// 	//printf("%s\n", buf);
// 	//printf("%d\n", len);
// 	if(send(s, filename, len, 0) == -1){
// 		perror("client send error!"); exit(1);
// 	}

// 	//printf("5\n");
// 	/* Receive file size message from server */
// 	if((len = recv(s, server_buf, sizeof(server_buf), 0)) == -1){
// 		perror("Client Received Error!");
// 		exit(1);
// 	}
// 	else if (len != 0){
// 		int fileSize = atoi(server_buf);
// 		if(fileSize < 0) {
// 			printf("File does not exist.\n");
// 			exit(1);
// 		}

// 		printf("Message size from server: %d\n", fileSize); //DEBUG
// 		bzero((char *)&server_buf, sizeof(server_buf));

// 		/* Receive file from server */
// 		FILE* newfile = fopen(filename, "wb");
// 		file_len = 0;

// 		//printf("5\n");

// 		gettimeofday(&detail_time_send,NULL);

// 		//int nit = 0;
// 		while(file_len != fileSize) {
// 			//printf("nit = %d\n", nit);
// 			if((file_chunk_len = recv(s, file_buf, MAX_LINE, 0)) == -1){
// 				perror("Client Received Error!");
// 				exit(1);
// 			}
// 			file_len += file_chunk_len;
// 			fwrite(file_buf, file_chunk_len, 1, newfile);
// 			//printf("%d\n", file_len);
// 			if(file_len > fileSize) {
// 				perror("Too many bytes written!");
// 				exit(1);
// 			}
// 			//nit++;
// 		}
// 		gettimeofday(&detail_time_recv,NULL);

// 		fclose(newfile);
// 		bzero((char *)&server_buf, sizeof(server_buf));

// 		/* Receive file hash from server */
// 		unsigned char hashbuffer[16];
// 		if((len=recv(s,hashbuffer,16,0))==-1){
// 			perror("Client receive error!\n");
// 			exit(1);
// 		}
// 		else if (len != 0){

// 			//Compute hash
// 			newfile = fopen(filename, "rb");

// 			MHASH td;
// 			unsigned char *hash;
// 			unsigned char hbuffer;

// 			td = mhash_init(MHASH_MD5);
			
// 			if (td == MHASH_FAILED){
// 				printf("Error: Hash fail\n");
// 				exit(1);
// 			}

// 			// printf("File position: %ld\n", ftell(newfile));
// 			// printf("File length: %d\n", file_len);

// 			while (fread(&hbuffer, 1, 1, newfile) == 1) {
//                 mhash(td, &hbuffer, 1);
//         	}
// 			hash = mhash_end(td);

// 			//Comparing hash values
// 			int bad = 0;
// 			int j, k;
// 			char hash1[32];
// 			char hash2[32];
// 			int i;
// 			for (i=0; i<16; i++){
// 			 	j = sprintf(hash1, "%.2x", hash[i]);
// 			 	k = sprintf(hash2, "%.2x", hashbuffer[i]);

// 			 	if(j<0 || k<0){	
// 			 		printf("hash string error\n");
// 			 		exit(1);
// 			 	}
// 			 	if(strncmp(hash1,hash2,strlen(hash1))!=0){
// 			 		bad=1;
// 			 	}
// 			}

// 			// printf("File MD5sum: ");

// 		 //    for (k = 0; k < 16; k++) {
// 		 //    	printf("%.2x", hashbuffer[k]);
// 		 //    }
// 		 //    printf("\n");
// 		 //    for (k = 0; k < 16; k++) {
// 		 //    	printf("%.2x", hash[k]);
// 		 //    }
// 		 //    printf("\n");

// 			if(bad){
// 				printf("Error: File hashes do not match — bad transfer\n");
// 				exit(1);
// 			}//otherwise continue

// 		    //Print results
// 		    printf("Hash matches\n");
// 		    send_time = detail_time_send.tv_sec + detail_time_send.tv_usec / 1000000.0;
// 		    recv_time = detail_time_recv.tv_sec + detail_time_recv.tv_usec / 1000000.0;
// 		    diff_time = recv_time - send_time;

// 		    printf("%d bytes transferred in %.4f seconds. Throughput: %.3f Kilobytes/sec. ",
// 		    	file_len, diff_time, file_len / (1000*diff_time));

// 		    printf("File MD5sum: ");

// 		    for (k = 0; k < 16; k++) {
// 		    	printf("%.2x", hashbuffer[k]);
// 		    }
// 		    printf("\n");

// 		    bzero((char *)&server_buf, sizeof(server_buf));
// 		}
// 		//printf("7\n");

// 		close(s);
// 	}
// }