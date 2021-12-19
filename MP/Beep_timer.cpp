#include <iostream> 
#include <unistd.h>
#include <windows.h> // WinApi header 

using namespace std;

int main() 
{ 
    cout << "WELCOME TO BEEP" << endl;
    while(true){
        for(int i=0; i<10; i++){
            Beep(523,500); // 523 hertz (C5) for 500 milliseconds     
            sleep(1);
            Beep(523,500);
        }
        sleep(300);
    }
    // cin.get(); // wait 
    return 0; 
}