/*
* @copyright 2019, Zhejiang Unittec Co.,Ltd
* @author Xu Peili
* @date 6-19-2019 Xu Peili: Create the file.
*/

#include "LogInput.h"
#include "CvtTool.h"
#include "LogParser.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

namespace LOG
{
    LogInput::LogInput():
        m_pLgTxtPsr(NULL),
        m_pLgXmlPsr(NULL)
    {
    }

    LogInput::~LogInput(void)
    {
    }

    string LogInput::GetTextLctn()
    {
        printf_s("Input Absolute File Location:");
        string sFileLctn;
        cin >> sFileLctn;
        return sFileLctn;
    }

    AllSearchKey LogInput::GetSearchKeys(string sFileName)
    {
        AllSearchKey structAsk;
        {
            if (sFileName.find(".txt") != string::npos)
            {
                structAsk = m_pLgTxtPsr->SearchKeys(sFileName);
            }
            else if (sFileName.find(".xml") != string::npos)
            {
                structAsk = m_pLgXmlPsr->SearchKeys(sFileName);
            }
            else
            {
                //
            }
        }
        return structAsk;
    }

    vector<vector<string>> LogInput::StoreSingleStr(vector<string>& aSingleAllStr, string sFileName)
    {
        if (aSingleAllStr.size() != 0)
        {
            vector<vector<string>> aAllStr;
            if (sFileName.find(".txt") != string::npos)
            {
                m_pLgTxtPsr->m_aAllInStr.push_back(aSingleAllStr);
                aAllStr = m_pLgTxtPsr->m_aAllInStr;
            }
            else if (sFileName.find(".xml") != string::npos)
            {
                m_pLgXmlPsr->m_aAllInStr.push_back(aSingleAllStr);
                aAllStr = m_pLgXmlPsr->m_aAllInStr;
            }
            return aAllStr;
        }
        else
        {
            printf_s("Single String Data Vector is Empty\n\n");
        }
    }
    
    //xpl-core algorithm
    vector<ListEntries> LogInput::DeleteSameContent(vector<ListEntries>& aStrings)
    {
        if (aStrings.size() != 0)
        {
            bool isPassOn = false;
            for (vector<ListEntries>::iterator sitr = aStrings.begin(); sitr != aStrings.end(); )
            {
                if (isPassOn == false)
                {
                    for (vector<ListEntries>::iterator ditr = aStrings.begin() + 1; ditr != aStrings.end(); )
                    {
                        if (sitr->GetPrbNo() == ditr->GetPrbNo()
                            && sitr->GetRvseContent() == ditr->GetRvseContent()
                            && sitr->GetRvsePerson() == ditr->GetRvsePerson()
                            && sitr->GetUploadPerson() == ditr->GetUploadPerson()
                            /*&& sitr->GetDate() == ditr->GetDate()*/)
                        {
                            ditr = aStrings.erase(ditr);
                            isPassOn = false;
                        }
                        else
                        {
                            ++ditr;
                            isPassOn = true;
                        }
                    }
                }
                else
                {
                    ++sitr;
                }
            }
        }
        else
        {
            printf_s("No Content\n\n");
        }
        return aStrings;
    }

    bool LogInput::CheckFileVaild(string sFileName)
    {
        bool isValid = false;
        if (sFileName.find(".txt") != string::npos)
        {
            isValid = true;
        }
        else if (sFileName.find(".xml") != string::npos)
        {
            isValid = true;
        }
        else
        {
            isValid = false;
        }
        return isValid;
    }

