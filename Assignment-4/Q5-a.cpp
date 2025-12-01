#include <iostream>
using namespace std;

class StackTwoQueues {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop() { if(!q1.empty()) q1.pop(); }
    int top() { return q1.empty() ? -1 : q1.front(); }
    bool empty() { return q1.empty(); }
};

int main() {
    StackTwoQueues st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.top() << endl; st.pop();
    cout << st.top() << endl; st.pop();
    cout << st.top() << endl; st.pop();
}