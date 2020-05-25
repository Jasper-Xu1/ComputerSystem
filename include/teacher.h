#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <windows.h>
#include <vector>
#include "Identity.h"
#include "orderFile.h"
#include "computerRoom.h"
#include "Identity.h"
#include "globalFile.h"


class Teacher : public Identity
{
    public:
        //默认构造
        Teacher();

        //析构函数
        virtual ~Teacher();

        //带参构造  （职工编号，姓名，密码）
        Teacher(int tchId, string name, string pwd);

        //菜单界面
        void openMenu();

        //查看所有预约
        void showAllOrder();

        //审核预约
        void validOrder();

        int m_TeacherId;     //教师职工号

    protected:

    private:
};

#endif // TEACHER_H
