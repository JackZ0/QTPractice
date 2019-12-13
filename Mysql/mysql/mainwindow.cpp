#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    connect_mysql();
    QString str1 = "SELECT equipment.ID,equipment.`name`,equipment.`port`,equipment.ip, equipment.`desc`FROM equipment";
    Mysqlquery(str1);
    ui->setupUi(this);

    connect(this->ui->queryButton,SIGNAL(clicked()),this,SLOT(setView()));
    connect(this->ui->exitpushButton,SIGNAL(clicked()),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connect_mysql(){
    db =  QSqlDatabase::addDatabase("QMYSQL");  //连接的MYSQL的数据库驱动
    db.setHostName("localhost");         //主机名
    db.setPort(3306);                    //端口
    db.setDatabaseName("mytest");          //数据库名
    db.setUserName("tester1");              //用户名
    db.setPassword("123456");            //密码
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

void MainWindow::close(){
    db.close();
    qDebug() << "close db!!";
}

void MainWindow::Mysqlquery(QString StrQuery){
    QSqlQuery query(db);
    query.exec(StrQuery);
    while(query.next()){
            qDebug()<<query.value(0).toInt()<<query.value(1).toString()<<query.value(2).toString();
    }
}
void MainWindow::setView(){
   QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select * from equipment",db);
    model->setHeaderData(0,Qt::Horizontal,tr("id"));
    model->setHeaderData(1,Qt::Horizontal,tr("name"));
    model->setHeaderData(2,Qt::Horizontal,tr("port"));
    model->setHeaderData(3,Qt::Horizontal,tr("ip"));
    model->setHeaderData(4,Qt::Horizontal,tr("desc"));
    qDebug()<< "1";
    ui->tableView->setModel(model);
    qDebug()<< "2";
    ui->tableView->show();

    qDebug()<< "3";

}
void MainWindow::setModel(){
//    table = new QTableView;
}

bool MainWindow::Delete(QString str, QString tablename){
    sqlquery = QSqlQuery(db);
    QString sq =QString("alter table %2 drop %1").arg(str),arg(tablename);
    return sqlquery.exec(sq);
}

bool MainWindow::Update(QStringList qstrl1, QStringList qstrl2, int id, QString tablename){
    QString sqlset;
    sqlquery = QSqlQuery(db);
    for(int i = 0; i < qstrl1.count(); i++)
        sqlset+=""+qstrl1.at(i)+" ='"+qstrl2.at(i)+"',";
    sqlset = sqlset.left(sqlset.length() - 1);
    QString sq = QString("update %2 set " + sqlset + " where id=%1").arg(id).arg(tablename);
    return sqlquery.exec(sq);

}
bool MainWindow::Insert(QStringList qstrl1, QStringList qstrl2, QString tablename){
    sqlquery=QSqlQuery(db);
        QString sqlset;
        for(int i = 0; i < qstrl1.count(); i++)
            sqlset += "" + qstrl1.at(i) + " ='" + qstrl2.at(i) + "',";
        sqlset = sqlset.left(sqlset.length() - 1);
        QString sq=QString("insert %1 set "+sqlset+" ").arg(tablename);
        return sqlquery.exec(sq);
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter p(this);
    QPen pen;
    pen.setWidth(10);

    pen.setColor(QColor(255,56,0));
    pen.setStyle(Qt::DashLine);
    p.setPen(pen);
    p.drawLine(50, 50, 200, 50);//直线
    p.drawLine(50, 50, 50, 200);//竖线
    p.drawLine(00, 90, 50, 200);//竖线
    p.drawLine(160, 400, 50, 200);//竖线
    p.drawPoint(400,90);
    p.drawPoint(400,200);

//    p.end();
//画矩形
    p.setPen(Qt::red);
    QRectF rectangle2(200.0, 20.0, 80.0, 60.0);
    p.drawRect(rectangle2);

//画扇形
    QRectF rectangle(10.0, 20.0, 100.0, 60.0);//设定扇形所在的矩形，扇形画在矩形内部
    int startAngle = 30 * 16;//起始角度，角度可以为负值，如-30*16
    int spanAngle = 120 * 16;//覆盖的角度，绘制方向为逆时针方向
    p.drawPie(rectangle, startAngle, spanAngle);

    p.setPen(QPen(Qt::blue,4, Qt::SolidLine));
    p.drawEllipse(20,20,160,160);
}

