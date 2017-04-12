#include "jeu.h"
#include <iostream>
#include <string>
#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

using namespace std;
int val = 2; //valeur initial d'une case de la matrice
int size = 4; //taille de la matrice
int nbBack = 20;
int cont = 0; //variable qui sert a voir si le jeu est fini (bloqué)
bool bloq = false; //variable qui sert a voir si le jeu est fini (bloqué)


jeu::jeu(QObject *parent) : QObject(parent) //CONSTRUCTEUR
{
    //inisialisation de le score/////
    D=nbBack;
    for(int i = 0; i<D; i++){
        score.push_back(0);
    }
    for (int i=0;i<2;i++){//inisialisation pour Qt
        sco.append("0");
    }
    Bscore = 0;
    //////////////////////////////////

    //inisialisation de la phrase d'information et du valeur du mode et
    info = "";   
    vall = QString::number(val);
    //////////////////////////////////

    //inisialisation des variables pour les matrices en QT (QML)/////////////////
    for (int i=0;i<16;i++){
        st.append("0");
    }
    for (int i=0;i<25;i++){
        st1.append("0");
    }
    st1[10] = vall;
    st[10] = vall;
    ///////////////////////////////////

    //Instantiation et inisialisation de la matrice de trois dimmensions
    Alloc(size, size, D);
    Init(0);
    ///////////////////////////////////
}


void jeu::Alloc(int l, int c, int d){ //CREATION DE LA MATRICE DE TROIS DIMMENSIONS DYNAMIQUEMENT
    L = l;
    C = c;
    D = d;
    T = new int**[L];
    for(int i=0; i<L; i++){
        T[i] = new int*[C];
        for(int j=0; j<C; j++){
            T[i][j] = new int[D];
        }
    }
}

void jeu::Init(int value){ // INISIALISATION DE TOUS LES CASES A ZERO SAUF UNE A 2
    for(int i=0; i<D; i++){score[i]=0;}
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
          for(int k=0; k<D; k++)
            T[i][j][k]=value;
    Set(2,2,0,val);//inisialisation a 2
}

void jeu::Set(int x, int y, int z, int value) { //DONNER  UNE VALEUR CONCRÈTE À UNE CASE DE LA MATRICE CONTRÈTE
    T[x][y][z]=value;
}


//ALGORITHME POUR FAIRE ROULER LE JEU ///////////////////////////////////
//Au début on bouge tous le numéro vers le haut, gauche etc... et après on fait la somme si deux cases à côté une de l'autre sont égales

//partie bouger en haut///////////////
void jeu::moveUp(){
    save();
    int pos = 0;
    for(int i=1; i<L; i++){
        for(int j=0; j<C; j++){
            if(T[i][j][0]!=0 && T[i-1][j][0]==0){
                up1 = true;
                while(T[pos][j][0]!=0){
                    pos++;
                    }
                T[pos][j][0] = T[i][j][0];
                T[i][j][0] = 0;
                pos = 0;
            }
        }
    }
}
//partie bouger à droite///////////////
void jeu::moveDroit(){
    save();
    int pos = 0;
    for(int i=0; i<L; i++){
        for(int j=0; j<C-1; j++){
            if(T[i][j][0]!=0 && T[i][j+1][0]==0){
                droit1 = true;
                while(T[i][C-pos-1][0]!=0){
                    pos++;
                    }
                T[i][C-pos-1][0] = T[i][j][0];
                T[i][j][0] = 0;
                pos = 0;
            }
        }
    }
}
//partie bouger en bas///////////////
void jeu::moveDown(){
    save();
    int pos = 0;
    for(int i=0; i<L-1; i++){
        for(int j=0; j<C; j++){
            if(T[i][j][0]!=0 && T[i+1][j][0]==0){
                down1 = true;
                while(T[L-pos-1][j][0]!=0){
                    pos++;
                    }
                T[L-pos-1][j][0] = T[i][j][0];
                T[i][j][0] = 0;
                pos = 0;
            }
        }
    }
}
//partie bouger à gauche///////////////
void jeu::moveGauche(){
    save();
    int pos = 0;
    for(int i=0; i<L; i++){
        for(int j=1; j<C; j++){
            if(T[i][j][0]!=0 && T[i][j-1][0]==0){
                gauche1 = true;
                while(T[i][pos][0]!=0){
                    pos++;
                    }
                T[i][pos][0] = T[i][j][0];
                T[i][j][0] = 0;
                pos = 0;
            }
        }
    }
}
//partie somme en haut///////////////
void jeu::sommeUp(){
    for(int i=0; i<L-1; i++){
        for(int j=0; j<C; j++){

            if (T[i+1][j][0] == T[i][j][0] && T[i][j][0] != 0){
                T[i][j][0] *= 2;
                score[0] += T[i][j][0];
                up2 = true;
                for(int k=i+1; k<L-1; k++){
                    T[k][j][0] = T[k+1][j][0];
                 }
                T[L-1][j][0] = 0;
            }
        }
    }
    if (up1==true||up2==true){//si ce n'est pas bloqué on introduit une nouveau numéro
       setRandom();//introduire le numéro random
       up1 = false;
       up2 = false;
     }
    else {bloq = true; if (cont<4){ info="Jeu bloqué en haut";cont++;}} //si c'est bloqué on le dit avec l'info
    if (size == 4) show(); //afficher matrix 4x4
    else show2();//afficher matrix 5x5
}

