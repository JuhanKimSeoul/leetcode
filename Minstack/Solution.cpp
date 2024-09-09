#include <vector>
#include <algorithm>

using namespace std;

class MinStack {
private:
    vector<int> v;
    vector<int> min_manager;
public:
    MinStack() {
        v.clear();
        min_manager.clear();
    }
    
    void push(int val) {
        if(v.empty())
        {
            min_manager.push_back(val);
        }
        else
        {
            min_manager.push_back(min(min_manager.back(), val));
        }
        v.push_back(val);
    }
    
    void pop() {
        min_manager.pop_back();
        v.pop_back();
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
        return min_manager.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */