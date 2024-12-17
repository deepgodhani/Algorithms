#include<bits/stdc++.h>

using namespace std;

struct Item;

struct Node
{
	int val;
	Node* next;
	Item* ItemPtr;//front pointer;
};

struct Item
{
	Node *hd,*tl;
};

class ListSet{

	unordered_map<int,Node*> nodeAdd;

	public:
		void makeSet(int v){
			Item *newSet = new Item;
			
			newSet->hd = new Node;

			newSet->tl=newSet->hd;

			nodeAdd[v]=newSet->hd;


			newSet->hd->val = v;
			
			newSet->hd->ItemPtr=newSet;

			newSet->hd->next=NULL;

		}

		void Union(Item *set1,Item *set2){	

			Node* curr = set2->hd;
			while(curr != 0){
				curr->ItemPtr=set1;
				curr=curr->next;
			}
			set1->tl->next = set2->hd;
			set1->tl = set2->tl;

			delete set2; 
		}

		bool isInSameComp(int a,int b){
			if(nodeAdd[a]->ItemPtr == nodeAdd[b]->ItemPtr){
				cout<<"true"<<endl;
				return true;
			}
			cout<<"False"<<endl;
			return false;
		}

		Item *find(int val){
			Node* ptr=nodeAdd[val];

			return ptr->ItemPtr;
		}

};




int main(){

	vector<int> Vertex;
	ListSet G;

	
	G.makeSet(140);
	G.makeSet(10);
	G.makeSet(20);
	G.makeSet(120);
	G.makeSet(150);


	G.Union(G.find(10),G.find(20));
	G.isInSameComp(10,20);
	G.isInSameComp(10,120);


}
