class trie
{
    bool bEnd;
    trie *pChild[10];
    public:
    trie()
    {
        bEnd = false;
        for(int i=0; i<10; i++)
            pChild[i] = nullptr;
    }
    void addInTrie(int val)
    {
        string str = to_string(val);
        int i, n = str.size();
        trie *ptr = this;
        for(i=0; i<n; i++)
        {
            int ind = str[i]-'0';
            if(!ptr->pChild[ind])
                ptr->pChild[ind] = new trie;
            ptr = ptr->pChild[ind];
        }
        ptr->bEnd = true;
    }
    int findMaxLenPrefix(int val)
    {
        string str = to_string(val);
        int i, n = str.size();
        trie *ptr = this;
        int ans = 0;
        for(i=0; i<n; i++)
        {
            int ind = str[i]-'0';
            if(!ptr->pChild[ind])
                break;
            ptr = ptr->pChild[ind];
            ans++;
        }
        return ans;      
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2)
    {
        trie *root = new trie();
        for(int val : arr2)
            root->addInTrie(val);
        int ans = 0;
        for(int val : arr1)
            ans = max(ans,root->findMaxLenPrefix(val));    
        return ans;
    }
};