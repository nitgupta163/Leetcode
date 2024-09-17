class Solution {
public:
    int lengthOfLIS(vector<int>& arr)
    {
        int i, j, n = arr.size();
        vector<int> lis(n,1);
        
       int ans = lis[0];
       for(i=1;i<n;i++)
       {
           for(j=0;j<i;j++)
           {
               if(arr[j] < arr[i] && (lis[i] < lis[j]+1))
               lis[i] = lis[j]+1;
           }
           if(ans < lis[i])
               ans = lis[i];
       }
       return ans;
    }
};
