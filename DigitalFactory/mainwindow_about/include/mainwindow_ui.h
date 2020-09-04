#ifndef UI_MAIN_WINDOW
#define UI_MAIN_WINDOW


/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/


#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include<QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class MainWindowAbstractUi
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QVBoxLayout *centralwidgetLayout;

    QHBoxLayout *topLayout;
    QHBoxLayout *middleLayout;
    QVBoxLayout *leftLayout;
    QVBoxLayout *rightLayout;

    QPushButton * navigationButton;
    QLabel *left;
    QLabel * right;



    void addTop(){
        this->topLayout=new QHBoxLayout();
//         QPushButton(const QIcon& icon, const QString &text, QWidget *parent = nullptr);
        navigationButton=new QPushButton(QIcon(":/resource/images/xiaoren.png"),"菜单导航");
        this->topLayout->addWidget(navigationButton);

        //        QSplitter spliter1(this->centralwidget);
        //        this->topLayout->addWidget(spliter1);

        this->centralwidgetLayout->addLayout(this->topLayout);
    }

    void addLeft(){
        this->leftLayout=new QVBoxLayout();
        left=new QLabel();
        left->setText("left");
        this->leftLayout->addWidget(left);
        //        this->middleLayout->addLayout(this->leftLayout);

    }
    void addRight(){
        this->rightLayout=new QVBoxLayout();
         right=new QLabel();
        right->setText("right");
        this->rightLayout->addWidget(right);

        //        this->middleLayout->addLayout(this->/*rightLayout*/);
    }

    void addMiddle(){
        this->middleLayout=new  QHBoxLayout();
        addLeft();
        this->middleLayout->addLayout(this->leftLayout);
        addRight();
        this->middleLayout->addLayout(this->rightLayout);
        this->centralwidgetLayout->addLayout(this->middleLayout);

    }



    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setWindowTitle("闪亮ERP");
        centralwidget = new QWidget(MainWindow);

        //打算采用上、中、下布局，然后中间再采用左右布局
        centralwidgetLayout=new QVBoxLayout();
        //        this->centralwidget->setLayout(centralwidgetLayout);
        centralwidget->setLayout(centralwidgetLayout);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->show();

        MainWindow->setCentralWidget(centralwidget);


        //用来展示当前打开的窗口
                addTop();
                addMiddle();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);






//        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

//    void retranslateUi(QMainWindow *MainWindow)
//    {
//        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
//    } // retranslateUi

};




namespace Ui {
class MainWindowUi: public MainWindowAbstractUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H


