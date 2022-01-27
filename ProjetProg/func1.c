//
// Created by Pablo-Fernando.ZUBIE on 14.01.2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


void page1();

//la structure joueur qui associe un nom et int score dans un seul objet

struct joueur {
    char nom[20];
    int score;
};
void couler(int tableau[10][10],int x, int y,char historique[50]);
int position2(int tableau[10][10],char position[2],int p1,int tabeaucopy[10][10],char historique[50]);
int position1(int tableau[10][10], char position[2],int tabeaucopy[10][10],char historique[50]);

//petites fonction de test qui si la valeur entrée dans le menu est valide

int test(int sup, int inf) {
    int a;
    scanf("%d", &a);
    if (( a>= inf) && ( a<= sup)) {
        return a;
    } else {
        printf("Votre saisie n'est pas pas valide\n", sup, inf);
        test(sup, inf);

    }


}

// première fonction tricky elle va prendre la valeur de la cellule trier pour savoir si elle contient un bateau ou autre chose
// ainsi que transmetre la une string contenant le cas qui a été rencontrer dans cette cellule

int triage(int valeur,char position[2],char historique[50]){
    if(valeur%2==1||valeur==-1){
        printf("cette case a déja ete touche\n");
        printf("veuillez entrer une autre position\n");
        return 0;
    }
    if (valeur==0){
        strcpy(historique,"00 manque c'est dommage");
        historique[0]=position[0];
        historique[1]=position[1];

        return 1;
    }

    strcpy(historique,"00 touche");
    historique[0]=position[0];
    historique[1]=position[1];
    return 2;

}

// petit fonction qui permet de copier un tableau dans un autre faite au debut du projet au cas ou jamais utilisé

void copytableau(int modele[10][10], int copy[10][10]){
    for (int i = 0; i<=9; i++) {
        for (int j=0;j<=9;j++){
            copy [i][j]=modele[i][j];
        }

    }
    return;
}

//petite fonction qui permet de entrer chaque celulle d'un tableau
// depuis le l'execution programme faite au debut du projet au cas ou jamais utilisé

void tableau_10 (int tableau[10][10]){

    for (int i = 0; i<=9; i++) {
        for (int j=0;j<=9;j++){
            printf ("Entrez un nombre: ");
            scanf ("%d", &tableau[i][j]);
        }

    }
    return;

}

//fonction d'affichage  qui affiche le tableau mise en forme qui affiche le nom du joueur et son score la jouée precedante

void affiche(int tableau[10][10], struct joueur player,char historique[50]){
    printf ("Nombres entres: \n");
    printf ("     0  1  2  3  4  5  6  7  8  9   Nom: %s\n",player.nom);
    for (int i = 0; i<=9; i++) {

        switch (i){
            case 0:
                printf("  A");
                break;
            case 1:
                printf("  B");
                break;
            case 2:
                printf("  C");
                break;
            case 3:
                printf("  D");
                break;
            case 4:
                printf("  E");
                break;
            case 5:
                printf("  F");
                break;
            case 6:
                printf("  G");
                break;
            case 7:
                printf("  H");
                break;
            case 8:
                printf("  I");
                break;
            case 9:
                printf("  J");
                break;

        }
        for (int j=0;j<=9;j++){
          if (tableau[i][j]==0){
            printf("  %c",126);}
            if(tableau[i][j]<0){
           printf("  O");}
           if(tableau[i][j]>0){
           printf ("  X");}


           // printf ("%3d", tableau[i][j]);




        }
        if (i==0){
            printf("   score: %d",player.score);
        }
        printf("\n");

    }
    printf("%s\n",historique);
    return;
}

//fonction qui initiale un tableau avec 0 dans toutes ses cellules

void settab_0 (int tableau[10][10]){

    for (int i = 0; i<=9; i++) {
        for (int j=0;j<=9;j++){

            tableau[i][j]=0;
        }

    }
    return;
}

//ok les soucis commencent, alors cette fonction demande a l'utilisateur d'entrer la position de la case qu'il vise et
//et elle va trier son premier d'ou le fait qu'il ait un gros switch
// elle fini donc par appeller position 2 en lui tranmetant l'integralité de parametre quelle a pris

