#ifndef COMPUTERROOM_H_INCLUDED
#define COMPUTERROOM_H_INCLUDED

#pragma once      //防止头文件重复包含的错误

#include <iostream>
using namespace std;

//机房类
class ComputerRoom
{
public:

    int m_ComId;        //计算机的id号

    int m_ComMaxNum;     //机房最大容量
};


#endif // COMPUTERROOM_H_INCLUDED
