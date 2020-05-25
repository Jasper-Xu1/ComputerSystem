/*
 *�ļ���
 *�� ��
 *�� ��
 *ʱ ��
 *�� Ȩ
 */
#include "manager.h"

Manager::Manager()
{
    //ctor
}

//���ι���  (����Ա����������)
Manager::Manager(string name, string pwd)
{
    //��ʼ������Ա��Ϣ
    this->m_Name = name;
    this->m_Pwd = pwd;

    //��ʼ������   ��ȡ�������ļ� ����ʦ��ѧ����Ϣ,������Ϣ
    this->initVector();
}

//ѡ��˵�
void Manager::openMenu()
{
    cout << "��ӭ����Ա," << this->m_Name << "��¼!" << endl;
    cout << "\t\t -------------------------------------------- \n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 1.����˺�                 |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 2.�鿴�˺�                 |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 3.�鿴����                 |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 4.���ԤԼ                 |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 0.ע����¼                 |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t -------------------------------------------- \n";
    cout << "��ѡ�����Ĳ�����" << endl;;

}

//����˺ţ�  ���ѧ����Ϣ����ӽ�ʦ��Ϣ
void Manager::addPerson()
{
    cout << "������Ҫ����˺�����" << endl;
    cout << "1�����ѧ��" << endl;
    cout << "2�������ʦ" << endl;

    string fileName;    //�������ļ���,����㶨��һ������������پ��嵽�ĸ��ļ���
    string tip;       //��ʾid��
    string errorTip;    //��ʾ�ظ��Ĵ�����ʾ

    //д���ļ�
    ofstream ofs;     //�ļ���������

    int select = 0;
    cin >> select;    //�����û���ѡ��

    if(select == 1)
    {
        //��ӵ���ѧ��
        fileName = STUDENT_FILE;      //����Ҳ���Ժ�ǰ��54�е�һ����
        tip = "������ѧ�ţ�";
        errorTip = "ѧ���ظ������������룺";
    }
    else if(select == 2)
    {
        //��ӵ��ǽ�ʦ
        fileName = TEACHER_FILE;
        tip = "������ְ����ţ�";
        errorTip = "ְ�����ظ������������룺";
    }
    else
    {
        cout << "���������������������" << endl;
        cin >> select;
    }

    //����׷�ӵķ�ʽ  д�ļ�
    ofs.open(fileName,ios::out | ios::app);

    int id;    //ѧ�� ��ְ����
    string name;    //����
    string pwd;    //��Ҫд�����Ϣ

    cout << tip << endl;     //������������֣�һ����ѧ�ţ���һ����ְ����

    while(true)     //ֻҪ�����ˣ���ȫ�����棬������ѭ����ֻҪ�����ж��Ƿ��ظ������ظ���break������ȥ
    {
        cin >> id;

        bool ret = this->checkRepeat(id,select);
        if(ret)
        {
            cout << errorTip << endl;   //����Ϊ��ʱ�����ʾ�ظ���
        }
        else
        {
            break;        //else�ǲ�Ϊ�棬���ظ���ֱ��break�˳�ѭ����
        }
    }

    cout << "������������" << endl;
    cin >> name;

    cout << "���������룺" << endl;
    cin >> pwd;

    //���ļ����������
    ofs << id << "  " << name << "  " << pwd << "\n";
    cout << "��ӳɹ�!" << endl;

    system("pause");
    system("cls");

    ofs.close();

    this->initVector();    //�������Ϣ��ҲҪ���½���һ�γ�ʼ����������ֹ�����������Ϣ�ظ�
}

void PrintStudent(Student & s)     //��ӡѧ����Ϣ
{
    cout << "ѧ��:" << s.m_Id << "\t|" << "������" << s.m_Name << "\t|" << "���룺" << s.m_Pwd << "\t|" << endl;
}

void PrintTeacher(Teacher & t)     //��ӡ��ʦ��Ϣ
{
    cout << "ְ����:" << t.m_TeacherId << "\t|" << "������" << t.m_Name << "\t|" << "���룺" << t.m_Pwd << "\t|" << endl;
}

