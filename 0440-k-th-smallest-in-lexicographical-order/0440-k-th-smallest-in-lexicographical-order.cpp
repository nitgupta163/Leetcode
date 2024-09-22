class Solution {
    /*
    // TLE
    void dfs(int node, int &count, int &ans, int n, int k)
    {
        if(node > n)
            return;     
        count++;
        if(count == k)
        {
            ans = node;
            return ;
        }
        for(int i=0; i<=9; i++)
        {
            dfs(node*10+i,count,ans,n,k);
        }
    }
    int findKthNumber(int n, int k)
    {
        int count = 0, ans = -1;
        for(int i=1; i<=9; i++)
        {
            dfs(i,count,ans,n,k);
        }        
        return ans;
    }
    */
private:
    int getStepCount(long prefix1,long prefix2,long n)
    {
        int step=0; 
        while(prefix1 <= n)
        {
            step += min(n+1,prefix2)-prefix1;
            prefix1*=10;
            prefix2*=10;
        }
        return step;
    }
public:
    int findKthNumber(long n, int k) {
        long ans = 1;
        int count = 1;
        while(count < k)
        {
            int step = getStepCount(ans,ans+1,n);
            if(count+step <= k)
            {
                count+=step;
                ans++;
            }
            else
            {
                count++;
                ans *= 10;
            }
        }
        return ans;
    }
};