#include <QtCore>
#include "log4qt/logger.h"
//#include "log4qttest.h"
#include "log4qt/basicconfigurator.h"

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
    }

};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Log4Qt::BasicConfigurator::configure();

    Object obj;
    return 0;
}
