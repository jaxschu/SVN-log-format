/*
* @copyright 2019, Zhejiang Unittec Co.,Ltd
* @author Xu Peili  Liu Chao
* @date 6-19-2019 Liu chao: Create the file.
* @file  LogHandler.h
*/
#ifndef   LOG_HANDLER_H
#define   LOG_HANDLER_H
#include  <vector>
#include  <string>
#include  "LogOutput.h"
#include  "LogListEnTryInfo.h"
using namespace std;
namespace LOG
{

    class  LogHandler
    {
    public:
        LogHandler();
        ~LogHandler();
        //����ÿ��֮����ַ�����
        bool LimitOuput(int LimitSize);
        //��ӻ����ࡾ���ⵥ�š�������
        bool AddIndex(ListEntries LogBase);
        //�ָ����ⵥ��
        vector<string> SubProbStr(std::string strProb,int count);
        //�������ⵥ�ŵ���Ŀ
        int  CountProbNo(string strProb);
        //������Ҫ����ַ������ַ����������
        std::string CompleStr(int strSize, std::string strOri);
        //�Դ��ڶ�������ŵĽ��зֽ�
        bool DissProb(std::vector<ListEntries>& vecRecData);
        //��������ļ���Ϣ�����н����Լ�����(��ȡ����Ϣ�Լ��ظ�����)
        bool  DataParse(std::vector<ListEntries>& vecRecData);
        //ȡ�ý����������ļ���Ϣ
        std::vector<ListEntries> GetDataOutput();
        //��ȡ���·��
        string  OutPath();
        //�õ����ָ��
        LogOutput* GetpLogOutput();
    private:
        std::vector<ListEntries> vecData;
        LogOutput* m_pLogOp;
    };
}
#endif
