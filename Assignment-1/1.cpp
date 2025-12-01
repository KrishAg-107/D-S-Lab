#include <iostream>
using namespace std;
int arr[100];
int size_ = 0;
void create() {
    cout << "Enter number of elements (max 100) : ";
    cin >> size_;
    if(size_>100){
    cout<<"Enter valid size_"<<endl;
    cin >> size_;
    }
    cout << "Enter " << size_ << " elements:\n";
    for (int i = 0; i < size_; i++)
        cin >> arr[i];
}

void display() {
    if (size_ == 0) {
        cout << "Empty Array.\n";
        return;
    }
    cout << "Array Elements: ";
    for (int i = 0; i < size_; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void insert() {
    if (size_ == 100)
        cout << "Array is full. Cannot insert more elements"<<endl;
    else{
    int n, in;
    cout << "Enter no. to insert: ";
    cin >> n;
    cout << "Enter position to insert : ";
    cin >> in;
    if (in < 0 || in > size_) {
        cout << "Enter a valid position"<<endl;
        return;
    }
    for (int i = size_; i > in; i--) 
        arr[i] = arr[i-1];
    arr[in] = n;
    ++size_;
    cout << "Element inserted"<<endl;
}
}

void delete_num() {
    if (size_ == 0) {
        cout << "Empty Array"<<endl;
        return;
    }
    int in;
    cout << "Enter position to delete : ";
    cin >> in;
    if (in < 0 || in >= size_) {
        cout << "Invalid position"<<endl;
        return;
    }
    cout << "Deleted"<< endl;
    for (int i = in; i < size_ - 1; i++)
        arr[i] = arr[i + 1];
    --size_;
}

void lin_search() {
    int n;
    cout << "Enter element to search for: ";
    cin >> n;
    for (int i = 0; i < size; i++) {
        if (arr[i] == n) {
            cout << "Element found at index " << i << "\n";
            return;
        }
    }
    cout << "Element not found" <<endl;
}

int main() {
    int choice;
    cout << "MENU -\n1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT"<<endl;
        cout << "Enter : ";
        cin >> choice;
    while(choice!=6) {
        
        switch(choice) {
            case 1:
            create();
            break;
            case 2:
            display();
            break;
            case 3:
            insert();
            break;
            case 4:
            delete_num();
            break;
            case 5:
            lin_search();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Enter 1-6"<<endl;
            }
            cout << "MENU -\n1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT"<<endl;
            cout << "Enter : ";
            cin >> choice;
        }
        return 0;
    }
