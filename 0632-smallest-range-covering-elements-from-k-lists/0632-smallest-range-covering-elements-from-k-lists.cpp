class Element
{
public:
    int num,row,col;
};
class myComp
{
    public:
        bool operator()(const Element &e1, const Element &e2)
        {
            if(e1.num != e2.num)
                return e1.num > e2.num;
            return e1.row > e2.row;
        }
};
class Solution {
    void updateAns(pair<int,int> &ans, const pair<int,int> p)
    {
        if(ans.second-ans.first > p.second-p.first)
            ans = p;
    }
public:
    vector<int> smallestRange(vector<vector<int>>& nums)
    {
        int i, n = nums.size(), _max = nums[0][0];
        priority_queue<Element,vector<Element>,myComp> pq;       
        for(i=0; i<n; i++)
        {
            pq.push({nums[i][0],i,0});
            if(_max < nums[i][0])
                _max = nums[i][0];
        }
        pair<int,int> ans({pq.top().num,_max});
        while(!pq.empty())
        {
            Element e = pq.top();
            pq.pop();
            updateAns(ans,{e.num,_max});
            if(e.col == nums[e.row].size()-1)
                break;
            pq.push({nums[e.row][e.col+1],e.row,e.col+1});
            if(_max < nums[e.row][e.col+1])
                _max = nums[e.row][e.col+1];
        }
        return {ans.first,ans.second};
    }
};