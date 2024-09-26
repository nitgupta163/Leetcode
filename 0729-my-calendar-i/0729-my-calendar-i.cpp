class MyCalendar 
{
    vector<pair<int,int>> arr;
    bool isOverlap(const pair<int,int> &p, const pair<int,int> &pr)
    {
        if(p.second <= pr.first || pr.second <= p.first)
            return false;
        return true;
    }
public:
    MyCalendar()
    {        
        // arr.clear();
    }
    
    bool book(int start, int end)
    {
        pair<int,int> pr(start,end);
        for(auto p : arr)        
        {
            if(isOverlap(p,pr))
                return false;
        }
        arr.push_back(pr);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */