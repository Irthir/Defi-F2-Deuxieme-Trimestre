#include "Menu.h"


void Menu(int erreur)
{
    int nFonctionnement=1;
    char cEntreeMenu='\0';

    while (nFonctionnement==1)
    {
        system("cls");
        AfficheMenu();
        cEntreeMenu=fgetc(stdin);
        fflush(stdin);

        if(cEntreeMenu=='h' || cEntreeMenu=='H')
        {
            hote();
            getchar();
            fflush(stdin);
        }
        else if(cEntreeMenu=='c' || cEntreeMenu=='C')
        {
            client();
            getchar();
            fflush(stdin);
        }
        else if(cEntreeMenu=='q' || cEntreeMenu=='Q')
        {
            nFonctionnement=0;
        }
    }
}

void AfficheMenu()
{
    color(11,0); //Couleur Cyan
    printf("TITRE DU JEU !\n");
    color(2,0); //Couleur Verte.
    printf("\n[H]");
    color(7,0);//On remet gris sur fond noir.
    printf("ote\n");
    color(14,0); //Couleur Jaune.
    printf("\n[C]");
    color(7,0);//On remet gris sur fond noir.
    printf("lient\n");
    color(12,0); //Couleur Rouge.
    printf("\n[Q]");
    color(7,0);//On remet gris sur fond noir.
    printf("uitter\n");
}

void color(int t,int f)
//Les couleurs qu'on utilise, 0 pour noir, 7 pour gris clair, 2 pour du vert, 14 pour du jaune, 12 pour du rouge, 11 pour du cyan.
{
	HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H,f*16+t);
}
