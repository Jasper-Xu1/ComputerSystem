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
        //Ĭ�Ϲ���
        Student();

        //�вι���     ����: ѧ��  ����  ����
        Student(int id, string name, string pwd);

        //�˵�����
        void openMenu() override;

        //����ԤԼ
        void applyOrder();

        //�鿴����ԤԼ
        void showOrder();

        //�鿴����ԤԼ
        void showAllOrder();

        //ȡ��ԤԼ
        void cancelOrder();

        //ѧ��ѧ��
        int m_Id;

        //��ʼ��������������Ϊ����ԤԼ��Ҫ֪�����������������Ҫ����һ��������vector����
        //���ǳ�ʼ��������װ��Ҳ���Բ���װ��   ����ֱ���ڹ��캯���г�ʼ��,���ߵ��ó�ʼ������
        void initVector();

        //����������
        vector<ComputerRoom> vCom;

        //��������
        virtual ~Student();

    protected:

    private:
};

#endif // STUDENT_H
