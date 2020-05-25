#ifndef IDENTITY_H
#define IDENTITY_H

#include <iostream>
#include <string>

using namespace std;

//抽象基类
class Identity
{
    public:
        Identity();
        virtual ~Identity();

        //操作菜单
        virtual void openMenu() = 0;

        string m_Name;
        string m_Pwd;

};

#endif // IDENTITY_H
