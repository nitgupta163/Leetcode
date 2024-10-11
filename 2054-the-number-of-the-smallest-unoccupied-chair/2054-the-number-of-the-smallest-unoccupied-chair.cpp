class type
{
public:
    int val, index;
    bool isStart;
    type(int _val, int _index, bool _isStart) :
        val(_val), index(_index), isStart(_isStart)
    {

    }
    type(const type &t)
    {
        val = t.val;
        index = t.index;
        isStart = t.isStart;
    }
    bool operator<(const type &t) const
    {
        // cout << t1.val << " " << t2.val << "\n";
        if (val < t.val)
            return true;
        else if (val > t.val)
            return false;
        else // same val, then put end one first
        {
            // if t1 is end
            if(isStart)
                return false;
            else if(t.isStart)
                return true;
            else if(index < t.index)
                return true;

            // if t1 is start, then return false
            return false;
        }
    }
};
class Solution
{
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend)
    {
        int i, n = times.size();
        vector<type> arr;
        for (i = 0; i < n; i++)
        {
            int start = times[i][0];
            int end = times[i][1];
            arr.push_back(type(start, i, true));
            arr.push_back(type(end, i, false));
        }
        cout << arr.size() << " --size \n";
        for (type t : arr)
            cout << t.val << " " << t.index << "\n";
        sort(arr.begin(), arr.end());
        cout << "After Sort\n";
        for (type t : arr)
            cout << t.val << " " << t.index << "\n";        

        priority_queue<int, vector<int>, greater<int> > pq;
        for (i = 0; i < n; i++)
            pq.push(i);
        vector<int> chairNum(n, -1);
        n = arr.size();
        for (i = 0; i < n; i++)
        {
            int index = arr[i].index;
            // it's a start, need a chair
            if (arr[i].isStart)
            {
                int nChair = pq.top();
                pq.pop();
                if (index == targetFriend)
                    return nChair;
                chairNum[index] = nChair;
            }
            else // it's end, release the occupied chair
            {
                int nChair = chairNum[index];
                pq.push(nChair);
            }            
        }
        return n / 2 - 1;
    }
 };