//partie somme à droite///////////////
void jeu::sommeDroit(){
      for(int i=0; i<L; i++){
        for(int j=C-1; j>0; j--){
            if (T[i][j-1][0] == T[i][j][0] && T[i][j][0] != 0){
                T[i][j][0] *= 2;
                score[0] += T[i][j][0];
                droit2 = true;
                for(int k=j-1; k>0; k--){
                    T[i][k][0] = T[i][k-1][0];
                 }
                T[i][0][0] = 0;
            }
        }
    }
      if (droit1==true||droit2==true){//si ce n'est pas bloqué on introduit une nouveau numéro
           setRandom();
         droit1 = false;
         droit2 = false;
       }
      else {bloq = true; if (cont<4){ info="Jeu bloqué à droit";cont++;}}//si c'est bloqué on le dit avec l'info
      if (size == 4) show(); //afficher matrix 4x4
      else show2();//afficher matrix 5x5
}

//partie somme en bas///////////////
void jeu::sommeDown(){
    for(int i=L-1; i>0; i--){
        for(int j=0; j<C; j++){
            if (T[i-1][j][0] == T[i][j][0] && T[i][j][0] != 0){
                T[i][j][0] *= 2;
                down2 = true;
                score[0] += T[i][j][0];
                for(int k=i-1; k>0; k--){
                    T[k][j][0] = T[k-1][j][0];
                 }
                T[0][j][0] = 0;
            }
        }
    }
      if (down1==true||down2==true){//si ce n'est pas bloqué on introduit une nouveau numéro
           setRandom();
         down1 = false;
         down2 = false;
       }
      else {bloq = true; if (cont<4){ info="Jeu bloqué en bas"; cont++;}}//si c'est bloqué on le dit avec l'info
      if (size == 4) show(); //afficher matrix 4x4
      else show2();//afficher matrix 5x5
}

//partie somme à droite///////////////
void jeu::sommeGauche(){

    for(int i=0; i<L; i++){
        for(int j=0; j<C-1; j++){
            if (T[i][j+1][0] == T[i][j][0] && T[i][j][0] != 0){
                T[i][j][0] *= 2;
                score[0] += T[i][j][0];
                gauche2= true;
                for(int k=j+1; k<C-1; k++){
                    T[i][k][0] = T[i][k+1][0];
                 }
                T[i][C-1][0] = 0;
            }
        }
    }
      if (gauche1==true||gauche2==true){//si ce n'est pas bloqué on introduit une nouveau numéro
           setRandom();
         gauche1 = false;
         gauche2 = false;

       }
      else {bloq = true;  if (cont<4){info="Jeu bloqué à gauche";cont++;}}//si c'est bloqué on le dit avec l'info
      if (size == 4) show(); //afficher matrix 4x4
      else show2();//afficher matrix 5x5
}
////////////////////////////////////////////////////

void jeu::setRandom(){
    cont = 0; //jeu pas bloqué
    info="";//pas d'info nécessaire
    int flag = 1;
    while(flag) //boucle pour trouver la case libre
            {
                int i=rand()%size;
                int j=rand()%size;
                int a=rand()%10;

                if(T[i][j][0]==0 && a<6)//60% de possiblités de que ce soit un 2
                {
                    T[i][j][0]=val;
                    flag=0;
                }
                if(T[i][j][0]==0 && a>6)//40% de possibilités de que ce soir 4
                {
                    T[i][j][0]=val*2;
                    flag=0;
                }
            }
    }

//fonctions pour retourner l'information au QML
QList<QString> jeu::status(){
    return st;
}
QString jeu::status1(){
    return vall;
}
QList<QString> jeu::status2(){
    return st1;
}
QList<QString> jeu::status3(){
    return sco;
}
QString jeu::status4(){
    return info;
}

