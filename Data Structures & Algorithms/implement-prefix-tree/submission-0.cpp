class PrefixTree {
public:
    vector<PrefixTree*> neigh;
    bool eow;
    PrefixTree() {
        neigh.resize(26,NULL);
        eow = false;
    }
    
    void insert(string word) {
        PrefixTree * node = this;
        for(auto x : word){
            if(node->neigh[x-'a']==NULL){
                node->neigh[x-'a'] = new PrefixTree();
            }
            node = node->neigh[x-'a'];
        }
        node->eow = true;
    }
    
    bool search(string word) {
        PrefixTree * node = this;
        for(auto x : word){
            if(node->neigh[x-'a']==NULL){
                return false;
            }
            node = node->neigh[x-'a'];
        }
        return node->eow;
    }
    
    bool startsWith(string prefix) {
        PrefixTree * node = this;
        for(auto x : prefix){
            if(node->neigh[x-'a']==NULL){
                return false;
            }
            node = node->neigh[x-'a'];
        }
        return true;
        
    }
};
