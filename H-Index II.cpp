class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        if(n==0)
            return 0;
        int ans=0;
        int i=1;
        while(i<=n-1)
        {
            if(citations[n-i]>=i&&citations[n-i-1]<=i)
                ans=i;
            i++;
        }
        if(citations[n-i]>=i)
            ans=i;
        return ans;
    }
};