#define ll long long int
class Solution {
    ll findHightReduce(int t, ll tm)
    {
        ll l = 1, r = sqrt(tm*4/t);
        ll ans = 0;
        while(l <= r)
        {
            ll mid = l + (r-l)/2;
            // cout << l << " " << r << " " << mid << "\n";
            if(t*(mid*(mid+1)/2) <= tm)
            {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
    bool isAns(int h, vector<int>& arr, ll mid)
    {
        int hr = 0;
        for(int t : arr)
        {
            hr += findHightReduce(t,mid);                
        }   
        if(hr >= h)
        return true;
        return false;
    }
public:
    long long minNumberOfSeconds(int h, vector<int>& arr)
    {        
        ll mx = *max_element(arr.begin(),arr.end());
        ll l = 1, r = mx*((ll)h*(h+1)/2);
        ll ans = r;
        // if(arr.size()==1)
        //     return r;
            // cout << "sdf";            
        while(l<=r)
        {
            // cout << l << " "<<r << "\n"; 
            ll mid = l + (r-l)/2;
            if(isAns(h,arr,mid))
            {
                ans = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }       
        return ans;
    }
};