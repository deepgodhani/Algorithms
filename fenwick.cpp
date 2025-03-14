#include<bits/stdc++.h>

using namespace std;

class fenwick{
	vector<int> bit;
	int n;
public:
	 fenwick(int n){
		this->n=n;
		bit.resize(n,0);
	}

	void update(int ind,int num){

		while(ind<n){
			bit[ind]+=num;
			ind = ind | (ind+1);
			//ind += (ind & -ind) one based indexing
		}

	}

	int sum(int r){
		int res=0;
		while(r>=0){
			res+=bit[r];
			r = ( r & (r+1) ) - 1; 
			// r-= (r & -r); one based indexing
		}
		return res;
	}

	int rangeSum(int l,int r){
		return sum(r) - sum(l-1);
	}

};

int main(){
	string x;
	cout<<"hello"<<endl;
	cin>>x;

	vector<int> v = {3,5,1,2,10,7,9,8,-4,5,6,3,2,7,10};
	int n=v.size();

	fenwick f(n);

	for(int i=0;i<n;i++){
		f.update(i,v[i]);
	}

	cout<<f.rangeSum(2,8)<<endl;
	cout<<f.rangeSum(1,6)<<endl;
	cout<<f.rangeSum(2,7)<<endl;
	cout<<f.rangeSum(2,9)<<endl;
	cout<<f.sum(n-1)<<endl;


	cout<<x;
	return 0;
}
