#include <iostream>
using namespace std;

class StackOneQueue {
    queue<int> q;
public:
    void push(int x) {
        int n = q.size();
        q.push(x);
        for(int i = 0; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() { if(!q.empty()) q.pop(); }
    int top() { return q.empty() ? -1 : q.front(); }
    bool empty() { return q.empty(); }
};

int main() {
    StackOneQueue st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.top() << endl; st.pop();
    cout << st.top() << endl; st.pop();
    cout << st.top() << endl; st.pop();
}