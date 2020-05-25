/*
 *�ļ���
 *�� ��
 *�� ��
 *ʱ ��
 *�� Ȩ
 */
#include "student.h"

Student::Student()
{
    //ctor
}

//�вι���     ����: ѧ��  ����  ����
Student::Student(int id, string name, string pwd)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_Pwd = pwd;

    //��ʼ������
    this->initVector();
}

//����������
//vector<ComputerRoom> vCom;

//��ʼ����������
void Student::initVector()
{
    ifstream ifs;
    ifs.open(COMPUTER_FILE,ios::in);     //��ȡ�����ļ�����Ϣ
    ComputerRoom com;                   //�����ļ��Ĳ���,��������ʾ�����ļ��е�����
    while(ifs >> com.m_ComId && ifs >> com.m_ComMaxNum)
    {
        //���ӻ����ļ��ж�ȡ������Ϣ���뵽  ����������
        vCom.push_back(com);
    }
    ifs.close();
}

//�˵�����
void Student::openMenu()
{
    cout << "��ӭѧ������," << this->m_Name << "��¼!" << endl;
    cout << "\t\t -------------------------------------------- \n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 1.����ԤԼ                 |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 2.�鿴�ҵ�ԤԼ             |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 3.�鿴����ԤԼ             |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 4.ȡ��ԤԼ                 |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 0.ע����¼                 |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t -------------------------------------------- \n";
    cout << "��ѡ�����Ĳ�����" << endl;;

}


//����ԤԼ
void Student::applyOrder()
{
    cout << "�������ŵ�ʱ��Ϊ��һ�����壡" << endl;
    cout << "����������ԤԼ��ʱ�䣺" << endl;
    cout << "-------------------------" << endl;
    cout << "|        1����һ        |" << endl;
    cout << "|        2���ܶ�        |" << endl;
    cout << "|        3������        |" << endl;
    cout << "|        4������        |" << endl;
    cout << "|        5������        |" << endl;
    cout << "-------------------------" << endl;

    int date = 0;       //���ڽ��� ����
    int interval = 0;    //���ڽ��� ʱ���
    int room = 0;        //���ڽ��� �������

    while(true)
    {
        cin >> date;
        if(date >= 1 && date <= 5)
        {
            break;
        }
        else
        {
            cout << "������������������" << endl;
        }
    }

    cout << "����������ԤԼ��ʱ��Σ�" << endl;
    cout << "-------------------------" << endl;
    cout << "|        1������        |" << endl;
    cout << "|        2������        |" << endl;
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
            cout << "������������������" << endl;
        }
    }

    cout << "����������ԤԼ�Ļ����ţ�" << endl;
    cout << "-------------------------" << endl;
    for(int i = 0; i < vCom.size(); i++)
    {
        //vCom[i]��ʾ��i������
        cout << vCom[i].m_ComId << "�Ż���������Ϊ��" << vCom[i].m_ComMaxNum << endl;
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
            cout << "������������������" << endl;
        }
    }

    cout << "ԤԼ�ɹ�������У�" << endl;

    //Ȼ������ļ�¼��Ϣд�뵽 ԤԼ���ļ���    ios::appҲ�ǿ��Դ��ļ��ģ��Ͳ���дopen��
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

