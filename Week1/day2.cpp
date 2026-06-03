//q1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};

    Solution obj;

    if (obj.containsDuplicate(nums))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}


//q2
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxsum=INT_MIN,currsum=0;
        for(int i:nums){
            currsum+=i;
            maxsum=max(maxsum,currsum);
            if(currsum<0){
                currsum=0;
            }
        }
        return maxsum;
    }
};

//q3
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
    double max_value=0;
    double sum=0;
    for(int i=0;i<k;i++){
        sum+=nums[i];
    }  
    max_value=sum;
    for(int i=1;i<=nums.size()-k;i++){
        sum=sum-nums[i-1]+nums[i+k-1];
        max_value=max(max_value,sum);
    }
    return max_value/k;
    }
};



