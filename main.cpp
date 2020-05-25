#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include "Identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include "globalFile.h"

using namespace std;

//全局函数--进入管理员子菜单界面 ,参数是多态  用父类的指针创建子类对象，然后调用子类接口，调用管理员菜单
void managerMenu(Identity * &manager)

/** 为什么这样定义参数    因为在刚开始的初始界面中，manager是子类，由基类调用，即用Identity调用，
    但当manager->openMenu()后，就进入到管理员的子菜单中，这时基类就变成了Manager，
    需要用Manager来调用Manager子类中的函数，
    因为调用函数的基类变了，所以调用子菜单中的函数时，不能只换参数，而且要换参数类型，这时就需要用到强转 来改变类型
*/
{
    while(true)  //设置一个死循环，只有点0 注销，才能退出
    {
        //调用管理员子菜单
        manager->openMenu();

        //将父类指针 转换为子类指针，然后才能去调用子类里的其他接口
        Manager * man = (Manager *)manager;

        int select = 0;
        //接收用户的选项
        cin >> select;

        if(select == 1)    //添加账号
        {
            cout << "1.添加账号" << endl;
            man->addPerson();
        }
        else if(select == 2)    //查看账号
        {
            cout << "查看账号" << endl;
            man->showPerson();
        }
        else if(select == 3)    //查看机房
        {
            cout << "查看机房" << endl;
            man->showComputer();
        }
        else if(select == 4)     //清空预约
        {
            cout << "清空预约" << endl;
            man->cleanFile();
        }
        else if(select == 0)
        {
            //注销
            delete manager;     //销毁掉堆区对象
            cout << "注销成功！" << endl;
            system("pause");
            system("cls");
            return ;
        }
        else
        {
            cout << "您输入的有误，您还有一次机会，请重新输入：\n";
            cout << "请选择您的操作：";
            cin >> select;
        }
    }
}

//全局函数--进入学生子菜单界面， 参数是多态  用父类的指针创建子类对象，然后调用子类接口，调用学生类菜单
void studentMenu(Identity * &student)     //student是父类中定义的一个指向子类的参数
{
    while(true)      //设置一个死循环，当输入任意非0值时，都进入循环判断
    {
        //学生菜单
        student->openMenu();    //调用student子类中的方法,

        Student * stu = (Student *)student;   //把这个父类中的参数（小写的student），强转成子类中的参数
        int select = 0;     //用来接收用户的输入
        cin >> select;

        switch(select)
        {
        case 1:
            {
                //申请预约
                stu->applyOrder();
                break;
            }
        case 2:
            {
                //查看自身预约
                stu->showOrder();
                break;
            }
        case 3:
            {
                 //查看所有预约
                stu->showAllOrder();
                break;
            }
        case 4:
            {
               //取消预约
                stu->cancelOrder();
                break;
            }
        case 0:
            {
                //注销登录
                delete stu;
                cout << "注销成功" << endl;
                system("pause");
                system("cls");
                return ;
                break;
            }
        default:
            {
                cout << "输入有误，还有一次输入机会：" << endl;
                cin >> select;
            }
        }
    }
}


//全局函数--进入教师子菜单界面，参数是多态   用父类的指针创建子类对象，然后调用子类接口，调用教师类菜单
void teacherMenu(Identity * &teacher)
{
    while(true)    //用一个死循环，只有当注销时才会退出
    {
        //教师菜单
        teacher->openMenu();     //调用子类的对象

        Teacher * tea = (Teacher *)teacher;       //将父类指针强转成子类指针，
        int select = 0;     //接收用户的选择
        cin >> select;

        if(select == 1)
        {
            //查看所有预约
            tea->showAllOrder();
        }
        else if(select == 2)
        {
            //审核预约
            tea->validOrder();
        }
        else if(select == 0)
        {
            //注销登录
            delete tea;
            cout << "注销成功!" << endl;
            system("pause");
            system("cls");
            return ;
        }
        else
        {
            cout << "输入有误，您还有一次机会输入：" << endl;
            cin >> select;
        }

    }
}


