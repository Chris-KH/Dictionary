/********************************************************************************
** Form generated from reading UI file 'engviet.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENGVIET_H
#define UI_ENGVIET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EngViet
{
public:
    QPushButton *backButton;
    QWidget *splitterPlaceholder;
    QWidget *buttonWidget;

    void setupUi(QDialog *EngViet)
    {
        if (EngViet->objectName().isEmpty())
            EngViet->setObjectName("EngViet");
        EngViet->resize(763, 452);
        EngViet->setMaximumSize(QSize(763, 452));
        backButton = new QPushButton(EngViet);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(10, 15, 100, 32));
        splitterPlaceholder = new QWidget(EngViet);
        splitterPlaceholder->setObjectName("splitterPlaceholder");
        splitterPlaceholder->setGeometry(QRect(0, 60, 1300, 840));
        buttonWidget = new QWidget(EngViet);
        buttonWidget->setObjectName("buttonWidget");
        buttonWidget->setGeometry(QRect(180, 5, 1100, 40));

        retranslateUi(EngViet);

        QMetaObject::connectSlotsByName(EngViet);
    } // setupUi

    void retranslateUi(QDialog *EngViet)
    {
        EngViet->setWindowTitle(QCoreApplication::translate("EngViet", "Dialog", nullptr));
        backButton->setText(QCoreApplication::translate("EngViet", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EngViet: public Ui_EngViet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENGVIET_H
