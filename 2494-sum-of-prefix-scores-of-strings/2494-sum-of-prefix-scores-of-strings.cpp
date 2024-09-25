class trie
{
    int count;
    trie *pChild[26];
    public:
    trie()
    {
        count = 0;
        for(int i=0; i<26; i++)
            pChild[i] = nullptr;
    }
    void addInTrie(string str)
    {         
        int i, n = str.size();
        trie *ptr = this;
        for(i=0; i<n; i++)
        {
            int ind = str[i]-'a';
            if(!ptr->pChild[ind])
                ptr->pChild[ind] = new trie;            
            ptr = ptr->pChild[ind];        
            ptr->count++;
        }        
    }
    int fun(string str )
    {
        int i, n = str.size();
        trie *ptr = this;
        int ans = 0;
        for(i=0; i<n; i++)
        {
            int ind = str[i]-'a';
            if(!ptr->pChild[ind])
                break;
            ptr = ptr->pChild[ind];
            ans += ptr->count;
        }
        return ans;      
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words)
    {
        trie *root = new trie();
        for(string str : words)
            root->addInTrie(str);
        vector<int> ans;
        for(string str : words)
            ans.push_back(root->fun(str));
        return ans;
    }
};