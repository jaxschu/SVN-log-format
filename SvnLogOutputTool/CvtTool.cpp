/*
* @copyright 2019, Zhejiang Unittec Co.,Ltd
* @author Xu Peili
* @date 6-19-2019 Xu Peili: Create the file.
*/

#include <string>
#include <istream>
#include <cstdio>
#include <sstream>
#include <codecvt>
#include<cstring>
#include "CvtTool.h"
using namespace std;

using WCHAR_GBK = codecvt_byname<wchar_t, char, mbstate_t>;
using WCHAR_UTF8 = codecvt_utf8<wchar_t>;
#define GBK_NAME ".936"

namespace LOG
{
    CVT::CVT()
    {
    }

    CVT::~CVT()
    {
    }

    string CVT::cvtTool(string str)
    {
        {
            // gbk unicode֮
            wstring_convert<WCHAR_GBK>  cvtGBK(new WCHAR_GBK(GBK_NAME));
            // utf8 unicode֮
            wstring_convert<WCHAR_UTF8> cvtUTF8;
            //  utf8ת Ϊunicode
            wstring ustr = cvtUTF8.from_bytes(str);
            //  unicodeת Ϊgbk
            string sResult = cvtGBK.to_bytes(ustr);
            return sResult;
        }
    }
}