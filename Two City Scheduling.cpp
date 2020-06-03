class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int,int> > diff;
        int n=costs.size();
        for(int i=0;i<n;i++)
        {
            diff.push_back(make_pair(abs(costs[i][0]-costs[i][1]),i));
        }
        sort(diff.begin(),diff.end());
        int an,bn,x;
        an=bn=n/2;
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
           x=diff[i].second;
            if(costs[x][0]<costs[x][1])
            {
                if(an)
                {
                    an--;
                    ans+=costs[x][0];
                }
                else
                {
                    bn--;
                    ans+=costs[x][1];
                }
            }
            else
            {
                if(bn)
                {
                    bn--;
                    ans+=costs[x][1];
                }
                else
                {
                    an--;
                    ans+=costs[x][0];
                }
            }
        }
        return ans;
    }
};