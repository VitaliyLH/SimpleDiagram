#include "squarediagram.h"
#include "ui_squarediagram.h"
#include <QPainter>
#include <math.h>

SquareDiagramm::SquareDiagramm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SquareDiagramm)
{
    ui->setupUi(this);
    m_data = new QList<LatticePoint>();
}

void SquareDiagramm::setLatticeSize(unsigned int latticeSize)
{
    this->m_latticeSize=latticeSize;
}

void SquareDiagramm::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    paint(painter);
}

void SquareDiagramm::paint(QPainter &painter)
{
    m_boxSize=qMin(512,512);
    QRect BigRect(0, 0, m_boxSize-1, m_boxSize-1);
    painter.fillRect(BigRect,QBrush(QColor(255,255,255),Qt::SolidPattern));


    for (int i = 0; i < m_data->size()-1; i++)
    {
        LatticePoint point=m_data->at(i);
        int padding = 0;
        double step = (m_boxSize-padding*2+5)/(m_latticeSize);
        double x=point.i*step;
        double y=point.j*step;
        painter.setBrush(QBrush(calculateColor(point.value), Qt::SolidPattern));
        //QRect rect(x,y,step,step);
        painter.drawRect(x,y,step,step);
        //painter.fillRect(rect,QBrush(calculateColor(point.value), Qt::SolidPattern));
    }
}

void SquareDiagramm::saveImage(QString fileName)
{
    QImage img(m_boxSize, m_boxSize, QImage::Format_RGB32);
    QPainter painter(&img);
    paint(painter);
    img.save(fileName);
}

void SquareDiagramm::loadFromFile(QFile &file , QString &fileName)
{
    ViData vidata;
    vidata.parse(file);
    m_data = vidata.getPoints();
    m_latticeSize = vidata.getLatticeSize();
    //QString NewfileName(fileName);
    //NewfileName.append("Diagram");
    saveImage(fileName+".jpg");
    this->repaint();
}

SquareDiagramm::~SquareDiagramm()
{
    delete ui;
}

QColor SquareDiagramm::calculateColor(double value)
{
    int RGB=225;
    int r,g,b;
    if((value-1)>0){
        r=RGB;
        b=g=(int)round((1-(value-1))*RGB);
    }
    else{
        b=RGB;
        r=g=(int)round((1+(value-1))*RGB);
    }
    return QColor(r,g,b);
}
