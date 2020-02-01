#include "Hote.h"

void hote(void)
{
    pthread_t threadRecept;
    pthread_t threadEnvoi;

    WSADATA WSAData;
    int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);

    SOCKET sock;
    SOCKADDR_IN sin;
    SOCKET csock;
    SOCKET *pCsock;
    SOCKADDR_IN csin;
    socklen_t recsize = sizeof(csin);
    int sock_err;


    /* Si les sockets Windows fonctionnent */
    if(!erreur)
    {
        sock = socket(AF_INET, SOCK_STREAM, 0);

        /* Si la socket est valide */
        if(sock != INVALID_SOCKET)
        {
            printf("La socket %d est maintenant ouverte en mode TCP/IP\n", sock);

            /* Configuration */
            sin.sin_addr.s_addr     = htonl(INADDR_ANY);   /* Adresse IP automatique */
            sin.sin_family          = AF_INET;             /* Protocole familial (IP) */
            sin.sin_port            = htons(PORT);         /* Listage du port */
            //sin.sin_addr.s_addr = inet_addr("127.0.0.1");
            sock_err = bind(sock, (SOCKADDR*)&sin, sizeof(sin));


            /* Si la socket fonctionne */
            if(sock_err != SOCKET_ERROR)
            {
                //Tentative d'affichage de l'IP.
                showHost();

                /* Démarrage du listage (mode server) */
                sock_err = listen(sock, 5);
                printf("Listage du port %d...\n", PORT);

                /* Si la socket fonctionne */
                if(sock_err != SOCKET_ERROR)
                {
                    /* Attente pendant laquelle le client se connecte */
                    printf("Patientez pendant que le client se connecte sur le port %d...\n", PORT);

                    csock = accept(sock, (SOCKADDR*)&csin, &recsize);
                    printf("Un client se connecte avec la socket %d de %s:%d\n", csock, inet_ntoa(csin.sin_addr), htons(csin.sin_port));

                    pCsock=&csock;

                    pthread_create(&threadEnvoi,NULL,ReceptionHote,pCsock);
                    pthread_create(&threadRecept,NULL,EnvoieHote,pCsock);

                    printf("Le tchat est lancé.\n");

                    pthread_join(threadEnvoi,NULL);
                    pthread_join(threadRecept,NULL);

                    /* Il ne faut pas oublier de fermer la connexion (fermée dans les deux sens) */
                    shutdown(csock, 2);
                }
            }
            /* Fermeture de la socket */
            printf("Fermeture de la socket...\n");
            closesocket(sock);
            printf("Fermeture du serveur terminee\n");
        }
    }
    WSACleanup();
    return EXIT_SUCCESS;
}

void showHost()
{
    char hostname[1024];
    hostname[1023] = '\0';
    gethostname(hostname, 1023);
    //printf("Hostname: %s\n", hostname);
    struct hostent* remoteHost;
    remoteHost = gethostbyname(hostname);
    char* ip;
    ip = inet_ntoa(*(struct in_addr *)*remoteHost->h_addr_list);
    printf("Votre adresse IP est : %s.\n", ip);
}

void* ReceptionHote(void* data)
{
    char cBufferReception[100];
    int nSock=(int)data;
    while (1)
    {
        /* Si l'on reçoit des informations : on les affiche à l'écran */
        if (recv(nSock, cBufferReception, 100, 0) != SOCKET_ERROR)
            printf("[Client]: %s\n", cBufferReception);
    }
}

void* EnvoieHote(void* data)
{
    char cBufferEnvoi[100];
    int sock_err;
    while (1)
    {
        fgets(cBufferEnvoi,sizeof(cBufferEnvoi),stdin);

        int nSock=(int)data;
        sock_err = send(nSock, cBufferEnvoi, 100, 0);

        if(sock_err != SOCKET_ERROR)
            printf("[Serveur]: %s\n", cBufferEnvoi);
        else
            printf("Erreur de transmission\n");
        fflush(stdin);
    }
}
