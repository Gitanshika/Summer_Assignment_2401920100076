//q1
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(temperatures[j] > temperatures[i]) {
                    answer[i] = j - i;
                    break; 
                }
            }
        }
        return answer;
    }
};

//q2
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string t : tokens) {
            if (t != "+" && t != "-" && t != "*" && t != "/") {
                st.push(stoi(t));
            } else {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                if (t == "+") st.push(a + b);
                else if (t == "-") st.push(a - b);
                else if (t == "*") st.push(a * b);
                else st.push(a / b);
            }
        }

        return st.top();
    }
};

//q3
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(),h,left,width;
        stack<int> st;
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                h = heights[st.top()];
                st.pop();
                left = st.empty() ? -1 : st.top();
                width = i - left - 1;
                ans = max(ans, h * width);
            }
            st.push(i);
        }
        return ans;
    }
};