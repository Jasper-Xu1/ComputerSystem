#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <windows.h>
#include <vector>
#include <fstream>
#include "computerRoom.h"
#include "Identity.h"
#include "globalFile.h"
#include "orderFile.h"

class Student : public Identity
{
    public:
        //默认构造
        Student();

        //有参构造     参数: 学号  姓名  密码
        Student(int id, string name, string pwd);

        //菜单界面
        void openMenu() override;

        //申请预约
        void applyOrder();

        //查看自身预约
        void showOrder();

        //查看所有预约
        void showAllOrder();

        //取消预约
        void cancelOrder();

        //学生学号
        int m_Id;

        //初始化机房容器，因为申请预约，要知道机房的情况，所以要设置一个机房的vector数组
        //这是初始化函数封装，也可以不封装，   可以直接在构造函数中初始化,或者调用初始化函数
        void initVector();

        //机房的容器
        vector<ComputerRoom> vCom;

        //析构函数
        virtual ~Student();

    protected:

    private:
};

#endif // STUDENT_H
