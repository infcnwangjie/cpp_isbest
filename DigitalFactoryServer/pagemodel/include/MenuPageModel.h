#ifndef MENU_PAGE_MODEL
#define MENU_PAGE_MODEL
#include <vector>
#include<string>


class MenuPageModel
{
public:
    MenuPageModel(int id, std::string menuname, std::string url,std::string icon,int pid,bool is_parent):id(id),
        menuname(menuname),url(url),icon(icon),pid(pid),is_parent(is_parent)
    {

    }

    ~MenuPageModel();

private:
    int id; //menuid
    std::string menuname;//菜单名称
    std::string url;
    std::string icon;
    int pid;
    bool is_parent;//备用

};
#endif // MAINWINDOW_H