void jeu::save(){ //SAUVEGARDER LA MATRICE DANS LA DERNIERE DIMMENSION

        if (bloq == false){//seulement si le jeu n'est pas bloqué
            for(int a=D-2;a>=0;a--){ //sauvegarder aussi le score
                score[a+1]=score[a];
            }
            for(int c=D-2; c>=0; c--){
                for (int i=0; i<L; i++){
                    for (int j=0; j<C; j++){
                       T[i][j][c+1]=T[i][j][c];
                    }
                }
            }
         }
}

void jeu::changeSize(){ //FONCTION QUI CHANGE AU MODE 5X5 EN APPUIANT SUR LE BOUTON 5X5
    size = 5; //on change le size
    Alloc(size,size,D); //on refait la matrice
    engine.load(QUrl(QStringLiteral("qrc:/Main1.qml"))); //on démarre une nouvelle fenetre avec une autre QML
    newJeu();//on reinisialise
}

void jeu::changeVal(){//FONCTION QUI CHANGE LE NUMERO LEQUEL LE JEU COMMENCE
    val++;
    if (val == 9) val = 2; //on a jusqu'à 8
    vall = QString::number(val);
    cptChanged1();
    newJeu();//on reinisialise
}

void jeu::newJeu(){ //reinisialiser
    Init(0);
    if (size == 4) show(); //afficher 4x4
    else show2(); //afficher 5x5
}

void jeu::back(){ //FONCTION QUI SERT A AFFICHER LA MATRICE SAUVEGARDÉ DANS LES TOURS D'AVANT
        score[0]=score[1]; //changer aussi le score
        for(int k = 0; k<D-1; k++){
            for (int i=0; i<L; i++){
                for (int j=0; j<C; j++){
                     T[i][j][k]=T[i][j][k+1];
                }
            }
        }
    info = "Jeu débloqué"; //dire que le jeu est débloqué
    bloq = false; //pas bloqué
    if (size == 4) show(); //afficher 4x4
    else show2(); //afficher 5x5
}

void jeu::play(){ //OUVRIR UNE NOUVELLE FENETRE LORSQU'ON CLIQUE SUR PLAY
    size = 4;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));//démarrer une nouvelle fenêtre
}

void jeu::show(){ //AFFICHAGE SUR L'ECRAN 4x4
    if(score[0]>Bscore){ sco[1] = QString::number(score[0]); Bscore = score[0];} //Changer le meilleur score
    sco[0] = QString::number(score[0]);
    st[0] = QString::number(T[0][0][0]);
    st[1] = QString::number(T[0][1][0]);
    st[2] = QString::number(T[0][2][0]);
    st[3] = QString::number(T[0][3][0]);
    st[4] = QString::number(T[1][0][0]);
    st[5] = QString::number(T[1][1][0]);
    st[6] = QString::number(T[1][2][0]);
    st[7] = QString::number(T[1][3][0]);
    st[8] = QString::number(T[2][0][0]);
    st[9] = QString::number(T[2][1][0]);
    st[10] = QString::number(T[2][2][0]);
    st[11] = QString::number(T[2][3][0]);
    st[12] = QString::number(T[3][0][0]);
    st[13] = QString::number(T[3][1][0]);
    st[14] = QString::number(T[3][2][0]);
    st[15] = QString::number(T[3][3][0]);
    if (cont == 4) info="GAME OVER, Clique Again";

     emit cptChanged();
}
void jeu::show2(){ //AFFICHAGE SUR L'ECRAN 5x5
    st1[0] = QString::number(T[0][0][0]);
    st1[1] = QString::number(T[0][1][0]);
    st1[2] = QString::number(T[0][2][0]);
    st1[3] = QString::number(T[0][3][0]);
    st1[4] = QString::number(T[1][0][0]);
    st1[5] = QString::number(T[1][1][0]);
    st1[6] = QString::number(T[1][2][0]);
    st1[7] = QString::number(T[1][3][0]);
    st1[8] = QString::number(T[2][0][0]);
    st1[9] = QString::number(T[2][1][0]);
    st1[10] = QString::number(T[2][2][0]);
    st1[11] = QString::number(T[2][3][0]);
    st1[12] = QString::number(T[3][0][0]);
    st1[13] = QString::number(T[3][1][0]);
    st1[14] = QString::number(T[3][2][0]);
    st1[15] = QString::number(T[3][3][0]);
    st1[16] = QString::number(T[0][4][0]);
    st1[17] = QString::number(T[1][4][0]);
    st1[18] = QString::number(T[2][4][0]);
    st1[19] = QString::number(T[3][4][0]);
    st1[20] = QString::number(T[4][0][0]);
    st1[21] = QString::number(T[4][1][0]);
    st1[22] = QString::number(T[4][2][0]);
    st1[23] = QString::number(T[4][3][0]);
    st1[24] = QString::number(T[4][4][0]);
     emit cptChanged2();
}






