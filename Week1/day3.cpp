//1
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    int c=0;
    int i=0;
    int j=i;
    for  (int i=0;i<nums.size();i++){
        if(nums[i]!=0){
            nums[j]=nums[i];
            j++;
        }
        
     } 
    while(j<nums.size()){
        nums[j]=0;
        j++;
     }
   
    }

};

//2
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int l = 0, r = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (abs(nums[l]) > abs(nums[r]))
                ans[i] = nums[l] * nums[l++];
            else
                ans[i] = nums[r] * nums[r--];
        }

        return ans;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;
        int c=0;

        while (left < right) {
            c =(right - left) * min(height[left], height[right]);
            maxArea=max(c,maxArea);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;        
    }
};