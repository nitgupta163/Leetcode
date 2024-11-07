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