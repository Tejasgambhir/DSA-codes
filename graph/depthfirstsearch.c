#include<stdio.h>
#include<string.h>

    int visited[7] = {0,0,0,0,0,0,0};
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };

void dfs(int i){
    printf("%d",i);
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (a[i][j]==1 && visited[j] == 0)
        {
            dfs(j);
        }
        
    }
    
}
int main()
{
    dfs(2);
    return 0;
}