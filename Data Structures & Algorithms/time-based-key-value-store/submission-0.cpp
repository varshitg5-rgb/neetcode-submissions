class TimeMap {
public:
    unordered_map<string,map<int,string>> u;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
       u[key].insert({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(u.find(key)==u.end()) return "";
        auto &internal_map = u[key];
        auto it = internal_map.upper_bound(timestamp);

        if (it == internal_map.begin()) {
            return "";
        }

        --it;
        return it->second;
    }
};
