/**
* @copyright 2019, Zhejiang UniTTEC Co., Ltd.
* @author   liu chao
*/
/**
* @file   " LogOutput.h"
*
*/
#ifndef LOGOUTPUT_H
#define LOGOUTPUT_H
#include <vector>
#include <string>
#include "LogListEntryInfo.h"
namespace LOG
{
    class LogOutput
    {
    public:
        LogOutput();
        ~LogOutput();
         bool SetOutPath(string strOutPath);
        //���մ���õ��ļ���Ϣ��Ȼ�������и�ʽ����xml�����Լ���Ҫ�ĸ�ʽ
         bool RecData(std::vector<ListEntries>& vecData);
         //�õ�����õ��ļ�����
         vector<ListEntries>  GetData();
         string  GetOutPath();
        //����ʽ�����õ��ļ���Ϣ��ӡ��ָ��·�����ļ���
        virtual bool Output(std::string strOutPath)=0;//data

        private:
            std::string  m_strOutPath;
            std::vector<ListEntries>  vecRecdata;
    };
}
#endif