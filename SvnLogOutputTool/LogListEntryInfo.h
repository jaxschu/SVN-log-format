#pragma once
#ifndef LOG_LIST_ENTRY_INFO_H
#define LOG_LIST_ENTRY_INFO_H
#include <string>
using namespace std;

/*
* @copyright 2019, Zhejiang Unittec Co.,Ltd
* @author Xu Peili
* @date 6-19-2019 Xu Peili: Create the file.
*/

namespace LOG
{
    class ListEntries
    {
    public:
        ListEntries() :
            m_sListPrbNo(""),
            m_sListRvseContent(""),
            m_sListRvsePerson(""),
            m_sListUploadPerson(""),
            m_sListDate(""),

            m_sListLineUp(""),
            m_sListLineDown("")
        {
        }
        void SetPrbNo(string str)
        {
            m_sListPrbNo = str;
        }
        void SetRvseContent(string str)
        {
            m_sListRvseContent = str;
        }
        void SetRvsePerson(string str)
        {
            m_sListRvsePerson = str;
        }
        void SetUploadPerson(string str)
        {
            m_sListUploadPerson = str;
        }
        void SetDate(string str)
        {
            m_sListDate = str;
        }

        void SetLineUp(string str)
        {
            m_sListLineUp = str;
        }
        void SetLineDown(string str)
        {
            m_sListLineDown = str;
        }

        string GetPrbNo()
        {
            return m_sListPrbNo;
        }
        string GetRvseContent()
        {
            return m_sListRvseContent;
        }
        string GetRvsePerson()
        {
            return m_sListRvsePerson;
        }
        string GetUploadPerson()
        {
            return m_sListUploadPerson;
        }
        string GetDate()
        {
            return m_sListDate;
        }

        string GetLineUp()
        {
            return m_sListLineUp;
        }
        string GetLineDown()
        {
            return m_sListLineDown;
        }
    private:
        string m_sListPrbNo;
        string m_sListRvseContent;
        string m_sListRvsePerson;
        string m_sListUploadPerson;
        string m_sListDate;

        string m_sListLineUp;
        string m_sListLineDown;
    };
}

#endif // !LOG_LIST_ENTRY_INFO_H