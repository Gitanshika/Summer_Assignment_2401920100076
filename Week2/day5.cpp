//q1
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> result;

        for(string s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());  
            mp[temp].push_back(s);           
        }

        
        for(auto it : mp) {
            result.push_back(it.second);
        }

        return result;
    }
};

//q2
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int k = 0;   // write pointer

        while (i < n) {
            int j = i;
            
            
            while (j < n && chars[j] == chars[i]) {
                j++;
            }

            int count = j - i;
            chars[k++] = chars[i];

           
            if (count > 1) {
                string s = to_string(count);
                for (char c : s) {
                    chars[k++] = c;
                }
            }

            i = j;
        }

        return k;
    }
};


//q3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        ans = ""

        for i in range(n):
            for j in range(i, n):
                sub = s[i:j+1]
                if sub == sub[::-1]:
                    if len(sub) > len(ans):
                        ans = sub;
        return ans;


}
};