int position1(int tableau[10][10], char position[2],int tabeaucopy[10][10],char historique[50]){
    printf("veuillez entrer une position sous la forme ligne colonne \nex: a9, C6\n");
    scanf("%s", position);
    int score=0;

    int p1= -1;
    switch (position[0]) {
        case 0x61: case 0x41:
            p1= 0;
            score= position2(tableau,position,p1, tabeaucopy,historique);
            break;
        case 0x62: case 0x42:
            p1= 1;
            score= position2(tableau,position,p1,tabeaucopy,historique);
            break;
        case 0x63: case 0x43:
            p1= 2;
            score= position2(tableau,position,p1,tabeaucopy,historique);
            break;
        case 0x64: case 0x44:
            p1= 3;
            score= position2(tableau,position,p1,tabeaucopy,historique);
            break;
        case 0x65: case 0x45:
            p1= 4;
            score= position2(tableau,position,p1,tabeaucopy,historique);
            break;
        case 0x66: case 0x46:
            p1= 5;
            score= position2(tableau,position,p1,tabeaucopy,historique);
            break;
        case 0x67: case 0x47:
            p1= 6;
            score= position2(tableau,position,p1,tabeaucopy,historique);
            break;
        case 0x68: case 0x48:
            p1= 7;
            score= position2(tableau,position,p1,tabeaucopy,historique);
            break;
        case 0x69: case 0x49:
            p1= 8;
            score= position2(tableau,position,p1,tabeaucopy,historique);
            break;
        case 0x6a: case 0x4a:
            p1= 9;
            score= position2(tableau,position,p1,tabeaucopy,historique);
            break;
        case 0x30:
            page1();
            break;
        default:
            printf("la position entree n'existe pas\n");
            position1(tableau, position,tabeaucopy,historique);
            break;
    }
    return score;
}

//ok donc voici l'horrible fonction cette fonction prend tout elle a dans un premier temps pour but de trier le dexième caractère
// d'ou le premier switch ensuite elle appelle le triage qui va orienté la fonction dans ce quelle doit faire du  et score du tableau
// elle fini par retour un si le score doit être decrmenté ou 0 sinon.

int position2(int tableau[10][10],char position[2],int p1,int tabeaucopy[10][10],char historique[50]){
    int score=0;
    switch (position[1]) {
        case 0x30:

            // on notera qui est fort probable que celle partie puisse être externalisé en une autre fonction mais par manque de temps


            switch (triage(tableau[p1][0],position,historique)) {
                case 0:
                    position1(tableau, position,tabeaucopy,historique);
                    break;
                case 1:
                    tableau[p1][0]-=1;
                    tabeaucopy[p1][0]= tableau[p1][0];
                    score=1;
                    break;
                case 2:
                    tableau[p1][0]-=1;
                    tabeaucopy[p1][0]= tableau[p1][0];
                    couler(tableau,p1,0,historique);
                    break;
            }

            break;
        case 0x31:
            switch (triage(tableau[p1][1],position,historique)) {
                case 0:
                    position1(tableau, position,tabeaucopy,historique);
                    break;
                case 1:
                    tableau[p1][1] -= 1;
                    tabeaucopy[p1][1]= tableau[p1][1];
                    score = 1;
                    break;
                case 2:
                    tableau[p1][1] -= 1;
                    tabeaucopy[p1][1]= tableau[p1][1];
                    couler(tableau,p1,1,historique);
                    break;
            }
            break;
        case 0x32:
            switch (triage(tableau[p1][2],position,historique)) {
                case 0:
                    position1(tableau, position,tabeaucopy,historique);
                    break;
                case 1:
                    tableau[p1][2] -= 1;
                    tabeaucopy[p1][2]= tableau[p1][2];
                    score = 1;
                    break;
                case 2:
                    tableau[p1][2] -= 1;
                    tabeaucopy[p1][2]= tableau[p1][2];
                    couler(tableau,p1,2,historique);
                    break;
            }
            break;
        case 0x33:
            switch (triage(tableau[p1][3],position,historique)) {
                case 0:
                    position1(tableau, position,tabeaucopy,historique);
                    break;
                case 1:
                    tableau[p1][3] -= 1;
                    tabeaucopy[p1][3]= tableau[p1][3];
                    score = 1;
                    break;
                case 2:
                    tableau[p1][3] -= 1;
                    tabeaucopy[p1][3]= tableau[p1][3];
                    couler(tableau,p1,3,historique);
                    break;
            }
            break;
        case 0x34:
            switch (triage(tableau[p1][4],position,historique)) {
                case 0:
                    position1(tableau, position,tabeaucopy,historique);
                    break;
                case 1:
                    tableau[p1][4]-=1;
                    tabeaucopy[p1][4]= tableau[p1][4];
                    score=1;
                    break;
                case 2:
                    tableau[p1][4]-=1;
                    tabeaucopy[p1][4]= tableau[p1][4];
                    couler(tableau,p1,4,historique);
                    break;
            }
            break;
        case 0x35:
            switch (triage(tableau[p1][5],position,historique)) {
                case 0:
                    position1(tableau, position,tabeaucopy,historique);
                    break;
                case 1:
                    tableau[p1][5] -= 1;
                    tabeaucopy[p1][5]= tableau[p1][5];
                    score = 1;
                    break;
                case 2:
                    tableau[p1][5] -= 1;
                    tabeaucopy[p1][5]= tableau[p1][5];
                    couler(tableau,p1,5,historique);
                    break;
            }
            break;
        case 0x36:
            switch (triage(tableau[p1][6],position,historique)) {
                case 0:
                    position1(tableau, position,tabeaucopy,historique);
                    break;
                case 1:
                    tableau[p1][6] -= 1;
                    tabeaucopy[p1][6]= tableau[p1][6];
                    score = 1;
                    break;
                case 2:
                    tableau[p1][6] -= 1;
                    tabeaucopy[p1][6]= tableau[p1][6];
                    couler(tableau,p1,6,historique);
                    break;
            }
            break;
        case 0x37:
            switch (triage(tableau[p1][7],position,historique)) {
                case 0:
                    position1(tableau, position,tabeaucopy,historique);
                    break;
                case 1:
                    tableau[p1][7] -= 1;
                    tabeaucopy[p1][7]= tableau[p1][7];
                    score = 1;
                    break;
                case 2:
                    tableau[p1][7] -= 1;
                    tabeaucopy[p1][7]= tableau[p1][7];
                    couler(tableau,p1,7,historique);
                    break;
            }
            break;
        case 0x38:
            switch (triage(tableau[p1][8],position,historique)) {
                case 0:
                    position1(tableau, position,tabeaucopy,historique);
                    break;
                case 1:
                    tableau[p1][8] -= 1;
                    tabeaucopy[p1][8]= tableau[p1][8];
                    score = 1;
                    break;
                case 2:
                    tableau[p1][8] -= 1;
                    tabeaucopy[p1][8]= tableau[p1][8];
                    couler(tableau,p1,8,historique);
                    break;
            }
            break;
        case 0x39:
            switch (triage(tableau[p1][9],position,historique)) {
                case 0:
                    position1(tableau, position,tabeaucopy,historique);
                    break;
                case 1:
                    tableau[p1][9] -= 1;
                    tabeaucopy[p1][9]= tableau[p1][9];
                    score = 1;
                    break;
                case 2:
                    tableau[p1][9] -= 1;
                    tabeaucopy[p1][9]= tableau[p1][9];
                    couler(tableau,p1,9,historique);
                    break;
            }
            break;
        default:
            printf("la position entree n'existe pas\n");
            position1(tableau, position,tabeaucopy,historique);
            break;
    }

    return score;

}

