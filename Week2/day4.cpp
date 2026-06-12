//q1
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word, result = "";

        while (ss >> word) {
            reverse(word.begin(), word.end());
            result += word + " ";
        }

        result.pop_back(); 
        return result;
    }
};

//q2
class Solution {
public:
    string decodeString(string s) {
        stack<int> numstack;
        stack<string> stringstack;

        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                int num = 0;
                while(i<s.length() && isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                numstack.push(num);
                i--;
            }
            else if(s[i] == ']'){
                string temp = "";
                while(!stringstack.empty() && stringstack.top() != "["){
                    temp = stringstack.top() + temp;
                    stringstack.pop();
                }

                stringstack.pop();

                int repeat = numstack.top();
                numstack.pop();

                string repeated = "";
                while(repeat--){
                    repeated += temp;
                }
                stringstack.push(repeated);
            }
            else{
                stringstack.push(string(1,s[i]));
            }
        }

        string result = "";
        while(!stringstack.empty()){
            result = stringstack.top() + result;
            stringstack.pop();
        }
        return result;
    }
};

//q3
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate("", 2 * n, res);
        return res;
    }
    
private:
    void generate(string s, int len, vector<string>& res) {
        if (s.size() == len) {
            if (isValid(s)) res.push_back(s);
            return;
        }
        
        generate(s + '(', len, res);
        generate(s + ')', len, res);
    }
    
    bool isValid(string s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else count--;
            if (count < 0) return false;
        }
        return count == 0;
    }
};