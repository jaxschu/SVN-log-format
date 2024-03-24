/*
* @copyright 2019, Zhejiang Unittec Co.,Ltd
* @author Xu Peili
* @date 6-22-2019 Xu Peili: Create the file.
*/

#pragma once
#ifndef LOG_INFO_H
#define LOG_INFO_H

#include <string>
using namespace std;

namespace LOG
{
    class LogInfo
    {
    public:
        LogInfo() :
            m_sPrbNo(""),
            m_sRvseContent(""),
            m_sRvsePerson(""),
            m_sUploadPerson(""),
            m_sRvseDate("")
        {
            //
        }
        string m_sPrbNo;
        string m_sRvseContent;
        string m_sRvsePerson;
        string m_sUploadPerson;
        string m_sRvseDate;
    };
}

#endif // !LOG_INFO_H
