#include <winsock2.h>
//Inclusion de winsock2.h
#include <stdio.h>
#include <stdlib.h>

//Note ne pas oublier d'ajouter le fichier "libws2_32.a" dans l'�diteur de lien, via un clique droit sur le projet >> Build options >> linker settings >> add >> s�lection de "libws2_32.a"

//Les typedef

typedef int socklen_t; //Cr�ation du type socklen_t pour �viter les probl�me de compilation.


//Les struct

struct sockaddr_in //Cette structure va nous permettre de param�trer la socket.
{
    short sin_family;
    unsigned short sin_port;
    struct in_addr sin_addr;
    char sin_zero[8];
};
/*sin.sin_addr.s_addr sera l'IP donn�e automatiquement au serveur. Pour le conna�tre nous utiliserons la fonction htonl avec comme seul param�tre la valeur INADDR_ANY.
Si vous voulez sp�cifier une adresse IP precise � utiliser, il est possible d'utiliser la fonction inet_addr avec comme seul param�tre l'IP dans une chaine de caract�res :

inet_addr("127.0.0.1");
sin.sin_family sera toujours �gal � AF_INET dans notre cas (en savoir plus).

Et sin.sin_port sera �gal � la valeur retourn�e par la fonction htons, avec comme param�tre le port utilis�.

Le champ sin_zero ne sera pas utilis�.*/


//Les Prototypes

int socket(int domain, int type, int protocol); //Pour cr�er la socket il nous faut cette fonction.
int bind(int socket, const struct sockaddr* addr, socklen_t addrlen);//Pour associer � la socket les informations de la structure pr�c�demment d�clar�e.
int listen(int socket, int backlog); //Pour mettre la socket en �tat d'�coute.
int accept(int socket, struct sockaddr* addr, socklen_t* addrlen);//Cette fonction permet la connexion client/serveur en acceptant un appel de connexion.*/
int closesocket(int sock); //Pour fermer la connexion.

int main()
{
    WSADATA WSAData; //Initialise la biblioth�que WinSock
    WSAStartup(MAKEWORD(2,2), &WSAData); //La Macro MAKEWORD transforme les deux entiers d'un octet en param�tres en un entier de deux octes qu'elle retourne.
    //Ceci va permettre de renseigner la version que l'utilisateur souhaite utiliser, soit 2.0 ici et elle retourne la valeur 0 si tout s'est bien pass�.
    WSACleanup(); //Cette fonction lib�re les ressources allou�es pour la fonction WSAStartup().

    SOCKET sock;

    //D�claration et initialisation de la structure de type SOCKADDR_IN
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

int socket(int domain, int type, int protocol) //Pour cr�er la socket il nous faut cette fonction.
/*La fonction retourne une socket cr��e � partir des param�tres qui suivent.

Le param�tre domain repr�sente la famille de protocoles utilis�e.
Il prend la valeur AF_INET pour le protocole TCP/IP.
Sinon, il prend la valeur AF_UNIX pour les communications UNIX en local sur une m�me machine.

Le type indique le type de service, il peut avoir les valeurs suivantes :

SOCK_STREAM, si on utilise le protocole TCP/IP.

SOCK_DGRAM, si on utilise le protocole UDP/IP.

Nous utiliserons donc la premi�re (notez qu'il en existe d'autres comme SOCK_RAW mais ils nous seront inutiles).

Dans le cas de la suite TCP/IP, le param�tre protocol n'est pas utile, on le mettra ainsi toujours � 0.
Comme dans notre cas nous utiliserons le protocole TCP/IP, notre fonction sera toujours :

sock = socket(AF_INET, SOCK_STREAM, 0);*/
{
}

int bind(int socket, const struct sockaddr* addr, socklen_t addrlen)//Pour associer � la socket les informations de la structure pr�c�demment d�clar�e.
/*La fonction retourne SOCKET_ERROR en cas d'erreur (en savoir plus).

Le param�tre socket d�signe la socket du serveur avec laquelle on va associer les informations.

Le param�tre addr est un pointeur de structure sockaddr du serveur.
Il sp�cifie l'IP � laquelle on se connecte... Comme la fonction a besoin d'un pointeur sur structure sockaddr, et que nous disposons que d'une structure SOCKADDR_IN, nous allons faire un cast, pour �viter que le compilateur nous retourne une erreur lors de la compilation.

Le param�tre addrlen sera la taille m�moire occup�e par le contexte d'adressage du serveur (notre structure SOCKADDR_IN), nous utiliserons donc sizeof ;) (si vous ne vous rappelez plus du cours de m@teo21, je vous conseil de relire le cours sur l'allocation dynamique :p ).*/
{
}

int listen(int socket, int backlog) //Pour mettre la socket en �tat d'�coute.
/*La fonction retourne SOCKET_ERROR si une erreur est survenue.

Le param�tre socket d�signe la socket qui va �tre utilis�e.

Le param�tre backlog repr�sente le nombre maximal de connexions pouvant �tre mises en attente.*/
{
}

int accept(int socket, struct sockaddr* addr, socklen_t* addrlen);//Cette fonction permet la connexion client/serveur en acceptant un appel de connexion.*/
/*La fonction retourne la valeur INVALID_SOCKET en cas d'�chec. Sinon, elle retourne la socket du client.

Le param�tre socket est, comme dans les autre fonctions, la socket serveur utilis�e.

Le param�tre addr est un pointeur sur le contexte d'adressage du client.

Le param�tre addrlen ne s'utilise pas comme dans la fonction bind ; ici, il faut cr�er une variable taille de type socklen_t (qui n'est rien d'autre qu'un entier), �gale � la taille du contexte d'adressage du client. Ensuite, il faudra passer l'adresse de cette variable en param�tre.*/
{
}

int closesocket(int sock); //Pour fermer la connexion.
{
}
