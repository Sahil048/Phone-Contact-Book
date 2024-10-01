// Implementation of phone contact book
#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26]={NULL};
    bool flag=false;
    string str="";
    
    bool containskey(char ch){
        if(links[ch-'a']!=NULL)
            return true;
    }
    
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    bool setend(string &s){
        flag=true;
        str=s;
    }
    
    bool isend(){
        return flag;
    }
};

class Trie {

private:Node* root;
public:

    /** Initialize your data structure here. */
    Trie() {
         root=new Node;
    }

    /** Inserts a word into the trie. */
    void insert(string word,string contact) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                node->put(word[i],new Node);
            }
            //moves to the reference trie
            node=node->get(word[i]);
        }
        node->setend(contact);
        
    }


    /** Returns if there is any word in the trie that starts with the given prefix. */
    Node* startsWith(string prefix) {
         Node* node=root;
         for(int i=0;i<prefix.size();i++){
             if(!node->containskey(prefix[i]))
                 return NULL;
             node=node->get(prefix[i]);
         }
        return node;
    }
    void displaycontact(Node* node,string &s){
    	if(node->isend())
    	cout<<s<<" "<<node->str<<endl;
    	
    	for(int i=0;i<26;i++){
    		if(node->links[i]!=NULL){
    			char cha='a'+i;
    			string st=s+cha;
    			displaycontact(node->links[i],st);
			}
		}
	}
    void display(string s){
    	Node* node=startsWith(s);
    	if(node==NULL)
    	cout<<"No contact"<<endl;
    	else
    	displaycontact(node,s);
	}
};
int main(){
	
	Trie* t=new Trie();
	int n;
	cout<<"Number of contacts that you want in your phone list"<<endl;
	cin>>n;
	cout<<"Enter name and phone of your phone list"<<endl;
	for(int i=0;i<n;i++){
		string name,phone;
		cin>>name;
		cin>>phone;
		t->insert(name,phone);
	}
	
	cout<<"enter number of queries"<<endl;
	int query;
	cin>>query;
	for(int i=0;i<query;i++){
		string q;
		cout<<"searched list"<<endl;
		cin>>q;
		t->display(q);
	}
}
