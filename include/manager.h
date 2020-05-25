#ifndef MANAGER_H
#define MANAGER_H

#include <fstream>
#include <vector>
#include <windows.h>
#include <algorithm>
#include "Identity.h"
#include "student.h"
#include "teacher.h"
#include "globalFile.h"
#include "computerRoom.h"

class Manager : public Identity
{
    public:
        //Ĭ�Ϲ���
        Manager();
        virtual ~Manager();

        //���ι���  (����Ա����������)
        Manager(string name, string pwd);

        //ѡ��˵�
        void openMenu();

        //����˺�
        void addPerson();

        //�鿴�˺�
        void showPerson();

        //void PrintStudent(Student & s);     //��ӡѧ����Ϣ
        //void PrintTeacher(Teacher & t);     //��ӡ��ʦ��Ϣ

        //�鿴������Ϣ
        void showComputer();

        //���ԤԼ��¼
        void cleanFile();

        //��ʼ������
        void initVector();

        //����ظ�      ����������id���������ͣ� ����ֵ��true�������ظ���false����û���ظ���
        //ȥ�غ����ķ�װ
        bool checkRepeat(int id, int type);

        //ѧ������
        vector<Student> vStu;

        //��ʦ����
        vector<Teacher> vTea;

        //��������
        vector<ComputerRoom> vCom;

    protected:

    private:
};

#endif // MANAGER_H
