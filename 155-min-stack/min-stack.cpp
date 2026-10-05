class MinStack {
    stack<long long> st;
    long long min;

public:
    MinStack() {
        min = LLONG_MAX;
    }

    void push(int value) {
        if (st.empty()) {
            min = value;
            st.push(value);
        }
        else if (value >= min) {
            st.push(value);
        }
        else {
            st.push(2LL * value - min);
            min = value;
        }
    }

    void pop() {
        if (st.empty()) return;

        long long x = st.top();
        st.pop();

        if (x < min) {
            min = 2LL * min - x;
        }
    }

    int top() {
        long long x = st.top();

        if (x < min)
            return (int)min;

        return (int)x;
    }

    int getMin() {
        return (int)min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */