#include<iostream>
#include<string>
using namespace std;

int main(){
    string str,result="";
    cout<<"enter the string :";
    getline(cin,str);
    for(char ch:str){
        if(!(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')){
            result+=ch;
        }
    }
    cout<<"The string without vowels is :"<<result<<endl;

    return 0;
}