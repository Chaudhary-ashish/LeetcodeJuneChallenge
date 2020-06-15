class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==0)
            return {};
        sort(nums.begin(),nums.end());
        int x,y,z=0,ans;
        vector<pair<int,int>> p;
        for(int i=0;i<nums.size();i++)
            p.push_back(make_pair(1,-1));
        for(int i=nums.size()-1;i>=0;i--)
        {
            x=1;
            y=1;
            for(int j=i+1;j<nums.size();j++)
                if(nums[j]%nums[i]==0)
                {
                    if(x+p[j].first>y)
                    {
                        y=x+p[j].first;
                        p[i].first=y;
                        p[i].second=j;
                    }
                }
            if(p[i].first>z)
            {
                z=p[i].first;
                ans=i;
            }
        }
        vector<int> v;
        while(ans!=-1)
        {
            v.push_back(nums[ans]);
            ans=p[ans].second;
        }
        return v;
        
    }
};