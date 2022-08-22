#include <stdio.h> 
#include <string.h> 
#include <unistd.h> 

#include <sys/types.h>
#include <sys/socket.h> 
#include <netinet/in.h>


#define SERVER_PORT 6789

int main(int argc, char **argv) {
    
	char buf[1024];
	socklen_t len = sizeof(buf);
	
    int sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		perror("socket");
		return -1;
	} 

	struct sockaddr_in serverAddress;
	memset(&serverAddress, 0, sizeof(serverAddress));
	socklen_t len2 = sizeof(serverAddress);
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(SERVER_PORT);    //convert the port to big indian
	serverAddress.sin_addr.s_addr = INADDR_ANY;		//all addres
	
	if(bind(sock,(struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
		perror("bind");
		return -1;
	}
	if(listen(sock,5) == -1) {
		perror("listen");
		return -1;
	}

    while(1) {

        printf("Ready to serve...\n");
        int acpt = accept(sock, (struct sockaddr*) &serverAddress, &len2);
        if(acpt == -1){
            perror("accept");
            return -1;
        }
    
        if(recv(acpt,buf,len,0) == -1) {
            printf("could not recieve\n");
            return -1;
        }

		// extract page request
		char* piece = strtok(buf, " ");
    	piece = strtok(NULL, " ");
		char toOpen[100];
		strncpy(toOpen, piece + 1, strlen(piece) - 1);


		FILE *fp = NULL;
		char sbuffer[1000];
		char *filename = toOpen;

		fp = fopen(filename, "r");

		if(fp == NULL) {
			printf("filename: %s, not found.\n", filename);
			continue;
		}

		char* okHeader = "HTTP/1.1 200 OK\n\n";

		if(send(acpt, okHeader, strlen(okHeader), 0) == -1) {
            perror("send");
        }

		// send html file
		int sent;
		while (fread(sbuffer, sizeof(char), 1000, fp) > 0) {
			sent = send(acpt, sbuffer, strlen(sbuffer), 0);
			memset(&sbuffer, 0, sizeof(sbuffer));
			if (sent < 0) {
				fclose(fp);
			}		  
		}
		close(acpt);
		
    }
	close(sock);
	
	return 0; 

}