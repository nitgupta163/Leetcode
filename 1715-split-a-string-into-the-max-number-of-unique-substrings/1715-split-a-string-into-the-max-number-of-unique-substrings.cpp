class Solution {
    void solve(int ind,string &s, unordered_set<string> &set, int &ans, string curr)
    {
        if(ind == s.size())
        {
            if(curr == "")
                return;
            if(set.find(curr) != set.end())
                return;
            if(ans < set.size()+1)
                ans = set.size()+1;
            // for(string tmp : set)
            //     cout << tmp << " ";
            // cout << curr << "\n";
            return ;
        }

        solve(ind+1,s,set,ans,curr+s[ind]);
        string temp = curr;
        temp += s[ind];
        if(set.find(temp) == set.end())
        {
            set.insert(temp);            
            solve(ind+1,s,set,ans,"");
            set.erase(set.find(temp));
        }
    }
public:
    int maxUniqueSplit(string s)
    {
        int ans = 1;
        unordered_set<string> set;
        solve(0,s,set,ans,"");
        return ans;    
    }
};