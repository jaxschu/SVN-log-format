/*
* @copyright 2019, Zhejiang Unittec Co.,Ltd
* @author Xu Peili
* @date 6-19-2019 Xu Peili: Create the file.
*/

#ifndef LOG_TXT_INPUT_H
#define LOG_TXT_INPUT_H

#include "AllSearchKeys.h"
#include "LogParser.h"
#include <string>
using namespace std;

namespace LOG
{
    class LogTxtInput : public LogParser
    {
    public:
        AllSearchKey SearchKeys(string sFileName)
        {
            //Get txt file Content
            if (sFileName.find(".txt") != sFileName.npos)
            {
                m_structTxtAsk.m_sMarkPrbNo = "���ⵥ������";
                m_structTxtAsk.m_sMarkRvseContent = "��  ��  ��  ��";
                m_structTxtAsk.m_sMarkRvsePerson = "��    ��    ��";
                m_structTxtAsk.m_sMarkUploadPerson = "+0800";
            }
            else
            {
                printf_s("Failure To Catch Keywords\n\n");
                exit(0);
            }
            return m_structTxtAsk;
        }

        vector<string> ReadFile(string sFileName)
        {
            ifstream* isInputFile = new ifstream();
            isInputFile->open(sFileName);
            if (!isInputFile->is_open())
            {
                cout << "Unable to Read the File\n\n";
                system("pause");
                exit(0);
            }
            else
            {
                if (isInputFile != NULL)
                {
                    string m_sVar;
                    while (getline(*isInputFile, m_sVar))
                    {
                        if (sFileName.find(".txt") != string::npos)
                        {
                            m_sVar = m_CvtTool.cvtTool(m_sVar);
                        }
                        else
                        {
                            //
                        }
                        //cout << m_sVar << endl << endl << endl;
                        m_aSingleAllInStr.push_back(m_sVar);
                    }
                }
                else
                {
                    printf_s("ifstream Exception\n\n");
                }
                return m_aSingleAllInStr;
            }
            isInputFile->clear();
            isInputFile->close();
        }
    private:
        AllSearchKey m_structTxtAsk;
        CVT m_CvtTool;
    };
}


#endif // !LOG_TXT_INPUT_H