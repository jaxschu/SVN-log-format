/*
* @copyright 2019, Zhejiang Unittec Co.,Ltd
* @author Xu Peili  Liu Chao
* @date 6-19-2019 Liu chao: Create the file.
* @file  LogHandler.h
*/
#ifndef   LOG_HANDLER_H
#define   LOG_HANDLER_H
#include  <vector>
#include  <string>
#include  "LogOutput.h"
#include  "LogListEnTryInfo.h"
using namespace std;
namespace LOG
{

    class  LogHandler
    {
    public:
        LogHandler();
        ~LogHandler();
        
        bool LimitOuput(int LimitSize);
        
        bool AddIndex(ListEntries LogBase);
        
        vector<string> SubProbStr(std::string strProb,int count);
        
        int  CountProbNo(string strProb);
        
        std::string CompleStr(int strSize, std::string strOri);
        
        bool DissProb(std::vector<ListEntries>& vecRecData);
        
        bool  DataParse(std::vector<ListEntries>& vecRecData);
        
        std::vector<ListEntries> GetDataOutput();
        
        string  OutPath();
        
        LogOutput* GetpLogOutput();
    private:
        std::vector<ListEntries> vecData;
        LogOutput* m_pLogOp;
    };
}
#endif
