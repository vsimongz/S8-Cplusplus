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
  
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
