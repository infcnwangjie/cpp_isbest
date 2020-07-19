/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class UiLoginForm
{
public:
    QGraphicsView *graphicsView;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *Label;
    QLineEdit *idEdit;
    QLabel *Label_2;
    QLineEdit *passwdEdit;
    QPushButton *quitButton;
    QPushButton *loginButton;
    QPushButton *regButton;

    void setupUi(QDialog *loginDialog)
    {
        if (loginDialog->objectName().isEmpty())
            loginDialog->setObjectName(QString::fromUtf8("loginDialog"));
                loginDialog->resize(270, 192);
        //        loginDialog->setMinimumSize(QSize(353, 192));
        //        loginDialog->setMaximumSize(QSize(353, 192));


        QPalette palette(loginDialog->palette());
        palette.setColor(QPalette::Background, Qt::white);
        loginDialog->setPalette(palette);


        graphicsView = new QGraphicsView(loginDialog);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(400, 500, 210, 61));
        formLayoutWidget = new QWidget(loginDialog);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 80, 210, 62));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        Label = new QLabel(formLayoutWidget);
        Label->setObjectName(QString::fromUtf8("Label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, Label);

        idEdit = new QLineEdit(formLayoutWidget);
        idEdit->setObjectName(QString::fromUtf8("idEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, idEdit);

        Label_2 = new QLabel(formLayoutWidget);
        Label_2->setObjectName(QString::fromUtf8("Label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, Label_2);

        passwdEdit = new QLineEdit(formLayoutWidget);
        passwdEdit->setObjectName(QString::fromUtf8("passwdEdit"));
        passwdEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, passwdEdit);


        quitButton = new QPushButton(loginDialog);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(10, 145, 81, 31));
        quitButton->setAutoDefault(false);
        quitButton->setFlat(false);
        loginButton = new QPushButton(loginDialog);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(180, 145, 81, 31));
        loginButton->setAutoDefault(false);
        regButton = new QPushButton(loginDialog);
        regButton->setObjectName(QString::fromUtf8("regButton"));
        regButton->setGeometry(QRect(145, 145, 51, 31));
        regButton->setAutoDefault(false);
        regButton->setFlat(true);

        retranslateUi(loginDialog);

        QMetaObject::connectSlotsByName(loginDialog);
    } // setupUi

    void retranslateUi(QDialog *loginDialog)
    {
        loginDialog->setWindowTitle(QCoreApplication::translate("loginDialog", "Login", nullptr));
        Label->setText(QCoreApplication::translate("loginDialog", "\345\270\220\345\217\267:", nullptr));
        Label_2->setText(QCoreApplication::translate("loginDialog", "\345\257\206\347\240\201:", nullptr));
        quitButton->setText(QCoreApplication::translate("loginDialog", "\351\200\200\345\207\272", nullptr));
        loginButton->setText(QCoreApplication::translate("loginDialog", "\347\231\273\345\275\225", nullptr));
        regButton->setText(QCoreApplication::translate("loginDialog", "&\346\263\250&\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialogUi: public UiLoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
