class RandomizedSet {
public:
    vector<int> v;
    map<int,int> m;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val)==m.end())
        {
            m.insert({val,v.size()});
            v.push_back(val);
            return true;
        }
        return false;
        
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val)==m.end())
            return false;
        int x=m[val];
        v[x]=v[v.size()-1];
        int y=v[x];
        m[y]=x;
        v.pop_back();
        m.erase(val);
        return true;
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand()%v.size()];
    }
};

//Prachi Prachi Prachi!!!!!!!!! <3<3
//I devote this code to you ma love!!!! 
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */