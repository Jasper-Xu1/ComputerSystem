/*
 *文件名
 *描 述
 *作 者
 *时 间
 *版 权
 */
#include "orderFile.h"


//构造函数
OrderFile::OrderFile()
{
    ifstream ifs;
    ifs.open(ORDER_FILE,ios::in);    //打开读取文件信息

    string date;         //日期
    string interval;     //时间段
    string stuId;        //学生学号
    string stuName;      //学生姓名
    string roomId;       //机房编号
    string status;       //预约状态

    this->m_Size = 0;    //预约记录的条数

    while(ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName
          && ifs >> roomId && ifs >> status)
    {

            //这是验证文件中的预约记录信息是否能准确读取出来
            //        cout << date << endl;
            //        cout << interval << endl;
            //        cout << stuId << endl;
            //        cout << stuName << endl;
            //        cout << roomId << endl;
            //        cout << status << endl;
            //        cout << endl;

        //这上面直接打印的是  一个键值对   即date：1，
        //但现在要把这个键值对 冒号前后的两个数据分开，一个截取给key，后面一个截取给value
        //这样面对大量数据的时候，就都可以有序的打印出来了

        //如下面这样的，使用map<>数组存放不同的数据，使用substr来截取两个数据
        string key;
        string value;
        map<string,string> m;      //这是存放记录的一个容器

        //截取日期数据
        int pos = date.find(":");    //find 是vector里面你的函数
        if(pos != -1)
        {
            key = date.substr(0,pos);         //substr（），substr中有两个参数，表示在date从0开始截取pos位个字符
            value = date.substr(pos + 1, date.size() - pos - 1);      //再来截取value的数值

            //这是截取出第一个date的数据
            //cout << "key = " << key << endl;
            //cout << "value = " << value << endl;

            //下面要截取所有的数据

            m.insert(make_pair(key,value));     //插入到map容器中，使用make_pair创建一个队组
        }

        //截取时间段
        pos = interval.find(":");
        if(pos != -1)
        {
            key = interval.substr(0,pos);                                 //截取到key的数据
            value = interval.substr(pos + 1, interval.size() - pos - 1);   //截取到value的数据
            m.insert(make_pair(key,value));              //插入到map容器中，并且要用make_pair创建一个队组让两个数组对应
        }

        //截取学生的学号
        pos = stuId.find(":");
        if(pos != -1)
        {
            key = stuId.substr(0,pos);
            value = stuId.substr(pos + 1, stuId.size() - pos - 1);
            m.insert(make_pair(key,value));
        }

        //截取学生的姓名
        pos = stuName.find(":");
        if(pos != -1)
        {
            key = stuName.substr(0,pos);
            value = stuName.substr(pos + 1, stuName.size() - pos - 1);
            m.insert(make_pair(key,value));
        }

        //截取机房的编号
        pos = roomId.find(":");
        if(pos != -1)
        {
            key = roomId.substr(0,pos);
            value = roomId.substr(pos + 1, roomId.size() - pos - 1);
            m.insert(make_pair(key,value));
        }

        //截取预约状态
        pos = status.find(":");
        if(pos != -1)
        {
            key = status.substr(0,pos);
            value = status.substr(pos + 1, status.size() - pos - 1);
            m.insert(make_pair(key,value));
        }

        //将小的map容器中的不同种类的数据，全都放到大的map容器中
        this->m_orderData.insert(make_pair(this->m_Size,m));
        this->m_Size++;            //依次将小map容器放入到大的map容器m_orderData中，每加一次，Size预约记录条数加1

    }
    ifs.close();

//    //测试最大的map容器
//    cout << "查看全部详细信息" << endl;
//    for(map<int,map<string,string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
//    {
//        cout << "条数为：" << it->first << " ,value的值为:" << endl;
//        for(map<string ,string>::iterator mit = (*it).second.begin(); mit != it->second.end(); mit++)
//        {
//            cout << " key = " << mit->first << "\t" << " value = " << mit->second << "\n";
//        }
//        cout << endl;
//    }
//
//    cout << "点击任意键查看关键信息" << endl;
 //   system("pause");
 //   system("cls");
}


//更新预约记录  ---即 将文件中所有预约信息重新打印一遍
void OrderFile::updateOrder()
{
    if(m_Size == 0)
    {
        return ;     //预约记录为0，直接return
    }

    ofstream ofs(ORDER_FILE, ios::out | ios::trunc);    //用out的方式告诉它要写，删除原文件的的数据，并创建一个新的文件
    for(int i = 0; i < m_Size; i++)
    {
        ofs << "date:" << this->m_orderData[i]["date"] << " ";     //也可以这样看  (m_orderData[0])这表示第1行，
        ofs << "interval:" << this->m_orderData[i]["interval"] << " ";      //因为底层还是一个容器，所以也可以用中括号表示
        ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";           //即 (m_orderData[0])["date"]
        ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
        ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
        ofs << "status:" << this->m_orderData[i]["status"] << " " << endl;
    }
    ofs.close();
}



//析构函数
OrderFile::~OrderFile()
{
    //dtor
}
