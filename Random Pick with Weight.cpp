class Solution {
public:
    vector<int> v;
    int ans=0;
    Solution(vector<int>& w) {
        for(int i=0;i<w.size();i++)
        {
            ans+=w[i];
            v.push_back(ans);
        }
    }
    
    int pickIndex() {
        int n=v.size();
        n=rand()%v[n-1];
        
        return upper_bound(v.begin(),v.end(),n)-v.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */