
#include <iostream>
#include <windows.h>
using namespace std;

int PID = 0;

int main(int argc, char* argv[])
{
	cout << "Slave starting  :   " << endl;
	cout << "Number of arguments in command line  :   " << argc << endl;
	cout << "List of arguments in command line  :   " << endl;
	for (int i = 0; i < argc; i++) { cout << i << "  " << argv[i] << endl; }
	PID = atoi(argv[1]);
	cout << "***********************" << endl;
	cout << "Received PID  :   " << PID << endl;
	HANDLE hMasterProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID);// Get a handle to the process.
	cout << "PID transformation for waiting  from int PID  :  " << PID << "  to Handle PID : " << hMasterProcess << endl;
	cout << "***********************" << endl;
	cout << "Waiting.........." << endl;
	WaitForSingleObject(hMasterProcess, INFINITE);
	cout << "Application finished   " << endl;
	cout << "Exiting  " << endl;
	system("pause");
	ExitProcess(0);//return 0;
}
