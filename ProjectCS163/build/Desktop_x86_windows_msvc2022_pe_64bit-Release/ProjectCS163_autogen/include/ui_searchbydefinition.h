/********************************************************************************
** Form generated from reading UI file 'searchbydefinition.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHBYDEFINITION_H
#define UI_SEARCHBYDEFINITION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_SearchByDefinition
{
public:

    void setupUi(QDialog *SearchByDefinition)
    {
        if (SearchByDefinition->objectName().isEmpty())
            SearchByDefinition->setObjectName("SearchByDefinition");
        SearchByDefinition->resize(400, 300);

        retranslateUi(SearchByDefinition);

        QMetaObject::connectSlotsByName(SearchByDefinition);
    } // setupUi

    void retranslateUi(QDialog *SearchByDefinition)
    {
        SearchByDefinition->setWindowTitle(QCoreApplication::translate("SearchByDefinition", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchByDefinition: public Ui_SearchByDefinition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHBYDEFINITION_H
