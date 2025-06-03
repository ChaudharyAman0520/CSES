#include<bits/stdc++.h>
#define int long long
using namespace std;
void prim(unordered_map<int,vector<pair<int,int>>>&adj,int V)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,1});
	vector<bool> visited(V+1,false);
	int maxi=0;
	int ans=0;
	while(pq.empty()==false)
	{
		auto it=pq.top();
		pq.pop();
		int wt=it.first;
		int u=it.second;
		if(visited[u]==true)
		{
			continue;
		}
		visited[u]=true;
		ans+=wt;
		maxi=max(maxi,wt);
		for(auto i:adj[u])
		{
			int d=i.second;
			int v=i.first;
			if(visited[v]==true)
			{
				continue;
			}
			pq.push({d,v});
		}
	}
	ans=ans-maxi;
	ans=ans+(maxi/2);
	cout<<ans<<endl;
}
main()
{
    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<pair<int,int>>> adj;
    while(m--)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }
    //~ for(auto i:adj)
    //~ {
        //~ for(auto j:i.second)
        //~ {
            //~ cout<<i.first<<" "<<j.first<<" "<<j.second<<endl;
        //~ }
    //~ }
    prim(adj,n);
}