    bool LogInput::ContentValidity(vector<string>& aSingleAll, string sFileName)
    {
        AllSearchKey structAsk;
        if (sFileName.find(".txt") != string::npos)
        {
            LogTxtInput clTxt;
            structAsk = clTxt.SearchKeys(sFileName);
        }
        else if (sFileName.find(".xml") != string::npos)
        {
            LogXmlInput clXml;
            structAsk = clXml.SearchKeys(sFileName);
        }
        else
        {
            //
        }
        //vector<bool> aBoolValue;

        bool bPrbNo = false;
        bool bRvseContent = false;
        bool bRvsePerson = false;
        bool bUploadPerson = false;

        bool isContentValid = false;
        for (vector<string>::iterator itr = aSingleAll.begin(); itr != aSingleAll.end(); ++itr)
        {
            if (bPrbNo == true)
            {
                bPrbNo = true;
            }
            else
            {
                if (itr->find(structAsk.m_sMarkPrbNo) != string::npos)
                {
                    bPrbNo = true;
                }
                else
                {
                    bPrbNo = false;
                }
            }

            if (bRvseContent == true)
            {
                bRvseContent = true;
            }
            else
            {
                if (itr->find(structAsk.m_sMarkRvseContent) != string::npos)
                {
                    bRvseContent = true;
                }
                else
                {
                    bRvseContent = false;
                }
            }

            if (bRvsePerson == true)
            {
                bRvsePerson = true;
            }
            else
            {
                if (itr->find(structAsk.m_sMarkRvsePerson) != string::npos)
                {
                    bRvsePerson = true;
                }
                else
                {
                    bRvsePerson = false;
                }
            }

            if (bUploadPerson == true)
            {
                bUploadPerson = true;
            }
            else
            {
                if (itr->find(structAsk.m_sMarkUploadPerson) != string::npos)
                {
                    bUploadPerson = true;
                }
                else
                {
                    bUploadPerson = false;
                }
            }

            if (bPrbNo == true
                && bRvseContent == true
                && bRvsePerson == true
                && bUploadPerson == true)
            {
                isContentValid = true;
                break;
            }
        }
        return isContentValid;
    }

    bool LogInput::Run()
    {
        vector<vector<string>> aPassOn;
        bool isFileValid = false;
        do
        {
            string sFileLctn = this->GetTextLctn();
            if ((sFileLctn == "q") || (sFileLctn == "quit") || (cin.eof()))
            {
                printf_s("Invalid Input\n\n");
                break;
            }
            else
            {
                //
            }
            bool bIsValid = CheckFileVaild(sFileLctn);
            if (bIsValid == true)
            {
                if (sFileLctn.find(".txt") != string::npos)
                {
                    m_pLgTxtPsr = new LogTxtInput();
                    vector<string> aSingleStr = m_pLgTxtPsr->ReadFile(sFileLctn);
                    if (ContentValidity(aSingleStr, sFileLctn) == false)
                    {
                        printf_s("Invalid Content\n\n");
                        break;
                    }
                    else
                    {
                        aPassOn = this->StoreSingleStr(aSingleStr, sFileLctn);
                        m_aAllListEntries = m_pLgTxtPsr->DataStorage(GetSearchKeys(sFileLctn), aPassOn, sFileLctn);
                        m_aAllListEntries = m_pLgTxtPsr->DataProcess(m_aAllListEntries);
                    }
                }
                else if (sFileLctn.find(".xml") != string::npos)
                {
                    m_pLgXmlPsr = new LogXmlInput();
                    vector<string> aSingleStr = m_pLgXmlPsr->ReadFile(sFileLctn);
                    if (ContentValidity(aSingleStr, sFileLctn) == false)
                    {
                        printf_s("Invalid Content\n\n");
                        break;
                    }
                    else
                    {
                        aPassOn = this->StoreSingleStr(aSingleStr, sFileLctn);
                        m_aAllListEntries = m_pLgXmlPsr->DataStorage(GetSearchKeys(sFileLctn), aPassOn, sFileLctn);
                        m_aAllListEntries = m_pLgXmlPsr->DataProcess(m_aAllListEntries);
                    }
                }
                else
                {
                    //
                }
            }
            else
            {
                printf_s("Incorrect File Location\n\n");
                //bIsValid = false;
                break;
            }
            isFileValid = bIsValid;
        } while (true);
        ///core-algorithm-by-xpl
        m_aAllListEntries = DeleteSameContent(m_aAllListEntries);
        return isFileValid;
    }

    vector<ListEntries> LogInput::PassListEntries()
    {
        return m_aAllListEntries;
    }
}