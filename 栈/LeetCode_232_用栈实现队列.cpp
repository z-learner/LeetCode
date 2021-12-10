#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> t1;
    stack<int> t2;

    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        t1.push(x);

    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (t1.empty() && t2.empty()) return -1;
        if (t2.empty())
        {
            while (!t1.empty())
            {
                t2.push(t1.top());
                t1.pop();
                /* code */
            }
            
        }

        int res = t2.top();
        t2.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        //t2 可能为 空
        //return t2.top();
        int res = pop();
        t2.push(res);
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return t1.empty() && t2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */