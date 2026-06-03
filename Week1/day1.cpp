
//q1
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;

        for(int i = 0; i < nums.size(); i++) {
            int c = target - nums[i];

            if(mpp.find(c) != mpp.end()) {
                return {mpp[c], i};
            }

            mpp[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    Solution obj;
    vector<int>ans=obj.twoSum(nums,target);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;


}

//q2
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int i = 1;

        for (int j = 1; j < n; j++) {
            if (nums[j] != nums[i - 1]) {
                nums[i] = nums[j];
                i++;
            }
        }

        return i;
    }
};


//q3

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            maxProfit= max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};
