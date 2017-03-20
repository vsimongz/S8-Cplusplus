#include "jeu.h"
#include <iostream>


jeu::jeu(QObject *parent) : QObject(parent)
{

    cptChanged();
    for (int i=0;i<16;i++){
        st.append("0");
    }
    st[10] = "2";
    Alloc(4, 4);
        Init(0);
        Set(2,2,2);
        up1 = false;
        up2 = false;
        droit1 = false;
        droit2 = false;
        gauche1 = false;
        gauche2 = false;
        down1 = false;
        down2 = false;
        score = 0;
}

void jeu::moveUp(){
    int ind = 0;
    int pos = 0;
    for(int i=1; i<L; i++){
        for(int j=0; j<C; j++){
            if(T[i][j]!=0 && T[i-1][j]==0){
                up1 = true;
                while(T[pos][j]!=0){
                    pos++;
                    }
                T[pos][j] = T[i][j];
                T[i][j] = 0;
                pos = 0;
            }
        }
    }
}

void jeu::moveDroit(){
    int pos = 0;
    for(int i=0; i<L; i++){
        for(int j=0; j<C-1; j++){
            if(T[i][j]!=0 && T[i][j+1]==0){
                droit1 = true;
                while(T[i][C-pos-1]!=0){
                    pos++;
                    }
                T[i][C-pos-1] = T[i][j];
                //cout << "pos es " << pos;
                T[i][j] = 0;
                pos = 0;
            }
        }
    }
}

void jeu::moveDown(){
    int pos = 0;
    for(int i=0; i<L-1; i++){
        for(int j=0; j<C; j++){
            if(T[i][j]!=0 && T[i+1][j]==0){
                down1 = true;
                while(T[L-pos-1][j]!=0){
                    pos++;
                    }
                T[L-pos-1][j] = T[i][j];
                //cout << "pos es " << pos;
                T[i][j] = 0;
                pos = 0;
            }
        }
    }
}

void jeu::moveGauche(){
    int pos = 0;
    for(int i=0; i<L; i++){
        for(int j=1; j<C; j++){
            if(T[i][j]!=0 && T[i][j-1]==0){
                gauche1 = true;
                while(T[i][pos]!=0){
                    pos++;
                    }
                T[i][pos] = T[i][j];
                //cout << "pos es " << pos;
                T[i][j] = 0;
                pos = 0;
            }
        }
    }
}



void jeu::sommeUp(){
    //T[0][0]  = 10;
    //st[0] = QString::number(T[0][0]);
    int ind = 0;
    for(int i=0; i<L-1; i++){
        for(int j=0; j<C; j++){

            if (T[i+1][j] == T[i][j] && T[i][j] != 0){
                T[i][j] *= 2;
                score += T[i][j];
                up2 = true;
                for(int k=i+1; k<L-1; k++){
                    T[k][j] = T[k+1][j];
                 }
                T[L-1][j] = 0;
            }
        }
    }

    if (up1==true||up2==true){
         setRandom();
       //  D3 = D2;
       up1 = false;
       up2 = false;
     }
    st[0] = QString::number(T[0][0]);
    st[1] = QString::number(T[0][1]);
    st[2] = QString::number(T[0][2]);
    st[3] = QString::number(T[0][3]);
    st[4] = QString::number(T[1][0]);
    st[5] = QString::number(T[1][1]);
    st[6] = QString::number(T[1][2]);
    st[7] = QString::number(T[1][3]);
    st[8] = QString::number(T[2][0]);
    st[9] = QString::number(T[2][1]);
    st[10] = QString::number(T[2][2]);
    st[11] = QString::number(T[2][3]);
    st[12] = QString::number(T[3][0]);
    st[13] = QString::number(T[3][1]);
    st[14] = QString::number(T[3][2]);
    st[15] = QString::number(T[3][3]);
    emit cptChanged();
}

