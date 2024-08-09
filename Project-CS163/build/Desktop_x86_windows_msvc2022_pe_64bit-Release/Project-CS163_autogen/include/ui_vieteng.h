/********************************************************************************
** Form generated from reading UI file 'vieteng.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIETENG_H
#define UI_VIETENG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_VietEng
{
public:
    QPushButton *backButton;

    void setupUi(QDialog *VietEng)
    {
        if (VietEng->objectName().isEmpty())
            VietEng->setObjectName("VietEng");
        VietEng->resize(1200, 900);
        backButton = new QPushButton(VietEng);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(10, 15, 100, 32));

        retranslateUi(VietEng);

        QMetaObject::connectSlotsByName(VietEng);
    } // setupUi

    void retranslateUi(QDialog *VietEng)
    {
        VietEng->setWindowTitle(QCoreApplication::translate("VietEng", "Dialog", nullptr));
        backButton->setText(QCoreApplication::translate("VietEng", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VietEng: public Ui_VietEng {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIETENG_H
