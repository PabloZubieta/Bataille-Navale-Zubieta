#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func1.h"
#include <stddef.h>
#include <conio.h>
#include "foncsystem.h"

#include <string.h>


//voici la fonction menu elle a l'afficha du début du jeu et da demander a l'utilisateur
// de entrée un int pour choisir la fonction qu'il desire en l'aide le score et le jeu

void menu(){

    system("cls");
    printf("Bataille Navale\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",238,238,238,238,238,238,238,238,238,238,238,238,238,238,238);
    printf("1.Aide\n2.Jouer\n3.Scores\n\nVotre choix?");
    int choix_menu=test(3,1);
    system("cls");
    switch (choix_menu) {
        case 1:
            aide();
            break;
        case 2:
            jeu();
            break;
        case 3:
            score();
            break;
    }

}

int main() {
    menu();


    return 0;
}

