/*
* @copyright 2019, Zhejiang Unittec Co.,Ltd
* @author Xu Peili
* @date 6-19-2019 Xu Peili: Create the file.
*/

#ifndef LOG_XML_INPUT_H
#define LOG_XML_INPUT_H

#include "AllSearchKeys.h"
#include "LogParser.h"
#include <objbase.h> 
#include <msxml6.h> 
#include <string>
#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#import <msxml3.dll> raw_interfaces_only

using namespace MSXML2;
using namespace std;

namespace LOG
{
    class LogXmlInput : public LogParser
    {
    public:
        AllSearchKey SearchKeys(string sFileName)
        { 
            //Get xml file Content
            if (sFileName.find(".xml") != sFileName.npos)
            {
                m_structXmlAsk.m_sMarkPrbNo = "";
                m_structXmlAsk.m_sMarkRvseContent = "";
                m_structXmlAsk.m_sMarkUploadPerson = "";
                m_structXmlAsk.m_sMarkUploadPerson = "author";
            }
            else
            {
                printf_s("Failure To Catch Keywords\n\n");
                exit(0);
            }
            return m_structXmlAsk;
        }

        //vector<string> ReadFile(string sFileName)
        //{
        //    HRESULT hr = CoInitialize(NULL);
        //    if (SUCCEEDED(hr))
        //    {
        //        try
        //        {
        //            MSXML2::IXMLDOMDocument2Ptr xmlDoc;
        //            hr = xmlDoc.CreateInstance(__uuidof(MSXML2::DOMDocument60),
        //                NULL, CLSCTX_INPROC_SERVER);
        //            // TODO: if (FAILED(hr))...

        //            if (xmlDoc->load(_T("input.xml")) != VARIANT_TRUE)
        //            {
        //                printf("Unable to load input.xml\n");
        //            }
        //            else
        //            {
        //                printf("XML was successfully loaded\n");

        //                xmlDoc->setProperty("SelectionLanguage", "XPath");
        //                MSXML2::IXMLDOMNodeListPtr wheels = xmlDoc->selectNodes("/Car/Wheels/*");
        //                printf("Car has %u wheels\n", wheels->Getlength());

        //                MSXML2::IXMLDOMNodePtr node;
        //                node = xmlDoc->createNode(MSXML2::NODE_ELEMENT, _T("Engine"), _T(""));
        //                node->text = _T("Engine 1.0");
        //                xmlDoc->documentElement->appendChild(node);
        //                hr = xmlDoc->save(_T("output.xml"));
        //                if (SUCCEEDED(hr))
        //                    printf("output.xml successfully saved\n");
        //            }
        //        }
        //        catch (_com_error &e)
        //        {
        //            printf("ERROR: %ws\n", e.ErrorMessage());
        //        }
        //        CoUninitialize();
        //    }
        //}

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
                        if (sFileName.find(".xml") != string::npos)
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
        AllSearchKey m_structXmlAsk;
        CVT m_CvtTool;
    };
}

#endif // !LOG_XML_INPUT_H
