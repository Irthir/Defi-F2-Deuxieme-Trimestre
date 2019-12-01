#include <winsock2.h>
//Inclusion de winsock2.h
#include <stdio.h>
#include <stdlib.h>

//Note ne pas oublier d'ajouter le fichier "libws2_32.a" dans l'éditeur de lien, via un clique droit sur le projet >> Build options >> linker settings >> add >> sélection de "libws2_32.a"

//Les typedef

typedef int socklen_t; //Création du type socklen_t pour éviter les problème de compilation.


//Les struct

struct sockaddr_in //Cette structure va nous permettre de paramétrer la socket.
{
    short sin_family;
    unsigned short sin_port;
    struct in_addr sin_addr;
    char sin_zero[8];
};
/*sin.sin_addr.s_addr sera l'IP donnée automatiquement au serveur. Pour le connaître nous utiliserons la fonction htonl avec comme seul paramètre la valeur INADDR_ANY.
Si vous voulez spécifier une adresse IP precise à utiliser, il est possible d'utiliser la fonction inet_addr avec comme seul paramètre l'IP dans une chaine de caractères :

inet_addr("127.0.0.1");
sin.sin_family sera toujours égal à AF_INET dans notre cas (en savoir plus).

Et sin.sin_port sera égal à la valeur retournée par la fonction htons, avec comme paramètre le port utilisé.

Le champ sin_zero ne sera pas utilisé.*/


//Les Prototypes

int socket(int domain, int type, int protocol); //Pour créer la socket il nous faut cette fonction.
int bind(int socket, const struct sockaddr* addr, socklen_t addrlen);//Pour associer à la socket les informations de la structure précédemment déclarée.
int listen(int socket, int backlog); //Pour mettre la socket en état d'écoute.
int accept(int socket, struct sockaddr* addr, socklen_t* addrlen);//Cette fonction permet la connexion client/serveur en acceptant un appel de connexion.*/
int closesocket(int sock); //Pour fermer la connexion.

int main()
{
    WSADATA WSAData; //Initialise la bibliothèque WinSock
    WSAStartup(MAKEWORD(2,2), &WSAData); //La Macro MAKEWORD transforme les deux entiers d'un octet en paramètres en un entier de deux octes qu'elle retourne.
    //Ceci va permettre de renseigner la version que l'utilisateur souhaite utiliser, soit 2.0 ici et elle retourne la valeur 0 si tout s'est bien passé.
    WSACleanup(); //Cette fonction libère les ressources allouées pour la fonction WSAStartup().

    SOCKET sock;

    //Déclaration et initialisation de la structure de type SOCKADDR_IN
    SOCKADDR_IN sin;
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(23);

    bind(sock, SOCKADDR*&sin, sizeof(sin)); //Utilisation de la fonction bind.

    listen(sock, 5); //Utilisation de la fonction listen.

    socklen_t taille = sizeof(csin); //Utilisation de la fonction accepte.
    csock = accept(sock, (SOCKADDR*)&csin, &taille);

    return 0;
}

int socket(int domain, int type, int protocol) //Pour créer la socket il nous faut cette fonction.
/*La fonction retourne une socket créée à partir des paramètres qui suivent.

Le paramètre domain représente la famille de protocoles utilisée.
Il prend la valeur AF_INET pour le protocole TCP/IP.
Sinon, il prend la valeur AF_UNIX pour les communications UNIX en local sur une même machine.

Le type indique le type de service, il peut avoir les valeurs suivantes :

SOCK_STREAM, si on utilise le protocole TCP/IP.

SOCK_DGRAM, si on utilise le protocole UDP/IP.

Nous utiliserons donc la première (notez qu'il en existe d'autres comme SOCK_RAW mais ils nous seront inutiles).

Dans le cas de la suite TCP/IP, le paramètre protocol n'est pas utile, on le mettra ainsi toujours à 0.
Comme dans notre cas nous utiliserons le protocole TCP/IP, notre fonction sera toujours :

sock = socket(AF_INET, SOCK_STREAM, 0);*/
{
}

int bind(int socket, const struct sockaddr* addr, socklen_t addrlen)//Pour associer à la socket les informations de la structure précédemment déclarée.
/*La fonction retourne SOCKET_ERROR en cas d'erreur (en savoir plus).

Le paramètre socket désigne la socket du serveur avec laquelle on va associer les informations.

Le paramètre addr est un pointeur de structure sockaddr du serveur.
Il spécifie l'IP à laquelle on se connecte... Comme la fonction a besoin d'un pointeur sur structure sockaddr, et que nous disposons que d'une structure SOCKADDR_IN, nous allons faire un cast, pour éviter que le compilateur nous retourne une erreur lors de la compilation.

Le paramètre addrlen sera la taille mémoire occupée par le contexte d'adressage du serveur (notre structure SOCKADDR_IN), nous utiliserons donc sizeof ;) (si vous ne vous rappelez plus du cours de m@teo21, je vous conseil de relire le cours sur l'allocation dynamique :p ).*/
{
}

int listen(int socket, int backlog) //Pour mettre la socket en état d'écoute.
/*La fonction retourne SOCKET_ERROR si une erreur est survenue.

Le paramètre socket désigne la socket qui va être utilisée.

Le paramètre backlog représente le nombre maximal de connexions pouvant être mises en attente.*/
{
}

int accept(int socket, struct sockaddr* addr, socklen_t* addrlen);//Cette fonction permet la connexion client/serveur en acceptant un appel de connexion.*/
/*La fonction retourne la valeur INVALID_SOCKET en cas d'échec. Sinon, elle retourne la socket du client.

Le paramètre socket est, comme dans les autre fonctions, la socket serveur utilisée.

Le paramètre addr est un pointeur sur le contexte d'adressage du client.

Le paramètre addrlen ne s'utilise pas comme dans la fonction bind ; ici, il faut créer une variable taille de type socklen_t (qui n'est rien d'autre qu'un entier), égale à la taille du contexte d'adressage du client. Ensuite, il faudra passer l'adresse de cette variable en paramètre.*/
{
}

int closesocket(int sock); //Pour fermer la connexion.
{
}
