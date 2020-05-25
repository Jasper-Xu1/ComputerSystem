/*
 *�ļ���
 *�� ��
 *�� ��
 *ʱ ��
 *�� Ȩ
 */
#include "teacher.h"

Teacher::Teacher()
{
    //ctor
}

//���ι���  ��ְ����ţ����������룩
Teacher::Teacher(int tchId, string name, string pwd)
{
    this->m_TeacherId = tchId;
    this->m_Name = name;
    this->m_Pwd = pwd;
}

//�˵�����
void Teacher::openMenu()
{
    cout << "��ӭ��ʦ," << this->m_Name << "��¼!" << endl;
    cout << "\t\t -------------------------------------------- \n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 1.�鿴����ԤԼ             |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 2.���ԤԼ                 |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 0.ע����¼                 |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t -------------------------------------------- \n";
    cout << "��ѡ�����Ĳ�����" << endl;;

}

//�鿴����ԤԼ
void Teacher::showAllOrder()
{
    OrderFile of;
    if(of.m_Size == 0)
    {
        cout << "��ԤԼ��¼" << endl;
        system("pause");
        system("cls");
        return ;
    }

    for(int i = 0; i < of.m_Size; i++)
    {
        cout << i + 1 << "��";
        cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"] << "  ";
        cout << "ʱ���:" << of.m_orderData[i]["interval"] << "  ";
        cout << "ѧ��:" << of.m_orderData[i]["stuId"] << "  ";
        cout << "����:" << of.m_orderData[i]["stuName"] << "  ";
        cout << "������:" << of.m_orderData[i]["roomId"] << "  ";
        string status = "״̬:" ;
        //�ĸ�״̬�� 1 �����   2 ԤԼ�ɹ�   -1 ԤԼʧ��   0 ȡ��ԤԼ
        if(of.m_orderData[i]["status"] == "1")
        {
            status += "�����";
        }
        else if(of.m_orderData[i]["status"] == "2")
        {
            status += "ԤԼ�ɹ�";
        }
        else if(of.m_orderData[i]["status"] == "0")
        {
            status += "ԤԼ��ȡ��";
        }
        else if(of.m_orderData[i]["status"] == "-1")
        {
            status += "���δͨ����ԤԼʧ��";
        }
        cout << status << endl;
    }
    system("pause");
    system("cls");
}

//���ԤԼ
void Teacher::validOrder()
{
    OrderFile of;
    if(of.m_Size == 0)
    {
        cout << "��ԤԼ��¼" << endl;
        system("pause");
        system("cls");
        return ;
    }

    int index = 1;      //���������ʾ��ӡ���ļ�¼�����
    vector<int>w;
    cout << "����˵�ԤԼ��¼���£�" << endl;
    for(int i = 0 ; i < of.m_Size; i++)
    {
        //ֻ��ӡ������˵���Ϣ
        if(of.m_orderData[i]["status"] == "1")
        {
            w.push_back(i);
            cout << index++ << "��";
            cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"] << "  ";
            cout << "ʱ���:" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << "  ";
            cout << "ѧ�����:" << of.m_orderData[i]["stuId"] << "  ";
            cout << "ѧ������:" << of.m_orderData[i]["stuName"] << "  ";
            cout << "������:" << of.m_orderData[i]["roomId"] << "  ";
            //string status = "״̬: �����";
            string status = "״̬:";
            if(of.m_orderData[i]["status"] == "1")
            {
                status += "�����";
            }
            cout << status << endl;
        }
    }


    cout << "������Ҫ������ԤԼ��¼��ţ���0�����˳�" << endl;
    int select = 0;      //���ڽ�������
    int ret = 0;       //���ڽ�����˵Ľ��

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
                cout << "��������˵Ľ��" << endl;
                cout << "1��ͨ��" << endl;
                cout << "2����ͨ��" << endl;
                cin >> ret;
                if(ret == 1)
                {
                    //ͨ�������  ,��״̬��ֵ��Ϊ2 ���ͨ��
                    of.m_orderData[w[select - 1]]["status"] = "2";
                }
                else
                {
                    //��ͨ�������    ��״̬��ֵ��Ϊ-1 ����˲�ͨ��
                    of.m_orderData[w[select - 1]]["status"] = "-1";
                }
                of.updateOrder();      //����ԤԼ�ļ�¼
                cout << "������" << endl;
                break;
            }
        }
        cout << "������������������" << endl;
    }

    system("pause");
    system("cls");
}

Teacher::~Teacher()
{
    //dtor
}
