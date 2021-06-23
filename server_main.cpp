#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
// #include<thread.h>
#include <stdio.h>

// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")


int  main()
{

    WORD wVersionRequested;
    WSADATA wsaData;
    SOCKET s,new_socket;
    struct sockaddr_in server,client;
	char *message , server_reply[2000];
	int recv_size;
    int err;
    int c;
/* Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h */
    wVersionRequested = MAKEWORD(2, 2);

    err = WSAStartup(wVersionRequested, &wsaData);
        if (err != 0) {
        /* Tell the user that we could not find a usable */
        /* Winsock DLL.                                  */
        printf("WSAStartup failed with error: %d\n", err);
        return 1;
    }

/* Confirm that the WinSock DLL supports 2.2.*/
/* Note that if the DLL supports versions greater    */
/* than 2.2 in addition to 2.2, it will still return */
/* 2.2 in wVersion since that is the version we      */
/* requested.                                        */

    if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
        /* Tell the user that we could not find a usable */
        /* WinSock DLL.                                  */
        printf("Could not find a usable version of Winsock.dll\n");
        WSACleanup();
        return 1;
    }
    else
        printf("The Winsock 2.2 dll was found okay\n");
        

/* The Winsock DLL is acceptable. Proceed to use it. */
    if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d" , WSAGetLastError());
	}

	printf("Socket created.\n");

/* Add network programming using Winsock here */
    server.sin_addr.s_addr = inet_addr("192.168.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons( 5050 );

	//Connect to remote server
	if (bind(s , (struct sockaddr *)&server , sizeof(server)) == 0)
	{
		puts("connect error");
		return 1;
	}
	
	puts("bind done");
    //Listen to incoming connections
	listen(s , 3);
	
	//Accept and incoming connection
	puts("Waiting for incoming connections...");
	
	c = sizeof(struct sockaddr_in);
	new_socket = accept(s , (struct sockaddr *)&client, &c);
	if (new_socket == INVALID_SOCKET)
	{
		printf("accept failed with error code : %d" , WSAGetLastError());
	}
	
	puts("Connection accepted");

	//Reply to client
	message = "Hello Client , I have received your connection. But I have to go now, bye\n";
	send(new_socket , message , strlen(message) , 0);
	
	getchar();

    
/* then call WSACleanup when done using the Winsock dll */
    // closesocket(s);    
    WSACleanup();
    return 0;
}
