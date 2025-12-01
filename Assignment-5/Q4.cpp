#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*next;

    Node(int value){
        data=value;
        next=nullptr;
    }
};

class SLL{
    private:
    Node *head, *newNode, *temp;

    public:
    SLL(){
        head=nullptr;
    }

    void insert_begg(int value){
        newNode=new Node(value);
        newNode->next=head;
        head=newNode;
    }

    void insert_end(int value){
        if (head==nullptr) insert_begg(value);
        else{
            temp=head;
            while (temp->next!=nullptr) temp=temp->next;
            newNode=new Node(value);
            temp->next=newNode;
        }
    }

    void display(){
        if (head==nullptr) return;
        temp=head;
        do {
            cout<<temp->data<<endl;
            temp=temp->next;
        } while (temp!=nullptr);
    }

    void reverse(){
        if (head==nullptr) return ;
        temp=nullptr;
        Node*current=head;
        newNode=nullptr;
        while(current!=nullptr){
            newNode=current->next;
            current->next=temp;
            temp=current;
            current=newNode;
        }
        head=temp;
    }
};

int main(){
    SLL L;
    L.insert_begg(1);
    L.insert_end(2);
    L.insert_end(3);
    L.insert_end(4);
    L.reverse();
    L.display();
    return 0;
}