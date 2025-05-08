#include<bits/stdc++.h>
#define size ranq
using namespace std;
vector<int> ranq(100001,1);
vector<int> parent(100001);
int maxcomp=1;
void make_set(int n)
{
	for(int i=1;i<=n;i++)
	{
		parent[i]=i;
	}
}
int find_set(int x)
{
	if(x==parent[x])
	{
		return x;
	}
	parent[x]=find_set(parent[x]);
	return parent[x];
}
bool union_set(int u,int v)
{
	int x=find_set(u);
	int y=find_set(v);
	if(x==y)
	{
		return false;
	}
	if(ranq[x]>ranq[y])
	{
		parent[y]=x;
		ranq[x]+=ranq[y];
		maxcomp=max(maxcomp,ranq[x]);
	}
	else
	{
		parent[x]=y;
		ranq[y]+=ranq[x];
		maxcomp=max(maxcomp,ranq[y]);
	}
	return true;
}
main()
{
	int n,m;
	cin>>n>>m;
	int comps=n;
	make_set(n);
	while(m--)
	{
		int u,v;
		cin>>u>>v;
		bool result=union_set(u,v);
		if(result==true)
		{
			comps--;
		}
		cout<<comps<<" "<<maxcomp<<endl;
	}
}
