/*
* @copyright 2019, Zhejiang Unittec Co.,Ltd
* @author Xu Peili
* @date 6-19-2019 Xu Peili: Create the file.
*/
#ifndef  ALL_SEARCH_KEYS_H
#define ALL_SEARCH_KEYS_H
using namespace std;

#include <string>

namespace LOG
{
    class AllSearchKey
    {
    public:
        AllSearchKey() :
            m_sMarkPrbNo(""),
            m_sMarkRvseContent(""),
            m_sMarkRvsePerson(""),
            m_sMarkUploadPerson(""),
            m_sMarkDate("")
        {
        }
        string m_sMarkPrbNo;
        string m_sMarkRvseContent;
        string m_sMarkRvsePerson;
        string m_sMarkUploadPerson;
        string m_sMarkDate;
    };
}

#endif // ! ALL_SEARCH_KEYS_H