// cette fonction est qui va test les allentour de la cellule pour voir si elle à été touche et dans ce cas transmetre a la variable historique la string coulé
// note cette fonction a encore des bugs que je n'ai pas eu le temps de corriger

void couler(int tableau[10][10],int x, int y,char historique[50]){
    int true=0;
    switch (tableau[x][y]) {
        case 19:
            for (int i=1;i<=3;i++){
                if ((tableau[x-i][y]%2==0)&&(tableau[x-i][y]<=20)&&(tableau[x-i][y]>=17)){
                    true= true+1;
                }
                if ((tableau[x+i][y]%2==0)&&(tableau[x-i][y]<=20)&&(tableau[x-i][y]>=17)){
                    true= true+1;
                }
                if ((tableau[x][y+i]%2==0)&&(tableau[x][y+1]<=20)&&(tableau[x][y+1]>=17)){
                    true= true+1;
                }
                if ((tableau[x][y-i]%2==0)&&(tableau[x][y-1]<=20)&&(tableau[x][y-1]>=17)){
                    true= true+1;
                }
            }

            break;
        case 17:
            for (int i=1;i<=4;i++){
                if ((tableau[x-i][y]%2==0)&&(tableau[x-i][y]<=20)&&(tableau[x-i][y]>=17)){
                    true= true+1;
                }
                if ((tableau[x+i][y]%2==0)&&(tableau[x-i][y]<=20)&&(tableau[x-i][y]>=17)){
                    true= true+1;
                }
                if ((tableau[x][y+i]%2==0)&&(tableau[x][y+1]<=20)&&(tableau[x][y+1]>=17)){
                    true= true+1;
                }
                if ((tableau[x][y-i]%2==0)&&(tableau[x][y-1]<=20)&&(tableau[x][y-1]>=17)){
                    true= true+1;
                }
            }


            break;
        case 15:
            for (int i=1;i<=2;i++){
                if ((tableau[x-i][y]%2==0)&&(tableau[x-i][y]<=16)&&(tableau[x-i][y]>=13)){
                    true= true+1;
                }
                if ((tableau[x+i][y]%2==0)&&(tableau[x-i][y]<=16)&&(tableau[x-i][y]>=13)){
                    true= true+1;
                }
                if ((tableau[x][y+i]%2==0)&&(tableau[x][y+1]<=16)&&(tableau[x][y+1]>=13)){
                    true= true+1;
                }
                if ((tableau[x][y-i]%2==0)&&(tableau[x][y-1]<=16)&&(tableau[x][y-1]>=13)){
                    true= true+1;
                }
            }

            break;
        case 13:
            for (int i=1;i<=3;i++){
                if ((tableau[x-i][y]%2==0)&&(tableau[x-i][y]<=16)&&(tableau[x-i][y]>=13)){
                    true= true+1;
                }
                if ((tableau[x+i][y]%2==0)&&(tableau[x-i][y]<=16)&&(tableau[x-i][y]>=13)){
                    true= true+1;
                }
                if ((tableau[x][y+i]%2==0)&&(tableau[x][y+1]<=16)&&(tableau[x][y+1]>=13)){
                    true= true+1;
                }
                if ((tableau[x][y-i]%2==0)&&(tableau[x][y-1]<=16)&&(tableau[x][y-1]>=13)){
                    true= true+1;
                }
            }

            break;
        case 11:
            for (int i=1;i<=2;i++){
                if ((tableau[x-i][y]%2==0)&&(tableau[x-i][y]<=12)&&(tableau[x-i][y]>=9)){
                    true= true+1;
                }
                if ((tableau[x+i][y]%2==0)&&(tableau[x-i][y]<=12)&&(tableau[x-i][y]>=9)){
                    true= true+1;
                }
                if ((tableau[x][y+i]%2==0)&&(tableau[x][y+1]<=12)&&(tableau[x][y+1]>=9)){
                    true= true+1;
                }
                if ((tableau[x][y-i]%2==0)&&(tableau[x][y-1]<=12)&&(tableau[x][y-1]>=9)){
                    true= true+1;
                }
            }
            break;
        case 9:
            if(((tableau[x-1][y]==11)&&(tableau[x+1][y]==11))||((tableau[x][y-1]==11)&&(tableau[x][y+1]==11))){

            }else{
                true=1;
            }

            break;
        case 5:
            if((tableau[x-1][y]==5)||(tableau[x+1][y]==5)||(tableau[x][y-1]==5)||(tableau[x][y+1]==5)){

            }else{
                true=1;
            }
            break;
        case 3:


            break;
        default:
            true=1;
            break;

    }
    if (true==0) {
        strcat(historique," coule bravo");
    }

}

