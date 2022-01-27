//
// Created by Pablo-Fernando.ZUBIE on 14.01.2022.
//

#ifndef PROJETPROG_FUNC1_H
#define PROJETPROG_FUNC1_H





struct joueur {
    char nom[20];
    int score;
};
void Readscore(struct joueur score[10]);
void updatescore(struct joueur score[10], struct joueur player);
int test(int sup, int inf);
void tableau_10 (int tableau[10][10]);
void affiche(int tableau[10][10],struct joueur player,char historique[50]);
void copytableau(int modele[10][10], int copy[10][10]);
void settab_0 (int tableau[10][10]);
int triage(int valeur,char position[2]);
int position1(int tableau[10][10], char position[2],int tabeaucopy[10][10],char historique[50]);
int position2(int tableau[10][10],char position[2],int p1,int tabeaucopy[10][10],char historique[50]);
void aide();
void menu();
void score();
void page1();
void page2();
void page3();
int victoire(int tableau[10][10]);
void jeu();

#endif //PROJETPROG_FUNC1_H
