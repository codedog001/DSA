#include<iostream>
using namespace std;
int main() {
  char st[] = "abcd";
  char c = 'a';
  char * ptr = st;
  int i=0;

  cout << "Address: " << &st<<endl;

  cout << "String: " << st<<endl;

    cout << "Index 0: " << st[0]<<endl;

    cout << "Index 0 using pointer pointing at string: " << ptr[0]<<endl;

        cout << "i+ptr: " << i+ptr<<endl;
cout << "i+ptr[0]: " << i+ptr[0]<<endl;

    cout << "10+ptr[10]: " << 10+ptr[10]<<endl;

    cout << "*(st+2): " << *(st+2) <<endl;
    
    cout << "*(st): " << *(st) <<endl;


    cout << "*(st)+i: " << *(st) + i <<endl;

      cout << "c+i: " << c + i <<endl;

       cout << "c+*(st): " << (c + *(st)) <<endl;
       cout << "(char)c+*(st): " << (char)(c + *(st)) <<endl;

       cout << "st[9]: " << st[9] <<endl;

      cout << "i[st] is: " << 3[st] <<endl;

      cout << "*(i+st) is: " << *(3+st) <<endl;




//   for(int i = 0; st[i] != '\0'; i++) {
//      cout << st[i] << *(st)+i << *(i+st) << i[st];
//   }
  return 0;
}