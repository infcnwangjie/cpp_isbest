#ifndef ROLE_PAGE_MODEL
#define ROLE_PAGE_MODEL

#include <string>
#include <vector>
#include "MenuPageModel.h"

/***
提供客户端信息如下：
是否合法用户| 用户角色名称 | 用户角色关联角色
****/

class RolePageModel
{

public:
    RolePageModel( std::string id1,std::string name1,std::string remark1,std::vector<MenuPageModel> menus1):
    id(id1),name(name1),remark(remark1)
    {
      for(MenuPageModel menu:menus1){
          menus.push_back(menu);
      }
    }
    ~RolePageModel();

private:
    std::string id;
    std::string name;
    std::string remark;
    std::vector<MenuPageModel> menus;

};
#endif // MAINWINDOW_H
