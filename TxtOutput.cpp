/*
* @copyright 2019, Zhejiang Unittec Co.,Ltd
* @author   Liu Chao
* @date 6-26-2019 Liu chao: Create the file.
* @file  TxtOutput.cpp
*/
#include "TxtOutput.h"
#include <iostream>
#include <fstream>
namespace LOG
{
    TxtOutput::TxtOutput()
    {

    }
    TxtOutput::~TxtOutput()
    {

    }
    bool TxtOutput::Output(string strOutput)
    {
        bool bRet = false;
        vector<ListEntries> vecTxtOutput;
        this->SetOutPath(strOutput);
        string strOutputPath = this->GetOutPath();
        vecTxtOutput = this->GetData();
        ofstream osOutputFile;//ofstream outfile("E:\\myfile.dat", ofstream::app); 
        /* osOutputFile.open(strOutPath);*/
        /*printf_s("Output Absolute File Location:");*/
        /*cin >> strOutPath;*/
        osOutputFile.open(strOutputPath);
        //osOutputFile.open("D:\\Repo\\PS6svnLog\\testSVNLogOutput.txt");
        if (!osOutputFile)
        {
            cout << "Output Document Open Error\n\n";
        }
        else
        {
            for (vector<ListEntries>::iterator itr = vecTxtOutput.begin(); itr != vecTxtOutput.end(); ++itr)
            {
                osOutputFile << itr->GetPrbNo() << itr->GetUploadPerson()
                    << itr->GetRvsePerson() << itr->GetRvseContent() << endl;
            }
            osOutputFile << "Write  In Successful";
            bRet = true;
        }
        osOutputFile.close();
       
        return bRet;
    }
}