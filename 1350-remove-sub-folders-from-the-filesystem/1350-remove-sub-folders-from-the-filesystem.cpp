class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder)
    {
        unordered_set<string> hash;
        vector<string> ans;
        for(string str : folder)
            hash.insert(str);
        for(string str : folder)
        {
            int i, n = str.size();
            for(i=1; i<n; i++)
            {
                if(str[i]=='/' && hash.find(str.substr(0,i)) != hash.end())
                    break;
            }
            if(i==n)                
                ans.push_back(str);
        }   
        return ans;
    }
};