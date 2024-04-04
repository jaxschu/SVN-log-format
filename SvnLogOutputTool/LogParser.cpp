/*
* @copyright 2019, Zhejiang Unittec Co.,Ltd
* @author Xu Peili
* @date 6-19-2019 Xu Peili: Create the file.
*/

#include "LogParser.h"
#include "CvtTool.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <cstdio>
#include <sstream>
#include <cstring>
using namespace std;

namespace LOG
{
    LogParser::LogParser()
    {
        m_offCn = 2;
        m_offEn = 1;
        LOC_FAIL = -1;
    }

    LogParser::~LogParser()
    {
    }

    vector<ListEntries> LogParser::DataStorage(AllSearchKey MarkKeys, 
        vector<vector<string>>& aReadAllStr, string sFileName)
    {
            for (vector<vector<string>>::iterator itr = aReadAllStr.begin(); itr != aReadAllStr.end(); ++itr)
            {
                for (vector<string>::iterator ditr = itr->begin(); ditr != itr->end(); ++ditr)
                {
                    string str = *ditr;
                    ListEntries LstEntry;

                    if (sFileName.find(".txt") != sFileName.npos)
                    {
                        if (str != "" && str.find(MarkKeys.m_sMarkPrbNo) != str.npos)
                        {
                            LstEntry.SetPrbNo(str);
                        }
                        else if (str != "" && str.find(MarkKeys.m_sMarkRvseContent) != str.npos)
                        {
                            LstEntry.SetRvseContent(str);
                        }
                        else if (str != "" && str.find(MarkKeys.m_sMarkRvsePerson) != str.npos)
                        {
                            LstEntry.SetRvsePerson(str);
                        }
                        else if (str != "" && str.find(MarkKeys.m_sMarkUploadPerson) != str.npos)
                        {
                            LstEntry.SetUploadPerson(str);
                        }
                        else
                        {
                            //
                        }
                    }
                    else if (sFileName.find(".xml") != sFileName.npos)
                    {
                        if (str != "" && str.find(MarkKeys.m_sMarkPrbNo) != str.npos)
                        {
                            LstEntry.SetPrbNo(str);
                        }
                        else if (str != "" && str.find(MarkKeys.m_sMarkRvseContent) != str.npos)
                        {
                            LstEntry.SetRvseContent(str);
                        }
                        else if (str != "" && str.find(MarkKeys.m_sMarkUploadPerson) != str.npos)
                        {
                            LstEntry.SetUploadPerson(str);
                        }
                        else if (str != "" && str.find(MarkKeys.m_sMarkDate) != str.npos)
                        {
                            LstEntry.SetDate(str);
                        }
                        else
                        {
                            //
                        }
                    }
                    m_aLogInfo.push_back(LstEntry);
                }
            }
            return m_aLogInfo;
    }

    vector<ListEntries>  LogParser::DataProcess(vector<ListEntries>& vecLogInfo)
    {
        int Offset_One = 1;
        int Offset_Two = 2;
        int Offset_Three = 3;
        std::string EMPTY_STRING = "";
        for (vector<ListEntries>::iterator itr = vecLogInfo.begin(); itr != vecLogInfo.end(); )
        {
            if ((itr->GetPrbNo() == EMPTY_STRING)
                && (itr->GetRvseContent() == EMPTY_STRING)
                && (itr->GetRvsePerson() == EMPTY_STRING)
                && (itr->GetUploadPerson() == EMPTY_STRING))
            {
                itr = vecLogInfo.erase(itr);
            }
            else
            {
                ++itr;
            }
        }
        for (vector<ListEntries>::iterator itr = vecLogInfo.begin(); itr != vecLogInfo.end(); /*++itr*/)
        {
            //it->m_sUploadPerson = itr->m_sUploadPerson;
            itr->SetPrbNo((itr + Offset_One)->GetPrbNo());
            itr->SetRvseContent((itr + Offset_Two)->GetRvseContent());
            itr->SetRvsePerson((itr + Offset_Three)->GetRvsePerson());
            itr = vecLogInfo.erase(itr + Offset_One);
            itr = vecLogInfo.erase(itr);
            itr = vecLogInfo.erase(itr);
        }
        for (vector<ListEntries>::iterator itr = vecLogInfo.begin(); itr != vecLogInfo.end(); ++itr)
        {
            itr->SetPrbNo(ProcessPrbNo(itr->GetPrbNo()));
            itr->SetRvseContent(ProcessRvseContent(itr->GetRvseContent()));
            itr->SetRvsePerson(ProcessRvsePerson(itr->GetRvsePerson()));
            itr->SetUploadPerson(ProcessUploadPerson(itr->GetUploadPerson()));
        }
        return vecLogInfo;
    }

    
    string LogParser::ProcessUploadPerson(std::string strUploadPerson)
    {
        std::string  strResult = "";
        std::string  flag = "|";
        int Position = 0;
        int strSize = 0;
        strSize = strUploadPerson.size();
        Position = strUploadPerson.find_first_of(flag);
        strResult = strUploadPerson.substr(Position + m_offEn, strSize - Position - m_offEn);
        Position = strResult.find_first_of(flag);
        strResult = strResult.substr(0, Position);
        return strResult;
    }
    
    string LogParser::ProcessPrbNo(std::string strPrbNo)
    {
        std::string strResult = " ";
        std::string flag = "D";
        int Position = 0;
        int strSize = 0;
        strSize = strPrbNo.size();
        Position = strPrbNo.find_first_of(flag);
        if (!(Position == LOC_FAIL))
        {
            strResult = strPrbNo.substr(Position, strSize - Position);
        }
        return strResult;
    }
    
    string LogParser::ProcessRvseContent(std::string strRvseContent)
    {
        std::string strResult = " ";
        std::string flag = "��";
        int Position = 0;
        int strSize = 0;
        strSize = strRvseContent.size();
        Position = strRvseContent.find_first_of(flag);
        if (!(Position == LOC_FAIL))
        {
            strResult = strRvseContent.substr(Position + m_offCn, strSize - Position - m_offCn);
        }
        return strResult;
    }
    
    string LogParser::ProcessRvsePerson(std::string strRvsePerson)
    {
        std::string strResult = " ";
        std::string flag = "��";
        int Position = 0;
        int strSize = 0;
        strSize = strRvsePerson.size();
        Position = strRvsePerson.find_first_of(flag);
        if (!(Position == LOC_FAIL))
        {
            strResult = strRvsePerson.substr(Position + m_offCn, strSize - Position - m_offCn);
        }
        return strResult;
    }
}