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

    void insert_after_val(int exist_value, int new_value){
        if (head==nullptr) insert_begg(new_value);
        else {
            temp=head;
            while (temp!=nullptr && temp->data!=exist_value) temp=temp->next;
            if (temp==nullptr) return;
            newNode=new Node(new_value);
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }

    void insert_before_val(int exist_value, int new_value){
        if (head==nullptr) insert_begg(new_value);
        else {
            temp=head;
            while (temp!=nullptr && temp->next->data!=exist_value) temp=temp->next;
            if (temp==nullptr) return;
            newNode=new Node(new_value);
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }

    void insert_atpos(int pos, int value){
        if (pos==0) insert_begg(value);
        else{
            int current_pos=0;
            temp=head;
            while (current_pos<pos-1) {
                temp=temp->next;
            
            }
            newNode=new Node(value);
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }

    void del_begg(){
        if (head==nullptr) return;
        else{
            temp=head;
            head=head->next;
            delete temp;//or temp->next=nullptr
        }
    }

    void del_end(){
        if (head==nullptr) return;
        else if (head->next==nullptr){
            delete head;
            head=nullptr;
        }
        else{
            temp=head;
            while (temp->next->next!=nullptr) temp=temp->next;
            temp->next=nullptr;
        }
    }

    void del_value(int value){
        if (head==nullptr) return;
        else{
            Node*pre=nullptr;
            temp=head;
            while (temp->data!=value) {
                pre=temp;
                temp=temp->next;
            }
            if (temp==nullptr) return;
            else if(temp==head) del_begg();
            else pre->next=temp->next;
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

    void display_node(int value){
        if (head==nullptr) return;
        else{
            int counter=1;
            temp=head;
            while (temp->data!=value){
                temp=temp->next;
                counter++;
            }
            cout<<"Value found at position"<<counter<<endl;
        }
    }
};

int main(){
    SLL L;
    int choice, value, key;
    while(true) {
        cout << "1.Insert Beginning 2.Insert End 3.Insert After 4.Insert Before\n";
        cout << "5.Delete Beginning 6.Delete End 7.Delete Node 8.Display 9.Exit\n";
        cin >> choice;
        switch(choice) {
            case 1: cin >> value; L.insert_begg(value); break;
            case 2: cin >> value; L.insert_end(value); break;
            case 3: cin >> key >> value; L.insert_after_val(key, value); break;
            case 4: cin >> key >> value; L.insert_before_val(key, value); break;
            case 5: L.del_begg(); break;
            case 6: L.del_end(); break;
            case 7: cin >> key;L.del_value(int value); break;
            case 8: L.display(); break;
            case 9: return 0;
        }
    }
    return 0;

}