//cette fonction va parcourir le tableau en cherchant a savoir si tout les bateaux on été coulé le cas present elle retourne 1

int victoire(int tableau[10][10]){
    for (int i = 0; i<=9; i++) {
        for (int j=0;j<=9;j++){
            if(tableau[i][j]%2==0 && tableau[i][j]>0){
                return 0;

            }
        }

    }
    return 1;

}

//cette fonction la prendre les resultat sur le fichier resultats et les mettre dans tableau de struct joueur de 10

void Readscore(struct joueur score[10]) {

    //lire dans le ficher le nom et le score selon le format et l'ecire dans le tableau score

    FILE *fp;
    fp = fopen("resultats.txt", "r+");
    if(fp == NULL) {
        printf("Impossible d'ouvrir le fichier\n");
        exit(1);
    }
    fflush(stdin);
    for (int i=0;i<=9;i++){
        fscanf(fp,"%s %d",score[i].nom,&score[i].score);
    }

    fclose(fp);

}

// cette fonction va prendre le score du joueur et l'inserer la bonne place das le tableau
// des scores avant d'ecire dans ce tableau dans le fichier ressultat

void updatescore(struct joueur score[10], struct joueur player){

    //on voit d'ailleur directeement un appel a la fonctin Readscore pour prendre le valeur du tableau

    Readscore(score);
    FILE *fp;
    fp = fopen("resultats.txt", "w");
    if(fp == NULL) {
        printf("Impossible d'ouvrir le fichier\n");
        exit(1);
    }

    fflush(stdin);
    for(int i=0;i<=9;i++) {
        //ecrire dans le ficher le nom et le score [i] selon le format

        if (player.score >= score[i].score) {
            fprintf(fp, "%s %d\n", player.nom, player.score);
            player.score = -1;
            fprintf(fp, "%s %d\n", score[i].nom, score[i].score);



        }
        else{
            fprintf(fp, "%s %d\n", score[i].nom, score[i].score);
        }

    }
    fclose(fp);
    return;

}
