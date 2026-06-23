class MyQueue {
public:
    stack<int> in, out;

    MyQueue() {}

    void push(int x) {
        in.push(x);
    }

    int pop() {
        if(out.empty()) {
            while(!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }

        int x = out.top();
        out.pop();
        return x;
    }

    int peek() {
        if(out.empty()) {
            while(!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }

        return out.top();
    }

    bool empty() {
        return in.empty() && out.empty();
    }
};

//q2
class RecentCounter {
public:
    queue<int>q;
    RecentCounter() {
      
    }
    
    int ping(int t) {
        q.push(t);
        while(q.front() < t - 3000) {
            q.pop();
        }

    return q.size();
    }
};

//q3
lass Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        for(int i = 0; i < n; i++) {

            if(i % k == 0)
                left[i] = nums[i];
            else
                left[i] = max(left[i - 1], nums[i]);
        }
        for(int i = n - 1; i >= 0; i--) {

            if(i == n - 1 || (i + 1) % k == 0)
                right[i] = nums[i];
            else
                right[i] = max(right[i + 1], nums[i]);
        }

        vector<int> ans;

        for(int i = 0; i <= n - k; i++) {
            ans.push_back(max(right[i], left[i + k - 1]));
        }

        return ans;
    }
};