class Solution {
public:
    int n,m;

    void dfs(vector<vector<int>>& grid, int r, int c){
            if(r<0 || r>=n|| c<0|| c>=m || grid[r][c]!= 1)
            return;

            grid[r][c]=2;

            dfs(grid, r+1,c);
            dfs(grid, r-1,c);
            dfs(grid, r,c+1);
            dfs(grid, r,c-1);
        }

         int numEnclaves(vector<vector<int>>& grid) {
             n=grid.size();
             m=grid[0].size();

             for (int i = 0; i < n; i++) {
                  if (grid[i][0] == 1)
                     dfs(grid, i, 0);

                 if (grid[i][m - 1] == 1)
                     dfs(grid, i, m - 1);
            }
          // for row and last colm

          for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1)
                dfs(grid,0,j);

            if (grid[n - 1][j] == 1)
                dfs(grid, n - 1, j);
           }  
           int ans=0;
            
        // now count remaining land cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    ans++;
            }
        }
        return ans;
    }
};