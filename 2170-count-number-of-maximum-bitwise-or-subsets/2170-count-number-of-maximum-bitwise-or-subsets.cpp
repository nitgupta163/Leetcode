class Solution {
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