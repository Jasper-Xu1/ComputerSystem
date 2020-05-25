#ifndef ORDERFILE_H
#define ORDERFILE_H

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <windows.h>
#include "globalFile.h"

using namespace std;

//这是一个预约记录的文件,当要显示预约记录时，需要从文件中获取到所有的记录，用来显示，创建预约类来管理记录以及更新
//主要用途就是打印预约全部的信息，因为保存在预约文件中的信息有不同类型，所以当要打印学生信息和教师信息时，
//    就需要对预约文件中的信息，进行拆分。因为数据量大，所以要创建预约类
//预约类
class OrderFile
{
    public:
        //构造函数
        OrderFile();
        //析构函数
        virtual ~OrderFile();

        //更新预约记录
        void updateOrder();

        //记录预约的条数
        int m_Size;

        //记录所有预约信息的容器     key记录条数，   value具体记录键值对信息
        //这是双层嵌套调用，map<string key,string value>    这个key表示第一个类型值，第二个value表示类型数据
        map<int,map<string,string>> m_orderData;

};

#endif // ORDERFILE_H