//全局函数--实现登录功能的函数   参数1 操作名文件   参数2 操作身份类型
void LoginIn(const string fileName, int type)
{
    //先定义一个父类指针，可以用于指向子类对象
    Identity * person = NULL;

    //读文件
    ifstream ifs;
    ifs.open(fileName,ios::in);

    //判断文件是否存在,文件不存在的情况
    if(!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }

    //准备接收用户输入的信息
    int id = 0;
    string name;
    string pwd;

    //判断输入的是什么身份     ,登录的接口
    if(type == 1)     //学生登录
    {
        cout << "请输入您的学号：" << endl;
        cin >> id;
    }
    else if(type == 2)     //教师登录
    {
        cout << "请输入您的职工号：" << endl;
        cin >> id;
    }

    cout << "请输入您的用户名：" << endl;
    cin >> name;
    cout << "请输入您的密码: " << endl;
    cin >> pwd;

    //输入之后，要对输入的数据进行验证，判断账号名和密码是否出错
    if(type == 1)           //登录信息的验证
    {
        //学生身份的验证
        int fId;
        string fName;
        string fPwd;      //这三个数据是从文件中获取的数据

        while(ifs >> fId && ifs >> fName && ifs >> fPwd)
            //使用ifs依次遍历出文件中的信息，
            //利用右移的方式一个一个将所有信息读到，它按照一行一行的读取，当遇到空格时就会暂停，
            //所以依次将编号，姓名和密码读取出来，然后去和录入的信息对比
        {
            if(id == fId && name == fName && pwd == fPwd)
            //当从文件中读取的数据和用户输入的数据相同时，即学生个人信息验证通过
            {
                cout << "学生信息验证通过，登录成功！" << endl;
                system("pause");
                system("cls");

                //学生登录成功后，就会在 堆中（系统）中创建一个学生的信息，以便后续进行操作
                person = new Student(id,name,pwd);    //创建一个学生信息的子菜单
                //进入学生菜单
                studentMenu(person);

                return ;
            }
        }
        //当找不到时，再往下一个循环去找，只有等所有数据都找完，都没有相等的，才会确定登录失败
        //所以上面while循环里没有break，只有当遍历完才能退出
        cout << "学生信息有误，请重新输入：" << endl << endl;
    }
    else if(type == 2)
    {
        //教师身份的验证
        int fId;
        string fName;
        string fPwd;     //从文件中获取的教师的个人信息

        while(ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if(id == fId && name == fName && pwd == fPwd)
            {
                cout << "教师信息验证通过，登录成功!" << endl;
                system("pause");
                system("cls");

                person = new Teacher(id,name,pwd);     //创建一个教师的子目录
                //进入教师子菜单
                teacherMenu(person);

                return ;
            }
        }
        cout << "教师信息有误，请重新输入：" << endl <<endl;
    }
    else if(type == 3)
    {
        //管理员身份的验证
        string fName;
        string fPwd;
        while(ifs >> fName && ifs >> fPwd)
        {
            if(name == fName && pwd == fPwd)
            {
                cout << "管理员信息验证通过，登陆成功！" << endl;
                //登录成功后，按任意键进入管理员界面
                system("pause");
                system("cls");

                //创建管理员对象
                person = new Manager(name,pwd);
                //进入管理员菜单
                managerMenu(person);

                return ;
            }
        }
        cout << "管理员信息有误，请重新输入：" << endl << endl;
    }
    else   //这个else也可以不写
    {
        cout << "登录验证失败!" << endl;
        system("pause");
        system("cls");
    }
    return;
}


int main()
{
    SetConsoleTitle("机房预约系统");
    int select = 0;        //用于接受用户的选择
    while(true)
    {
    cout << "========================  欢迎使用机房预约系统  ========================" << endl;
    cout << "请选择您的身份" << endl;
    cout << "\t\t -------------------------------------------- \n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 1.学生代表                 |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 2.教师                     |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 3.管理员                   |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 0.退出                     |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t -------------------------------------------- \n";
    cout << "请输入您的选择：";
    cin >> select;               //接受用户的选择

    switch(select)      //根据用户的选择来  实现不同的接口
    {
    case 1:       //选择学生身份
        LoginIn(STUDENT_FILE, 1);
        break;
    case 2:       //选择老师身份
        LoginIn(TEACHER_FILE,2);
        break;
    case 3:       //选择管理员身份
        LoginIn(ADMIN_FILE,3);
        break;
    case 0:       //选择退出
        cout << "欢迎下一次使用" << endl;
        system("pause");      //表示按任意键退出
        return 0;
        break;
    default:      //输入的命令不符合的情况
        cout << "您输入有误，请重新输入：\n";
        system("pause");      //表示按任意键退出
        system("cls");
        break;
    }
    }
    system("pause");         //表示按任意键退出
    return 0;
}


/**
遗留问题：当输入学号的时候，输入的不是数字，就会进入死循环
        给管理员添加删除学生信息的功能
*/
