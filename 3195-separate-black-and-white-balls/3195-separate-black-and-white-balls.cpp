class Solution {
public:
    long long minimumSteps(string s)
    {
        long long int ans = 0;
        int oneCount = 0;
        for(char ch : s)
        {
            if(ch=='1')
                oneCount++;
            else ans += oneCount;
        }    
        return ans;
    }
};