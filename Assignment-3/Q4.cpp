#include<iostream>
#include <string>
using namespace std;

#define N 100

class Conversion_Stack{
    public:
    char op_stack[N];
    string post_exp;
    int top;

    Conversion_Stack(){
        top=-1;
    }

    bool isEmpty(){
        return (top==-1);
    }

    bool isFull(){
        return (top==N-1);
    }

    void push (char op){
        if (isFull()){
            cout<<"Full Stack";
            return;
        }
        op_stack[++top]=op;
    }

    char pop(){
        return op_stack[top--];
    }

    int precedence (char ch){
        if (ch=='^') return 3;
        else if (ch=='*'||ch =='/') return 2;
        else return 1;
    }

    char peek(){
        return (op_stack[top]);
    }

    void append_str(char ch){
        post_exp+=ch;
    }

    string exp(){
        return post_exp;
    }
};

void postfix(string i){
    Conversion_Stack c;
    for (char ch:i){
        if (ch=='+'||'-'||'*'||'/'||'^'){
            int pre1=c.precedence (ch);
            while (true){
                if (c.isEmpty()) {
                    c.push (ch);
                    break;
                }
                char op=c.peek();
                int pre2=c.precedence (op);
                if (pre1>pre2) {
                    c.push(ch);
                    break;                    
                }
                else {
                    char x=c.pop();
                    c.append_str(x);
                }
            } 
        }
        else c.append_str(ch);
    }

    cout<<"Postfix is:"<<c.exp()<<endl;
}

int main(){
    string infix;
    cout<<"Enter Infix espression without spaces";
    cin>>infix;

    postfix(infix);
    return 0;
}