class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k)
    {
        int i=0, j=0, n = nums.size();
        long long int sum=0, ans=0;
        unordered_map<int,int> hash;
        while(j<n)
        {
            sum += nums[j];
            if(hash.find(nums[j]) != hash.end())
            {
                int ind = hash[nums[j]];
                for(; i<=ind; i++)
                {
                    sum -= nums[i];
                    hash.erase(nums[i]);
                }                
                hash[nums[j]] = j; // update index
            }
            else
            {
                hash.insert({nums[j],j});
                int len = j-i+1;
                if(len==k)
                {
                    ans = max(ans,sum);                    
                    sum -= nums[i];
                    hash.erase(nums[i]);
                    i++;
                }        
            }
            j++;
        }
        return ans;
    }    
};