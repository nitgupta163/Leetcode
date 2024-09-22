#define type1 unordered_map<string,pair<string,int>>::iterator
class Solution {
    string getString(vector<int> &arr)
    {
        string str = to_string(arr[0]);
        str += '$';
        str += to_string(arr[1]);
        return str;
    }
    type1 findPar(type1 itr, unordered_map<string,pair<string,int>> &unmap)
    {
        if(itr == unmap.end())
            return itr;
        if(itr->second.first == "-1")
            return itr;       
        type1 par = unmap.find(itr->second.first);
        if(par==unmap.end())
            return par;
        type1 OrgPar = findPar(par,unmap);
        itr->second.first = OrgPar->first;
        return OrgPar;
    }
    void takeUnion(auto itr1, auto itr2,
                    unordered_map<string,pair<string,int>> &unmap)
    {
        if(itr1==unmap.end() || itr2==unmap.end())
            return;
        if(itr1->second.second >= itr2->second.second)
        {
            itr2->second.first = itr1->first;
            itr1->second.second += itr2->second.second;
        }
        else
        {
            itr1->second.first = itr2->first;
            itr2->second.second += itr1->second.second;
        }
    }
public:
 
    int removeStones(vector<vector<int>>& stones)
    {
        int i, j, n = stones.size();
        unordered_map<string,pair<string,int>> unmap;        
        unmap.insert({getString(stones[0]),{"-1",1}});
        int connectedComp = 1;
        for(i=1; i<n; i++)
        {       
            unmap.insert({getString(stones[i]),{"-1",1}});     
            int rowIndex = -1;
            int colIndex = -1;
            for(j=0; j<i; j++)
            {
                // finding first matching row and col
                if(stones[i][0] == stones[j][0])                
                    rowIndex = j;               
                if(stones[i][1] == stones[j][1])
                    colIndex = j;
                if(rowIndex!=-1 && colIndex!=-1)
                    break;                     
            }
            // no matching row or col found
            if(rowIndex==-1 && colIndex==-1)
            {
                connectedComp++;                
                continue;
            }
            // both matching row or col found
            else if(rowIndex!=-1 && colIndex!=-1)
            {
                type1 rItr = unmap.find(getString(stones[rowIndex]));
                type1 cItr = unmap.find(getString(stones[colIndex]));
                type1 rItrParent = findPar(rItr,unmap);
                type1 cItrParent = findPar(cItr,unmap);
                if(rItrParent != cItrParent)
                {
                    // take union of both row and col
                    takeUnion(rItrParent,cItrParent,unmap);
                    // decrement connected component
                    connectedComp--;                    
                }
                // take union of the current new element
                takeUnion(rItrParent,unmap.find(getString(stones[i])),unmap);
            }
            // only row matching found
            else if(rowIndex != -1)
            {
                type1 rItr = unmap.find(getString(stones[rowIndex]));
                type1 rItrParent = findPar(rItr,unmap);
                takeUnion(rItrParent,unmap.find(getString(stones[i])),unmap);
            }
            // only col matching found
            else if(colIndex != -1)
            {
                type1 cItr = unmap.find(getString(stones[colIndex]));
                type1 cItrParent = findPar(cItr,unmap);
                takeUnion(cItrParent,unmap.find(getString(stones[i])),unmap);
            }
        }
        
        return n-connectedComp;
    }
};