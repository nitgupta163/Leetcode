class Solution {
    void fillLIS(vector<int> &lis, vector<int> &nums)
    {
        int i, j, n = nums.size();
        for(i=1; i<n; i++)
        {
            for(j=0; j<i; j++)
            {
                if(nums[j]<nums[i] && lis[i]<lis[j]+1)
                    lis[i] = lis[j]+1;
            }
        }
    }
    void fillLDS(vector<int> &lds, vector<int> &nums)
    {
        int i, j, n = nums.size();
        for(i=n-2; i>=0; i--)
        {
            for(j=n-1; j>i; j--)
            {
                if(nums[j]<nums[i] && lds[i]<lds[j]+1)
                    lds[i] = lds[j]+1;
            }
        }
    }    
public:
    int minimumMountainRemovals(vector<int>& nums)
    {
        int i, n = nums.size();
        vector<int> lis(n,1), lds(n,1);

        fillLIS(lis,nums);
        fillLDS(lds,nums);

        int _max = 0;
        for(i=0; i<n; i++)
            if(_max<(lis[i]+lds[i]) && lis[i]!=1 && lds[i]!=1)
                _max = lis[i]+lds[i];
            
        for(i=0; i<n; i++)
            cout << lis[i] << " ";
        cout << "\n";
        for(i=0; i<n; i++)
            cout << lds[i] << " ";
        cout << "\n";        
        return n-_max+1;
    }
};