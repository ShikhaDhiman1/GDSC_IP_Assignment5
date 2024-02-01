#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>> &grid,int x, int y, int r, int c){
        if(x<0||y<0||x>=r||y>=c||grid[x][y]!='1'){
            return;
        }
        grid[x][y]='2';
        dfs(grid,x+1,y,r,c);
        dfs(grid,x,y+1,r,c);
        dfs(grid,x-1,y,r,c);
        dfs(grid,x,y-1,r,c);
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows==0){
            return 0;
        }
        int cols = grid[0].size();
        int cnt = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j,rows,cols);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};