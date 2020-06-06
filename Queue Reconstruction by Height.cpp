class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
            v.push_back(make_pair(people[i][0],(-1*people[i][1])));
        sort(v.begin(),v.end());
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i].push_back(0);
            ans[i].push_back(0);
        }
        int x,y,temp,j;
        for(int i=n-1;i>=0;i--)
        {
            x=v[i].first;
            y=v[i].second*-1;
            int j=n-1;
            while(j!=y)
            {
                ans[j][0]=ans[j-1][0];
                ans[j][1]=ans[j-1][1];
                j--;
            }
            ans[j][0]=x;
            ans[j][1]=y;
        }
        return ans;
        
    }
};