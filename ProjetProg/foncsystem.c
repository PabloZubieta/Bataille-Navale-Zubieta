//
// Created by Pablo-Fernando.ZUBIE on 21.01.2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "func1.h"

//cette page de fonction regroupe le fonction que je qualifirais de système celle qui ont des fonction globale et independante

void aide();
void menu();
void score();
void page1();
void page2();
void page3();
void jeu();

//petite fonction d'aide qui lance les page d'aide

void aide(){
    page1();
    menu();
}

//Voici les page d'aides elle sont au nombre de 3 elle on particularité d'avoir qui de code qui n'est pas de moi
//Ce code a pour effet de habilité les touches fleches et permetre a l'utlisateur de ainsi changer de page

void page3(){
    system("cls");
    printf("Aide\n%c%c%c%c\n",238,238,238,238);
    printf("Il est dit que :\n"
           " Deux bateaux ne peuvent pas\n "
           "se toucher\n "
           "Un bateau ne peut pas etre\n "
           "en contact avec le bord de\n"
           " la grille par plus que 1 case");


    //voici la partie de code qui habilite les fleches

    int ch1, ch2;
    ch1 = getch();
    ch2 = 0;
    switch (ch1) {
        case 0xE0:
            ch2 = getch();
            switch(ch2)
            {
                case 72:
                    page2();
                    break;
                case 80:
                    return;
                default:
                    break;
            };
            break;
        case 'q': case'Q':
            return;
        default:
            page3();
            break;
    }




}
void page2(){
    system("cls");
    printf("Aide\n%c%c%c%c\n",238,238,238,238);
    printf("Il est dit que la flotte\n"
           " ennemie se compose de:\n"
           " Un zodiaque de 1 case\n"
           " Une vedette rapide de 2 cases\n"
           " Un croiseur de 3 cases\n"
           " Un cuirasse de 4 cases\n"
           " Un porte-avion de 5 cases");
    int ch1, ch2;
    ch1 = getch();
    ch2 = 0;
    switch (ch1) {
        case 0xE0:
            ch2 = getch();
            switch(ch2)
            {
                case 72:

                    page1();
                    break;
                case 80:

                    page3();
                    break;

                default:

                    break;
            };
            break;
        case 'q': case'Q':

            return;
        default:

            page2();
            break;
    }




}
void page1(){
    system("cls");
    printf("Aide\n%c%c%c%c\n",238,238,238,238);
    printf(" Vous trouverez un tuto\n"
           " video a \n");
    printf(" Pour jouer, il faut entrer\n"
           " la case sur laquelle\n"
           ""
           " vous voulez tirer\n ");
    int ch1, ch2;

    ch1 = getch();
    ch2 = 0;
    switch (ch1) {
        case 0xE0:
            ch2 = getch();
            switch(ch2)
            {
                case 80:

                    page2();
                    break;
                default:

                    break;
            };
            break;
        case 'q': case'Q':

            return;
        default:

            page1();
            break;
    }



}

//voici la fonction score elle affiche les scores qui sont recuperés grace a la fonction readscore

void score(){
    struct joueur scoretab[10]={{"none",0}
            ,{"none",0},{"none",0}
            ,{"none",0},{"none",0}
            ,{"none",0},{"none",0}
            ,{"none",0},{"none",0}
            ,{"none",0}};
    Readscore(scoretab);
    for (int i = 0; i<=9; i++){
        printf("%d:%s  score:%d\n",i+1,scoretab[i].nom,scoretab[i].score);
    }
    getch();

    menu();

    return;

}

//et voilà la fonction jeu c'est elle qui va grace a l'affichage
// et la fonction position 1 elle appelle aussi la fonction victoire qui va verifier si le jeu est ganger ou pas

void jeu(){
    struct joueur player;
    player.score= 50;
    struct joueur scoretab[10]={{"none",0},
                                {"none",0},{"none",0}
            ,{"none",0},{"none",0}
            ,{"none",0},{"none",0}
            ,{"none",0},{"none",0}
            ,{"none",0}};
    int victory= 0;
    char historique[50]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    printf("Veuillez entrer votre nom\n");
    scanf("%s",player.nom);
    system("cls");
    int tableau_affiche[10][10];
    settab_0(tableau_affiche);
    int table[10][10]={{0,00,00,00,00,0,0,0,18,0},
                       {0,04,00,00,00,0,0,0,20,0},
                       {0,00,00,00,00,0,0,0,20,0},
                       {0,06,06,00,00,0,0,0,20,0},
                       {0,00,00,00,00,0,0,0,18,0},
                       {0,10,12,10,00,0,0,0,00,0},
                       {0,00,00,00,00,0,0,0,00,0},
                       {0,14,16,16,14,0,0,0,00,0},
                       {0,00,00,00,00,0,0,0,00,0},
                       {0,00,00,00,00,0,0,0,00,0}};
    char saisie [2];
    do{
        affiche(tableau_affiche,player,historique);
        player.score-= position1(table,saisie,tableau_affiche,historique);
        victory= victoire(table);
        system("cls");
    } while (player.score!=0&&victory==0);
    system("cls");
    if(victory){
        printf("vous Avez gagneé\n vous êtes fort");
    }else{
        printf("vous Avez perdu\n vous êtes nul");
    }
    updatescore(scoretab, player);
    getch();
    menu();

    return;
}
