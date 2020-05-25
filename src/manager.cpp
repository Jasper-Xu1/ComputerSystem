/*
 *文件名
 *描 述
 *作 者
 *时 间
 *版 权
 */
#include "manager.h"

Manager::Manager()
{
    //ctor
}

//带参构造  (管理员姓名，密码)
Manager::Manager(string name, string pwd)
{
    //初始化管理员信息
    this->m_Name = name;
    this->m_Pwd = pwd;

    //初始化容器   获取到所有文件 的老师、学生信息,机房信息
    this->initVector();
}

//选择菜单
void Manager::openMenu()
{
    cout << "欢迎管理员," << this->m_Name << "登录!" << endl;
    cout << "\t\t -------------------------------------------- \n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 1.添加账号                 |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 2.查看账号                 |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 3.查看机房                 |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 4.清空预约                 |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 0.注销登录                 |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t -------------------------------------------- \n";
    cout << "请选择您的操作：" << endl;;

}

//添加账号，  添加学生信息，添加教师信息
void Manager::addPerson()
{
    cout << "请输入要添加账号类型" << endl;
    cout << "1、添加学生" << endl;
    cout << "2、添加老师" << endl;

    string fileName;    //操作的文件名,先随便定义一个，后面可以再具体到哪个文件，
    string tip;       //提示id号
    string errorTip;    //表示重复的错误提示

    //写入文件
    ofstream ofs;     //文件操作对象

    int select = 0;
    cin >> select;    //接收用户的选项

    if(select == 1)
    {
        //添加的是学生
        fileName = STUDENT_FILE;      //这里也可以和前面54行的一起定义
        tip = "请输入学号：";
        errorTip = "学号重复，请重新输入：";
    }
    else if(select == 2)
    {
        //添加的是教师
        fileName = TEACHER_FILE;
        tip = "请输入职工编号：";
        errorTip = "职工号重复，请重新输入：";
    }
    else
    {
        cout << "您输入的有误，请重新输入" << endl;
        cin >> select;
    }

    //利用追加的方式  写文件
    ofs.open(fileName,ios::out | ios::app);

    int id;    //学号 ，职工号
    string name;    //姓名
    string pwd;    //将要写入的信息

    cout << tip << endl;     //这输入的有两种，一种是学号，另一种是职工号

    while(true)     //只要输入了，就全都是真，进入死循环，只要就是判断是否重复，不重复才break继续下去
    {
        cin >> id;

        bool ret = this->checkRepeat(id,select);
        if(ret)
        {
            cout << errorTip << endl;   //当它为真时，则表示重复了
        }
        else
        {
            break;        //else是不为真，则不重复，直接break退出循环了
        }
    }

    cout << "请输入姓名：" << endl;
    cin >> name;

    cout << "请输入密码：" << endl;
    cin >> pwd;

    //向文件中添加数据
    ofs << id << "  " << name << "  " << pwd << "\n";
    cout << "添加成功!" << endl;

    system("pause");
    system("cls");

    ofs.close();

    this->initVector();    //添加完信息后，也要重新进行一次初始化遍历，防止连续输入的信息重复
}

void PrintStudent(Student & s)     //打印学生信息
{
    cout << "学号:" << s.m_Id << "\t|" << "姓名：" << s.m_Name << "\t|" << "密码：" << s.m_Pwd << "\t|" << endl;
}

void PrintTeacher(Teacher & t)     //打印教师信息
{
    cout << "职工号:" << t.m_TeacherId << "\t|" << "姓名：" << t.m_Name << "\t|" << "密码：" << t.m_Pwd << "\t|" << endl;
}

//查看账号
void Manager::showPerson()
{
    cout << "请选择你要查看的内容：" << endl;
    cout << "1、查看所有学生" << endl;
    cout << "2、查看所有教师" << endl;

    int select = 0;     //输入一个数，用来接收用户的输入
    cin >> select;

    if(select == 1)
    {
        cout << "所有学生的信息如下：" << endl;
        for_each(vStu.begin() , vStu.end(), PrintStudent);    //这里使用for_each算法来遍历vector数组中的学生信息
    }                                                      //也可以使用for循环遍历
    else
    {
        cout << "所有教师的信息如下：" << endl;
        for_each(vTea.begin(), vTea.end(), PrintTeacher);
    }
    system("pause");
    system("cls");
}

//查看机房信息
void Manager::showComputer()
{
    cout << "机房的信息如下：" << endl;

    for(vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
    {
        cout << "机房编号：" << it->m_ComId << " \t| " << "机房最大容量:" << it->m_ComMaxNum << "\t|" << endl;
    }
    system("pause");
    system("cls");
}

//清空预约记录
void Manager::cleanFile()
{
    //ofstream是写入，前提就是打开文件，所以就不用open了
    ofstream ofs(ORDER_FILE, ios::trunc);    //trunc是删除文件中内容，并创建新的文件
    ofs.close();

    cout << "清空成功！" << endl;
    system("pause");
    system("cls");
}

//初始化容器
void Manager::initVector()
{
    //先对两个vector数据进行清空
    vStu.clear();
    vTea.clear();
    vCom.clear();

    //读取信息    学生  老师
    ifstream ifs;
    ifs.open(STUDENT_FILE,ios::in);   //打开并读取学生文件
    if(!ifs.is_open())
    {
        cout << "文件读取失败!" << endl;
        return ;
    }
    Student s;
    while(ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)    //读取文件中学生数据
    {
        vStu.push_back(s);    //将读取到的学生数据，依次放到vector学生容器中
    }
    cout << "当前学生数量：" << vStu.size() << endl;    //顺便打印出学生的人数
    ifs.close();         //操作完，要记得关闭学生文件

    ifs.open(TEACHER_FILE,ios::in);     //打开并读取教师文件
    //因为上面对打开文件做了可行性判断了，所以这里就用再进行判断了
    Teacher t;
    while(ifs >> t.m_TeacherId && ifs >> t.m_Name && ifs >> t.m_Pwd)
    {
        vTea.push_back(t);     //将读取到的老师的数据，push——back到教师vector容器中
    }
    cout << "当前教师的数量：" << vTea.size() << endl;
    ifs.close();      //关闭文件


    //读取机房的信息，并将机房的信息存储到vector机房数组中，方便后续进行添加、修改使用
    ifs.open(COMPUTER_FILE,ios::in);    //打开并读取机房文件的信息
    ComputerRoom com;
    while(ifs >> com.m_ComId && ifs >> com.m_ComMaxNum)
    {
        vCom.push_back(com);
    }
    cout << "当前机房内电脑的数量：" << vCom.size() << endl;
    ifs.close();       //关闭文件

}

//检测重复      参数（传入id，传入类型） 返回值（true代表有重复，false代表没有重复）
bool Manager::checkRepeat(int id, int type)
{
    if(type == 1)     //当传入的类型是学生时
    {
        for(vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)   //使用迭代器来遍历学生的信息
        {
            if(id == it->m_Id)       //如果输入的id号和遍历到的id号相等，则表示重复了
            {
                return true;
            }
        }
    }
    else        //不考虑其他情况，除了学生，就是老师
    {
        for(vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)    //这里不能用++it，只能用it++  ？
        {
            if(id == it->m_TeacherId)
            {
                return true;
            }
        }
    }
    return false;
}

//学生容器

//教师容器

Manager::~Manager()
{
    //dtor
}
