#ifndef MANAGER_H
#define MANAGER_H

#include <fstream>
#include <vector>
#include <windows.h>
#include <algorithm>
#include "Identity.h"
#include "student.h"
#include "teacher.h"
#include "globalFile.h"
#include "computerRoom.h"

class Manager : public Identity
{
    public:
        //默认构造
        Manager();
        virtual ~Manager();

        //带参构造  (管理员姓名，密码)
        Manager(string name, string pwd);

        //选择菜单
        void openMenu();

        //添加账号
        void addPerson();

        //查看账号
        void showPerson();

        //void PrintStudent(Student & s);     //打印学生信息
        //void PrintTeacher(Teacher & t);     //打印教师信息

        //查看机房信息
        void showComputer();

        //清空预约记录
        void cleanFile();

        //初始化容器
        void initVector();

        //检测重复      参数（传入id，传入类型） 返回值（true代表有重复，false代表没有重复）
        //去重函数的封装
        bool checkRepeat(int id, int type);

        //学生容器
        vector<Student> vStu;

        //教师容器
        vector<Teacher> vTea;

        //机房容器
        vector<ComputerRoom> vCom;

    protected:

    private:
};

#endif // MANAGER_H
