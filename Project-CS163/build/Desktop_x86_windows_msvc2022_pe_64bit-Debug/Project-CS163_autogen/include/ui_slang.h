/********************************************************************************
** Form generated from reading UI file 'slang.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLANG_H
#define UI_SLANG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Slang
{
public:
    QPushButton *backButton;

    void setupUi(QDialog *Slang)
    {
        if (Slang->objectName().isEmpty())
            Slang->setObjectName("Slang");
        Slang->resize(1200, 900);
        backButton = new QPushButton(Slang);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(10, 15, 100, 32));

        retranslateUi(Slang);

        QMetaObject::connectSlotsByName(Slang);
    } // setupUi

    void retranslateUi(QDialog *Slang)
    {
        Slang->setWindowTitle(QCoreApplication::translate("Slang", "Dialog", nullptr));
        backButton->setText(QCoreApplication::translate("Slang", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Slang: public Ui_Slang {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLANG_H
