/*class Solution {
public:
    int maxMoves(vector<vector<int>>& grid)
    {
        int i, j, n = grid.size(), m = grid[0].size();
        vector<int> dp1(n,0), dp2(n,0);
        for(j=m-2; j>=0; j--)
        {
            for(i=0; i<n; i++)
            {
                if(grid[i][j] < grid[i][j+1])
                    dp1[i] = max(dp1[i],1+dp2[i]);
                if(i-1>=0 && grid[i][j] < grid[i-1][j+1])
                    dp1[i] = max(dp1[i],1+dp2[i-1]);
                if(i+1<n && grid[i][j] < grid[i+1][j+1])
                    dp1[i] = max(dp1[i],1+dp2[i+1]);
            }
            for(int num : dp1)
                cout << num << " ";
            cout << "\n";
            swap(dp2,dp1);
        }    
        int ans = 0;
        for(i=0; i<n; i++)
        {
            if(dp1[i] > ans)
                ans = dp1[i];
        }
        return ans;
    }
}; */

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid)
    {
        int i, j, n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(j=m-2; j>=0; j--)
        {
            for(i=0; i<n; i++)
            {
                if(grid[i][j] < grid[i][j+1])
                    dp[i][j] = max(dp[i][j],1+dp[i][j+1]);
                if(i-1>=0 && grid[i][j] < grid[i-1][j+1])
                    dp[i][j] = max(dp[i][j],1+dp[i-1][j+1]);
                if(i+1<n && grid[i][j] < grid[i+1][j+1])
                    dp[i][j] = max(dp[i][j],1+dp[i+1][j+1]);                    
            }
        }    
        int ans = 0;
        for(i=0; i<n; i++)
        {
            if(dp[i][0] > ans)
                ans = dp[i][0];
        }
        return ans;
    }
};