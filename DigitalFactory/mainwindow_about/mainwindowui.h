/********************************************************************************
** Form generated from reading UI file 'mainwindowui.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWUI_H
#define MAINWINDOWUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBar>
#include <QActionGroup>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindowUi
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;//垂直布局：上中下 三层布局
    QHBoxLayout *middle_horizontalLayout;//横向布局，左侧树状导航栏，右侧显示面板
    QVBoxLayout *left_verticalLayout,*right_verticalLayout;//中间部分，分出来的 左侧，右侧


    //    QHBoxLayout *topHorizontalLayout;
    //    QPushButton * paidanTopButton;
    //    QPushButton * caigouTopButton;

    QMenuBar *m_MenuBar;
    QMenu *basicinformation_Menu,*system_Menu,*purchaseManage_Menu,*salesManage_Menu,*stocksManage_Menu;

    //基本信息相关action
    QAction *basicinformation_Action; //基本信息
    QAction *stafferinfo_Action; //职员信息
    QAction *supplyerinfo_Action; //供应商信息
    QAction *customerinfo_Action; //客户信息
    QAction *storehouseinfo_Action; //仓库信息
    QAction *banksettlementaccounts_Action; //结算账号
    QAction * incomeExpenditure_Action;//收支项目

    //进货管理Action
    QAction * jinhuoruku_Action; //进货入库
    QAction *tuihuochuku_Action; //退货出库
    QAction *jinhuodanjuchaxun_Action; //进货单据查询
    QAction *tuihuodanjuchaxun_Action; //退货单据查询
    QAction *dangqiankucun_Action; //当前库存





    //销售管理
    QAction * xiaoshouchuku_Action; //销售出库
    QAction *kehutuihuo_Action; //客户退货
    QAction *xiaoshoudanjuchaxun_Action; //销售单据查询
    QAction *kehutuihuochaxun_Action; //客户退货查询


    //系统设置
    QAction * permissionSetting_Action; //权限设置




    //创建工具栏
    QToolBar *m_ToolBar;
    QAction *userinfo_ActionToolBar; //用户信息
    //    QAction *supplymarket_ActionToolBar2;//供销管理
    //    QAction *storehouse_ActionToolBar2;//库存管理
    //    QAction *stastic_ActionToolBar2;//统计查询
    //    QAction *accountreport_ActionToolBar2;//财务报表
    //    QAction *system_ActionToolBar2;//系统配置
    //    QAction *help_ActionToolBar2;//帮助




    QPushButton * basicInformation_pushButton;//基本信息按钮

    QListWidget  * basicListWidget;//基本信息按钮群


    QPushButton * businessentry_pushButton;//业务录入按钮
    QPushButton * accountreport_pushButton;//报表查询按钮
    QPushButton * systemsetting_pushButton;//系统设置按钮
    QPushButton * others_pushButton;//其他按钮



    QStatusBar *statusbar;

    void generatorToolBars(){
        //QDebug()<<"生成toolbar";
    }

    void create_top(QMainWindow *MainWindow){
        //创建菜单
        m_MenuBar=MainWindow->menuBar();
        basicinformation_Menu = m_MenuBar->addMenu("【基础资料】");
        basicinformation_Action=new QAction(QString("&Open"));

        //        basicinformation_Action->setShortcut(QKeySequence::);
        basicinformation_Action->setStatusTip(QString("基础资料"));
        basicinformation_Menu->addAction(basicinformation_Action);
        //        connect(pNew, &QAction::triggered,
        //               //Lambda 表达式
        //               [=]()
        //               {
        //                   qDebug() << "已退出";
        //               }

        //               );



        //        connect(basicinformation_Action, &QAction::triggered, this, &MainWindowUi::generatorToolBars));

        //        productinfo_Action=basicinformation_Menu->addAction("产品信息");
        //        stafferinfo_Action=basicinformation_Menu->addAction("职员信息");
        //        supplyerinfo_Action=basicinformation_Menu->addAction("供应商信息");
        //        customerinfo_Action=basicinformation_Menu->addAction("客户信息");
        //        storehouseinfo_Action=basicinformation_Menu->addAction("仓库信息");
        //        banksettlementaccounts_Action=basicinformation_Menu->addAction("结算账户");
        //        incomeExpenditure_Action=basicinformation_Menu->addAction("收支项目");


        //系统设置
        system_Menu=m_MenuBar->addMenu("【系统设置】");
        permissionSetting_Action=system_Menu->addAction("权限设置");
        system_Menu->addAction(permissionSetting_Action);


        //进货管理
        purchaseManage_Menu = m_MenuBar->addMenu("【进货管理】");
        jinhuoruku_Action=new QAction(QString("进货入库"));
        tuihuochuku_Action=new QAction(QString("退货入库"));
        jinhuodanjuchaxun_Action=new QAction(QString("进货单据查询"));
        tuihuodanjuchaxun_Action=new QAction(QString("退货单据查询"));
        dangqiankucun_Action=new QAction(QString("当前库存"));
        purchaseManage_Menu->addAction(jinhuoruku_Action);
        purchaseManage_Menu->addAction(tuihuochuku_Action);
        purchaseManage_Menu->addAction(jinhuodanjuchaxun_Action);
        purchaseManage_Menu->addAction(tuihuodanjuchaxun_Action);
        purchaseManage_Menu->addAction(dangqiankucun_Action);




        //销售管理
        salesManage_Menu=m_MenuBar->addMenu("【销售管理】");
        xiaoshouchuku_Action=new QAction(QString("销售出库"));
        kehutuihuo_Action=new QAction(QString("客户退货"));
        xiaoshoudanjuchaxun_Action=new QAction(QString("销售单据查询"));
        kehutuihuochaxun_Action=new QAction(QString("客户退货单据查询"));
        salesManage_Menu->addAction(xiaoshouchuku_Action);
        salesManage_Menu->addAction(kehutuihuo_Action);
        salesManage_Menu->addAction(xiaoshoudanjuchaxun_Action);
        salesManage_Menu->addAction(kehutuihuochaxun_Action);


        m_MenuBar->show();
        m_MenuBar->setStyleSheet("background-color:#4682B4;");
        verticalLayout->addWidget(m_MenuBar);
        //        verticalLayout->addLayout(topHorizontalLayout);


        //创建工具栏
        m_ToolBar = new QToolBar;
        m_ToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        //        //        m_ToolBarActionGroup = new QActionGroup();
        QList<QAction*> m_ToolBarList;

        userinfo_ActionToolBar = new QAction(QStringLiteral("ToolBar1"));
        userinfo_ActionToolBar->setIcon(QIcon(":/resource/images/xiaoren.png"));
        userinfo_ActionToolBar->setText("订单管理");


        //        supplymarket_ActionToolBar2 = new QAction(QStringLiteral("ToolBar2"));
        //        supplymarket_ActionToolBar2->setIcon(QIcon(":/resource/images/xiaoren.png"));
        //        supplymarket_ActionToolBar2->setText("供销管理");

        //        storehouse_ActionToolBar2=new QAction(QStringLiteral("ToolBar3"));
        //        storehouse_ActionToolBar2->setIcon(QIcon(":/resource/images/xiaoren.png"));
        //        storehouse_ActionToolBar2->setText("仓库管理");


        //        stastic_ActionToolBar2=new QAction(QStringLiteral("ToolBar4"));
        //        stastic_ActionToolBar2->setIcon(QIcon(":/resource/images/xiaoren.png"));
        //        stastic_ActionToolBar2->setText("统计查询");

        //        accountreport_ActionToolBar2=new QAction(QStringLiteral("ToolBar5"));
        //        accountreport_ActionToolBar2->setIcon(QIcon(":/resource/images/xiaoren.png"));
        //        accountreport_ActionToolBar2->setText("财务报表");

        //        system_ActionToolBar2=new QAction(QStringLiteral("ToolBar6"));
        //        system_ActionToolBar2->setIcon(QIcon(":/resource/images/xiaoren.png"));
        //        system_ActionToolBar2->setText("系统管理");

        //        help_ActionToolBar2=new QAction(QStringLiteral("ToolBar7"));
        //        help_ActionToolBar2->setIcon(QIcon(":/resource/images/xiaoren.png"));
        //        help_ActionToolBar2->setText("帮助");

        m_ToolBarList.append(userinfo_ActionToolBar);
        //        m_ToolBarList.append(supplymarket_ActionToolBar2);
        //        m_ToolBarList.append(storehouse_ActionToolBar2);
        //        m_ToolBarList.append(stastic_ActionToolBar2);
        //        m_ToolBarList.append(accountreport_ActionToolBar2);
        //        m_ToolBarList.append(system_ActionToolBar2);
        //        m_ToolBarList.append(help_ActionToolBar2);


        m_ToolBar->addActions(m_ToolBarList);
        m_ToolBar->setStyleSheet("background-color:#E9F1FF;");
        m_ToolBar->show();


        verticalLayout->addWidget(m_ToolBar);
    }


    void create_middlle(QMainWindow *MainWindow){

        //        basicInformation_pushButton=new QPushButton("基本信息");
        //        basicInformation_pushButton->show();
        businessentry_pushButton=new QPushButton("业务录入");
        accountreport_pushButton=new QPushButton("报表查询");
        systemsetting_pushButton=new QPushButton("系统设置");
        others_pushButton=new QPushButton("其它");



        //        basicListWidget=new QListWidget();
        //        basicListWidget->setMaximumWidth(200);

        //        QListWidgetItem *productInfo=new QListWidgetItem();
        //        productInfo->setText("产品信息");
        //        productInfo->setIcon(QIcon(":/resource/images/logo.jpg"));

        //        basicListWidget->addItem(productInfo);


        //        QListWidgetItem *staffInfo=new QListWidgetItem();
        //        staffInfo->setText("职员信息");
        //        basicListWidget->addItem(staffInfo);

        //        QListWidgetItem *supplierInfo=new QListWidgetItem();
        //        supplierInfo->setText("供应商信息");

        //        basicListWidget->addItem(supplierInfo);


        //        basicListWidget->setStyleSheet("background-color:#4682B4;");

        //        left_verticalLayout->addWidget(basicListWidget);







        businessentry_pushButton->setStyleSheet("background-color:#4682B4;");
        accountreport_pushButton->setStyleSheet("background-color:#4682B4;");
        systemsetting_pushButton->setStyleSheet("background-color:#4682B4;");
        //QPushButton:hover{background-color:rgb(14, 220, 0);border-radius: 10px;color: rgb(0, 0, 0);}
        others_pushButton->setStyleSheet("background-color:#4682B4;");


        left_verticalLayout->addWidget(businessentry_pushButton);
        left_verticalLayout->addWidget(accountreport_pushButton);
        left_verticalLayout->addWidget(systemsetting_pushButton);
        left_verticalLayout->addWidget(others_pushButton);



    }

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1167, 787);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));

        //        widget = new QWidget(centralwidget);
        //        widget->setObjectName(QString::fromUtf8("widget"));
        //        widget->setGeometry(QRect(20, 160, 1111, 258));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setAlignment(Qt::AlignTop);
        verticalLayout->setContentsMargins(0, 0, 0, 0);


        //上层构建：menubar以及toolbar
        create_top(MainWindow);


        //中层构建
        middle_horizontalLayout = new QHBoxLayout(centralwidget);
        middle_horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        middle_horizontalLayout->setAlignment(Qt::AlignLeft);

        //将中间布局添加到垂直布局
        verticalLayout->addLayout(middle_horizontalLayout);

        //中层 左侧部分布局
        left_verticalLayout=new QVBoxLayout();
        left_verticalLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
        //中层右侧部分布局
        right_verticalLayout=new QVBoxLayout();
        right_verticalLayout->setAlignment(Qt::AlignTop);

        middle_horizontalLayout->addLayout(left_verticalLayout);
        middle_horizontalLayout->addLayout(right_verticalLayout);

        create_middlle(MainWindow);




        //        logolabel = new QLabel(widget);
        //        logolabel->setObjectName(QString::fromUtf8("label"));
        //        //        logolabel->setText("放置icon");
        //        logolabel->setMaximumSize(60, 60);



        //        QImage Image;//声明QImage 对象
        //        Image.load(":/resource/images/logo.jpg");//加载图片，前提是该图片存在项目的资源文件中
        //        QPixmap pixmap = QPixmap::fromImage(Image);//QPixmap引入Image
        //        int with = logolabel->width();//设置宽度
        //        int height = logolabel->height();//设置高度
        //        //        QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation); // 饱满填充
        //        QPixmap fitpixmap = pixmap.scaled(with, height, Qt::KeepAspectRatio, Qt::SmoothTransformation); // 按比例缩放
        //        logolabel->setPixmap(fitpixmap);





        //        horizontalLayout_top->addWidget(logolabel);

        //        horizontalSpacer_top = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        //        horizontalLayout_top->addItem(horizontalSpacer_top);

        //        userInfoPushButton =new QPushButton(QIcon(":/resource/images/xiaoren.png"),"用户信息");
        //        userInfoPushButton->setMaximumSize(100,50);
        //        userInfoPushButton->setObjectName(QString::fromUtf8("userInfoPushButton"));






        //        horizontalLayout_top->addWidget(userInfoPushButton);

        //        pushButton_4 = new QPushButton(widget);
        //        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        //        horizontalLayout_top->addWidget(pushButton_4);

        //        pushButton_5 = new QPushButton(widget);
        //        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        //        horizontalLayout_top->addWidget(pushButton_5);



        //    /*    pushButton_2 = new QPushButton(widget);*/
        //        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        //        horizontalLayout_top->addWidget(pushButton_2);

        //        pushButton_3 = new QPushButton(widget);
        //        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        //        horizontalLayout_top->addWidget(pushButton_3);


        //        verticalLayout->addLayout(horizontalLayout_top);

        //        horizontalLayout_middle = new QHBoxLayout();
        //        horizontalLayout_middle->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        //        listWidget = new QListWidget(widget);
        //        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        //        horizontalLayout_middle->addWidget(listWidget);

        //        tabWidget = new QTabWidget(widget);
        //        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        //        tab_3 = new QWidget();
        //        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        //        tabWidget->addTab(tab_3, QString());
        //        tab_4 = new QWidget();
        //        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        //        tabWidget->addTab(tab_4, QString());

        //        horizontalLayout_middle->addWidget(tabWidget);


        //        verticalLayout->addLayout(horizontalLayout_middle);

        //        horizontalLayout_tail = new QHBoxLayout();
        //        horizontalLayout_tail->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        //        pushButton_7 = new QPushButton(widget);
        //        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        //        horizontalLayout_tail->addWidget(pushButton_7);

        //        pushButton_8 = new QPushButton(widget);
        //        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        //        horizontalLayout_tail->addWidget(pushButton_8);

        //        pushButton_6 = new QPushButton(widget);
        //        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        //        horizontalLayout_tail->addWidget(pushButton_6);

        //        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        //        horizontalLayout_tail->addItem(horizontalSpacer_2);


        //        verticalLayout->addLayout(horizontalLayout_tail);
        centralwidget->setLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        //        menubar = new QMenuBar(MainWindow);
        //        menubar->setObjectName(QString::fromUtf8("menubar"));
        //        menubar->setGeometry(QRect(0, 0, 1167, 23));
        //        MainWindow->setMenuBar(menubar);


        //        retranslateUi(MainWindow);

        //        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    //    void retranslateUi(QMainWindow *MainWindow)
    //    {
    //        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    //        //        logolabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    //        pushButton_4->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    //        pushButton_5->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    //        userInfoPushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    //        pushButton_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    //        pushButton_3->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    //        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
    //        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
    //        pushButton_7->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    //        pushButton_8->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    //        pushButton_6->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    //    } // retranslateUi

};


} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWUI_H
