class Solution {
    bool isOperatr(char op)
    {
        switch(op)
        {
            case '+':                        
            case '-':
            case '*':
                return true;                                         
        }        
        return false;
    }
    void preProcess(string exp, vector<int> &operand, vector<char> &operatr)
    {
        int i, n = exp.size();
        for(i=0; i<n; i++)
        {
            if(isOperatr(exp[i]))
                operatr.push_back(exp[i]);
            else
            {
                int num = exp[i]-'0';
                if(i+1<n && !isOperatr(exp[i+1]))
                {
                    num *= 10;
                    num += exp[i+1]-'0';
                    i++;
                }
                operand.push_back(num);
            }
        }
    }
    void calculate( vector<int> &left, vector<int> &right,
                    vector<int> &ans,char op)
    {
        int i, j, n = left.size(), m = right.size();
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                int res = 0;
                switch(op)
                {
                    case '+':
                        res = left[i]+right[j];
                        break;
                    case '-':
                        res = left[i]-right[j];
                        break;
                    case '*':
                        res = left[i]*right[j];
                        break;                        
                }
                ans.push_back(res);
            }
        }        
    }
    vector<int> solve(int l, int r, vector<int> &operand,
                        vector<char> &operatr, vector<int> dp[21][21])
    {
        vector<int> ans;
        if(l==r)
        {
            ans.push_back(operand[l]);
            return ans;
        }
        if(dp[l][r].size() != 0)
            return dp[l][r]; 

        for(int x=l; x<r; x++)
        {
            vector<int> left = solve(l,x,operand,operatr,dp);
            vector<int> right = solve(x+1,r,operand,operatr,dp);
            calculate(left,right,ans,operatr[x]);
        }
        return dp[l][r] = ans;
    }
public:
    vector<int> diffWaysToCompute(string exp)
    {
        vector<int> operand;        
        vector<char> operatr;
        preProcess(exp,operand,operatr);
        // cout << operand.size() << " " << operatr.size() << "\n";
        // for(int num : operand)
        //     cout << num << " ";

        vector<int> dp[21][21];
        return solve(0,operand.size()-1,operand,operatr,dp);
    }
};