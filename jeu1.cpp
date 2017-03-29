#include "jeu.h"
#include <iostream>
#include <QDebug>
using namespace std;
int change = 1;

jeu::jeu(QObject *parent) : QObject(parent)
{

    cptChanged();
    for (int i=0;i<16;i++){
        st.append("0");
    }
    st[10] = "2";
    gauche1 = false;
    gauche2 = false;
    down1 = false;
    Alloc(4, 4, 7);
        Init(0);
        Set(2,2,0,2);
        up1 = false;
        up2 = false;
        droit1 = false;
        droit2 = false;
        down2 = false;
        score = 0;
}

void jeu::moveUp(){
    save();
    int ind = 0;
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
                //cout << "pos es " << pos;
                T[i][j][0] = 0;
                pos = 0;
            }
        }
    }
}

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
                //cout << "pos es " << pos;
                T[i][j][0] = 0;
                pos = 0;
            }
        }
    }
}

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
                //cout << "pos es " << pos;
                T[i][j][0] = 0;
                pos = 0;
            }
        }
    }
}


bool bloq = false;

void jeu::sommeUp(){
    int ind = 0;
    for(int i=0; i<L-1; i++){
        for(int j=0; j<C; j++){

            if (T[i+1][j][0] == T[i][j][0] && T[i][j][0] != 0){
                T[i][j][0] *= 2;
                score += T[i][j][0];
                up2 = true;
                for(int k=i+1; k<L-1; k++){
                    T[k][j][0] = T[k+1][j][0];
                 }
                T[L-1][j][0] = 0;
            }
        }
    }

    if (up1==true||up2==true){
         setRandom();
       //  D3 = D2;
       up1 = false;
       up2 = false;
       //save();
     }
    else bloq = true;
    show();
}

void jeu::sommeDroit(){
      for(int i=0; i<L; i++){
        for(int j=C-1; j>0; j--){
            if (T[i][j-1][0] == T[i][j][0] && T[i][j][0] != 0){
                T[i][j][0] *= 2;
                score += T[i][j][0];
                droit2 = true;
                for(int k=j-1; k>0; k--){
                    T[i][k][0] = T[i][k-1][0];
                 }
                T[i][0][0] = 0;
            }
        }
    }
      if (droit1==true||droit2==true){
           setRandom();
         //  D3 = D2;
         droit1 = false;
         droit2 = false;
         //save();
       }
      else bloq = true;
        show();
}
void jeu::sommeDown(){
    for(int i=L-1; i>0; i--){
        for(int j=0; j<C; j++){
            if (T[i-1][j][0] == T[i][j][0] && T[i][j][0] != 0){
                T[i][j][0] *= 2;
                down2 = true;
                score += T[i][j][0];
                for(int k=i-1; k>0; k--){
                    T[k][j][0] = T[k-1][j][0];
                 }
                T[0][j][0] = 0;
            }
        }
    }
      if (down1==true||down2==true){
           setRandom();
         //  D3 = D2;
         down1 = false;
         down2 = false;
         //save();
       }
      else bloq = true;
      show();
}


void jeu::sommeGauche(){

    for(int i=0; i<L; i++){
        for(int j=0; j<C-1; j++){
            if (T[i][j+1][0] == T[i][j][0] && T[i][j][0] != 0){
                T[i][j][0] *= 2;
                score += T[i][j][0];
                gauche2= true;
                for(int k=j+1; k<C-1; k++){
                    T[i][k][0] = T[i][k+1][0];
                 }
                T[i][C-1][0] = 0;
            }
        }
    }
      if (gauche1==true||gauche2==true){
           setRandom();
         //  D3 = D2;
         gauche1 = false;
         gauche2 = false;
         //save();
       }
      else bloq = true;
      show();
}

void jeu::setRandom(){

    int flag = 1;
    while(flag)
            {
                int i=rand()%4;
                int j=rand()%4;
                if(T[i][j][0]==0)
                {
                    T[i][j][0]=2;
                    flag=0;
                }
            }
    }


QList<QString> jeu::status(){
    return st;
}

/*

jeu::~jeu(){
    if (T != NULL) {
        Free();
        T = NULL;
    }
}*/
void jeu::Alloc(int l, int c, int d){
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



void jeu::Print(){
    //cout << endl;
    for(int i=0; i<L; i++) {
      //  cout << endl;
        for(int j=0; j<C; j++){
      //      cout << T[i][j][0] << ", ";
    }
    }
}


void jeu::Init(int value){
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
          for(int k=0; k<D; k++)
            if (i==2 && j==2 && k==0){
                T[i][j][k]=2;
            }
            else T[i][j][k]=value;
}

void jeu::save(){
        change = 1;
        if (bloq == false){
            for(int c=D-2; c>=0; c--){
                for (int i=0; i<L; i++){
                    for (int j=0; j<C; j++){
                       T[i][j][c+1]=T[i][j][c];
                    }
                }
            }
         }
}


void jeu::back(){
     if (change < D){
        for (int i=0; i<L; i++){
            for (int j=0; j<C; j++){
                 T[i][j][0]=T[i][j][change];
            }
        }
        change++;
    }
    bloq = false;
     show();
}

/*
void jeu::imprimer(){
    qDebug() <<"fase"<< cont << ", ";
    qDebug() << "Matrix 0";
    for(int i=0; i<L; i++) {
        qDebug() << endl;
        for(int j=0; j<C; j++)
            qDebug() << T[i][j][1] << ", ";
    }
    qDebug() << "Matrix 1";
    for(int i=0; i<L; i++) {
        qDebug() << endl;
        for(int j=0; j<C; j++)
            qDebug() << T[i][j][2] << ", ";
    }

    if (cont == 2) cont = 0;
}*/


void jeu::show(){
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
    emit cptChanged();
}


void jeu::Set(int x, int y, int z, int value) {
    T[x][y][z]=value;
}


void jeu::ReDim(int l, int c, int vd) {
   // Free();
    Alloc(l, c, 0);
    Init(vd);
}

 
