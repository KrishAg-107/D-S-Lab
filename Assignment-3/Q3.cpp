#include <iostream>
#include <string>
using namespace std;

#define maxsize 10

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
        cout<<element<<" added to stack"<<endl;
    }

    void pop(){
        if (isEmpty()){
            cout<<"Stack is empty, cannot pop"<<endl;
            return;
        }
        cout<<stack[top--]<<" popped"<<endl;
    }

    void display(){
        if (isEmpty()){
            cout<<"Stack is empty, cannot pop"<<endl;
            return;
        }
        while (top!=-1){
            cout<<stack[top--]<<endl;
        }
    }

    char peek(){
        return stack[top];
    }
};

int main(){
    string str;
    Stack s;
    cout<<"Enter parantheses string:";
    cin>>str;
    for (char ch:str){
        if (ch==')'){
            if ((s.isEmpty()) || (s.peek()!='(')){
                cout<<"Imbalance parantheses"<<endl;
                return 0;
            }
            else {
                s.pop();
            }
        }

        else if (ch=='('){
            s.push(ch);
        }
    }

    if (s.isEmpty()){
        cout<<"Balanced Parantheses";
    }
    else {
        cout<<"Imbalance parantheses"<<endl;
    }
    return 0;
    
}