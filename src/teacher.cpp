/*
 *文件名
 *描 述
 *作 者
 *时 间
 *版 权
 */
#include "teacher.h"

Teacher::Teacher()
{
    //ctor
}

//带参构造  （职工编号，姓名，密码）
Teacher::Teacher(int tchId, string name, string pwd)
{
    this->m_TeacherId = tchId;
    this->m_Name = name;
    this->m_Pwd = pwd;
}

//菜单界面
void Teacher::openMenu()
{
    cout << "欢迎教师," << this->m_Name << "登录!" << endl;
    cout << "\t\t -------------------------------------------- \n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 1.查看所有预约             |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 2.审核预约                 |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 0.注销登录                 |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t -------------------------------------------- \n";
    cout << "请选择您的操作：" << endl;;

}

//查看所有预约
void Teacher::showAllOrder()
{
    OrderFile of;
    if(of.m_Size == 0)
    {
        cout << "无预约记录" << endl;
        system("pause");
        system("cls");
        return ;
    }

    for(int i = 0; i < of.m_Size; i++)
    {
        cout << i + 1 << "、";
        cout << "预约日期：周" << of.m_orderData[i]["date"] << "  ";
        cout << "时间段:" << of.m_orderData[i]["interval"] << "  ";
        cout << "学号:" << of.m_orderData[i]["stuId"] << "  ";
        cout << "姓名:" << of.m_orderData[i]["stuName"] << "  ";
        cout << "机房号:" << of.m_orderData[i]["roomId"] << "  ";
        string status = "状态:" ;
        //四个状态： 1 审核中   2 预约成功   -1 预约失败   0 取消预约
        if(of.m_orderData[i]["status"] == "1")
        {
            status += "审核中";
        }
        else if(of.m_orderData[i]["status"] == "2")
        {
            status += "预约成功";
        }
        else if(of.m_orderData[i]["status"] == "0")
        {
            status += "预约已取消";
        }
        else if(of.m_orderData[i]["status"] == "-1")
        {
            status += "审核未通过，预约失败";
        }
        cout << status << endl;
    }
    system("pause");
    system("cls");
}

//审核预约
void Teacher::validOrder()
{
    OrderFile of;
    if(of.m_Size == 0)
    {
        cout << "无预约记录" << endl;
        system("pause");
        system("cls");
        return ;
    }

    int index = 1;      //用这个来表示打印出的记录的序号
    vector<int>w;
    cout << "待审核的预约记录如下：" << endl;
    for(int i = 0 ; i < of.m_Size; i++)
    {
        //只打印出待审核的信息
        if(of.m_orderData[i]["status"] == "1")
        {
            w.push_back(i);
            cout << index++ << "、";
            cout << "预约日期：周" << of.m_orderData[i]["date"] << "  ";
            cout << "时间段:" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << "  ";
            cout << "学生编号:" << of.m_orderData[i]["stuId"] << "  ";
            cout << "学生姓名:" << of.m_orderData[i]["stuName"] << "  ";
            cout << "机房号:" << of.m_orderData[i]["roomId"] << "  ";
            //string status = "状态: 审核中";
            string status = "状态:";
            if(of.m_orderData[i]["status"] == "1")
            {
                status += "审核中";
            }
            cout << status << endl;
        }
    }


    cout << "请输入要审批的预约记录编号，按0代表退出" << endl;
    int select = 0;      //用于接收输入
    int ret = 0;       //用于接收审核的结果

    while(true)
    {
        cin >> select;
        if(select >= 0 && select <= w.size())
        {
            if(select == 0)
            {
                system("pause");
                system("cls");
                break;
            }
            else
            {
                cout << "请输入审核的结果" << endl;
                cout << "1、通过" << endl;
                cout << "2、不通过" << endl;
                cin >> ret;
                if(ret == 1)
                {
                    //通过的情况  ,将状态的值设为2 审核通过
                    of.m_orderData[w[select - 1]]["status"] = "2";
                }
                else
                {
                    //不通过的情况    将状态的值设为-1 ，审核不通过
                    of.m_orderData[w[select - 1]]["status"] = "-1";
                }
                of.updateOrder();      //更新预约的记录
                cout << "审核完毕" << endl;
                break;
            }
        }
        cout << "输入有误，请重新输入" << endl;
    }

    system("pause");
    system("cls");
}

Teacher::~Teacher()
{
    //dtor
}
