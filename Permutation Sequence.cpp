class Solution {
public:
    int fact[10];
    string getPermutation(int n, int k) {
        fact[0]=1;
        for(int i=1;i<10;i++)
            fact[i]=fact[i-1]*i;
        int i,j,x,z;
        j=n-1;
        z=0;
        string ans="";
        int ct[n+1];
        for(i=0;i<=n;i++)
            ct[i]=0;
        while(z<k&&j)
        {
            int i=0;
            while(z<k)
            {
               z+=fact[j];
                i++;
            }
            z-=fact[j];
            j--;
            x=1;
            while(i>1)
            {
                if(ct[x]==0)
                    i--;
                x++;
            }
            while(ct[x]==1)
                x++;
            ans+=char('0'+x);
            ct[x]=1;
        }
        x=1;
        while(x<=n)
        {
            if(ct[x]==0)
              ans+=char('0'+x);  
            x++;
        }
        return ans;
    }
};