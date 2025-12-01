#include <iostream>
#include <string>
using namespace std;

#define maxsize 100

class Stack{
    char stack[maxsize];
    int top;

    public:
    Stack(){
        top=-1;
    }

    bool isEmpty(){
        return (top==-1);
    }

    void push(char element){
        top++;
        stack[top]=element;
    }

    void display(){
        while (top!=-1){
            cout<<stack[top--];
        }
    }
};

int main(){
    string str;
    Stack s;
    cout<<"Enter string to be reversed: ";
    cin>>str;

    for (char ch:str){
        s.push(ch);
    }

    s.display();
    return 0;
}