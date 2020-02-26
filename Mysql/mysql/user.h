#ifndef USER_H
#define USER_H
#include <QString>
#include <QDateTime>

class User
{
public:
    User();
    int id;
    int orgniztionId;
    QString accountName;
    QString realName;
    QString password;
    int loginCount;
    QString email;
    QString telephone;
    QDateTime createAt;
    QDateTime loginAt;
    bool isValid;
    QString json;

private:

};

#endif // USER_H
