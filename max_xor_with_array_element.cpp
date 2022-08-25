#define ll long long
struct Node{
    Node * links[2] ;
    
    bool containskey(int bit){
        return links[bit]!=NULL ;
    }
    
    void put(int bit ,Node* node){
        links[bit] = node ;
    }
    
    Node* get(int bit){
        return links[bit] ;
    }
} ;
class trie{
public:
    Node * root = new Node() ;
    
    void insert(int n){
        Node * node = root ;
        
        for(int i=30;i>=0;i--){
            bool flag = ((1LL<<i)&n) ;
            int fl = flag ;
            if(!node->containskey(fl)){
                node->put(fl,new Node()) ;
            }
            node = node->get(fl);
        }
    }
} ;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        trie * t = new trie() ;
        for(auto n :nums){
            t->insert(n) ;
        }
        
        ll ans = -1 ;
        for(auto x :nums){
            Node * node = t->root;
            ll num = 0 ;
            for(int i=30;i>=0;i--){
                bool flag = ((1LL<<i)&x) ;
                int fl = flag ;
                fl^=1 ;
                if(node->containskey(fl)){
                    num+=(1LL<<i) ;
                    node = node->get(fl) ;
                }
                else{
                    node = node->get(fl^1) ;
                }
            }
            
            ans = max(ans,num);
        }
        
        return ans ;
    }
};