void jeu::sommeDroit(){
      for(int i=0; i<L; i++){
        for(int j=C-1; j>0; j--){
            if (T[i][j-1] == T[i][j] && T[i][j] != 0){
                T[i][j] *= 2;
                score += T[i][j];
                droit2 = true;
                for(int k=j-1; k>0; k--){
                    T[i][k] = T[i][k-1];
                 }
                T[i][0] = 0;
            }
        }
    }
      if (droit1==true||droit2==true){
           setRandom();
         //  D3 = D2;
         droit1 = false;
         droit2 = false;
       }
      st[0] = QString::number(T[0][0]);
      st[1] = QString::number(T[0][1]);
      st[2] = QString::number(T[0][2]);
      st[3] = QString::number(T[0][3]);
      st[4] = QString::number(T[1][0]);
      st[5] = QString::number(T[1][1]);
      st[6] = QString::number(T[1][2]);
      st[7] = QString::number(T[1][3]);
      st[8] = QString::number(T[2][0]);
      st[9] = QString::number(T[2][1]);
      st[10] = QString::number(T[2][2]);
      st[11] = QString::number(T[2][3]);
      st[12] = QString::number(T[3][0]);
      st[13] = QString::number(T[3][1]);
      st[14] = QString::number(T[3][2]);
      st[15] = QString::number(T[3][3]);
      emit cptChanged();
}
void jeu::sommeDown(){
    for(int i=L-1; i>0; i--){
        for(int j=0; j<C; j++){
            if (T[i-1][j] == T[i][j] && T[i][j] != 0){
                T[i][j] *= 2;
                down2 = true;
                score += T[i][j];
                for(int k=i-1; k>0; k--){
                    T[k][j] = T[k-1][j];
                 }
                T[0][j] = 0;
            }
        }
    }
      if (down1==true||down2==true){
           setRandom();
         //  D3 = D2;
         down1 = false;
         down2 = false;
       }
      st[0] = QString::number(T[0][0]);
      st[1] = QString::number(T[0][1]);
      st[2] = QString::number(T[0][2]);
      st[3] = QString::number(T[0][3]);
      st[4] = QString::number(T[1][0]);
      st[5] = QString::number(T[1][1]);
      st[6] = QString::number(T[1][2]);
      st[7] = QString::number(T[1][3]);
      st[8] = QString::number(T[2][0]);
      st[9] = QString::number(T[2][1]);
      st[10] = QString::number(T[2][2]);
      st[11] = QString::number(T[2][3]);
      st[12] = QString::number(T[3][0]);
      st[13] = QString::number(T[3][1]);
      st[14] = QString::number(T[3][2]);
      st[15] = QString::number(T[3][3]);
      emit cptChanged();
}


void jeu::sommeGauche(){
    for(int i=0; i<L; i++){
        for(int j=0; j<C-1; j++){
            if (T[i][j+1] == T[i][j] && T[i][j] != 0){
                T[i][j] *= 2;
                score += T[i][j];
                gauche2= true;
                for(int k=j+1; k<C-1; k++){
                    T[i][k] = T[i][k+1];
                 }
                T[i][C-1] = 0;
            }
        }
    }
      if (gauche1==true||gauche2==true){
           setRandom();
         //  D3 = D2;
         gauche1 = false;
         gauche2 = false;
       }
      st[0] = QString::number(T[0][0]);
      st[1] = QString::number(T[0][1]);
      st[2] = QString::number(T[0][2]);
      st[3] = QString::number(T[0][3]);
      st[4] = QString::number(T[1][0]);
      st[5] = QString::number(T[1][1]);
      st[6] = QString::number(T[1][2]);
      st[7] = QString::number(T[1][3]);
      st[8] = QString::number(T[2][0]);
      st[9] = QString::number(T[2][1]);
      st[10] = QString::number(T[2][2]);
      st[11] = QString::number(T[2][3]);
      st[12] = QString::number(T[3][0]);
      st[13] = QString::number(T[3][1]);
      st[14] = QString::number(T[3][2]);
      st[15] = QString::number(T[3][3]);
      emit cptChanged();
}

void jeu::setRandom(){
    int flag = 1;
    while(flag)
            {
                int i=rand()%4;
                int j=rand()%4;
                if(T[i][j]==0)
                {
                    T[i][j]=2;
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
void jeu::Alloc(int l, int c){
    L = l;
    C = c;
    T = new int*[L];
    for(int i=0; i<L; i++)
        T[i] = new int[C];
}



void jeu::Print(){
    //cout << endl;
    for(int i=0; i<L; i++) {
      //  cout << endl;
        for(int j=0; j<C; j++){
      //      cout << T[i][j] << ", ";
    }
    }
}


void jeu::Init(int value){
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            T[i][j]=value;
}

void jeu::Set(int x, int y, int value) {
    T[x][y]=value;
}


void jeu::ReDim(int l, int c, int vd) {
   // Free();
    Alloc(l, c);
    Init(vd);
}
