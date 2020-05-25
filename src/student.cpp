/*
 *文件名
 *描 述
 *作 者
 *时 间
 *版 权
 */
#include "student.h"

Student::Student()
{
    //ctor
}

//有参构造     参数: 学号  姓名  密码
Student::Student(int id, string name, string pwd)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_Pwd = pwd;

    //初始化容器
    this->initVector();
}

//机房的容器
//vector<ComputerRoom> vCom;

//初始化机房容器
void Student::initVector()
{
    ifstream ifs;
    ifs.open(COMPUTER_FILE,ios::in);     //读取机房文件的信息
    ComputerRoom com;                   //机房文件的参数,用它来表示机房文件中的数据
    while(ifs >> com.m_ComId && ifs >> com.m_ComMaxNum)
    {
        //将从机房文件中读取到的信息放入到  机房容器中
        vCom.push_back(com);
    }
    ifs.close();
}

//菜单界面
void Student::openMenu()
{
    cout << "欢迎学生代表," << this->m_Name << "登录!" << endl;
    cout << "\t\t -------------------------------------------- \n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 1.申请预约                 |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 2.查看我的预约             |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 3.查看所有预约             |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 4.取消预约                 |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 0.注销登录                 |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t -------------------------------------------- \n";
    cout << "请选择您的操作：" << endl;;

}


//申请预约
void Student::applyOrder()
{
    cout << "机房开放的时间为周一至周五！" << endl;
    cout << "请输入申请预约的时间：" << endl;
    cout << "-------------------------" << endl;
    cout << "|        1、周一        |" << endl;
    cout << "|        2、周二        |" << endl;
    cout << "|        3、周三        |" << endl;
    cout << "|        4、周四        |" << endl;
    cout << "|        5、周五        |" << endl;
    cout << "-------------------------" << endl;

    int date = 0;       //用于接收 日期
    int interval = 0;    //用于接收 时间段
    int room = 0;        //用于接收 机房编号

    while(true)
    {
        cin >> date;
        if(date >= 1 && date <= 5)
        {
            break;
        }
        else
        {
            cout << "输入有误，请重新输入" << endl;
        }
    }

    cout << "请输入申请预约的时间段：" << endl;
    cout << "-------------------------" << endl;
    cout << "|        1、上午        |" << endl;
    cout << "|        2、下午        |" << endl;
    cout << "-------------------------" << endl;
    while(true)
    {
        cin >> interval;
        if(interval >= 1 && interval <= 2)
        {
            break;
        }
        else
        {
            cout << "输入有误，请重新输入" << endl;
        }
    }

    cout << "请输入申请预约的机房号：" << endl;
    cout << "-------------------------" << endl;
    for(int i = 0; i < vCom.size(); i++)
    {
        //vCom[i]表示第i个房间
        cout << vCom[i].m_ComId << "号机房的容量为：" << vCom[i].m_ComMaxNum << endl;
    }
    cout << "-------------------------" << endl;
    while(true)
    {
        cin >> room;
        if(room >= 1 && room <= 3)
        {
            break;
        }
        else
        {
            cout << "输入有误，请重新输入" << endl;
        }
    }

    cout << "预约成功，审核中！" << endl;

    //然后将申请的记录信息写入到 预约的文件中    ios::app也是可以打开文件的，就不用写open了
    ofstream ofs(ORDER_FILE,ios::app);

    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuId:" << this->m_Id << " ";
    ofs << "stuName:" << this->m_Name << " ";
    ofs << "roomId:" << room << " ";
    ofs << "status:" << 1 << endl;

    ofs.close();
    system("pause");
    system("cls");
}

