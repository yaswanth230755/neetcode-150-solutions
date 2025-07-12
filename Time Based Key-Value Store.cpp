class TimeMap {
    unordered_map<string,vector<pair<int,string>>> unmap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        //unmap[key].push_back({timestamp,value});
        unmap[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto& vec = unmap[key];
        int l = 0, r = vec.size() - 1, ans = -1;
        
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (vec[m].first <= timestamp) {
                ans = m;      // possible answer
                l = m + 1;    // search right side
            } else {
                r = m - 1;    // search left side
            }
        }

        return (ans == -1) ? "" : vec[ans].second;
        // int l=0,h=unmap[key].size()-1,m,index=-1;
        // while(l<=h){
        //     m=l+((h-l)>>1);
        //     if(unmap[key][m].first>timestamp){
        //         h=m-1;
        //     }
        //     else{
        //         index=m;
        //         l=m+1;
        //     }
        // }
        // return (index>=0)?unmap[key][index].second:"";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */