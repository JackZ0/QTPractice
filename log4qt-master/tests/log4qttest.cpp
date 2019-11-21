#include <QtCore>
#include "log4qt/logger.h"
//#include "log4qttest.h"
#include "log4qt/basicconfigurator.h"
#include "log4qt/propertyconfigurator.h"
#include "log4qt/logmanager.h"

class Object
{
    Log4Qt::Logger * logger;
public:
    Object() {
        logger = Log4Qt::Logger::logger("Object");
        logger->info("Constructor");
    }

    ~Object() {
        logger->info("Destructor");
        logger->warn("warn");

    }

};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Log4Qt::PropertyConfigurator::configure("QtLog4Qt.conf");
    Log4Qt::LogManager::setHandleQtMessages(true);
    Log4Qt::BasicConfigurator::configure();

    QString strInfo = QStringLiteral("qDebug Qt 中文显示!");
    qDebug(strInfo.toStdString().c_str());
    strInfo = QStringLiteral("qWarning Qt 中文显示!");
    qWarning(strInfo.toStdString().c_str());
    strInfo = QStringLiteral("qCritical Qt 中文显示!");
    qCritical(strInfo.toStdString().c_str());

    Object obj;
    return 0;
}
