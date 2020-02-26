#ifndef USERDB_H
#define USERDB_H

#include <QString>
#include <QList>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include "user.h"

class UserDB
{
public:
    UserDB();
    QSqlQuery sqlquery;
    QSqlDatabase db;
    int AddUser(User user);
    int UpdateUser(User user);
    int DeleteUserById(int userId);
    User QueryUserById(int userId);
    User QueryUserByName(QString userName);
    QList<User> QueryAllUser();
private:
    User Common(User usercommon,QSqlQuery QSqlQuerycommon);
};

#endif // USERDB_H
