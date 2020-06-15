class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> adjList(n);
        for(auto f : flights) {
            int u = f[0];
            int v = f[1];
            int p = f[2];
            adjList[u].push_back({v, p});
        }
       queue<vector<int>> q;
       q.push({src, 0, -1});
        
     int ans = INT_MAX;   
    
        
     while(!q.empty()) {
            vector<int> curStation = q.front(); q.pop();
         
            int curCity = curStation[0];
            int curCost = curStation[1];
            int curK = curStation[2];      
            if(curCity == dst) {
              ans = min(ans, curCost);
              continue;  
            }
             
         
            for(auto p : adjList[curCity]) {
                
                if(curK+1 <= k and curCost + p[1] < ans)
                q.push({p[0], p[1] + curCost, curK+1});
            } 
         
     }   
        
     if(ans==INT_MAX)
         return -1;
        return ans;
    }
};