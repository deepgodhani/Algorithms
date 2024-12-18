#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int val;
	int rank;
	Node *par;
};



class DSU{

	unordered_map<int,Node*> addNode;

public:

	void makeSet(int  val){
		Node* node=new Node();
		node->val=val;
		node->par=node;
		node->rank=1;
		addNode[val]=node;
	}

	void Union(int a,int b){
		Node* par_a=find_par(addNode[a]);
		Node* par_b=find_par(addNode[b]);

		if(par_a->val == par_b->val)return; 

		if(par_a->rank >= par_b->rank){
			par_b->par=par_a;
			if(par_a->rank == par_b->rank)par_a->rank++;
			
		}

		else{
			par_a->par=par_b;
			
		}
	}

	Node* find_par(Node* node){
		if(node->par->val == node->val){
			return node;
		}
		return node->par=find_par(node->par);
	}

	bool isSameComp(int a,int b){
		if(find_par(addNode[a]) == find_par(addNode[b])){
			cout<<"TRUE"<<endl;
			return true;
		}
		cout<<"FALSE"<<endl;
		return false;

	}

};


int main(){

	
	DSU g;
	g.makeSet(10);
	g.makeSet(20);
	g.makeSet(30);
	g.makeSet(50);
	g.makeSet(70);
	g.makeSet(80);
	g.makeSet(90);

	g.Union(10,20);
	g.Union(20,30);

	g.isSameComp(10,50);
	g.isSameComp(10,30);
	g.isSameComp(10,90);


}
