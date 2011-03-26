#include <QtGui/QApplication>
#include "mainwindow.h"
#include "mainwindow2.h"
#include <QLabel>
#include <QListWidgetItem>
#include <QProcess>
#include <iostream>
#include "dialog.h"
#include "ui_dialog.h"


using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    MainWindow2 w2;
    //w2.show();
    return a.exec();
}
