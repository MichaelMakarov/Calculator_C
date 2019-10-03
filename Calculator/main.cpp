#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen * splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/resources/Witch_King.png"));
    splash->show();
    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
    splash->showMessage(QObject::tr("Setting up the aplication..."), topRight, Qt::white);
    QThread::sleep(1);
    MainWindow w;
    splash->showMessage(QObject::tr("Loading..."), topRight, Qt::white);
    QThread::sleep(1);
    w.show();
    splash->finish(&w);
    delete splash;

    return a.exec();
}
