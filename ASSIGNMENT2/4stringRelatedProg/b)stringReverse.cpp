#include<iostream>
#include<string>
#include<algorithm>       // to use the reverse func
using namespace std;

int main(){
    string str;
    cout<<"enter the string:";
    getline(cin,str);
    reverse(str.begin(),str.end());
    cout<<str<<endl;
    return 0;
}