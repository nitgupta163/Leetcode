typedef long long int lli;
class Solution {
    lli solve(int r, int f, vector<int>& robot, vector<int>& fact,
              vector<vector<lli>> &dp)
    {
         
        int n = robot.size(), m = fact.size();
        if(r>=n)
            return 0;
        if((n-r>m-f) ||f>=m)
            return LLONG_MAX;
        if(dp[r][f] != -1)
            return dp[r][f];
        // if(n-r == m-f)
        // {
        //     lli ans = 0;
        //     int i = 0;
        //     while(r+i < n)
        //     {
        //         ans += abs(robot[r+i]-fact[f+i]);
        //         i++;
        //     }
        //     return dp[r][f]=ans;
        // }
        lli skip = solve(r,f+1,robot,fact,dp);
        lli noSkip = solve(r+1,f+1,robot,fact,dp);
        if(noSkip == LLONG_MAX)
            return dp[r][f] = skip;
        return dp[r][f] = min(skip,noSkip+abs(robot[r]-fact[f]));
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory)
    {
        int i,j, n=robot.size(), m=factory.size();
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<int> fact;
        for(i=0; i<m; i++)
        {
            int position = factory[i][0];
            int limit = factory[i][1];
            for(j=0; j<limit; j++)
                fact.push_back(position);
        }
        vector<vector<lli>> dp(n,vector<lli>(fact.size(),-1));
        return solve(0,0,robot,fact,dp);
    }
};