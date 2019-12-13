/********************************************************************************
** Form generated from reading UI file 'operationdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPERATIONDIALOG_H
#define UI_OPERATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_operationDialog
{
public:

    void setupUi(QDialog *operationDialog)
    {
        if (operationDialog->objectName().isEmpty())
            operationDialog->setObjectName(QStringLiteral("operationDialog"));
        operationDialog->resize(640, 480);

        retranslateUi(operationDialog);

        QMetaObject::connectSlotsByName(operationDialog);
    } // setupUi

    void retranslateUi(QDialog *operationDialog)
    {
        operationDialog->setWindowTitle(QApplication::translate("operationDialog", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class operationDialog: public Ui_operationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERATIONDIALOG_H
