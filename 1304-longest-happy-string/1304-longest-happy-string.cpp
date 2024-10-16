typedef pair<int,int> pii;
class Solution {
public:
    string longestDiverseString(int a, int b, int c)
    {
        priority_queue<pii> pq;
        if(a>0)
            pq.push({a,'a'});
        if(b>0)
            pq.push({b,'b'});
        if(c>0)
            pq.push({c,'c'});
        string ans;
        int lastPrintChar = 'z', lastPrintCount = 0;
        while(!pq.empty())
        {
            pii p = pq.top();
            pq.pop();
            if(p.second == lastPrintChar && lastPrintCount==2)
            {
                if(pq.empty())
                    return ans;
                pii p2 = pq.top();
                pq.pop();
                ans += p2.second;
                lastPrintChar = p2.second;
                lastPrintCount = 1;
                if(p2.first>1)
                    pq.push({p2.first-1,p2.second});
                pq.push(p);
            }
            else
            {
                ans += p.second;
                if(lastPrintChar == p.second)
                    lastPrintCount++;
                else
                {
                    lastPrintChar = p.second;
                    lastPrintCount = 1;                    
                }
                if(p.first>1)
                    pq.push({p.first-1,p.second});
            }
        }
        return ans;
    }
};