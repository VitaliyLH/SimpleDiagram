#include "vidata.h"
#include <QStringList>
#include <QTextStream>

ViData::ViData()
{
    m_points=new QList<LatticePoint>;
}

void ViData::parse(QFile &file)
{
    QTextStream stream(&file);
    if(!stream.atEnd()){
        stream>>m_latticeSize;
    }
    while (!stream.atEnd()) {
        int num;
        double val;
        stream>>num;
        stream>>val;
        int i=num%m_latticeSize;
        int j=num/m_latticeSize;
        LatticePoint p;
        p.i=i;
        p.j=j;
        p.value=val+1.0;
        m_points->append(p);
    }
}

QList<LatticePoint>* ViData::getPoints()
{
    return m_points;
}

unsigned int ViData::getLatticeSize()
{
    return m_latticeSize;
}
