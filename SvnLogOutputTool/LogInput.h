#pragma once
#ifndef LOG_INPUT_H
#define LOG_INPUT_H

/*
* @copyright 2019, Zhejiang Unittec Co.,Ltd
* @author Xu Peili
* @date 6-19-2019 Xu Peili: Create the file.
*/

#include <string>
#include "LogParser.h"
#include "LogTxtParser.h"
#include "LogXmlParser.h"
#include <algorithm>
using namespace std;

namespace LOG
{
    class LogInput /*: public LogTxtInput, public LogXmlInput, public LogParser*/
    {
    public:
        LogInput();
        virtual ~LogInput(void);
        string GetTextLctn();
        bool Run();
        vector<ListEntries> PassListEntries();
    private:
        vector<vector<string>> StoreSingleStr(vector<string>&, string);
        vector<ListEntries> DeleteSameContent(vector<ListEntries>&);
        bool CheckFileVaild(string);
        bool ContentValidity(vector<string>&, string);
        AllSearchKey GetSearchKeys(string);
    private:
        CVT m_CvtTool;
        LogParser* m_pLgTxtPsr;
        LogParser* m_pLgXmlPsr;
        vector<ListEntries> m_aAllListEntries;
        //LogTxtInput m_LogTxtInput;
        //LogXmlInput m_LogXmlInput;
    };
}

#endif // !LOG_INPUT_H