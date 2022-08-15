class Solution {
public:

    int findArea(vector<vector<int>>& grid, int row, int col)
    {
        //base condition
         int area=0;

        int n=grid.size();
        int m=grid[0].size();

        if(row<0 || col<0 ||  row>n-1 || col>m-1 ) return 0;
       
        if(grid[row][col]==1)
        {
            //update the current cell
            grid[row][col]=0;
            //itrate over the other cells
            area=1+ findArea(grid,row+1,col) +findArea(grid,row,col+1)+findArea(grid,row-1,col)+findArea(grid,row,col-1);
        }
         return area;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j]==1)
                {
                    area=findArea(grid,i,j);
                }
            }
        } 
         return area;   
    }
};





























// Method 2

class Solution {
public:

    bool check(int i,int j,int m,int n){
        if(i>=0 or j>=0 or i<n or j<m) return true;
         return false;
    }

    void dfs(vector<vector<int>> grid ,vector<vector<int>> &visited ,int i,int j, int& curArea , int n,int m)
    {
        visited[i][j]=1;
        // int dx = [0,1,-1,0];
        // int dy = [1,0,0,-1];
        // for(int i=0;i<4;i++)
        // {
        //     f(grid[i+dx[i]][j+dy[i]]==1 and check(i+dx[i],j+dy[i],m,n) and !visited[i+dx[i]][j+dy[i]]) 
        // {    curArea++;
        //     dfs(grid, visited,i+dx[i],j+dy[i],curArea,n,m);
        // }
        // }


        if(grid[i+1][j]==1 and check(i+1,j,m,n) and !visited[i+1][j]) 
        {    curArea++;
            dfs(grid, visited,i+1,j,curArea,n,m);}

             if(grid[i-1][j]==1 and check(i-1,j,m,n) and !visited[i-1][j])
           { curArea++;
            dfs(grid, visited,i-1,j,curArea,n,m);}
        
             if(grid[i][j+1]==1 and check(i,j+1,m,n) and !visited[i][j+1])
          {  curArea++;
            dfs(grid, visited,i,j+1,curArea,n,m);}

             if(grid[i][j-1]==1 and check(i,j-1,m,n) and !visited[i][j-1])
            {curArea++;
            dfs(grid, visited,i,j-1,curArea,n,m);}
    }



    int maxAreaOfIsland(vector<vector<int>>& grid){
        int area=INT_MIN;
            

       int n=grid.size();
       int m=grid[0].size();
        
         vector<vector<int>> visited(m, vector<int>(n,0));
       for(int i=0; i<n; i++) {
        for(int j=0;j<m;j++){
            int curArea=0;  //calculate area for current dfs call 
            if(grid[i][j]==1 and !visited[i][j])
           {
                curArea=1;
                dfs(grid,visited,i,j,curArea,n,m);
            }
            area=max(area,curArea);
        }
       }

       return area;
    }



};