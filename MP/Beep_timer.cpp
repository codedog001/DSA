#include <iostream> 
#include <unistd.h>
#include <windows.h> // WinApi header 
#include <stdio.h>
#include <sys/types.h>
#include<cwchar>
using namespace std;

int main() 
{ 
    cout << "WELCOME TO BEEP" << endl;
    cout << getpid() << endl;
    sleep(1);
    FreeConsole();
    while(true){
        for(int i=0; i<7; i++){
            Beep(523,500); // 523 hertz (C5) for 500 milliseconds     
            sleep(1);
            Beep(523,500);
        }
        AllocConsole();
        FILE* fp;

        freopen_s(&fp, "CONOUT$", "w", stdout);
        cout << "Kroge to guaranteed ho jaega." << endl;
        fclose(stdout);
        sleep(2);
        FreeConsole();
        sleep(300);
    }
    return 0; 
}//