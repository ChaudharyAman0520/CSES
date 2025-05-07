#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> dijkstra(unordered_map<int,vector<pair<int,int>>>&adj,int V)
{
	//~ priority_queue <Type, vector<Type>, ComparisonType > min_heap;
	priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
	vector<int>result(V+1,LLONG_MAX);
	vector<bool> visited(V+1,false);
	pq.push({0,1});
	result[1]=0;
	while(pq.empty()==false)
	{
		pair<int,int>p=pq.top();
		pq.pop();
		int d=p.first;
		int u=p.second;
		if(visited[u]==true)
		{
			continue;
		}
		visited[u]=true;
		for(pair<int,int> i:adj[u])
		{
			int w=i.second;
			int v=i.first;
			if(visited[v]==true)
			{
				continue;
			}
			if(result[v]>d+w)
			{
				result[v]=d+w;
				pq.push({result[v],v});
			}
		}
	}
	return result;
}
main()
{
	int n,m;
	cin>>n>>m;
	unordered_map<int,vector<pair<int,int>>> adj;
	for(int i=1;i<=m;i++)
	{
		int u,v,wt;
		cin>>u>>v>>wt;
		adj[u].push_back({v,wt});
	}
	//~ for(auto i:adj)
	//~ {
		//~ for(auto j:i.second)
		//~ {
			//~ cout<<i.first<<" -> "<<j.first<<" Wt- "<<j.second<<"  ";
		//~ }
		//~ cout<<endl;
	//~ }
	vector<int> ans=dijkstra(adj,n);
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}
