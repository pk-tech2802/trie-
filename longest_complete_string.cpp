// Q find longest complete string in array of string complete string is a string
// such that everyprefix of string is present in string array if there are multiple longest
// strings of same length return lexicographically smallest one 

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
    bool flag = false ;
    Node* links[26] ;

    bool containskey(char ch){
        return links[ch-'a']!=NULL ;
    }

    void put(char ch , Node * node){
        links[ch-'a'] = node ;
    }

    Node * get(char ch){
        return links[ch-'a'] ;
    }
};

class trie {
public:
    Node * root = new Node() ;    

    void insert(string word){
        Node* node = root ;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                node->put(word[i],new Node()) ;
            }

            node = node->get(word[i]) ;
        }

        node->flag = true ;
    }
} ;

int main()
{   
    int q ;
    cin>>q ;

    trie * t = new trie() ;
    vector<string> v; 

    while(q--){
        string s ;
        cin>>s ;
        t->insert(s);
        v.pb(s) ;
    }

    string ans = "";
    for(int i=0;i<v.size();i++){
        string word = v[i] ;
        Node * node = t->root ;
        node = node->get(word[0]) ;
        bool f1 = 1 ;
        for(int i=0;i<word.size();i++){
            if(node->flag==false){
                f1 = false;
                break;
            }
        }

        if(f1){
            if(ans.size()<word.size()){
                ans = word ;
                // cout<<"ans updated to "<<ans<<"\n";
            }
            else if(ans.size()==word.size()){
                if(word<=ans){
                    ans = word ;
                    // cout<<"ans updated to "<<ans<<"\n";
                }
            }
        }
    }

    cout<<ans<<"\n";

    return 0;
}
