class Solution {
public:
    int maxWidthRamp(vector<int>& nums)
    {
        int i, n = nums.size(), ans = 0;
        vector<int> stack;
        stack.push_back(n-1);
        for(i=n-2; i>=0; i--)
        {
            if(nums[i]>nums[stack.back()])
                stack.push_back(i);
            else
            {
                // we can use binary search here to optimize further
                for(int j=stack.size()-1; j>=0; j--)
                {
                    if(nums[i] <= nums[stack[j]])
                        ans = max(ans,stack[j]-i);
                }
            }
        }
        return ans;
    }
};
/*
class Solution {
    int Check(vector<int>& nums, int ind, stack<int> st)
    {
        int ans = 0;
        stack<int> save;
        while(!st.empty() && nums[ind] <= nums[st.top()])
        {
            int index = st.top();
            st.pop();
            save.push(index);
            ans = index-ind;
        }
        while(!save.empty())
        {
            st.push(save.top());
            save.pop();
        }
        return ans;
    }
public:
    int maxWidthRamp(vector<int>& nums)
    {
        int i, n = nums.size(), ans = 0;
        stack<int> st;
        st.push(n-1);
        for(i=n-2; i>=0; i--)
        {
            if(nums[i]>nums[st.top()])
                st.push(i);
            else
                ans = max(ans,Check(nums,i,st));
        }
        return ans;
    }
};
*/