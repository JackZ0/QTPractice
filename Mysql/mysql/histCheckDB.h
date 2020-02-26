#ifndef HISTCHECKDB_H
#define HISTCHECKDB_H
#include <QString>
#include <QList>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class histCheckDB
{
public:
    histCheckDB();

    QSqlQuery sqlquery;
    QSqlDatabase db;

};

#endif // HISTCHECKDB_H
