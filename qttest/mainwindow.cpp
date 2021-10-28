#include "mainwindow.h"
#include "finddialog.h"
#include "spreadsheet.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
   spreedsheet = new Spreadsheet;
   setCentralWidget(spreedsheet);

   createAction();
   createMenus();
   createContextMenu();
   createToolBars();
   createStatusBar();

   readSettings();
   findDialog = 0;
   setWindowIcon(QIcon(":/images/icon.png"));
   setCurrentFile("");
}

MainWindow::~MainWindow()
{

}

void MainWindow::closeEvent(QCloseEvent *event)
{

}

void MainWindow::createAction()
{
    newAction = new QAction(tr("New"),this);
    newAction->setIcon(QIcon(":images/icon.png"));
    newAction->setShortcut(QKeySequence::New);
    connect(newAction,SIGNAL(triggered()),this,SLOT(newFile()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);

    seperatorAction = fileMenu->addSeparator();
    for(int i = 0; i < MaxRecentFils;i++)
        fileMenu->addAction(recentFileActions[i]);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

}

void MainWindow::createContextMenu()
{

}

void MainWindow::createToolBars()
{

}

void MainWindow::createStatusBar()
{

}

void MainWindow::readSettings()
{

}

bool MainWindow::writeSettins()
{

}

bool MainWindow::okToContinue()
{

}

bool MainWindow::loadFile(const QString &fileName)
{

}

bool MainWindow::saveFile(const QString &fileName)
{

}

void MainWindow::setCurrentFile(const QString &fileName)
{

}

void MainWindow::updateRecentFileActions()
{

}

QString MainWindow::strippedName(const QString &fullFileName)
{

}

void MainWindow::newFile()
{

}

void MainWindow::open()
{

}

void MainWindow::save()
{

}

void MainWindow::saveAs()
{

}

void MainWindow::find()
{

}

void MainWindow::goToCell()
{

}

void MainWindow::sort()
{

}

void MainWindow::about()
{

}

void MainWindow::openRecentFile()
{

}

void MainWindow::updateStatusBar()
{

}

void MainWindow::spreadsheetModified()
{

}

