#pragma once
#ifndef LOG_PARSER_H
#define LOG_PARSER_H

/*
* @copyright 2019, Zhejiang Unittec Co.,Ltd
* @author Xu Peili
* @date 6-19-2019 Xu Peili: Create the file.
*/

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <cstdio>
#include <sstream>
#include "CvtTool.h"
#include "AllSearchKeys.h"
//#include "LogTxtParser.h"
//#include "LogXmlParser.h"
#include "LogListEntryInfo.h"
using namespace std;

namespace LOG
{
    class LogParser
    {
    public:
        LogParser();
        virtual ~LogParser();

        vector<ListEntries> DataStorage(AllSearchKey, vector<vector<string>>&, string);
        vector<ListEntries> DataProcess(vector<ListEntries>&);

        virtual AllSearchKey SearchKeys(string) = 0;
        virtual vector<string> ReadFile(string) = 0;

        //all file content
        vector<vector<string>> m_aAllInStr;

        //void TestWrite();
        //bool TextJudge();
        //bool TextInSelector(vector<string>);
        //vector<string> GetInFileName(string);
        //vector<ListEntries> DecodeBody(vector<LogInfo>);
    protected:
        //single file content
        vector<string> m_aSingleAllInStr;
        //filtered entries
        vector<ListEntries> m_aLogInfo;
        //vector<string> m_aAllOutFileName;
        CVT m_CvtTool;
    protected:
        //bool ContentValidity(vector<string>&, string);
    private:
        string LogParser::ProcessUploadPerson(std::string strUploadPerson);
        string LogParser::ProcessPrbNo(std::string strPrbNo);
        string LogParser::ProcessRvseContent(std::string strRvseContent);
        string LogParser::ProcessRvsePerson(std::string strRvsePerson);
    private:
        long m_offCn;
        long m_offEn;
        long LOC_FAIL;
    };
}

#endif // !LOG_HANDLER_H
