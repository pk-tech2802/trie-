// trick here is to sort the queries thats how our trie contains elements not exceding the required element 

#define ll long long
#define pb push_back
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
        
        for(int i=31;i>=0;i--){
            bool flag = ((1LL<<i)&n) ;
            int fl = flag ;
            if(!node->containskey(fl)){
                node->put(fl,new Node()) ;
            }
            node = node->get(fl);
        }
    }
    
} ;
// bool comp1(vector<int>a,vector<int>b)
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        trie *t= new trie() ;
        vector<vector<int>>mat ;
        for(int i=0;i<queries.size();i++){
            int x = queries[i][0] ;
            int mx = queries[i][1] ;
            // int ind = i ;
            mat.pb({mx,x,i}) ;
        }
        sort(nums.begin(),nums.end());
        sort(mat.begin(),mat.end());
        
        int q = queries.size() ;
        int n = nums.size() ;
        vector<int>ans(q) ;
        int j = 0 ;
        for(auto v:mat){
            int mx = v[0] ;
            int x = v[1];
            int ind = v[2] ;
            while(j<n && nums[j]<=mx){
                t->insert(nums[j++]) ;
            }
            
            Node*node = t->root ;
            if(!node->containskey(0) && !node->containskey(1)){
                ans[ind]=-1 ;
            }
            else{
                int num = 0 ;
                for(int i=31;i>=0;i--){
                    bool flag = ((1LL<<i)&x);
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
                ans[ind] = num ;
            }

        }
        
        return ans ;
    }
};
