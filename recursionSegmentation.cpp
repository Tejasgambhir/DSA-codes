 #include <bits/stdc++.h>
 using namespace std;
bool isSafe(int x,int y,int m ,int n){
        return (x<n && x>=0 ) && ( y<m && y>=0);
    }
    int minCount = INT_MAX;
    void dfs(vector<vector<int>> &mat,int i ,int j,int m,int n,int c){
       if(j==m){
        // cout<<i<< " "<< j<<endl;
           minCount = min(minCount,c);
           return;
       }

    //   cout<<isSafe(i,j,m,n)<<endl;
       if(isSafe(i,j,m,n)){
        //   cout<<i<< " "<< j<<endl;
          if(mat[i][j]==1){
            dfs(mat,i,j+1,m,n,c+1);
           }
          else{
            dfs(mat,i+1,j-1,m,n,c);
            dfs(mat,i-1,j-1,m,n,c);
          }
       }
       else{
           return;
       }
    }
    int findShortestPath(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int>row{1,0,0,-1};
        vector<int>col{0,1,-1,0};
       for(int i = 0 ;i<n;i++){
           for(int j = 0 ;j<m;j++){
               if(mat[i][j]==0){
                   for(int k = 0 ;k<4;k++){
                       if(isSafe(i+row[k],j+col[k],m,n)){
                           mat[i+row[k]][j+col[k]] = -1;
                       }
                   }
               }
           }
       }

       for(int i = 0 ;i<n;i++){
           if(mat[i][0]==1)
           {
              dfs(mat,i,0,m,n,0);
           }
       }
    //   dfs(mat,0,0,m,n,0);
        // for(auto x:mat){
        //     for(auto y:x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
       return (minCount == INT_MAX) ? -1 : minCount;
    }
   
    int main()
    {
    int n =3,m=3;
    vector<vector<int>>mat(n,vector<int>(m,1));
    // mat[0][1] = 0;
    mat[2][2] = 0;
    // mat[1][1] = 0;
    cout<<"entering"<<endl;
    cout<<findShortestPath(mat)<<endl;
       
        
    return 0;
    }