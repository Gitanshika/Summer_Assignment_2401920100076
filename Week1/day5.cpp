//q1
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(') st.push(')');
            else if (c == '{') st.push('}');
            else if (c == '[') st.push(']');
            else {
                if (st.empty() || st.top() != c)
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};


//q2
class Solution {
public:
    void reverseString(vector<char>& s) {
        int st=0;
        int e= s.size()-1;
        while(st<e){
            swap(s[st++],s[e--]);
        }
    }
};


//q3
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++)
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }
        return prefix;
    }
};