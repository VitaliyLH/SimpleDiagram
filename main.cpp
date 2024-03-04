#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QString fileName = argv[1];
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return EXIT_FAILURE;

    fileName.remove(".dat");

    w.loadData(file,fileName);

    w.close();

    return 0;
}
