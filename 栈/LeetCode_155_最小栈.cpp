#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
实现一 ： 栈 中 计算每一步的 最小值
空间 换 时间 的思想
*/
class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int, int>> st;
    MinStack() {

    }
    
    void push(int x) {
        if (st.empty()) st.push(make_pair(x, x));
        else
        {
            if (x <= st.top().second)
            {
                st.push(make_pair(x, x));
            }
            else  
            {
                st.push(make_pair(x, st.top().second));
            }
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;

    }
    
    int getMin() {
        return st.top().second;
    }
};

/*
实现二 ： 建立辅助最小栈
空间 换 时间 的思想
*/
class MinStack {
public:
    stack<int> st;
    stack<int> min_st;
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if (st.empty())
        {
            st.push(x);
            min_st.push(x);
            return;
        }

        st.push(x);
        if (x <= min_st.top())
            min_st.push(x);
    }
    
    void pop() {
        int res = st.top();
        st.pop();
        if (res == min_st.top())
            min_st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};

/*
实现三 ： 用负数 建立标记
难懂

将 数据 改为 long long  因为 此种方法 涉及到 int 的 加减 可能会 溢出
*/
class MinStack {
public:
    stack<int> st;
    int min;
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if (st.empty())
        {
            st.push(0);
            min = x;
        }
        else  
        {
            int temp = x - min;
            st.push(temp);
            if (temp < 0) min = x;
        }
    }
    
    void pop() {

        int temp = st.top();
        st.pop();
        if (temp < 0)
        {
            min = min - temp;
        }
    }
    
    int top() {
        int res = st.top();
        if (res < 0) return min;
        else return res + min;
    }
    
    int getMin() {
        return min;
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
