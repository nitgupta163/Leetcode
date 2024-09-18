class myFunctor
{
    public:
    bool operator()(const string &a, const string &b)
    {
        if((a+b) > (b+a))
            return true;
        return false;
    }
};
/*
    Syntax of std::sort
    template<class RandomIt, class Compare>
    void sort(RandomIt first, RandomIt last, Compare comp);
*/
/*
bool myComp(const string &a, const string &b)
{
    if((a+b) > (b+a))
        return true;
    return false;
}
sort(strArr.begin(),strArr.end(),myComp);
sort(strArr.begin(),strArr.end(),&myComp);

bool (*funcPtr)(const string&,const string&) = &myComp;
sort(strArr.begin(),strArr.end(),funcPtr);
*/

class Solution {    
public:
    string largestNumber(vector<int>& nums)
    {
        vector<string> strArr;
        int i, n = nums.size();
        for(i=0; i<n; i++)
        strArr.push_back(to_string(nums[i]));
        sort(strArr.begin(),strArr.end(),myFunctor());
        string ans;
        for(string str : strArr)
            ans += str;
        if(ans[0]=='0')
            return "0";
        return ans;        
    }
};