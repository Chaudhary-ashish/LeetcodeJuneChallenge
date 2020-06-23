class Solution {
public:
    string solve(string s,int x)
    {
        if(x==0)
            return "";
        int n=s.size(),cur=0;
        int mod=1e7+9;
        vector<int> power(n);
        for(int i=0;i<n;i++)
            power[i] = (i == 0) ? 1 : (power[i-1] * 26) % mod;
        unordered_map<int,vector<int>> hash;
        for(int i=0;i<x;i++)
            cur=(cur*26+(s[i]-97))%mod;
        hash[cur]={0};
        for(int i=x;i<n;i++)
        {
            cur=((cur-power[x-1]*(s[i-x]-97))%mod+mod)%mod;
            cur=(cur*26+s[i]-97)%mod;
            if(hash.find(cur)==hash.end())
                hash[cur]={i-x+1};
            else
            {
                for(int id:hash[cur])
                {
                    if(s.substr(id,x)==s.substr(i-x+1,x))
                        return s.substr(id,x);
                }
                hash[cur].push_back({i-x+1});
            }
        }
        return "";
    }
    string longestDupSubstring(string s) {
        string ans="";
        int n=s.size();
        int i,j,k;
        int mid,low,high;
        low=1;
        high=n-1;
        while(low<=high)
        {
            int flag=0;
            mid=(low+high)/2;
            string r=solve(s,mid);
            if(r.size()>ans.size())
            {
                flag=1;
                ans=r;
            }
            if(flag==0)
            {
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};