/********************************************************************************
** Form generated from reading UI file 'emoij.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMOIJ_H
#define UI_EMOIJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_emoij
{
public:
    QPushButton *backButton;

    void setupUi(QDialog *emoij)
    {
        if (emoij->objectName().isEmpty())
            emoij->setObjectName("emoij");
        emoij->resize(1200, 900);
        backButton = new QPushButton(emoij);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(10, 15, 100, 32));

        retranslateUi(emoij);

        QMetaObject::connectSlotsByName(emoij);
    } // setupUi

    void retranslateUi(QDialog *emoij)
    {
        emoij->setWindowTitle(QCoreApplication::translate("emoij", "Dialog", nullptr));
        backButton->setText(QCoreApplication::translate("emoij", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class emoij: public Ui_emoij {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMOIJ_H
