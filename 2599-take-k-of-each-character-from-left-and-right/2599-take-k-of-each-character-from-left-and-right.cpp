class Solution {
    int getInd(vector<vector<int>> &dp, vector<int> &count, int r, int k)
{
    int remA_count = k-count[0];
    int remB_count = k-count[1];
    int remC_count = k-count[2];

    int n = dp.size();
    while(r<n && dp[r][0]>=remA_count && dp[r][1]>=remB_count && dp[r][2]>=remC_count)
        r++;
    return r-1;
}

public:
    int takeCharacters(string s, int k)
{
    if(k==0)
        return 0;

    vector<int> counts(3,0);
    for(char ch : s)
    {   
        counts[ch-'a']++;
    }   
    if(counts[0]<k || counts[1]<k || counts[2]<k)
        return -1; 

    int i, n = s.size();
    vector<vector<int>> dp(n,vector<int>(3,0));
    dp[n-1][s[n-1]-'a']++;
    for(i=n-2; i>=0; i--)
    {   
        dp[i] = dp[i+1];
        dp[i][s[i]-'a']++;
    }   
    int ans=n, l=0,r=0;
    vector<int> count(3,0);
    do  
    {   
        int ind = getInd(dp,count,r,k);
        r = ind;        
        int len = n-ind+l;
        ans = min(ans,len);

        count[s[l]-'a']++;
        if(count[0]>=k && count[1]>=k && count[2]>=k)
        {
            ans = min(ans,l+1);
            break;
        }
        l++;
    }while(l<=n);
    return ans;
}
};

/*


*/
/*
class Solution {
public:
  
    Brute force - Will get TLE.
    Time complexity -> O(2^n)

int solve(string s, int l, int r, int k, vector<int> count)
{
    if(count[0]>=k && count[1]>=k && count[2]>=k)
        return 0;
    if(l>r)
        return 1e6; // > size
    //take left char
    count[s[l]-'a']++;
    int lTime = 1+solve(s,l+1,r,k,count);
    count[s[l]-'a']--;

    // take right char
    count[s[r]-'a']++;
    int rTime = 1+solve(s,l,r-1,k,count);
    count[s[r]-'a']--;

    int ans = min(lTime,rTime);
    return ans >= 1e6 ? -1 : ans;
}
int takeCharacters(string s, int k)
{
    if(k==0)
        return 0;

    vector<int> counts(3,0);
    for(char ch : s)
    {
        counts[ch-'a']++;
    }
    if(counts[0]<k || counts[1]<k || counts[2]<k)
        return -1;

    vector<int> count(3,0);
    return solve(s,0,s.size()-1,k,count);
}

};
*/