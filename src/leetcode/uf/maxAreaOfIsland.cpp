//
// Created by 施奕成 on 2023/3/5.
//
#include "connectivity.h"
using namespace std;

int maxAreaOfIsland(vector<vector<int>>& grid) {
  int m = (int)grid.size(), n = (int)grid[0].size();
  UF<int> uf(grid);
  for(int i=0; i<m; ++i) {
    for(int j=0; j<n; ++j) {
      if(grid[i][j]) {
        grid[i][j] = 0;  // I didn't take this into account
        if(i-1 >= 0 && grid[i-1][j]) uf.uni(i*n+j, (i-1)*n+j);
        if(j+1 < n && grid[i][j+1]) uf.uni(i*n+j, i*n+j+1);
        if(i+1 < m && grid[i+1][j]) uf.uni(i*n+j, (i+1)*n+j);
        if(j-1 >= 0 && grid[i][j-1]) uf.uni(i*n+j, i*n+j-1);
      }
    }
  }
  return uf.get_max_comp_size();
}
