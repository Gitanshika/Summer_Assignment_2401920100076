//q1
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int max_len = 0;
        unordered_map<char,int> mpp;

        for(int i = 0; i < s.length(); i++) {
            mpp[s[i]]+=1;
            while (mpp[s[i]]>1){
                    mpp[s[l]]--;
                    l++;
                }
            max_len=max(max_len,i-l+1);
            
 
        }

        return max_len;
    }
};

//q2
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        
        unordered_map<char, int> s1Count;
        unordered_map<char, int> s2Count;
        
        for (int i = 0; i < s1.length(); i++) {
            s1Count[s1[i]]++;
            s2Count[s2[i]]++;
        }
        
        if (s1Count == s2Count) {
            return true;
        }
        
        int left = 0;
        for (int right = s1.length(); right < s2.length(); right++) {
            s2Count[s2[right]]++;
            s2Count[s2[left]]--;
            
            if (s2Count[s2[left]] == 0) {
                s2Count.erase(s2[left]);
            }
            
            left++;
            
            if (s1Count == s2Count) {
                return true;
            }
        }
        
        return false;        
    }
};

//q3
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1 = s.size(), n2 = p.size();
        vector<int> ans;

        if (n1 < n2) return ans;

        vector<int> a(26, 0), b(26, 0);

        for (int i = 0; i < n2; i++) {
            a[p[i] - 'a']++;
            b[s[i] - 'a']++;
        }

        if (a == b) ans.push_back(0);

        for (int i = n2; i < n1; i++) {
            b[s[i] - 'a']++;
            b[s[i - n2] - 'a']--;

            if (a == b) {
                ans.push_back(i - n2 + 1);
            }
        }

        return ans;
    }
};