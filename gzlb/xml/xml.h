#ifndef XML_H
#define XML_H

#include <QtXml/QDomDocument>
#include <QFile>
#include <QTextStream>
class Xml
{
public:
    Xml();
    void WriteXml(QString fileName);
    void ReadXml(QString fileName);
    void AddXml(QString fileName);
    void RemoveXml(QString fileName);
    void UpdateXml(QString fileName);
};

#endif // XML_H
