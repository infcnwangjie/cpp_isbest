/********************************************************************************
** Form generated from reading UI file 'first_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FIRST_WIDGET_H
#define FIRST_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog:public QWidget
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QWidget *tab_2;
    QLabel *label_2;

    Ui_Dialog(){
        setupUi(this);
    }

    void setupUi(QWidget *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(962, 545);
        tabWidget = new QTabWidget(Dialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 921, 471));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 392, 131, 31));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 370, 111, 16));
        tabWidget->addTab(tab_2, QString());

        retranslateUi(Dialog);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QWidget *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "first page", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Dialog", "Tab 1", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "second page", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Dialog", "Tab 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyFirstWidget: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FIRST_WIDGET_H
