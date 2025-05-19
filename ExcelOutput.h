/**
* @copyright 2019, Zhejiang UniTTEC Co., Ltd.
* @author   liu chao
*/
/**
* @file   " XmlOutput.h"
*
*/
#ifndef  EXCELOUTPUT_H
#define  EXCELOUTPUT_H
#include "LogOutput.h"
namespace LOG
{
    class ExcelOutput : public LogOutput
    {
    public:
        ExcelOutput();
        ~ExcelOutput();
        bool Output(string strOutput);
    };
}
#endif // ! XMLOUTPUT_H
