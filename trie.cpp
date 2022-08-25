#include <bits/stdc++.h>
using namespace std;
#define fo(i, s, e) for (int i = s; i < e; i++)
typedef long long ll;
#define ff first
#define ss second
#define in insert
#define all(x) x.begin(), x.end()
#define pb push_back
using vi = vector<int>;
using vvi = vector<vector<int>>;

int mod = 998244353;

struct Node {
    Node *links[26] ;
    bool flag = false ;

    bool containskey(char ch){
        return (links[ch-'a']!=NULL) ;
    }

    void put(char ch ,Node *node){
        links[ch-'a']=node;
    }

    Node * get(char ch){
        return links[ch-'a'];
    }

    bool setend(){
        flag =true ;
    }

    bool isend(){
        return flag ;
    }
} ;

class trie{
    public :
        Node *root = new Node ;
        // root = new Node  ;
        trie (){ //constrctor 
            
        }

        void insert(string word){
            Node * node = root ; // dummmy ptr
            for(int i=0;i<word.size();i++){
                if(!node->containskey(word[i])){
                    node->put(word[i] ,new Node());
                }
                node = node->get(word[i]) ;
            }

            node->setend() ;

            // cout<<"word inserted\n";
        }

        bool serch(string word){
            Node* node = root ;
            for(int i=0;i<word.size();i++){
                if(!node->containskey(word[i])){
                    return 0 ;
                }

                node = node->get(word[i]) ;
            }

            return node->isend() ;
        }

        bool startwith(string word){
            Node * node = root ;
            for(int i=0;i<word.size();i++){
                if(!node->containskey(word[i])){
                    return 0 ;
                }
                node = node->get(word[i]) ;
            }
            return 1 ;
        }
} ;

void solve(){
    // cout<<"enter value q : " ;
    int q ;
    cin>>q ;
    // cout<<"q val "<<q<<"\n";
    trie * t= new trie() ;

    while(q--){
        int n ;
        string s ;
        cin>>n>>s ;
        // cout<<"n val "<<n<<" q val "<<q<<"\n";
        if(n==1){
            t->insert(s) ;
        }
        else if(n==2){
            bool f = t->serch(s) ;

            if(f){
                cout<<"word "<<s<<" exists\n";
            }
            else{
                cout<<"word "<<s<<" does not exist\n";
            }
        }
        else{
            bool f = t->startwith(s);

            if(f){
                cout<<"prefix "<<s<<" exists\n";
            }
            else{
                cout<<"prefix "<<s<<" does not exist\n";
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }

    return 0;
}
