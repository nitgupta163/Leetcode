class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
            sort(nums.begin(),nums.end());
        long long int ans = 0;
        int i, n = nums.size();
        for(i=0; i<n; i++)
        {   
            auto l = lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i]);
            auto r = upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i]);
            ans += r-l;
        }   
        return ans;
    }
};