//�鿴����ԤԼ
void Student::showOrder()
{
    OrderFile of;      //������һ��ԤԼ��Ķ�������ʾԤԼ�ļ�������
    if(of.m_Size == 0)
    {
        cout << "��ԤԼ��¼��" << endl;
        system("pause");
        system("cls");
        return ;
    }

    for(int i = 0; i < of.m_Size; i++)
    {
        //of.orderData[i]["stuId"] ��string���͵����ݣ�   m_Id��int���͵�����
        //string ���� .c_str()����C++�е�string����תΪC�е�string���ͣ�  ��תΪ const char*
        //������atoi��const char*����C�е�   string����ת��Ϊint����
//        if(this->m_Name == of.m_orderData[i]["stuId"].c_str());   ���ܲ�����������Ϊ��������������
        if(this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))   //����   idѧ���ҵ���Ӧ������ԤԼ
        {
            cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"] << "\n";
            cout << "ʱ �� ��:" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << "\n";
            cout << "�� �� ��:" << of.m_orderData[i]["roomId"] << "\n";
            string status = "״   ̬:";
            //�ĸ�״̬�� 1 �����   2 ԤԼ�ɹ�   -1 ԤԼʧ��   0 ȡ��ԤԼ
            if(of.m_orderData[i]["status"] == "1")
            {
                status += "�����";
            }
            else if(of.m_orderData[i]["status"] == "2")
            {
                status += "ԤԼ�ɹ�";
            }
            else if(of.m_orderData[i]["status"] == "-1")
            {
                status += "���δͨ����ԤԼʧ��";
            }
            else
            {
                status += "ȡ��ԤԼ";
            }
            cout << status << endl;
            cout << endl;
         }
    }
    system("pause");
    system("cls");
}

//�鿴����ԤԼ
void Student::showAllOrder()
{
    OrderFile of;          //������һ��ԤԼ��Ķ���
    if(of.m_Size == 0)
    {
        cout << "��ԤԼ��¼!" << endl;
        system("pause");
        system("cls");
        return ;
    }

    for(int i = 0; i < of.m_Size; i++)
    {
        cout << i + 1 << ":\n";
        cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"] << "\n";
        cout << "ʱ �� ��:" << of.m_orderData[i]["interval"] << "\n";
        cout << "ѧ    ��:" << of.m_orderData[i]["stuId"] << "\n";
        cout << "��    ��:" << of.m_orderData[i]["stuName"] << "\n";
        cout << "�� �� ��:" << of.m_orderData[i]["roomId"] << "\n";
        string status = "״   ̬:" ;
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
        cout << endl;
    }
    system("pause");
    system("cls");
}

//ȡ��ԤԼ
void Student::cancelOrder()
{
    OrderFile of;
    if(of.m_Size == 0)
    {
        cout << "��ԤԼ��¼";
        system("pause");
        system("cls");
        return ;
    }

    cout << "����л�ԤԼ�ɹ��ļ�¼������ȡ����������Ҫȡ���ļ�¼���" << endl;
    vector<int>w;      //�������������е��±���
    int index = 1;     //һ����1��ʼ�Ĳ���������ͬѧ����ԤԼ��¼�ֿ�ʱ��������index����ʾ��¼���±�
    for(int i = 0; i < of.m_Size; i++)
    {
        //���ж�������ѧ��
        if(this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
        {
            //��ɸѡ ����� �� ԤԼ�ɹ�������״̬
            if(of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
            {
                //��Ȼ������ԤԼ��¼���ǰ�˳��ģ����Ǳ��������Ŀ�����index�±��ʾ�����ǰ�˳���
                cout << index++ << "�� ";
                w.push_back(i);    //�����������ϵ��� �±꣨i�����ŵ�vector������
                cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"] << "  ";
                cout << "ʱ���:" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << "  ";
                cout << "������:" << of.m_orderData[i]["roomId"] << "  ";
                string status = "״̬:";
                if(of.m_orderData[i]["status"] == "1")
                {
                    status += "�����";
                }
                else if(of.m_orderData[i]["status"] == "2")
                {
                    status += "ԤԼ�ɹ�";
                }
                cout << status << endl;
            }
        }
    }


    cout << "������Ҫȡ���ļ�¼��ţ�0������" << endl;   //�����ž���index��ֵ
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
                //w[select - 1] select-1������ж�Ӧ���о���Ҫɾ����λ��
                of.m_orderData[w[select - 1]]["status"] = "0";

                of.updateOrder();

                cout << "��ȡ��ԤԼ" << endl;
                return ;      //break;
            }
        }
        cout << "�����������������룺" << endl;
    }

    system("pause");
    system("cls");
}

Student::~Student()
{
    //dtor
}
