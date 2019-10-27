#include <bits/stdc++.h>
#include <cmath>
#define f first
#define s second
#define pb push_back
#define MAX 13
using namespace std;
vector<pair<int,int> > arr1[MAX];
vector<pair<int,int> > arr2[MAX];
map<int,int> m;
void allocate(int s, int n){
	int x = (int)ceil(log2(s));
	if(x>n){
		cout<<"Not enough space\n";
		return;
	}
	//cout<<x<<endl;
	pair<int,int> temp;
	//cout<<arr1[x].size()<<endl;
	if(arr1[x].size()!=0){
		//cout<<"p"<<arr1[x][0].f<<arr1[x][0].s<<endl;
		//arr2[x].pb(arr1[x][0]);
		temp.f=arr1[x][0].f;
		temp.s=arr1[x][0].s;
		arr1[x].erase(arr1[x].begin());
		cout<<"Memory allocated from "<<temp.f<<" to "<<temp.s<<". Total= "<<temp.s-temp.f+1<<" bytes "<<endl;
		m[temp.f]=temp.s-temp.f+1;
		return;
	}
	//cout<<"a"<<endl;
	int i=x+1;
	for(i=x+1;i<=n;i++){
		if(arr1[i].size()==0) continue;
		else break;
	}
	//cout<<"b"<<endl;
	if(i==n+1){
		cout<<"Failed to allocate memory \n";
	}
	
	else{
		pair<int,int> temp=arr1[i][0];
		arr1[i].erase(arr1[i].begin());
		i--;
		pair<int,int> p1, p2;
		for(;i>=x;i--){
			
			p2.f=temp.f+(temp.s-temp.f+1)/2;
			p2.s=temp.s;
			p1.f=temp.f;
			p1.s=temp.f+(temp.s-temp.f)/2;			
			arr1[i].pb(p2);
			temp=p1;
		}
		cout<<"Memory allocated from "<<temp.f<<" to "<<temp.s<<". Total= "<<temp.s-temp.f+1<<" bytes "<<endl;
		m[temp.f]=temp.s-temp.s+1;
	}	
}

void deallocate(int s,int n){
	if(m.find(s)==m.end()){
		cout<<"Invalid Request. This memory was never allocated \n";
		return;
	}
	int x = (int)ceil(log2(m[s]));
	//cout<<s<<" "<<x<<endl;
	int i, bn, ba;
	arr1[x].pb({s,s+m[s]-1});
	cout<<"Memory block from "<<s<<" freed \n";
	bn=s/m[s];
	if(bn%2!=0){
		ba=s-pow(2,x);
	}
	else ba=s+pow(2,x);
	for(i=0;i<arr1[x].size();i++){
		if(arr1[x][i].f==ba){
			if(bn%2==0){
				arr1[x+1].pb({s,2*pow(2,x)});
				cout<<"Merging blocks starting at "<<s<<" and "<<ba<<endl;
			}
			else{
				arr1[x+1].pb({ba,ba+2*pow(2,x)});
				cout<<"Merging blocks starting at "<<ba<<" and "<<s<<endl;
			}
		arr1[x].erase(arr1[x].begin()+i);
		arr1[x].erase(arr1[x].begin()+arr1[x].size()-1);
		break;
		}
	}
	m.erase(s);
}

void displaymem(int n){
	for(int i=1;i<=n;i++){
		if(arr1[i].size()!=0){
			cout<<"Memory free of size "<<pow(2,i)<<" :"<<endl;
			for(int j=0;j<arr1[i].size();j++) cout<<arr1[i][j].f<<" to "<<arr1[i][j].s<<endl;
		}
	}
	map<int,int>::iterator i;
	for (i = m.begin(); i != m.end(); i++) {
		cout<<"Memory allocated: "<<endl;
		cout<<(i->first)<<" to "<<(i->first)+(i->second)<<endl;
	}
}
int main(){
	int max1;
	cout<<"Enter maximum memory available <=4096 bytes \n";
	cin>>max1;
	int x = (int)ceil(log2(max1));
	arr1[x].pb({1,max1});
	cout<<"enter stuff \n";
	int y,z;
	while(1){
		cin>>y;
		if(y==1){	
		cin>>z;
		//cout<<"kfdk "<<arr1[x].f<<" "<<arr1[x].s<<endl;
		allocate(z,x);
		}
		else if(y==2){
			cin>>z;
			deallocate(z,x);
		}
		else if(y==3){
			displaymem(x);
		}
		else break;
	}
	return 0;
}

