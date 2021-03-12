#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
int main(void)
{
    int socket_desc, client_sock;
    socklen_t client_size;
    struct sockaddr_in server_addr, client_addr;
    char server_message[2000], client_message[2000];

    // Clean buffers:
    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));

    // Create socket:
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);


    // Set port and IP:
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(2000);
 //server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  server_addr.sin_addr.s_addr = inet_addr("192.168.43.72");

//int reuse = 1;
//    if (setsockopt(socket_desc, SOL_SOCKET, SO_REUSEADDR, (const char*)&reuse, sizeof(reuse)) < 0)
//        perror("setsockopt(SO_REUSEADDR) failed");
//
//#ifdef SO_REUSEPORT
//    if (setsockopt(socket_desc, SOL_SOCKET, SO_REUSEPORT, (const char*)&reuse, sizeof(reuse)) < 0)
//        perror("setsockopt(SO_REUSEPORT) failed");
//#endif
    // Bind to the set port and IP:
    if(bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr))<0){
        printf("Couldn't bind to the port\n");
        return -1;
    }
    printf("Done with binding\n");
    uint32_t msgCounter =0UL;
//char abhayCounter = 0;
//for(abhayCounter = 0; abhayCounter <= 2; abhayCounter++)
while(1){     //if the while is here then it will read the different clients one by one
    // Listen for clients:
    if(listen(socket_desc, 1) < 0){
        printf("Error while listening\n");
        return -1;
    }
    printf("\nListening for incoming connections.....\n");

    // Accept an incoming connection:
    client_size = sizeof(client_addr);
    client_sock = accept(socket_desc, (struct sockaddr*)&client_addr, &client_size);

    if (client_sock < 0){
        printf("Can't accept\n");
        return -1;
    }
    printf("Client connected at IP: %s and port: %i\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
//while(1){   //if the while is here it locks onto only one client and displays it's request
    // Receive client's message:
    if (recv(client_sock, client_message, sizeof(client_message), 0) < 0){
        printf("Couldn't receive\n");
        return -1;
    }
    printf("%d Msg from client: %s\n", msgCounter, client_message);

    // Respond to client:
    strcpy(server_message, "This is the server's message.");

    if (send(client_sock, server_message, strlen(server_message), 0) < 0){
        printf("Can't send\n");
        return -1;
    }
    msgCounter++;
}
    // Closing the socket:
    close(client_sock);
    close(socket_desc);

    return 0;
}
