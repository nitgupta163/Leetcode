/*
Time complexity = O(N*Max(nums[i]))
Result- TLE
class Solution {
    int solve(int ind, vector<int>& nums, int currAnd,
                vector<unordered_map<int,int>> &dp)
    {
        if(ind >= nums.size())
            return 0;
        if(dp[ind].find(currAnd) != dp[ind].end())
            return dp[ind][currAnd];
        
        int skip = solve(ind+1,nums,currAnd,dp);
        int noSkip = 0;
        if((nums[ind] & currAnd))
            noSkip = 1+solve(ind+1,nums,(nums[ind] & currAnd),dp);
        return dp[ind][currAnd] = max(skip,noSkip);
    }
public:
    int largestCombination(vector<int>& nums)
    {
        int i, n = nums.size();
        vector<unordered_map<int,int>> dp(n);
        // inital value of currAnd should be all bits 111...
        // which is greater than nums[i]
        return solve(0,nums,(1<<30)-1,dp);
    }
};
*/
class Solution {
public:
    int largestCombination(vector<int>& nums)
    {
        int i, ans = 0, count = 0;
        for(i=0; i<31; i++)
        {
            count = 0 ;
            for(int num : nums)
            {
                if(num & (1<<i))
                    count++;
            }
            ans = max(ans,count);
        }
        return ans;
    }
};