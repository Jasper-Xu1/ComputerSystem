#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <windows.h>
#include <vector>
#include "Identity.h"
#include "orderFile.h"
#include "computerRoom.h"
#include "Identity.h"
#include "globalFile.h"


class Teacher : public Identity
{
    public:
        //Ĭ�Ϲ���
        Teacher();

        //��������
        virtual ~Teacher();

        //���ι���  ��ְ����ţ����������룩
        Teacher(int tchId, string name, string pwd);

        //�˵�����
        void openMenu();

        //�鿴����ԤԼ
        void showAllOrder();

        //���ԤԼ
        void validOrder();

        int m_TeacherId;     //��ʦְ����

    protected:

    private:
};

#endif // TEACHER_H
