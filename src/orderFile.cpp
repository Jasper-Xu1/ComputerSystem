/*
 *�ļ���
 *�� ��
 *�� ��
 *ʱ ��
 *�� Ȩ
 */
#include "orderFile.h"


//���캯��
OrderFile::OrderFile()
{
    ifstream ifs;
    ifs.open(ORDER_FILE,ios::in);    //�򿪶�ȡ�ļ���Ϣ

    string date;         //����
    string interval;     //ʱ���
    string stuId;        //ѧ��ѧ��
    string stuName;      //ѧ������
    string roomId;       //�������
    string status;       //ԤԼ״̬

    this->m_Size = 0;    //ԤԼ��¼������

    while(ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName
          && ifs >> roomId && ifs >> status)
    {

            //������֤�ļ��е�ԤԼ��¼��Ϣ�Ƿ���׼ȷ��ȡ����
            //        cout << date << endl;
            //        cout << interval << endl;
            //        cout << stuId << endl;
            //        cout << stuName << endl;
            //        cout << roomId << endl;
            //        cout << status << endl;
            //        cout << endl;

        //������ֱ�Ӵ�ӡ����  һ����ֵ��   ��date��1��
        //������Ҫ�������ֵ�� ð��ǰ����������ݷֿ���һ����ȡ��key������һ����ȡ��value
        //������Դ������ݵ�ʱ�򣬾Ͷ���������Ĵ�ӡ������

        //�����������ģ�ʹ��map<>�����Ų�ͬ�����ݣ�ʹ��substr����ȡ��������
        string key;
        string value;
        map<string,string> m;      //���Ǵ�ż�¼��һ������

        //��ȡ��������
        int pos = date.find(":");    //find ��vector������ĺ���
        if(pos != -1)
        {
            key = date.substr(0,pos);         //substr������substr����������������ʾ��date��0��ʼ��ȡposλ���ַ�
            value = date.substr(pos + 1, date.size() - pos - 1);      //������ȡvalue����ֵ

            //���ǽ�ȡ����һ��date������
            //cout << "key = " << key << endl;
            //cout << "value = " << value << endl;

            //����Ҫ��ȡ���е�����

            m.insert(make_pair(key,value));     //���뵽map�����У�ʹ��make_pair����һ������
        }

        //��ȡʱ���
        pos = interval.find(":");
        if(pos != -1)
        {
            key = interval.substr(0,pos);                                 //��ȡ��key������
            value = interval.substr(pos + 1, interval.size() - pos - 1);   //��ȡ��value������
            m.insert(make_pair(key,value));              //���뵽map�����У�����Ҫ��make_pair����һ�����������������Ӧ
        }

        //��ȡѧ����ѧ��
        pos = stuId.find(":");
        if(pos != -1)
        {
            key = stuId.substr(0,pos);
            value = stuId.substr(pos + 1, stuId.size() - pos - 1);
            m.insert(make_pair(key,value));
        }

        //��ȡѧ��������
        pos = stuName.find(":");
        if(pos != -1)
        {
            key = stuName.substr(0,pos);
            value = stuName.substr(pos + 1, stuName.size() - pos - 1);
            m.insert(make_pair(key,value));
        }

        //��ȡ�����ı��
        pos = roomId.find(":");
        if(pos != -1)
        {
            key = roomId.substr(0,pos);
            value = roomId.substr(pos + 1, roomId.size() - pos - 1);
            m.insert(make_pair(key,value));
        }

        //��ȡԤԼ״̬
        pos = status.find(":");
        if(pos != -1)
        {
            key = status.substr(0,pos);
            value = status.substr(pos + 1, status.size() - pos - 1);
            m.insert(make_pair(key,value));
        }

        //��С��map�����еĲ�ͬ��������ݣ�ȫ���ŵ����map������
        this->m_orderData.insert(make_pair(this->m_Size,m));
        this->m_Size++;            //���ν�Сmap�������뵽���map����m_orderData�У�ÿ��һ�Σ�SizeԤԼ��¼������1

    }
    ifs.close();

//    //��������map����
//    cout << "�鿴ȫ����ϸ��Ϣ" << endl;
//    for(map<int,map<string,string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
//    {
//        cout << "����Ϊ��" << it->first << " ,value��ֵΪ:" << endl;
//        for(map<string ,string>::iterator mit = (*it).second.begin(); mit != it->second.end(); mit++)
//        {
//            cout << " key = " << mit->first << "\t" << " value = " << mit->second << "\n";
//        }
//        cout << endl;
//    }
//
//    cout << "���������鿴�ؼ���Ϣ" << endl;
 //   system("pause");
 //   system("cls");
}


//����ԤԼ��¼  ---�� ���ļ�������ԤԼ��Ϣ���´�ӡһ��
void OrderFile::updateOrder()
{
    if(m_Size == 0)
    {
        return ;     //ԤԼ��¼Ϊ0��ֱ��return
    }

    ofstream ofs(ORDER_FILE, ios::out | ios::trunc);    //��out�ķ�ʽ������Ҫд��ɾ��ԭ�ļ��ĵ����ݣ�������һ���µ��ļ�
    for(int i = 0; i < m_Size; i++)
    {
        ofs << "date:" << this->m_orderData[i]["date"] << " ";     //Ҳ����������  (m_orderData[0])���ʾ��1�У�
        ofs << "interval:" << this->m_orderData[i]["interval"] << " ";      //��Ϊ�ײ㻹��һ������������Ҳ�����������ű�ʾ
        ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";           //�� (m_orderData[0])["date"]
        ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
        ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
        ofs << "status:" << this->m_orderData[i]["status"] << " " << endl;
    }
    ofs.close();
}



//��������
OrderFile::~OrderFile()
{
    //dtor
}
