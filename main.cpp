#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include "Identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include "globalFile.h"

using namespace std;

//ȫ�ֺ���--�������Ա�Ӳ˵����� ,�����Ƕ�̬  �ø����ָ�봴���������Ȼ���������ӿڣ����ù���Ա�˵�
void managerMenu(Identity * &manager)

/** Ϊʲô�����������    ��Ϊ�ڸտ�ʼ�ĳ�ʼ�����У�manager�����࣬�ɻ�����ã�����Identity���ã�
    ����manager->openMenu()�󣬾ͽ��뵽����Ա���Ӳ˵��У���ʱ����ͱ����Manager��
    ��Ҫ��Manager������Manager�����еĺ�����
    ��Ϊ���ú����Ļ�����ˣ����Ե����Ӳ˵��еĺ���ʱ������ֻ������������Ҫ���������ͣ���ʱ����Ҫ�õ�ǿת ���ı�����
*/
{
    while(true)  //����һ����ѭ����ֻ�е�0 ע���������˳�
    {
        //���ù���Ա�Ӳ˵�
        manager->openMenu();

        //������ָ�� ת��Ϊ����ָ�룬Ȼ�����ȥ����������������ӿ�
        Manager * man = (Manager *)manager;

        int select = 0;
        //�����û���ѡ��
        cin >> select;

        if(select == 1)    //����˺�
        {
            cout << "1.����˺�" << endl;
            man->addPerson();
        }
        else if(select == 2)    //�鿴�˺�
        {
            cout << "�鿴�˺�" << endl;
            man->showPerson();
        }
        else if(select == 3)    //�鿴����
        {
            cout << "�鿴����" << endl;
            man->showComputer();
        }
        else if(select == 4)     //���ԤԼ
        {
            cout << "���ԤԼ" << endl;
            man->cleanFile();
        }
        else if(select == 0)
        {
            //ע��
            delete manager;     //���ٵ���������
            cout << "ע���ɹ���" << endl;
            system("pause");
            system("cls");
            return ;
        }
        else
        {
            cout << "�����������������һ�λ��ᣬ���������룺\n";
            cout << "��ѡ�����Ĳ�����";
            cin >> select;
        }
    }
}

//ȫ�ֺ���--����ѧ���Ӳ˵����棬 �����Ƕ�̬  �ø����ָ�봴���������Ȼ���������ӿڣ�����ѧ����˵�
void studentMenu(Identity * &student)     //student�Ǹ����ж����һ��ָ������Ĳ���
{
    while(true)      //����һ����ѭ���������������0ֵʱ��������ѭ���ж�
    {
        //ѧ���˵�
        student->openMenu();    //����student�����еķ���,

        Student * stu = (Student *)student;   //����������еĲ�����Сд��student����ǿת�������еĲ���
        int select = 0;     //���������û�������
        cin >> select;

        switch(select)
        {
        case 1:
            {
                //����ԤԼ
                stu->applyOrder();
                break;
            }
        case 2:
            {
                //�鿴����ԤԼ
                stu->showOrder();
                break;
            }
        case 3:
            {
                 //�鿴����ԤԼ
                stu->showAllOrder();
                break;
            }
        case 4:
            {
               //ȡ��ԤԼ
                stu->cancelOrder();
                break;
            }
        case 0:
            {
                //ע����¼
                delete stu;
                cout << "ע���ɹ�" << endl;
                system("pause");
                system("cls");
                return ;
                break;
            }
        default:
            {
                cout << "�������󣬻���һ��������᣺" << endl;
                cin >> select;
            }
        }
    }
}


//ȫ�ֺ���--�����ʦ�Ӳ˵����棬�����Ƕ�̬   �ø����ָ�봴���������Ȼ���������ӿڣ����ý�ʦ��˵�
void teacherMenu(Identity * &teacher)
{
    while(true)    //��һ����ѭ����ֻ�е�ע��ʱ�Ż��˳�
    {
        //��ʦ�˵�
        teacher->openMenu();     //��������Ķ���

        Teacher * tea = (Teacher *)teacher;       //������ָ��ǿת������ָ�룬
        int select = 0;     //�����û���ѡ��
        cin >> select;

        if(select == 1)
        {
            //�鿴����ԤԼ
            tea->showAllOrder();
        }
        else if(select == 2)
        {
            //���ԤԼ
            tea->validOrder();
        }
        else if(select == 0)
        {
            //ע����¼
            delete tea;
            cout << "ע���ɹ�!" << endl;
            system("pause");
            system("cls");
            return ;
        }
        else
        {
            cout << "��������������һ�λ������룺" << endl;
            cin >> select;
        }

    }
}


