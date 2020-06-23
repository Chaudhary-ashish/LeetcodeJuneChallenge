class Solution {
public:
    string validIPAddress(string IP) {
        int n=IP.size();
        string s=IP;
        int dot,col;
        dot=col=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='.')
                dot++;
            if(s[i]==':')
                col++;
        }
        if(dot==3&&col==0)
        {
            s="";
            int ct=0;
            IP+='.';
            int i=0;
            while(i<IP.size())
            {
                ct=0;
                while(IP[i]!='.')
                {
                  ct=ct*10+(IP[i]-'0');
                    i++;
                    if(ct>255)
                    return "Neither";
                }
                s+=to_string(ct)+'.';
                i++;
                
            }
            if(s==IP)
                return "IPv4";
        }
        if(col==7&&dot==0)
        {
            int flag=1;
            IP+=':';
            int j=0;
            while(j<IP.size())
            {
                int ct=0;
                while(IP[j]!=':')
                {
                    ct++;
                    if((IP[j]<='9'&&IP[j]>='0')||(IP[j]>='a'&&IP[j]<='f')||(IP[j]>='A'&&IP[j]<='F'))
                    {
                        
                    }
                    else flag=0;
                    j++;
                }
                if(ct==0||ct>4)
                    flag=0;
                j++;
            }
            if(flag)
                return "IPv6";
        }
        return "Neither";
    }
};