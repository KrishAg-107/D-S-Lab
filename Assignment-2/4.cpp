#include <iostream>
#include <string>

using namespace std;

string conc (string str1,string str2){
    return str1+str2;
}

string reverse_(string str1){
    int n=str1.size();
    string rev_="";
    for (int i=n-1;i>=0;i--){
        rev_+=str1[i];
    }
    return rev_;
}

string vowel_remove(string str1){
    int n=str1.size();
    string str_="";
    for (int i=0;i<n;i++){
        char ch=tolower(str1[i]);
        if (!(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')){
            str_+=ch;
        }
    }
    return str_;
}

string lowercase(string str1){
    for (int i=0;i<str1.size();i++){
        str1[i]=tolower(str1[i]);
    }
    return str1;
}


int main(){
    //string str1="";
    //string str2="";
    string str1, str2;
    cout<<"Enter string 1:";
    cin>>str1;
    cout<<"Enter string 2";
    cin>>str2;

    string conc_=conc(str1, str2);
    cout<<conc_<<"\n";
    string reversed=reverse_(str1);
    cout<<reversed<<"\n";
    string removed=vowel_remove(str1);
    cout<<removed<<"\n";
    string lowered=lowercase(str2);
    cout<<lowered<<"\n";

    return 0;
}