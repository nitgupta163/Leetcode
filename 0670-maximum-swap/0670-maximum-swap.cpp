class Solution {
    void getMaxNum(string &str)
    {
        int i, j, n = str.size();
        for(i=0; i<n; i++)
        {
            int maxInd = i;
            for(j=i+1; j<n; j++)
            {
                if(str[j]>str[i] && str[j]>=str[maxInd])
                    maxInd = j;
            }
            if(i != maxInd)
            {
                swap(str[i],str[maxInd]);
                return ;
            }
        }
    }
public:
    int maximumSwap(int num)
    {
        string str = to_string(num);
        getMaxNum(str);    
        return stoi(str);        
    }
};