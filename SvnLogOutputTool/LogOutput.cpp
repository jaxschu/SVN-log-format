/*
* @copyright 2019, Zhejiang Unittec Co.,Ltd
* @author   Liu Chao
* @date 6-24-2019 Liu chao: Create the file.
* @file  LogHandler.cpp
*/
#include "LogOutput.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
namespace LOG
{
    LogOutput::LogOutput():m_strOutPath("")
    {
    }
    LogOutput::~LogOutput()
    {
    }
    bool LogOutput::SetOutPath(string strOutPath)
    {
        bool bRet = false;
        m_strOutPath = strOutPath;
        bRet = true;
        return bRet;
    }
    string  LogOutput::GetOutPath()
    {
        return m_strOutPath;
    }
    vector<ListEntries> LogOutput::GetData()
    {
        return vecRecdata;
    }
    bool LogOutput::RecData(std::vector<ListEntries>& vecData)
    {
        bool  bRet = false;
        for (vector<ListEntries>::iterator it = vecData.begin(); it != vecData.end(); it++)
        {
            vecRecdata.push_back(*it);
        }
        bRet = true;
        return bRet;
    }

    bool LogOutput::Output(std::string strOutPath)
    {
        bool bRet = false;
        cout << "OUTPUT MAIN FUNCTION" << endl;
        bRet = true;
        return bRet;
    }
}