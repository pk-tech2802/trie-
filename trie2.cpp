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
    int prefixes =0 ;
    int ends = 0 ;

    Node* links[26] ;

    bool containskey(char ch ){
        return links[ch-'a']!=NULL ;
    }

    void put(char ch, Node*node){
        links[ch-'a'] = node ;
    }

    Node* get(char ch){
        return links[ch-'a'] ;
    }
} ;
class trie {
private:
    Node *root ;
public :
    trie(){
        root = new Node ;
    }

    void insert(string word){
        Node * node = root ;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                node->put(word[i],new Node()) ;
            }
            node = node->get(word[i]) ;
            node->prefixes++ ;
        }
        // node->prefixes++ ;
        node->ends++ ;
    }

    int countPrefix(string word){
        Node * node = root ;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                return 0 ;
            }
            node = node->get(word[i]) ;
        }

        return node->prefixes ;
    }

    int countends(string word){
        Node * node = root ;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                return 0 ;
            }
            node = node->get(word[i]) ;
        }

        return node->ends ;
    }

    void remove(string word){
        Node * node = root ;
        for(int i=0;i<word.size();i++){
            node = node->get(word[i]) ;
            node->prefixes-- ;
        }
        // node->prefixes-- ;
        node->ends-- ;
    }
} ;
int main()
{   
    int q ;
    cin>>q ;

    trie *t = new trie(); 
    while(q--){
        int n ;
        string s ;
        cin>>n>>s ;
        // cout<<"n val "<<n<<" q val "<<q<<"\n";
        if(n==1){
            t->insert(s) ;
        }
        else if(n==2){
            int f = t->countPrefix(s) ;

            cout<<"no of pre for the word "<<s<<" are "<<f<<"\n";
        }
        else if(n==3){
            t->remove(s) ;
        }
        else{
            int f = t->countends(s);
            cout<<"no of ends for the word "<<s<<" are "<<f<<"\n";
        }
    }
    
    return 0;
}
