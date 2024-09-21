class Solution {
    static bool comp(int a, int b)
    {
        string str1 = to_string(a);
        string str2 = to_string(b);
        if(str1<str2)
        return true;
        return false;
    }
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> ans(n);
        for(int i=1; i<=n; i++)
            ans[i-1] = i;
        sort(ans.begin(),ans.end(),comp);     
        return ans;           
    }
};