//�鿴�˺�
void Manager::showPerson()
{
    cout << "��ѡ����Ҫ�鿴�����ݣ�" << endl;
    cout << "1���鿴����ѧ��" << endl;
    cout << "2���鿴���н�ʦ" << endl;

    int select = 0;     //����һ���������������û�������
    cin >> select;

    if(select == 1)
    {
        cout << "����ѧ������Ϣ���£�" << endl;
        for_each(vStu.begin() , vStu.end(), PrintStudent);    //����ʹ��for_each�㷨������vector�����е�ѧ����Ϣ
    }                                                      //Ҳ����ʹ��forѭ������
    else
    {
        cout << "���н�ʦ����Ϣ���£�" << endl;
        for_each(vTea.begin(), vTea.end(), PrintTeacher);
    }
    system("pause");
    system("cls");
}

//�鿴������Ϣ
void Manager::showComputer()
{
    cout << "��������Ϣ���£�" << endl;

    for(vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
    {
        cout << "������ţ�" << it->m_ComId << " \t| " << "�����������:" << it->m_ComMaxNum << "\t|" << endl;
    }
    system("pause");
    system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile()
{
    //ofstream��д�룬ǰ����Ǵ��ļ������ԾͲ���open��
    ofstream ofs(ORDER_FILE, ios::trunc);    //trunc��ɾ���ļ������ݣ��������µ��ļ�
    ofs.close();

    cout << "��ճɹ���" << endl;
    system("pause");
    system("cls");
}

//��ʼ������
void Manager::initVector()
{
    //�ȶ�����vector���ݽ������
    vStu.clear();
    vTea.clear();
    vCom.clear();

    //��ȡ��Ϣ    ѧ��  ��ʦ
    ifstream ifs;
    ifs.open(STUDENT_FILE,ios::in);   //�򿪲���ȡѧ���ļ�
    if(!ifs.is_open())
    {
        cout << "�ļ���ȡʧ��!" << endl;
        return ;
    }
    Student s;
    while(ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)    //��ȡ�ļ���ѧ������
    {
        vStu.push_back(s);    //����ȡ����ѧ�����ݣ����ηŵ�vectorѧ��������
    }
    cout << "��ǰѧ��������" << vStu.size() << endl;    //˳���ӡ��ѧ��������
    ifs.close();         //�����꣬Ҫ�ǵùر�ѧ���ļ�

    ifs.open(TEACHER_FILE,ios::in);     //�򿪲���ȡ��ʦ�ļ�
    //��Ϊ����Դ��ļ����˿������ж��ˣ�������������ٽ����ж���
    Teacher t;
    while(ifs >> t.m_TeacherId && ifs >> t.m_Name && ifs >> t.m_Pwd)
    {
        vTea.push_back(t);     //����ȡ������ʦ�����ݣ�push����back����ʦvector������
    }
    cout << "��ǰ��ʦ��������" << vTea.size() << endl;
    ifs.close();      //�ر��ļ�


    //��ȡ��������Ϣ��������������Ϣ�洢��vector���������У��������������ӡ��޸�ʹ��
    ifs.open(COMPUTER_FILE,ios::in);    //�򿪲���ȡ�����ļ�����Ϣ
    ComputerRoom com;
    while(ifs >> com.m_ComId && ifs >> com.m_ComMaxNum)
    {
        vCom.push_back(com);
    }
    cout << "��ǰ�����ڵ��Ե�������" << vCom.size() << endl;
    ifs.close();       //�ر��ļ�

}

//����ظ�      ����������id���������ͣ� ����ֵ��true�������ظ���false����û���ظ���
bool Manager::checkRepeat(int id, int type)
{
    if(type == 1)     //�������������ѧ��ʱ
    {
        for(vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)   //ʹ�õ�����������ѧ������Ϣ
        {
            if(id == it->m_Id)       //��������id�źͱ�������id����ȣ����ʾ�ظ���
            {
                return true;
            }
        }
    }
    else        //�������������������ѧ����������ʦ
    {
        for(vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)    //���ﲻ����++it��ֻ����it++  ��
        {
            if(id == it->m_TeacherId)
            {
                return true;
            }
        }
    }
    return false;
}

//ѧ������

//��ʦ����

Manager::~Manager()
{
    //dtor
}
