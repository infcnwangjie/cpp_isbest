#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Widgets演示"));

//    this->resize(500,300);

     connect(ui->showButton, SIGNAL(clicked()), this, SLOT(open_window()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open_window(){
                printf("dianwo%s","ok?");

                this->newWindow=new Ui_Dialog();
                this->newWindow->show();
}
