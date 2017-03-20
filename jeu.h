#ifndef JEU_H
#define JEU_H

#include <QObject>
using namespace std;

class jeu : public QObject
{
    Q_OBJECT
public:
public:
   // jeu(int l, int c, int vd=9);
   // jeu(const jeu &D);
   // ~jeu();

   // jeu operator=  (const jeu D); // opérateur d'affectation
   // jeu& operator+= (const jeu &D);
   // jeu& operator+= (int c);
   // jeu  operator+  (const jeu &D);
   // friend ostream& operator<< (ostream& sortie, jeu& V);

    Q_INVOKABLE void Print();
    Q_INVOKABLE void Init(int value);
    Q_INVOKABLE void Set(int x, int y, int value);
    Q_INVOKABLE void ReDim(int l, int c, int vd = -7);


    Q_INVOKABLE void moveUp();
    Q_INVOKABLE void moveDroit();
    Q_INVOKABLE void moveGauche();
    Q_INVOKABLE void moveDown();
    Q_INVOKABLE void sommeUp();
    Q_INVOKABLE void sommeDroit();
    Q_INVOKABLE void sommeGauche();
    Q_INVOKABLE void sommeDown();
    Q_INVOKABLE void setRandom();

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


    explicit jeu(QObject *parent = 0);
   // Q_INVOKABLE void increment();
    Q_INVOKABLE QList<QString> status();

    Q_PROPERTY(QList<QString> stat READ status NOTIFY cptChanged);

    //QString readCompteur();

signals:
    void cptChanged();

public slots:

private:
    int L;
    int C;
    int** T;
    QList<QString> st;

    // Méthode privée (factorisation  de code)
    void Alloc(int l, int c);
    void Free();
    bool sameDimensions (const jeu &D);
};

#endif // JEU_H
