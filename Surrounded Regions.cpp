class Solution {
public:
    int vis[1000][1000];
    int m,n;
    void solve(int i,int j,vector<vector<char>>& v)
    {
        if(i<0||i>=n||j<0||j>=m||v[i][j]=='X'||vis[i][j]==0)
            return;
        vis[i][j]=0;
        solve(i+1,j,v);
        solve(i-1,j,v);
        solve(i,j+1,v);
        solve(i,j-1,v);
    }
    void solve(vector<vector<char>>& v) {
        if(v.size()==0)
            return;
        for(int i=0;i<1000;i++)
            for(int j=0;j<1000;j++)
                vis[i][j]=1;
        m=v[0].size();
        n=v.size();
        for(int j=0;j<m;j++)
            if(v[0][j]=='O')
            {
                solve(0,j,v);
            }
        for(int j=0;j<m;j++)
            if(v[n-1][j]=='O')
            {
                solve(n-1,j,v);
            }
        for(int i=1;i<n-1;i++)
            if(v[i][0]=='O')
            {
                solve(i,0,v);
            }
        for(int i=1;i<n-1;i++)
            if(v[i][m-1]=='O')
            {
                solve(i,m-1,v);
            }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(v[i][j]=='O'&&vis[i][j]==1)
                    v[i][j]='X';
    }
};