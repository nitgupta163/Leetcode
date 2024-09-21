class Solution {
    /*
    Time Complexity- O(nlogn)
    static bool comp(int a, int b)
    {
        string str1 = to_string(a);
        string str2 = to_string(b);
        if(str1<str2)
        return true;
        return false;
    }
    vector<int> lexicalOrder(int n)
    {
        vector<int> ans(n);
        for(int i=1; i<=n; i++)
            ans[i-1] = i;
        sort(ans.begin(),ans.end(),comp);     
        return ans;           
    }
    */
    void dfs(int node, vector<int> &ans, int n)
    {
        if(node > n)
        return ;
        ans.push_back(node);
        for(int i=0; i<=9; i++)
            dfs(node*10+i,ans,n);
    }
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> ans;
        for(int i=1; i<=9; i++)
            dfs(i,ans,n); 
        return ans;           
    }
};