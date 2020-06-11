class Solution {
public:
    bool isSubsequence(string s, string t) {
        int flag=0;
        int i,j;
        i=j=0;
        while(j<t.size()&&i<s.size())
        {
            if(s[i]==t[j])
            {
                flag++;
                i++;
                j++;
            }
            else
                j++;
        }
        if(flag==s.size())
            return true;
        return false;
        
    }
};