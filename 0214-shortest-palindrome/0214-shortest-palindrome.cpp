class Solution {
    void computeLPS(string pat, vector<int> &lps)
    {
        int i, j, n = pat.size();
        lps[0] = 0;
        j=0;
        i=1;
        while(i<n)
        {
            if(pat[j] == pat[i])
            {
                lps[i] = j+1;
                i++;
                j++;
            }
            else
            {
                if(j != 0)
                    j = lps[j-1];
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
public:
    string shortestPalindrome(string s) {
        //Check previous submit also.
        int n = s.size();
        
        string rev(s);  //Reverse string
        reverse(rev.begin(), rev.end());
        
        string s_new = s + "#" + rev;  
        //Concatenate it using one special char in middle
        int n_new = s_new.size();
        
        vector<int> lps(n_new, 0);
        computeLPS(s_new,lps); //Compute LPS, lps[n_new - 1] will be the
                                //Length of longest prefix which is palindrome
        
        return rev.substr(0, n - lps[n_new - 1]) + s;
    }
};