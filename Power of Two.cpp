class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0)
            return false;
        int flag=0;
        while(n)
        {
            if(n%2>0)
                flag++;
            n=n>>1;
        }
        if(flag==1)
            return true;
        return false;
    }
};