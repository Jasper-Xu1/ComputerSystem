#ifndef IDENTITY_H
#define IDENTITY_H

#include <iostream>
#include <string>

using namespace std;

//�������
class Identity
{
    public:
        Identity();
        virtual ~Identity();

        //�����˵�
        virtual void openMenu() = 0;

        string m_Name;
        string m_Pwd;

};

#endif // IDENTITY_H
