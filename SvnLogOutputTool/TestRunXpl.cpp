/*
* @copyright 2019, Zhejiang Unittec Co.,Ltd
* @author Xu Peili, Liu Chao
* @date 6-19-2019 Xu Peili: Create the file.
*/

#include "LogInput.h"
#include "LogHandler.h"
#include "LogOutput.h"
#include "TxtOutput.h"
#include "ExcelOutput.h"
using namespace LOG;

int main()
{
    vector<ListEntries> vecOutput;
    string  strOutPath = "";
    LogInput cLogIp;
    bool isValid = cLogIp.Run();
    vector<ListEntries> aAll = cLogIp.PassListEntries();
    //test
    //for (vector<ListEntries>::iterator itr = aAll.begin(); itr != aAll.end(); ++itr)
    //{
    //    //cout << itr->m_sListDate << endl;
    //    //cout << itr->m_sListLineDown << endl;
    //    //cout << itr->m_sListLineUp << endl;
    //    cout << itr->GetPrbNo() << endl;
    //    cout << itr->GetRvseContent() << endl;
    //    cout << itr->GetRvsePerson() << endl;
    //    cout << itr->GetUploadPerson() << endl;
    //}
    
    if (isValid)
    {
        LogHandler cLogHr;
        if (cLogHr.DataParse(aAll))
        {
            vecOutput = cLogHr.GetDataOutput();
            LogOutput* pLogOp = NULL;
           /* cLogOp = new TxtOutput();*/
            strOutPath = cLogHr.OutPath();
            pLogOp = cLogHr.GetpLogOutput();
                if (pLogOp->RecData(vecOutput))
                {
                    if (pLogOp->Output(strOutPath))
                    {
                        cout << "Output Success" << endl;
                    }
                    else
                    {
                        cout << "Output Error" << endl;
                    }
                }
                else
                {
                    cout << "There's a Problem in Output RecData" << endl;
                }
            
        }
        else
        {
            cout << "There's a Problem in LogHandler DataParse" << endl;
        }
    }
    else
    {
        cout << "There's a Problem in LogInput" << endl;
    }
    system("pause");
}