#include "damierdyn.h"

DamierDyn::DamierDyn(int l, int c, int vd)
{
    Alloc(l, c);
    Init(vd);
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

DamierDyn::DamierDyn(const DamierDyn &D)
{
    Alloc(D.L, D.C);

    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            T[i][j] = D.T[i][j];
}


DamierDyn::~DamierDyn(){
    if (T != NULL) {
        Free();
        T = NULL;
    }
}

void DamierDyn::Free(){
    for (int i=0; i<L; i++) {
        delete [] T[i];
    }
    delete [] T;
}

void DamierDyn::Alloc(int l, int c){
    L = l;
    C = c;
    T = new int*[L];
    for(int i=0; i<L; i++)
        T[i] = new int[C];
}

void DamierDyn::Print(){
    cout << endl;
    for(int i=0; i<L; i++) {
        cout << endl;
        for(int j=0; j<C; j++)
            cout << T[i][j] << ", ";
    }
}

void DamierDyn::Init(int value){
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            T[i][j]=value;
}

void DamierDyn::Set(int x, int y, int value) {
    T[x][y]=value;
}


void DamierDyn::ReDim(int l, int c, int vd) {
    Free();
    Alloc(l, c);
    Init(vd);
}

DamierDyn DamierDyn::operator= (const DamierDyn D){
    if ( this != &D) { // protection autoréférence
        Free();
        Alloc(D.L, D.C);
        for(int i=0; i<L; i++)
            for(int j=0; j<C; j++)
                T[i][j] = D.T[i][j];
    }
    return *this;
}

bool DamierDyn::sameDimensions (const DamierDyn &D) {
    if ((L == D.L) && (C == D.C))
        return true;
    return false;
}

DamierDyn& DamierDyn::operator+= (int c)
{
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            T[i][j] += c;
    return *this;
}

DamierDyn& DamierDyn::operator+= (const DamierDyn &D)
{
    if (!sameDimensions(D)){
        cerr << endl << __PRETTY_FUNCTION__ << " - Dimensions différentes !\n";
        exit(1);
    }
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            T[i][j] += D.T[i][j];
    return *this;
}


DamierDyn DamierDyn::operator+ (const DamierDyn &D1)
{
    if (!sameDimensions(D1)){
        cerr << endl << __PRETTY_FUNCTION__ << " - Dimensions différentes !\n";
        exit(1);
    }

    DamierDyn D(D1.L, D1.C);
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            D.T[i][j] = T[i][j]+D1.T[i][j];

    return D;
}

DamierDyn& DamierDyn::moveUp (DamierDyn &D){

    int pos = 0;
    for(int i=1; i<L; i++){
        for(int j=0; j<C; j++){
            if(D.T[i][j]!=0 && D.T[i-1][j]==0){
                D.up1 = true;
                while(D.T[pos][j]!=0){
                    pos++;
                    }
                D.T[pos][j] = D.T[i][j];
                D.T[i][j] = 0;
                pos = 0;
            }
        }
    }
}

DamierDyn& DamierDyn::moveDroit (DamierDyn &D){
    int pos = 0;
    for(int i=0; i<L; i++){
        for(int j=0; j<C-1; j++){
            if(D.T[i][j]!=0 && D.T[i][j+1]==0){
                D.droit1 = true;
                while(D.T[i][C-pos-1]!=0){
                    pos++;
                    }
                D.T[i][C-pos-1] = D.T[i][j];
                //cout << "pos es " << pos;
                D.T[i][j] = 0;
                pos = 0;
            }
        }
    }
}

DamierDyn& DamierDyn::moveGauche (DamierDyn &D){
    int pos = 0;
    for(int i=0; i<L; i++){
        for(int j=1; j<C; j++){
            if(D.T[i][j]!=0 && D.T[i][j-1]==0){
                D.gauche1 = true;
                while(D.T[i][pos]!=0){
                    pos++;
                    }
                D.T[i][pos] = D.T[i][j];
                //cout << "pos es " << pos;
                D.T[i][j] = 0;
                pos = 0;
            }
        }
    }
}


DamierDyn& DamierDyn::moveDown (DamierDyn &D){
    int pos = 0;
    for(int i=0; i<L-1; i++){
        for(int j=0; j<C; j++){
            if(D.T[i][j]!=0 && D.T[i+1][j]==0){
                D.down1 = true;
                while(D.T[L-pos-1][j]!=0){
                    pos++;
                    }
                D.T[L-pos-1][j] = D.T[i][j];
                //cout << "pos es " << pos;
                D.T[i][j] = 0;
                pos = 0;
            }
        }
    }
}


DamierDyn& DamierDyn :: sommeUp(DamierDyn &D)
{

    for(int i=0; i<L-1; i++){
        for(int j=0; j<C; j++){
            if (D.T[i+1][j] == D.T[i][j] && D.T[i][j] != 0){
                D.T[i][j] *= 2;
                D.score += D.T[i][j];
                D.up2 = true;
                for(int k=i+1; k<L-1; k++){
                    D.T[k][j] = D.T[k+1][j];
                 }
                D.T[L-1][j] = 0;
            }
        }
    }
}

DamierDyn& DamierDyn :: sommeDroit(DamierDyn &D)
{

    for(int i=0; i<L; i++){
        for(int j=C-1; j>0; j--){
            if (D.T[i][j-1] == D.T[i][j] && D.T[i][j] != 0){
                D.T[i][j] *= 2;
                D.score += D.T[i][j];
                D.droit2 = true;
                for(int k=j-1; k>0; k--){
                    D.T[i][k] = D.T[i][k-1];
                 }
                D.T[i][0] = 0;
            }
        }
    }
}


DamierDyn& DamierDyn :: sommeGauche(DamierDyn &D)
{

    for(int i=0; i<L; i++){
        for(int j=0; j<C-1; j++){
            if (D.T[i][j+1] == D.T[i][j] && D.T[i][j] != 0){
                D.T[i][j] *= 2;
                D.score += D.T[i][j];
                D.gauche2= true;
                for(int k=j+1; k<C-1; k++){
                    D.T[i][k] = D.T[i][k+1];
                 }
                D.T[i][C-1] = 0;
            }
        }
    }
}

DamierDyn& DamierDyn :: sommeDown(DamierDyn &D)
{

    for(int i=L-1; i>0; i--){
        for(int j=0; j<C; j++){
            if (D.T[i-1][j] == D.T[i][j] && D.T[i][j] != 0){
                D.T[i][j] *= 2;
                D.down2 = true;
                D.score += D.T[i][j];
                for(int k=i-1; k>0; k--){
                    D.T[k][j] = D.T[k-1][j];
                 }
                D.T[0][j] = 0;
            }
        }
    }
}

DamierDyn& DamierDyn:: setRandom (DamierDyn &D){
    int flag = 1;
    while(flag)
            {
                int i=rand()%4;
                int j=rand()%4;
                if(D.T[i][j]==0)
                {
                    D.T[i][j]=2;
                    flag=0;
                }
            }
    }

void DamierDyn::PrintScore(){
    cout << endl;
      cout << "Le score est" << score << ", ";

}



ostream& operator<< (ostream& sortie, DamierDyn& V)
{
    sortie << endl;
    for(int i=0; i<V.L; i++) {
        sortie << endl;
        for(int j=0; j<V.C; j++)
            sortie << V.T[i][j] << ", ";
    }

    return sortie;
}
