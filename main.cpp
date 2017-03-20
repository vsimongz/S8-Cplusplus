#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "jeu.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    jeu monJeu;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("vueObjetCpt", &monJeu);
    //engine.rootContext()->setContextProperty("vueObjetCpt1", &unCompteur);
    //engine.rootContext()->setContextProperty("vueObjetCpt2", &unCompteur);


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
