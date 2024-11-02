class Solution {
public:
    bool isCircularSentence(string s)
    {
        int i, n = s.size();
        if(s[0] != s[n-1])
            return false;
        for(i=1; i<n; i++)
        {
            if(s[i-1]==' ')
            {
                if(s[i]!=s[i-2])
                    return false;
            }
        }
        return true;
    }
};