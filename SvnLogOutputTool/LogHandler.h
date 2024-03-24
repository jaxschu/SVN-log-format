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
        //限制每行之间的字符个数
        bool LimitOuput(int LimitSize);
        //添加基础类【问题单号】。。。
        bool AddIndex(ListEntries LogBase);
        //分割问题单号
        vector<string> SubProbStr(std::string strProb,int count);
        //计算问题单号的数目
        int  CountProbNo(string strProb);
        //对少于要求的字符数的字符串进行填充
        std::string CompleStr(int strSize, std::string strOri);
        //对存在多个订单号的进行分解
        bool DissProb(std::vector<ListEntries>& vecRecData);
        //对输入的文件信息，进行解析以及处理(提取简化信息以及重复处理)
        bool  DataParse(std::vector<ListEntries>& vecRecData);
        //取得解析处理后的文件信息
        std::vector<ListEntries> GetDataOutput();
        //获取输出路径
        string  OutPath();
        //得到输出指针
        LogOutput* GetpLogOutput();
    private:
        std::vector<ListEntries> vecData;
        LogOutput* m_pLogOp;
    };
}
#endif
