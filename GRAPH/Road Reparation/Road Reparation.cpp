#include<bits/stdc++.h>
#define int long long
using namespace std;
void mst(unordered_map<int,vector<pair<int,int>>>&adj,int n)
{
	bool poss=true;
	int ans=0;
	vector<int> visited(n+1,0);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,1});
	while(pq.empty()==false)
	{
		auto it=pq.top();
		pq.pop();
		if(visited[it.second]==1)
		{
			continue;
		}
		visited[it.second]=1;
		ans+=it.first;
		for(auto i:adj[it.second])
		{
			if(visited[i.first]==0)
			{
				pq.push({i.second,i.first});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			poss=false;
			break;
		}
	}
	if(poss==false)
	{
		cout<<"IMPOSSIBLE"<<endl;
	}
	else
	{
		cout<<ans<<endl;
	}
}
main()
{
	int n,m;
	cin>>n>>m;
	unordered_map<int,vector<pair<int,int>>> adj;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	//~ for(auto i:adj)
	//~ {
		//~ for(auto j:i.second)
		//~ {
			//~ cout<<i.first<<" -> "<<j.first<<" Wt- "<<j.second<<"  ";
		//~ }
		//~ cout<<endl;
	//~ }
	mst(adj,n);
}
