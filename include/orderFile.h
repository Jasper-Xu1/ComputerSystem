#ifndef ORDERFILE_H
#define ORDERFILE_H

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <windows.h>
#include "globalFile.h"

using namespace std;

//����һ��ԤԼ��¼���ļ�,��Ҫ��ʾԤԼ��¼ʱ����Ҫ���ļ��л�ȡ�����еļ�¼��������ʾ������ԤԼ���������¼�Լ�����
//��Ҫ��;���Ǵ�ӡԤԼȫ������Ϣ����Ϊ������ԤԼ�ļ��е���Ϣ�в�ͬ���ͣ����Ե�Ҫ��ӡѧ����Ϣ�ͽ�ʦ��Ϣʱ��
//    ����Ҫ��ԤԼ�ļ��е���Ϣ�����в�֡���Ϊ������������Ҫ����ԤԼ��
//ԤԼ��
class OrderFile
{
    public:
        //���캯��
        OrderFile();
        //��������
        virtual ~OrderFile();

        //����ԤԼ��¼
        void updateOrder();

        //��¼ԤԼ������
        int m_Size;

        //��¼����ԤԼ��Ϣ������     key��¼������   value�����¼��ֵ����Ϣ
        //����˫��Ƕ�׵��ã�map<string key,string value>    ���key��ʾ��һ������ֵ���ڶ���value��ʾ��������
        map<int,map<string,string>> m_orderData;

};

#endif // ORDERFILE_H
