/*
* @copyright 2019, Zhejiang Unittec Co.,Ltd
* @author   Liu Chao
* @date 6-19-2019 Liu chao: Create the file.
* @file  LogHandler.cpp
*/
#include "LogHandler.h"
#include  <iostream>
#include  "TxtOutput.h"
#include  "ExcelOutput.h"
#define   LOC_FAIL  -1
#define   ProbSize  9
#define   EachRowLimit  25

namespace LOG
{
    LogHandler::LogHandler():m_pLogOp(NULL)
    {

    }
    LogHandler::~LogHandler()
    {

    }
    int  LogHandler::CountProbNo(string strProb)
    {
        int lCount = 0;
        for (string::iterator it = strProb.begin(); it != strProb.end(); ++it)
        {
            if ((*it) == 'D')
            {
                lCount++;
            }
       }
        return lCount;
    }
    vector<string> LogHandler::SubProbStr(std::string strProb,int count)
    {
        vector<string> DataProcess;
        std::string flag = "D";
        std::string  RecvStr = "";
        int Position = 0;
        int lSzie = 0;
        for (int Index = 0; Index < count; Index++)
        {
            Position = strProb.find_first_of(flag);
            if (!(Position == LOC_FAIL))
            {
                RecvStr = strProb.substr(Position, ProbSize);
                lSzie = strProb.size();
                strProb = strProb.substr(Position + ProbSize, lSzie - Position - ProbSize);
            }
            DataProcess.push_back(RecvStr);
        }
        return DataProcess;
    }
    bool LogHandler::DissProb(std::vector<ListEntries>& vecRecData)
    {
        bool bRet = false;
        int lCount = 0;
        ListEntries ListRecord;
        std::string LogProb="";
        std::string LogRvseCont="";
        std::string LogRvsePer="";
        std::string LogUpLoadPer="";
        vector<string> vecLogProb;
        for (vector<ListEntries>::iterator itr = vecRecData.begin(); itr != vecRecData.end();itr++)
        {   
             
            LogProb = itr->GetPrbNo();
            LogRvseCont = itr->GetRvseContent();
            LogRvsePer = itr->GetRvsePerson();
            LogUpLoadPer = itr->GetUploadPerson();
            lCount = CountProbNo(LogProb);
            vecLogProb=SubProbStr(LogProb, lCount);
            if (lCount>1)
            {
                for (vector<string>::iterator it = vecLogProb.begin(); it != vecLogProb.end(); it++)
                {
                    ListRecord.SetPrbNo(*it);
                    ListRecord.SetRvseContent(LogRvseCont);
                    ListRecord.SetRvsePerson(LogRvsePer);
                    ListRecord.SetUploadPerson(LogUpLoadPer);
                    vecData.push_back(ListRecord);
               }
                
            }
            else
            {
                vecData.push_back(*itr);
            }
           
        }
        bRet = true;
        return bRet;
    }
    std::string LogHandler::CompleStr(int strSize, std::string strOri)
    {
        int strOriSize = strOri.size();
        int lStrResult = strSize - strOriSize;
        string strAdd = " ";
        string strResult = "";
        while (lStrResult > 0)
        {
            strResult = strOri.insert(strOri.size(), strAdd);

            lStrResult = strSize - strResult.size();
        }
        return strResult;
    }
    bool  LogHandler::AddIndex(ListEntries LogBase)
    {
        bool bRet = false;
        string IndexPrbNo = "【问题单或变更号】";
        string IndexRvseContent = "【修改内容】";
        string IndexRvsPerson = "【修改人】";
        string IndexUpLoadPerson = "【提交人】";
        LogBase.SetPrbNo(IndexPrbNo);
        LogBase.SetRvseContent(IndexRvseContent);
        LogBase.SetRvsePerson(IndexRvsPerson);
        LogBase.SetUploadPerson(IndexUpLoadPerson);
        vecData.insert(vecData.begin(), LogBase);
        bRet = true;
        return bRet;
    }
    bool LogHandler::LimitOuput(int LimitSize)
    {
        int bRet = false;
        for (vector<ListEntries>::iterator itr = vecData.begin(); itr != vecData.end(); ++itr)
        {
            itr->SetPrbNo(CompleStr(LimitSize, itr->GetPrbNo()));
            itr->SetUploadPerson(CompleStr(LimitSize, itr->GetUploadPerson()));
            itr->SetRvsePerson(CompleStr(LimitSize, itr->GetRvsePerson()));
        }
        bRet = true;
        return bRet;
    }
    bool  LogHandler::DataParse(std::vector<ListEntries>& vecRecData)
    {
        bool bRet = false;
        if (DissProb(vecRecData))
        {
            
            ListEntries  ListLogBase;
            if (AddIndex(ListLogBase))
            {
                if (LimitOuput(EachRowLimit))
                {
                    //cout << "LogHandler Parse Sucessful" << endl;
                }
                else
                {
                    cout << "There is a problem in LimitRowOutput" << endl;
                }
            }
            else
            {
                cout << "There is a problem in AddIndex" << endl;
            }
        }
        else
        {
            cout << "There is a problem in DissProb" << endl;
        }
        bRet = true;
        return true;
    }
    std::vector<ListEntries> LogHandler::GetDataOutput()
    {
        return  vecData;
    }
    string  LogHandler::OutPath()
    {
        bool bRet = true;
        string OutPath;
        printf_s("Output path and format: ");
        cin >> OutPath;
        if (OutPath.find(".txt") != OutPath.npos)
        {
            m_pLogOp = new TxtOutput();
             
        }
        else if (OutPath.find(".xls") != OutPath.npos)
        {
            m_pLogOp = new ExcelOutput();
        }
        else
        {
            cout << "Out of Format Range" << endl;
            bRet = false;
        }
        return OutPath;
    }
    LogOutput* LogHandler::GetpLogOutput()
    {
        return m_pLogOp;
    }

}