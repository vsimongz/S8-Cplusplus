#ifndef DAMIERDYN_H
#define DAMIERDYN_H

#include <iostream>
using namespace std;

class DamierDyn
{
public:
    DamierDyn(int l, int c, int vd=9);
    DamierDyn(const DamierDyn &D);
    ~DamierDyn();

    DamierDyn operator=  (const DamierDyn D); // opérateur d'affectation
    DamierDyn& operator+= (const DamierDyn &D);
    DamierDyn& operator+= (int c);
    DamierDyn  operator+  (const DamierDyn &D);
    friend ostream& operator<< (ostream& sortie, DamierDyn& V);

    void Print();
    void Init(int value);
    void Set(int x, int y, int value);
    void ReDim(int l, int c, int vd = -7);

    DamierDyn& moveUp(DamierDyn &D);
    DamierDyn& moveDroit(DamierDyn &D);
    DamierDyn& moveGauche(DamierDyn &D);
    DamierDyn& moveDown(DamierDyn &D);
    DamierDyn& sommeUp(DamierDyn &D);
    DamierDyn& sommeDroit(DamierDyn &D);
    DamierDyn& sommeGauche(DamierDyn &D);
    DamierDyn& sommeDown(DamierDyn &D);
    DamierDyn& setRandom(DamierDyn &D);

    bool up1;
    bool up2;
    bool droit1;
    bool droit2;
    bool gauche1;
    bool gauche2;
    bool down1;
    bool down2;
    int score;
    void PrintScore();
private:
    int L;
    int C;
    int** T;

    // Méthode privée (factorisation  de code)
    void Alloc(int l, int c);
    void Free();
    bool sameDimensions (const DamierDyn &D);
};

#endif // DAMIERDYN_H
