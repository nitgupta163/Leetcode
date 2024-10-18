class Solution
{
    int countSubsetsRecursive(vector<int>& nums, int index, int currentOr,
                              int targetOr, vector<vector<int>>& memo)
    {
        // Base case: reached the end of the array
        if (index == nums.size()) {
            return (currentOr == targetOr) ? 1 : 0;
        }

        // Check if the result for this state is already memoized
        if (memo[index][currentOr] != -1) {
            return memo[index][currentOr];
        }

        // Don't include the current number
        int countWithout =
            countSubsetsRecursive(nums, index + 1, currentOr, targetOr, memo);

        // Include the current number
        int countWith = countSubsetsRecursive(
            nums, index + 1, currentOr | nums[index], targetOr, memo);

        // Memoize and return the result
        return memo[index][currentOr] = countWithout + countWith;
    }
public:
    // Check editorital, several solutions there
    int countMaxOrSubsets(vector<int>& nums)
    {
        int n = nums.size();
        int maxOrValue = 0;

        // Calculate the maximum OR value
        for (int num : nums) {
            maxOrValue |= num;
        }

        vector<vector<int>> memo(n, vector<int>(maxOrValue + 1, -1));

        return countSubsetsRecursive(nums, 0, 0, maxOrValue, memo);
    }
};
/*class Solution {
    void solve(int ind,vector<int>& nums, int &ans,
               const int &targetOrVal,int &currOrVal)
    {
        if(ind>=nums.size())
            return ;
        int temp = currOrVal | nums[ind];
        if(temp == targetOrVal)
            ans++;

        solve(ind+1,nums,ans,targetOrVal,temp);
        //skip currVal
        solve(ind+1,nums,ans,targetOrVal,currOrVal);
    }
public:
    int countMaxOrSubsets(vector<int>& nums)
    {
        long int orVal = 0; 
        for(int num : nums)
            orVal |= num;
        int ans = 0, currOrVal = 0;
        solve(0,nums,ans,orVal,currOrVal);
        return ans;   
    }
};
*/