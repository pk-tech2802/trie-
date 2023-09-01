//Q count number of distinct substrings of a string 

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
    string s ;
    cin>>s ;
    int n = s.size() ;
    int ans = 0 ;

    trie* t = new trie() ;

    fo(i,0,n){
        Node * node = t->root ;
        fo(j,i,n){
            if(!node->containskey(s[j])){
                node->put(s[j],new Node()) ;
                // cout<<"ans ++ed when i is "<<i<<" and j is "<<j<<"\n";
                ans++ ;
            }
            // else{
            //     break ;
            // }
            node =  node->get(s[j]) ;
        }
    }

    cout<<ans+1<<"\n" ;
    return 0;
}
