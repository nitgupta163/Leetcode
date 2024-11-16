class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k)
    {
        if(k==1)
            return nums;
        int i, j, n = nums.size();
        vector<int> ans(n-k+1,-1);
        i=0;
        while(i < n-k+1)
        {
            j = i+1;
            while(j<n && nums[j]==1+nums[j-1])
            {
                j++;
                if(j >= i+k)
                    ans[i++] = nums[j-1];
            }
            i=j;
            /*
            j=i+1;
            while(j<i+k && nums[j]==1+nums[j-1])
                j++;
            if(j==i+k)
            {
                ans[i] = nums[j-1];
                i++;
            }
            else i = j;
            */
        }
        return ans;
    }
    /*
    Time complexity- O(N*K)
    vector<int> resultsArray(vector<int>& nums, int k)
    {
        int i, j, n = nums.size();
        vector<int> ans(n-k+1,-1);
        for(i=0; i<=n-k; i++)
        {
            for(j=i+1; j<i+k; j++) // k==1?
            {
                if(nums[j]!=nums[j-1]+1)
                    break;
            }
            if(j==i+k)
                ans[i] = nums[j-1];
        }   
        return ans;
    }
    */
};