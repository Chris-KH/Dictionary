/********************************************************************************
** Form generated from reading UI file 'engeng.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENGENG_H
#define UI_ENGENG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EngEng
{
public:
    QPushButton *backButton;
    QLabel *label;

    void setupUi(QDialog *EngEng)
    {
        if (EngEng->objectName().isEmpty())
            EngEng->setObjectName("EngEng");
        EngEng->resize(1200, 900);
        EngEng->setStyleSheet(QString::fromUtf8(""));
        backButton = new QPushButton(EngEng);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(10, 15, 100, 32));
        label = new QLabel(EngEng);
        label->setObjectName("label");
        label->setGeometry(QRect(400, 230, 161, 81));

        retranslateUi(EngEng);

        QMetaObject::connectSlotsByName(EngEng);
    } // setupUi

    void retranslateUi(QDialog *EngEng)
    {
        EngEng->setWindowTitle(QCoreApplication::translate("EngEng", "Dialog", nullptr));
        backButton->setText(QCoreApplication::translate("EngEng", "back", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EngEng: public Ui_EngEng {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENGENG_H
