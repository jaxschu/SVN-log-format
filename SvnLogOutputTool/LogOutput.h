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
        
         bool RecData(std::vector<ListEntries>& vecData);
         
         vector<ListEntries>  GetData();
         string  GetOutPath();
        
        virtual bool Output(std::string strOutPath)=0;//data

        private:
            std::string  m_strOutPath;
            std::vector<ListEntries>  vecRecdata;
    };
}
#endif