#ifndef SQUAREDIAGRAMM_H
#define SQUAREDIAGRAMM_H

#include <QWidget>
#include "vidata.h"

namespace Ui {
class SquareDiagramm;
}

class SquareDiagramm : public QWidget
{
    Q_OBJECT

public:
    explicit SquareDiagramm(QWidget *parent = 0);
    void setLatticeSize(unsigned int latticeSize=32);
     void paintEvent(QPaintEvent * event);
     void paint(QPainter &painter);
     void saveImage(QString fileName);
     unsigned int getLatticeSize();
     void loadFromFile(QFile &file, QString &fileName);
    ~SquareDiagramm();

private:
    Ui::SquareDiagramm *ui;
    QList<LatticePoint>* m_data;
    unsigned int m_latticeSize;
    unsigned int m_boxSize;
    QColor calculateColor(double value);
};

#endif // SQUAREDIAGRAMM_H
