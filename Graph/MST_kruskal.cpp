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
			//cout<<"TRUE"<<endl;
			return true;
		}
		//cout<<"FALSE"<<endl;
		return false;

	}

};

vector<vector<int>> kruskal(vector<vector<int>>& edges,int n){//n=nodes
	
	DSU graph;	
	vector<vector<int>> mst;
	for(int i=0;i<=n;i++){
		graph.makeSet(i);
	}


sort(edges.begin(),edges.end(),comp);
	for(auto edge:edges){
		int u=edge[0];
		int v=edge[1];
		int w=edge[2];
		if(graph.isSameComp(u,v))continue;
		mst.push_back({u,v,w});
		graph.Union(u,v);
	}
	
	return mst;

}

bool comp(vector<int> a,vector<int> b){
	return a[2]<b[2];
}
