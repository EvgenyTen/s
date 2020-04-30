#include <iostream>
#include <windows.h>
using namespace std;

int sleepTime = 0;
char path[1024];
PROCESS_INFORMATION pim;
STARTUPINFO sim;

int main(int argc, char* argv[])
{
    cout << "Master starting  !!  " << endl;
    cout << "Number of arguments in command line  :   " << argc << endl;
    cout << "List of arguments in command line  :   " << endl;
    for (int i = 0; i < argc; i++) { cout << i << "  " << argv[i] << endl; }
    sleepTime = atoi(argv[1]);
    cout << "Received sleepingTime  :   " << sleepTime << endl;
    memset(&sim, 0, sizeof(STARTUPINFO));
    cout << "Going to open application    " << endl;
    if (argc == 2)
    {
        DWORD CurrentPID = GetCurrentProcessId();
        cout << "Received master  PID number  : " << CurrentPID << endl;
        sprintf_s(path,"%s %u", "E:\\s\\Debug\\slave.exe", ::GetCurrentProcessId());// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
        CreateProcess(NULL, path, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &sim, &pim);
        cout << "Slave PID number  : " << pim.dwProcessId << endl;
        cout << "Slave Theread number  : " << pim.hProcess << endl;
        CloseHandle(pim.hProcess);
        CloseHandle(pim.hThread);
    }
    else if (argc == 3)
    {
        CreateProcess(path, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &sim, &pim);
        cout << "Slave PID number  : " << pim.dwProcessId << endl;
        cout << "Slave Theread number  : " << pim.hProcess << endl;
        CloseHandle(pim.hProcess);
        CloseHandle(pim.hThread);
    }
    else { cout << "Master error " << endl; }
    cout << "Going to Sleep  !!!!!!!!     " << endl;
    Sleep(sleepTime);
    system("pause");
    return 0;
}

