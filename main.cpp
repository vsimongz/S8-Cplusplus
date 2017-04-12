#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "jeu.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    jeu monJeu;//creation de la classe

    monJeu.engine.rootContext()->setContextProperty("vueObjetCpt", &monJeu);//conexion avec QML

    monJeu.engine.load(QUrl(QStringLiteral("qrc:/Ma.qml"))); //Fenêtre de démarrage

    return app.exec();
}
