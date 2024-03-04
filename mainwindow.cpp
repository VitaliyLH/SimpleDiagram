#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_diagramm(new  SquareDiagramm(parent))
{
    ui->setupUi(this);
    ui->latticeLayout->addWidget(m_diagramm);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть", "../");
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    m_diagramm->loadFromFile(file,fileName);
    m_diagramm->repaint();
}


void MainWindow::loadData(QFile& file,QString fileName)
{
//    QFile file(fileName);
//    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
//            return;
    m_diagramm->loadFromFile(file,fileName);
    m_diagramm->saveImage(fileName+".jpg");
    m_diagramm->repaint();
}
