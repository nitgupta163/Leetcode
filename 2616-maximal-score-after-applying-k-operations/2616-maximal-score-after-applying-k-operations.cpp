class Solution {
public:
    long long maxKelements(vector<int>& nums, int k)
    {
        priority_queue<int> pq;
        // Only max k elements are required, sort and take only max k elem.
        for(int num : nums)
            pq.push(num);        
        long long int ans = 0;
        for(int i=0; i<k; i++)
        {
            int num = pq.top();
            pq.pop();
            ans += num;
            pq.push(ceil(num/3.0));
        }
        return ans;
    }
};