//ȫ�ֺ���--ʵ�ֵ�¼���ܵĺ���   ����1 �������ļ�   ����2 �����������
void LoginIn(const string fileName, int type)
{
    //�ȶ���һ������ָ�룬��������ָ���������
    Identity * person = NULL;

    //���ļ�
    ifstream ifs;
    ifs.open(fileName,ios::in);

    //�ж��ļ��Ƿ����,�ļ������ڵ����
    if(!ifs.is_open())
    {
        cout << "�ļ�������" << endl;
        ifs.close();
        return;
    }

    //׼�������û��������Ϣ
    int id = 0;
    string name;
    string pwd;

    //�ж��������ʲô���     ,��¼�Ľӿ�
    if(type == 1)     //ѧ����¼
    {
        cout << "����������ѧ�ţ�" << endl;
        cin >> id;
    }
    else if(type == 2)     //��ʦ��¼
    {
        cout << "����������ְ���ţ�" << endl;
        cin >> id;
    }

    cout << "�����������û�����" << endl;
    cin >> name;
    cout << "��������������: " << endl;
    cin >> pwd;

    //����֮��Ҫ����������ݽ�����֤���ж��˺����������Ƿ����
    if(type == 1)           //��¼��Ϣ����֤
    {
        //ѧ����ݵ���֤
        int fId;
        string fName;
        string fPwd;      //�����������Ǵ��ļ��л�ȡ������

        while(ifs >> fId && ifs >> fName && ifs >> fPwd)
            //ʹ��ifs���α������ļ��е���Ϣ��
            //�������Ƶķ�ʽһ��һ����������Ϣ������������һ��һ�еĶ�ȡ���������ո�ʱ�ͻ���ͣ��
            //�������ν���ţ������������ȡ������Ȼ��ȥ��¼�����Ϣ�Ա�
        {
            if(id == fId && name == fName && pwd == fPwd)
            //�����ļ��ж�ȡ�����ݺ��û������������ͬʱ����ѧ��������Ϣ��֤ͨ��
            {
                cout << "ѧ����Ϣ��֤ͨ������¼�ɹ���" << endl;
                system("pause");
                system("cls");

                //ѧ����¼�ɹ��󣬾ͻ��� ���У�ϵͳ���д���һ��ѧ������Ϣ���Ա�������в���
                person = new Student(id,name,pwd);    //����һ��ѧ����Ϣ���Ӳ˵�
                //����ѧ���˵�
                studentMenu(person);

                return ;
            }
        }
        //���Ҳ���ʱ��������һ��ѭ��ȥ�ң�ֻ�е��������ݶ����꣬��û����ȵģ��Ż�ȷ����¼ʧ��
        //��������whileѭ����û��break��ֻ�е�����������˳�
        cout << "ѧ����Ϣ�������������룺" << endl << endl;
    }
    else if(type == 2)
    {
        //��ʦ��ݵ���֤
        int fId;
        string fName;
        string fPwd;     //���ļ��л�ȡ�Ľ�ʦ�ĸ�����Ϣ

        while(ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if(id == fId && name == fName && pwd == fPwd)
            {
                cout << "��ʦ��Ϣ��֤ͨ������¼�ɹ�!" << endl;
                system("pause");
                system("cls");

                person = new Teacher(id,name,pwd);     //����һ����ʦ����Ŀ¼
                //�����ʦ�Ӳ˵�
                teacherMenu(person);

                return ;
            }
        }
        cout << "��ʦ��Ϣ�������������룺" << endl <<endl;
    }
    else if(type == 3)
    {
        //����Ա��ݵ���֤
        string fName;
        string fPwd;
        while(ifs >> fName && ifs >> fPwd)
        {
            if(name == fName && pwd == fPwd)
            {
                cout << "����Ա��Ϣ��֤ͨ������½�ɹ���" << endl;
                //��¼�ɹ��󣬰�������������Ա����
                system("pause");
                system("cls");

                //��������Ա����
                person = new Manager(name,pwd);
                //�������Ա�˵�
                managerMenu(person);

                return ;
            }
        }
        cout << "����Ա��Ϣ�������������룺" << endl << endl;
    }
    else   //���elseҲ���Բ�д
    {
        cout << "��¼��֤ʧ��!" << endl;
        system("pause");
        system("cls");
    }
    return;
}


int main()
{
    SetConsoleTitle("����ԤԼϵͳ");
    int select = 0;        //���ڽ����û���ѡ��
    while(true)
    {
    cout << "========================  ��ӭʹ�û���ԤԼϵͳ  ========================" << endl;
    cout << "��ѡ���������" << endl;
    cout << "\t\t -------------------------------------------- \n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 1.ѧ������                 |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 2.��ʦ                     |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 3.����Ա                   |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                 0.�˳�                     |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t -------------------------------------------- \n";
    cout << "����������ѡ��";
    cin >> select;               //�����û���ѡ��

    switch(select)      //�����û���ѡ����  ʵ�ֲ�ͬ�Ľӿ�
    {
    case 1:       //ѡ��ѧ�����
        LoginIn(STUDENT_FILE, 1);
        break;
    case 2:       //ѡ����ʦ���
        LoginIn(TEACHER_FILE,2);
        break;
    case 3:       //ѡ�����Ա���
        LoginIn(ADMIN_FILE,3);
        break;
    case 0:       //ѡ���˳�
        cout << "��ӭ��һ��ʹ��" << endl;
        system("pause");      //��ʾ��������˳�
        return 0;
        break;
    default:      //�����������ϵ����
        cout << "�������������������룺\n";
        system("pause");      //��ʾ��������˳�
        system("cls");
        break;
    }
    }
    system("pause");         //��ʾ��������˳�
    return 0;
}


/**
�������⣺������ѧ�ŵ�ʱ������Ĳ������֣��ͻ������ѭ��
        ������Ա���ɾ��ѧ����Ϣ�Ĺ���
*/
