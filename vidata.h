#ifndef VIDATA_H
#define VIDATA_H

#include <QFile>
#include <QList>

struct LatticePoint{
    double i;
    double j;
    double value;
};

class ViData
{
public:
    ViData();
    void parse(QFile &file);
    QList<LatticePoint> *getPoints();
    unsigned int getLatticeSize();
private:
    QList<LatticePoint> *m_points;
    unsigned int m_latticeSize;
};

#endif // VIDATA_H
