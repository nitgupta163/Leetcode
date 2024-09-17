class Solution {
public:
    int tribonacci(int n)
    {
        if(n==0 || n== 1)
            return n;
        if(n==2)
            return 1;
        int i, a = 0, b = 1, c = 1;
        for(i=3; i<=n; i++)
        {
            int ti = a + b + c;
            a = b;
            b = c;
            c = ti;
        }
        return c;    
    }
};