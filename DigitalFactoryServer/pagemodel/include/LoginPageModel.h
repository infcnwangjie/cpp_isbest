#ifndef LOGIN_PAGE_MODEL
#define MAINWINDOW_H

#include <vector>




/***
提供客户端信息如下：
是否合法用户| 用户角色名称 | 用户角色关联角色
****/

class LoginPageModel
{
public:
    LoginPageModel(bool authorized, std::vector<RolePageModel> roles):authorized(authorized),roles(roles){

    }
    ~LoginPageModel();

private:
    bool authorized; //登录成功
    std::vector<RolePageModel> roles;//拥有角色


};
#endif // MAINWINDOW_H
