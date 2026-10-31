class Solution {
public:
    vector<pair<int,int>>dir{{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0||i>=grid.size()||
        j<0||j>=grid[0].size()||
        grid[i][j]!=0){
        return ;
        }
        grid[i][j]=1;
        for (auto& p : dir) {
        int ni = i + p.first;
        int nj = j + p.second;

        dfs(grid, ni, nj);
     }
    }
    int closedIsland(vector<vector<int>>& grid) {
      if(grid.empty())  
        return 0;
        int m=grid.size();
        int n=grid[0].size();
          for (int i = 0; i < m; i++) {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            dfs(grid, 0, j);
            dfs(grid, m - 1, j);
        }
        int count=0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==0){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};