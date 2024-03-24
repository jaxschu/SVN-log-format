/**
* @copyright 2019, Zhejiang UniTTEC Co., Ltd.
* @author   liu chao
*/
/**
* @file   " TxtOutput.h"
*
*/
#ifndef  TXTOUTPUT_H
#define  TXTOUTPUT_H
#include "LogOutput.h"
namespace LOG
{
    class TxtOutput : public LogOutput
    {
    public:
        TxtOutput();
        ~TxtOutput();
        bool Output(string strOutput);
    };
}
#endif // ! TXTOUTPUT_H
