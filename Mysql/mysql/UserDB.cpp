#include "UserDB.h"
#include <QDebug>
UserDB::UserDB()
{
    db =  QSqlDatabase::addDatabase("QMYSQL");  //连接的MYSQL的数据库驱动
    db.setHostName("localhost");         //主机名
    db.setPort(3306);                    //端口
    db.setDatabaseName("automationdata");          //数据库名
    db.setUserName("root");              //用户名
    db.setPassword("admin123!@#");            //密码
    db.open();
    //测试连接
    if(!db.open())
    {
        qDebug()<<"不能连接"<<"connect to mysql error"<<db.lastError().text();
        return ;
    }
    else
    {
         qDebug()<<"连接成功"<<"connect to mysql OK";
    }
}

int UserDB::AddUser(User user)
{
    sqlquery=QSqlQuery(db);
    QString QstAddSql = QString("INSERT INTO `tbluserinfo` "
                                "(`OrgnizationId`,"
                                "`AccountName`,"
                                "`RealName`,"
                                "`Password`,"
                                "`LogintCount`,"
                                "`Email`,"
                                "`Telephone`,"
                                " `CreateAt`,"
                                "`LoginAt`,"
                                "`IsValid`,"
                                "`Json`)"
                                "VALUES"
                                "('%1','%2','%3','%4','%5','%6','%7','%8','%9',%10,'%11')")
            .arg(user.orgniztionId)
            .arg(user.accountName)
            .arg(user.realName)
            .arg(user.password)
            .arg(user.loginCount)
            .arg(user.email)
            .arg(user.telephone)
            .arg(user.createAt.toString("yyyy-MM-dd hh:mm:ss"))
            .arg(user.loginAt.toString("yyyy-MM-dd hh:mm:ss"))
            .arg(user.isValid)
            .arg(user.json);
    qDebug() <<  QstAddSql << endl;
    return sqlquery.exec(QstAddSql);
}

int UserDB::UpdateUser(User user)
{
     sqlquery=QSqlQuery(db);
     QString QstUpdateSql = QString("UPDATE `tbluserinfo`"
                                    " SET `OrgnizationId` = %1,"
                                    "`AccountName` = '%2',"
                                    "`RealName` = '%3',"
                                    "`Password` = '%4',"
                                    "`LogintCount` = %5,"
                                    "`Email` = '%6',"
                                    "`Telephone` = '%7',"
                                    "`CreateAt` = '%8',"
                                    "`LoginAt` = '%9',"
                                    "`IsValid` = %10, "
                                    "`Json` = '%11'"
                                    "WHERE(`Id` = %12)").arg(user.orgniztionId)
             .arg(user.accountName)
             .arg(user.realName)
             .arg(user.password)
             .arg(user.loginCount)
             .arg(user.email)
             .arg(user.telephone)
             .arg(user.createAt.toString("yyyy-MM-dd hh:mm:ss"))
             .arg(user.loginAt.toString("yyyy-MM-dd hh:mm:ss"))
             .arg(user.isValid).arg(user.json)
             .arg(user.id);
     qDebug() <<  QstUpdateSql << endl;
      return sqlquery.exec(QstUpdateSql);
}
int UserDB::DeleteUserById(int userId){
     sqlquery=QSqlQuery(db);
     QString QStDeleteSql = QString("DELETE from tbluserinfo where id = %1")
             .arg(userId);
     qDebug() <<  QStDeleteSql << endl;
     return sqlquery.exec(QStDeleteSql);
}
User UserDB::Common(User usercommon,QSqlQuery QSqlQuerycommon)
{
    usercommon.id = QSqlQuerycommon.value(0).toInt();
    usercommon.orgniztionId = QSqlQuerycommon.value(1).toInt();
    usercommon.accountName = QSqlQuerycommon.value(2).toString();
    usercommon.realName = QSqlQuerycommon.value(3).toString();
    usercommon.password = QSqlQuerycommon.value(4).toString();
    usercommon.loginCount = QSqlQuerycommon.value(5).toInt();
    usercommon.email = QSqlQuerycommon.value(6).toString();
    usercommon.telephone = QSqlQuerycommon.value(7).toString();
    usercommon.createAt = QSqlQuerycommon.value(8).toDateTime();
    usercommon.loginAt = QSqlQuerycommon.value(9).toDateTime();
    usercommon.isValid = QSqlQuerycommon.value(10).toInt();
    usercommon.json = QSqlQuerycommon.value(11).toString();
    return usercommon;
}
User UserDB::QueryUserById(int userId){
    User QueryResult;
    sqlquery=QSqlQuery(db);
    QString QStQuerysql = QString("SELECT * from tbluserinfo where id = %1")
            .arg(userId);
    sqlquery.exec(QStQuerysql);
    while(sqlquery.next()){
        QueryResult = Common(QueryResult,sqlquery);
    }
    return QueryResult;
}

User UserDB::QueryUserByName(QString userName)
{
    User QueryResult;
    sqlquery=QSqlQuery(db);
    QString QStQuerysql = QString("SELECT * from tbluserinfo where AccountName= %1")
            .arg(userName);
    sqlquery.exec(QStQuerysql);
    while(sqlquery.next()){
        QueryResult = Common(QueryResult,sqlquery);
    }
    return QueryResult;
}

QList<User> UserDB::QueryAllUser()
{
    QList<User> ListQueryResult;
    User UserTemp;
    sqlquery=QSqlQuery(db);
    QString QStQuerysql = QString("SELECT * from tbluserinfo");
    sqlquery.exec(QStQuerysql);
    int index = 0;
    while(sqlquery.next()){
        qDebug()<<sqlquery.value(0).toInt()<<sqlquery.value(1).toString()<<sqlquery.value(2).toString();
        UserTemp = Common(UserTemp,sqlquery);
        ListQueryResult[index] = UserTemp;
//        ListQueryResult[index].id = sqlquery.value(0).toInt();
//        ListQueryResult[index].orgniztionId = sqlquery.value(1).toInt();
//        ListQueryResult[index].accountName = sqlquery.value(2).toString();
//        ListQueryResult[index].realName = sqlquery.value(3).toString();
//        ListQueryResult[index].password = sqlquery.value(4).toString();
//        ListQueryResult[index].loginCount = sqlquery.value(5).toInt();
//        ListQueryResult[index].email = sqlquery.value(6).toString();
//        ListQueryResult[index].telephone = sqlquery.value(7).toString();
//        ListQueryResult[index].createAt = sqlquery.value(8).toDateTime();
//        ListQueryResult[index].loginAt = sqlquery.value(9).toDateTime();
//        ListQueryResult[index].isValid = sqlquery.value(10).toInt();
//        ListQueryResult[index].json = sqlquery.value(11).toString();
        index++;
    }
    return ListQueryResult;
}
