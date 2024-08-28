/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *engVietButton;
    QPushButton *vietEngButton;
    QPushButton *engEngButton;
    QPushButton *emoijButton;
    QPushButton *slangButton;
    QLabel *title_2;
    QLabel *title_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 660);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(200, 70, 600, 580));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        groupBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 80, 601, 391));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        engVietButton = new QPushButton(verticalLayoutWidget);
        engVietButton->setObjectName("engVietButton");
        engVietButton->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(engVietButton);

        vietEngButton = new QPushButton(verticalLayoutWidget);
        vietEngButton->setObjectName("vietEngButton");
        vietEngButton->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(vietEngButton);

        engEngButton = new QPushButton(verticalLayoutWidget);
        engEngButton->setObjectName("engEngButton");
        engEngButton->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(engEngButton, 0, Qt::AlignmentFlag::AlignVCenter);

        emoijButton = new QPushButton(verticalLayoutWidget);
        emoijButton->setObjectName("emoijButton");

        verticalLayout->addWidget(emoijButton);

        slangButton = new QPushButton(verticalLayoutWidget);
        slangButton->setObjectName("slangButton");

        verticalLayout->addWidget(slangButton);

        title_2 = new QLabel(groupBox);
        title_2->setObjectName("title_2");
        title_2->setGeometry(QRect(0, -10, 601, 60));
        title_2->setSizeIncrement(QSize(0, 0));
        QFont font;
        font.setPointSize(35);
        font.setWeight(QFont::ExtraBold);
        font.setItalic(false);
        title_2->setFont(font);
        title_2->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        title_2->setStyleSheet(QString::fromUtf8("color: white;              \n"
"border-radius: 10px;   "));
        title_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        title_3 = new QLabel(groupBox);
        title_3->setObjectName("title_3");
        title_3->setGeometry(QRect(0, 500, 601, 60));
        title_3->setSizeIncrement(QSize(0, 0));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(false);
        font1.setItalic(false);
        title_3->setFont(font1);
        title_3->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        title_3->setStyleSheet(QString::fromUtf8("color: white;              \n"
"border-radius: 10px;   "));
        title_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        engVietButton->setText(QCoreApplication::translate("MainWindow", "English-Vietnamese", nullptr));
        vietEngButton->setText(QCoreApplication::translate("MainWindow", "Vietnamese-English", nullptr));
        engEngButton->setText(QCoreApplication::translate("MainWindow", "English-English", nullptr));
        emoijButton->setText(QCoreApplication::translate("MainWindow", "Emoij", nullptr));
        slangButton->setText(QCoreApplication::translate("MainWindow", "Slang", nullptr));
        title_2->setText(QCoreApplication::translate("MainWindow", "DICTIONARY", nullptr));
        title_3->setText(QCoreApplication::translate("MainWindow", "GROUP PROJECT CS163 - GROUP 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
