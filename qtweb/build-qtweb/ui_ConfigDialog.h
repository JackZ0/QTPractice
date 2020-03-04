/********************************************************************************
** Form generated from reading UI file 'ConfigDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGDIALOG_H
#define UI_CONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConfigDialog
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *labelWidth;
    QLabel *labelHeight;
    QLabel *labelMines;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *LineEditWidth;
    QLineEdit *lineEditHeight;
    QLineEdit *lineEditMines;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConfigDialog)
    {
        if (ConfigDialog->objectName().isEmpty())
            ConfigDialog->setObjectName(QStringLiteral("ConfigDialog"));
        ConfigDialog->resize(445, 226);
        gridLayout_2 = new QGridLayout(ConfigDialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox = new QGroupBox(ConfigDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelWidth = new QLabel(groupBox);
        labelWidth->setObjectName(QStringLiteral("labelWidth"));

        verticalLayout->addWidget(labelWidth);

        labelHeight = new QLabel(groupBox);
        labelHeight->setObjectName(QStringLiteral("labelHeight"));

        verticalLayout->addWidget(labelHeight);

        labelMines = new QLabel(groupBox);
        labelMines->setObjectName(QStringLiteral("labelMines"));

        verticalLayout->addWidget(labelMines);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        LineEditWidth = new QLineEdit(groupBox);
        LineEditWidth->setObjectName(QStringLiteral("LineEditWidth"));

        verticalLayout_2->addWidget(LineEditWidth);

        lineEditHeight = new QLineEdit(groupBox);
        lineEditHeight->setObjectName(QStringLiteral("lineEditHeight"));

        verticalLayout_2->addWidget(lineEditHeight);

        lineEditMines = new QLineEdit(groupBox);
        lineEditMines->setObjectName(QStringLiteral("lineEditMines"));

        verticalLayout_2->addWidget(lineEditMines);


        horizontalLayout->addLayout(verticalLayout_2);


        horizontalLayout_2->addLayout(horizontalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout_3->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout_3->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout_3->addWidget(radioButton_3);


        horizontalLayout_2->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(groupBox);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(ConfigDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConfigDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConfigDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigDialog)
    {
        ConfigDialog->setWindowTitle(QApplication::translate("ConfigDialog", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ConfigDialog", "\346\270\270\346\210\217\351\205\215\347\275\256", Q_NULLPTR));
        labelWidth->setText(QApplication::translate("ConfigDialog", "\345\256\275\345\272\246\357\274\232", Q_NULLPTR));
        labelHeight->setText(QApplication::translate("ConfigDialog", "\351\253\230\345\272\246\357\274\232", Q_NULLPTR));
        labelMines->setText(QApplication::translate("ConfigDialog", "\351\233\267\346\225\260\357\274\232", Q_NULLPTR));
        radioButton->setText(QApplication::translate("ConfigDialog", "\345\210\235\347\272\247", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("ConfigDialog", "\344\270\255\347\272\247", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("ConfigDialog", "\351\253\230\347\272\247", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConfigDialog: public Ui_ConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDIALOG_H
