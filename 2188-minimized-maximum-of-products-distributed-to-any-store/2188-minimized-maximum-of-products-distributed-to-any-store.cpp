class Solution {
    bool IsPossible(int n, vector<int>& nums, int val)
{
    if(val==0)
        return false;
    int count = 0;
    for(int num : nums)
    {
        count += ceil(num*1.0/val);
        if(count>n)
            return false;
    }
    return true;
}

public:
int minimizedMaximum(int n, vector<int>& nums)
{
    int l=0, r=*max_element(nums.begin(),nums.end()), ans = r;
    while(l<=r)
    {   
        int mid = l + (r-l)/2;
        if(IsPossible(n,nums,mid))
        {
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }   
    return ans;
}

};