#ifndef JEU_H
#define JEU_H
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>


#include <QObject>
using namespace std;

class jeu : public QObject
{
    Q_OBJECT
public:
    QQmlApplicationEngine engine;

    //mouvement vers le haut
    Q_INVOKABLE void moveUp();
    Q_INVOKABLE void sommeUp();

    //mouvement vers la droite
    Q_INVOKABLE void moveDroit();
    Q_INVOKABLE void sommeDroit();

    //mouvement vers la gauche
    Q_INVOKABLE void moveGauche();
    Q_INVOKABLE void sommeGauche();

    //mouvement vers le bas
    Q_INVOKABLE void moveDown();
    Q_INVOKABLE void sommeDown();

    Q_INVOKABLE void setRandom();//remplir une case vide de manière aléatoire

    Q_INVOKABLE void play(); //fonction pour le bouton play de l'écran de démarrage
    Q_INVOKABLE void changeVal(); //fonction pour changer la valeur initiale de l'écran de démarrage
    Q_INVOKABLE void changeSize(); //fonction pour changer la taille du jeude l'écran de démarrage

    Q_INVOKABLE void back(); //fonction pour le bouton venir en arrière
    Q_INVOKABLE void newJeu(); //fonction pour le bouton nouveau jeu

    void save(); //fonction qui sert a sauvegarder la matrice a chaque fois
    void show(); //fontion qui sert a afficher la matrice sur l'écran
    void show2(); //fontion qui sert a afficher la matrice sur l'écran mais pour le mode 5x5


    void Alloc(int l, int c, int d); //fonction qui sert à créér la matrice dynamiquement
    void Free(); // destructeur
    bool sameDimensions (const jeu &D);
    void Init(int value); //initialiser la matrice
    void Set(int x, int y,int z, int value); //Introduir une valeur dans la matrice

    explicit jeu(QObject *parent = 0);

    //fonctions nécessaires pour afficher les variables sur l'écran
    Q_INVOKABLE QList<QString> status(); //matrice
    Q_INVOKABLE QString status1(); // mode de jeu
    Q_INVOKABLE QList<QString> status2(); // matrice 5x5
    Q_INVOKABLE QList<QString> status3(); // les deux scores
    Q_INVOKABLE QString status4(); // Information qui apparaît en bas
    Q_PROPERTY(QList<QString> stat READ status NOTIFY cptChanged);
    Q_PROPERTY(QString stat1 READ status1 NOTIFY cptChanged1);
    Q_PROPERTY(QList<QString> stat2 READ status2 NOTIFY cptChanged2);
    Q_PROPERTY(QList<QString> stat3 READ status3 NOTIFY cptChanged);
    Q_PROPERTY(QString stat4 READ status4 NOTIFY cptChanged);

signals:
    //nécessaire pour le fonctionnement du Qt
    void cptChanged();
    void cptChanged1();
    void cptChanged2();
    void cptChanged3();

private:
    int L; //nombre de lignes
    int C; //nombre de colonnes
    int D; //nombre de fois que le jeu peut venir en arrière en appuiant sur "back".

    //pointeur de pointeur de pointeurs qui sert à créer une matrice de trois
    //dimension. Deux dimmensions pour la taille de la matrice et
    //la dernière pour le nombre de fois qu'on veut venir en arrière.
    int*** T;

    //variables à afficher sur l'écran
    QList<QString> st; //matrice 4x4
    QList<QString> st1; //matrice 5x5
    QString vall; // mode de jeu
    QList<QString> sco; //le deux scores
    QString info; //information suplémentaire

    bool up1; //drapeaux qui servent a savoir si le jeu est bloqué en haut
    bool up2;
    bool droit1;//drapeaux qui servent a savoir si le jeu est bloqué à droite
    bool droit2;
    bool gauche1;//drapeaux qui servent a savoir si le jeu est bloqué à gauche
    bool gauche2;
    bool down1;//drapeaux qui servent a savoir si le jeu est bloqué en bas
    bool down2;
    vector<int> score; //vecteur qui sert a sauvegarder les score à chaque tour afin de pouvoir venir en arrière
    int Bscore; // variable pour le meilleur score
};

#endif // JEU_H

