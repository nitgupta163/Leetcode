const int mod = 1e9 + 7;
class Solution {
public:
    int lengthAfterTransformations(string s, int t)
    {
        vector<long long int> count(26,0);
        for(char ch : s)
            count[ch-'a']++;
        for(int j=0; j<t; j++)
        {
            int c25 = count[25];            
            for(int i=25; i>0; i--)            
                count[i] = count[i-1];          
            count[1] = (count[1] + (c25%mod))%mod;
            count[0] = c25;
        }
        long long int ans = 0;
        for(long long int num : count)
        {
                ans = (ans + (num % mod))%mod;
                if(ans < 0)
                    ans += mod;
        }
        return ans;
    }
};