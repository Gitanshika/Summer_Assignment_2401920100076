//q1
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        for (int i = 0; i <= n - m; i++) {
            int j = 0;

            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }

            if (j == m) {
                return i;
            }
        }

        return -1;
    }
};

//q2
class Solution {
public:
    bool isSubsequence(string s, string t) {
      int i=0;
      int j=0;
      //while(i<s.size()){
        while(j<t.size()){
            if(t[j]!=s[i]){
                j+=1;
            }
            else{
                i+=1;
                j+=1;
                //break;
            }
        }
      
    return (i==s.size());
    }

    
};


//q3
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string temp = s + s;
        temp = temp.substr(1, temp.size() - 2);

        return temp.find(s) != string::npos;
    }
};