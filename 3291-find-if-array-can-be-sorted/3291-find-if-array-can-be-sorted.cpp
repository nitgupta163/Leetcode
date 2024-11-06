class Solution {
    int getSetBit(int num)
    {
        return __builtin_popcount(num);
    }
    void computeSetBit(vector<int>& nums, vector<int> &setBit)
    {
        for(int num : nums)
            setBit.push_back(getSetBit(num));
    }
public:
    bool canSortArray(vector<int>& nums)
    {
        int i, n = nums.size();
        vector<int> setBit;
        computeSetBit(nums,setBit);
        for(int pass=1; pass<n; pass++)
        for(i=0; i<n-1; i++)
        {
            if(nums[i] > nums[i+1])
            {
                if(setBit[i] != setBit[i+1])
                    return false;
                swap(nums[i],nums[i+1]);
            }
        }
        return true;
    }
};