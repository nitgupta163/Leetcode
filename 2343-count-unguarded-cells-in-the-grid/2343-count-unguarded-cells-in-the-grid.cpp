class Solution {
public:
    void markVisited(vector<vector<int> > &grid, int i, int j)
{
    int it, m=grid.size(), n=grid[0].size();
    // left
    it = j-1;
    while(it>=0 && (grid[i][it]==0 || grid[i][it]==1))
    {
        grid[i][it] = 1;
        it--;
    }
    // right
    it = j+1;
    while(it<n && (grid[i][it]==0 || grid[i][it]==1))
    {
        grid[i][it] = 1;
        it++;
    }
    // up
    it = i-1;
    while(it>=0 && (grid[it][j]==0 || grid[it][j]==1))
    {
        grid[it][j] = 1;
        it--;
    }
    // down
    it = i+1;
    while(it<m && (grid[it][j]==0 || grid[it][j]==1))
    {
        grid[it][j] = 1;
        it++;
    }
}

int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls)
{
    vector<vector<int> > grid(m,vector<int>(n,0));
    int i,j;
    for(auto t : guards)
        grid[t[0]][t[1]] = 2;
    for(auto t : walls)
        grid[t[0]][t[1]] = 3;

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(grid[i][j]==2)
                markVisited(grid,i,j);
        }
    }
    int ans = 0;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
            if(grid[i][j]==0)
                ans++;
    }
    return ans;
}

};