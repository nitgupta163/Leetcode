class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr)
    {
        int i, n = arr.size();
        int l=0, r=n-1;
        while(l<r)
        {
            // if only two elements are left
            if(l==r-1)
            {
                if(arr[l] < arr[r])
                    return r;
                return l;
            } // if more than two elements
            else
            {
                int mid = l + (r-l)/2;

                int leftVal = arr[mid-1];
                int midVal = arr[mid];
                int rightVal = arr[mid+1];
                
                if(leftVal<midVal && midVal<rightVal)
                    l = mid+1;
                else if(leftVal>midVal && midVal>rightVal)
                    r = mid-1;
                else return mid;
            }
        }   
        return l;
    }
};