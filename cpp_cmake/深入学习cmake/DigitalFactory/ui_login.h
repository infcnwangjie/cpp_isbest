/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef LOGIN_H
#define LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

namespace Ui {

class Ui_Login
{
public:
    QSplitter *splitter;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QCheckBox *checkBox;
    QPushButton *pushButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(400, 300);
        Form->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        splitter = new QSplitter(Form);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(60, 80, 261, 151));
        splitter->setOrientation(Qt::Vertical);
        lineEdit = new QLineEdit(splitter);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        splitter->addWidget(lineEdit);
        lineEdit_2 = new QLineEdit(splitter);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        splitter->addWidget(lineEdit_2);
        checkBox = new QCheckBox(splitter);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        splitter->addWidget(checkBox);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);\n"
"font: 12pt \"\345\256\213\344\275\223\";"));
        splitter->addWidget(pushButton);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        checkBox->setText(QCoreApplication::translate("Form", "\344\270\213\346\254\241\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
        pushButton->setText(QCoreApplication::translate("Form", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

}
//namespace Ui {
//    class Form: public Ui_Login {};
//} // namespace Ui

QT_END_NAMESPACE

#endif // LOGIN_H
