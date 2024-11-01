class Solution {
public:
    string makeFancyString(string s)
    {
        int i, n = s.size();
        string ans;
        for(i=0; i<n; i++)
        {
            if(i>=2 && s[i]==s[i-1] && s[i]==s[i-2])
                continue;
            ans += s[i];
        }
        return ans;
    }
};