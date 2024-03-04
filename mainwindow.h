#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "squarediagram.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void loadData(QFile &file,QString fileName);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    SquareDiagramm* m_diagramm;
};

#endif // MAINWINDOW_H
