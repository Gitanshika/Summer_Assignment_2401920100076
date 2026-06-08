//q1
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

//q2
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mpp;
        queue<int> q;

        for (int i = 0; i < s.size(); i++) {
            mpp[s[i]]++;
            q.push(i);

            while (!q.empty() && mpp[s[q.front()]] > 1) {
                q.pop();
            }
        }

        if (!q.empty()) {
            return q.front();
        }

        return -1;
    }
};


//q3
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) return false;

        int freq[26] = {0};

        for (char c : magazine) {
            freq[c - 'a']++;
        }

        for (char c : ransomNote) {
            if (--freq[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};