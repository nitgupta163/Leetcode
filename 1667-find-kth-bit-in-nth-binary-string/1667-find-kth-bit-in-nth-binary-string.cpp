class Solution {
    void getNextStr(string &prev)
    {
        string ans = prev;
        ans += '1';
        int i, n = prev.size();
        for(i=n-1; i>=0; i--)
            ans += prev[i]=='1'?'0':'1';
        prev = ans;
    }    
    string getNthStr(int n)
    {
        string ans = "0";
        for(int i=2; i<=n; i++)        
            getNextStr(ans);        
        return ans;
    }
public:
    char findKthBit(int n, int k)
    {
        string s = getNthStr(n);
        return s[k-1];
    }
};