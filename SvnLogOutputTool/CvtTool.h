/*
* @copyright 2019, Zhejiang Unittec Co.,Ltd
* @author Xu Peili
* @date 6-19-2019 Xu Peili: Create the file.
*/

#ifndef CVT_TOOL_H
#define CVT_TOOL_H

#include <string>
#include <istream>
#include <cstdio>
#include <sstream>
#include <codecvt>
#include<cstring>
using namespace std;

namespace LOG
{
    class CVT
    {
    public:
        CVT();
        ~CVT();

        //ANSI to UTF-8 Converter
        string cvtTool(string str);
    };
}
#endif