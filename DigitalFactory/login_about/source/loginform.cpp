#include "loginform.h"
#include "loginwindow.h"

/*****************
 * 点击登录
 *
*/
void LoginForm::onlogin(){

    this->mainWindow=new MainWindow;
    this->mainWindow->show();
    this-> loginWindow->hide();
    //    delete this->loginWindow;
    //    delete this->loginWindow;
}
