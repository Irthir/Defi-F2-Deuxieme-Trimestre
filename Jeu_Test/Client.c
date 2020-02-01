#include "Client.h"

void client(void)
{
    pthread_t threadRecept;
    pthread_t threadEnvoi;

    WSADATA WSAData;
    int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);

    SOCKET sock;
    SOCKET *pSock;
    SOCKADDR_IN sin;
    //char buffer[32] = "";

    //SOCKET csock;
    //SOCKADDR_IN csin;
    //socklen_t recsize = sizeof(csin);

    /* Si les sockets Windows fonctionnent */
    if(!erreur)
    {
        /* Création de la socket */
        sock = socket(AF_INET, SOCK_STREAM, 0);

        char cIP[15]={'\0'};
        printf("Rentrez l'adresse IP de l'hote.\n");
        fflush(stdin);
        fgets(cIP,sizeof(cIP),stdin);
        fflush(stdin);

        /* Configuration de la connexion */
        sin.sin_addr.s_addr = inet_addr(cIP);
        sin.sin_family = AF_INET;
        sin.sin_port = htons(PORT);

        /* Si l'on a réussi à se connecter */
        if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
        {
            printf("Connection a %s sur le port %d\n", inet_ntoa(sin.sin_addr), htons(sin.sin_port));

            pSock=&sock;
            pthread_create(&threadEnvoi,NULL,ReceptionClient,pSock);
            /* Si l'on reçoit des informations : on les affiche à l'écran */
            pthread_create(&threadRecept,NULL,EnvoieClient,pSock);

            printf("Le tchat est lancé.\n");

            pthread_join(threadEnvoi,NULL);
            pthread_join(threadRecept,NULL);
        }
        /* sinon, on affiche "Impossible de se connecter" */
        else
        {
            printf("Impossible de se connecter\n");
        }

        /* On ferme la socket */
        closesocket(sock);
    }
    WSACleanup();
    return EXIT_SUCCESS;
}


void* ReceptionClient(void* data)
{
    int nSock=(int)data;
    while (1)
    {
        char cBufferReception[100];
        /* Si l'on reçoit des informations : on les affiche à l'écran */
        if (recv(nSock, cBufferReception, 100, 0) != SOCKET_ERROR)
            printf("[Serveur]: %s\n", cBufferReception);
    }

}

void* EnvoieClient(void* data)
{
    int nSock=(int)data;
    char cBufferEnvoi[100];
    int sock_err;
    while (1)
    {
        fgets(cBufferEnvoi,sizeof(cBufferEnvoi),stdin);

        sock_err = send(nSock, cBufferEnvoi, 100, 0);

        if(sock_err != SOCKET_ERROR)
            printf("[Client]: %s\n", cBufferEnvoi);
        else
            printf("Erreur de transmission\n");
        fflush(stdin);
    }
}
