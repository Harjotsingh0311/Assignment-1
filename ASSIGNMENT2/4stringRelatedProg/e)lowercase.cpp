#include<iostream>
#include<string>
#include <cctype>   // for tolower()
                    //gives us character-handling functions like tolower(), toupper(), isalpha(), etc.
using namespace std;

int main(){
        char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;

    // if (ch >= 'A' && ch <= 'Z') {
    //     ch = ch + 32;  // ASCII conversion
    // }

    ch=tolower(ch);

    cout << "Lowercase character: " << ch << endl;
    return 0;
}