//查看自身预约
void Student::showOrder()
{
    OrderFile of;      //创建的一个预约类的对象，它表示预约文件的内容
    if(of.m_Size == 0)
    {
        cout << "无预约记录！" << endl;
        system("pause");
        system("cls");
        return ;
    }

    for(int i = 0; i < of.m_Size; i++)
    {
        //of.orderData[i]["stuId"] 是string类型的数据，   m_Id是int类型的数据
        //string 利用 .c_str()来将C++中的string类型转为C中的string类型；  即转为 const char*
        //再利用atoi（const char*）将C中的   string类型转换为int类型
//        if(this->m_Name == of.m_orderData[i]["stuId"].c_str());   不能查找姓名，因为可能有重名的人
        if(this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))   //根据   id学号找到对应的自身预约
        {
            cout << "预约日期：周" << of.m_orderData[i]["date"] << "\n";
            cout << "时 间 段:" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << "\n";
            cout << "机 房 号:" << of.m_orderData[i]["roomId"] << "\n";
            string status = "状   态:";
            //四个状态： 1 审核中   2 预约成功   -1 预约失败   0 取消预约
            if(of.m_orderData[i]["status"] == "1")
            {
                status += "审核中";
            }
            else if(of.m_orderData[i]["status"] == "2")
            {
                status += "预约成功";
            }
            else if(of.m_orderData[i]["status"] == "-1")
            {
                status += "审核未通过，预约失败";
            }
            else
            {
                status += "取消预约";
            }
            cout << status << endl;
            cout << endl;
         }
    }
    system("pause");
    system("cls");
}

//查看所有预约
void Student::showAllOrder()
{
    OrderFile of;          //创建的一个预约类的对象
    if(of.m_Size == 0)
    {
        cout << "无预约记录!" << endl;
        system("pause");
        system("cls");
        return ;
    }

    for(int i = 0; i < of.m_Size; i++)
    {
        cout << i + 1 << ":\n";
        cout << "预约日期：周" << of.m_orderData[i]["date"] << "\n";
        cout << "时 间 段:" << of.m_orderData[i]["interval"] << "\n";
        cout << "学    号:" << of.m_orderData[i]["stuId"] << "\n";
        cout << "姓    名:" << of.m_orderData[i]["stuName"] << "\n";
        cout << "机 房 号:" << of.m_orderData[i]["roomId"] << "\n";
        string status = "状   态:" ;
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
        cout << endl;
    }
    system("pause");
    system("cls");
}

//取消预约
void Student::cancelOrder()
{
    OrderFile of;
    if(of.m_Size == 0)
    {
        cout << "无预约记录";
        system("pause");
        system("cls");
        return ;
    }

    cout << "审核中或预约成功的记录均可以取消，请输入要取消的记录编号" << endl;
    vector<int>w;      //存放在最大容器中的下标编号
    int index = 1;     //一个从1开始的参数，当不同学生的预约记录分开时，可以用index来表示记录的下标
    for(int i = 0; i < of.m_Size; i++)
    {
        //先判断是自身学号
        if(this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
        {
            //在筛选 审核中 或 预约成功的两种状态
            if(of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
            {
                //虽然张三的预约记录不是按顺序的，但是遍历出来的可以用index下标表示，就是按顺序的
                cout << index++ << "、 ";
                w.push_back(i);    //将遍历到符合的行 下标（i），放到vector容器中
                cout << "预约日期：周" << of.m_orderData[i]["date"] << "  ";
                cout << "时间段:" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << "  ";
                cout << "机房号:" << of.m_orderData[i]["roomId"] << "  ";
                string status = "状态:";
                if(of.m_orderData[i]["status"] == "1")
                {
                    status += "审核中";
                }
                else if(of.m_orderData[i]["status"] == "2")
                {
                    status += "预约成功";
                }
                cout << status << endl;
            }
        }
    }


    cout << "请输入要取消的记录编号，0代表返回" << endl;   //这个编号就是index的值
    int select = 0;

    while(true)
    {
        cin >> select;
        if(select >= 0 && select <= w.size())
        {
            if(select == 0)
            {
                return ;   //break;
            }
            else
            {
                //w[select - 1] select-1输入的行对应的行就是要删除的位置
                of.m_orderData[w[select - 1]]["status"] = "0";

                of.updateOrder();

                cout << "已取消预约" << endl;
                return ;      //break;
            }
        }
        cout << "输入有误，请重新输入：" << endl;
    }

    system("pause");
    system("cls");
}

Student::~Student()
{
    //dtor
}
