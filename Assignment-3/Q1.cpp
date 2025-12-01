#include <iostream>
using namespace std;

#define maxsize 5

class Stack{
    int stack[maxsize];
    int top;

    public:
    Stack(){
        top=-1;
    }

    bool isEmpty(){
        return (top==-1);
    }

    bool isFull(){
        return (top==maxsize-1);
    }

    void push(int element){
        if (isFull()){
            cout<<"Stack is full, cannot be pushed"<<endl;
            return;
        }
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

    void peek(){
        if (isEmpty()){
            cout<<"Stack is empty, cannot pop"<<endl;
            return;
        }
        cout<<stack[top]<<endl;
    }
};

int main(){
    int choice=0;
    Stack s;
    while (true){
        cout<<endl<<"Choose a number:";
        cout<<endl<<"1. Check if stack is empty";
        cout<<endl<<"2. Check if stack is full";
        cout<<endl<<"3. Add an element to stack";
        cout<<endl<<"4. Pop an element";
        cout<<endl<<"5. Show stack";
        cout<<endl<<"6. Peek";
        cout<<endl<<"7. Exit"<<endl; 
        cin>>choice;

        if (choice==1){
            if (s.isEmpty()){
                cout<<endl<<"Stack is empty"<<endl;
            }
            else{
                cout<<endl<<"Stack is not empty"<<endl;
            }
        }

        else if (choice==2){
            if (s.isFull()){
                cout<<endl<<"Stack is full"<<endl;
            }
            else{
                cout<<endl<<"Stack is not full"<<endl;
            }
        }

        else if (choice==3){
            int element;
            cout<<"Enter element to insert"<<endl;
            cin>>element;
            s.push(element);
        }

        else if (choice==4){
            s.pop();
        }

        else if (choice==5){
            s.display();
        }

        else if (choice==6){
            s.peek();
        }

        else if (choice==7){
            cout<<endl<<"Program terminated";
            return 0;
        }
    }
    
    return 0;   
}