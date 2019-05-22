#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_LINE 1024 //maximum packet length

int main(int argc, const char** argv) {
    //check server parameters
    if (argc != 2) {
        fprintf(stderr, "<Error> Program requires 1 argument, %d found \n",argc - 1);
        exit(1);
    }
    
    struct sockaddr_in saddr;
    int server_port = strtol(argv[1], NULL, 10);
    int sockfd;

    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = INADDR_ANY;
    saddr.sin_port = htons(server_port);

    if((sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP)) == -1) {
        fprintf(stderr, "<Error> Failed to create socket!! \n");
        exit(2);
    }

    if (bind(sockfd,(struct sockaddr*)&saddr, sizeof (saddr)) == -1) {
        fprintf(stderr, "<Error> Failed to bind socket!! \n");
        exit(3);
    }
    

    return 0;
}