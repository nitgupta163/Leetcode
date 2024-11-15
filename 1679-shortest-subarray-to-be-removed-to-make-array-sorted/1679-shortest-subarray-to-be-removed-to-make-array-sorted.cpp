class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& nums)
    {
        int i, j, k, n = nums.size();
        i=0;
        while(i<n-1 && nums[i]<=nums[i+1])
            i++;
        if(i==n-1)
            return 0;
        j=n-1;
        while(j>0 && nums[j]>=nums[j-1])
            j--;
        int prefix = i+1;
        int suffix = n-j;
        cout << prefix << " " << suffix << "\n";
        int concatenate = 0;
        for(k=i; k>=0; k--)
        {
            auto it = lower_bound(nums.begin()+j,nums.end(),nums[k]);
            if(it != nums.end())    
                concatenate = max(concatenate, (int)(k+1+(nums.end()-it)));
        }
        cout << k <<"\n";
        // int concatenate = k+1 + num.end();
        return n-max(concatenate,max(prefix,suffix));
    }
};