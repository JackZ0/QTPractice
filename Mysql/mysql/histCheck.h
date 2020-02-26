#ifndef HISTCHECK_H
#define HISTCHECK_H

#include <QString>
#include <QDateTime>
class histCheck
{
public:
    histCheck();
    int id;
    QString overhaulPersion;
    QString operationMsg;
    int roomId;
    int cubicleId;
    int unitId;
    int cableId;
    int fiberId;
    QString checkReason;
    QDateTime createAt;
    QDateTime occurTime;
    int status;
    QString discoverer;
    QString json;
    QString defectNature;
};

#endif // HISTCHECK_H
