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
        //接收处理好的文件信息，然后对其进行格式调整xml或者自己想要的格式
         bool RecData(std::vector<ListEntries>& vecData);
         //得到处理好的文件资料
         vector<ListEntries>  GetData();
         string  GetOutPath();
        //将格式调整好的文件信息打印到指定路径的文件下
        virtual bool Output(std::string strOutPath)=0;//data

        private:
            std::string  m_strOutPath;
            std::vector<ListEntries>  vecRecdata;
    };
}
#endif