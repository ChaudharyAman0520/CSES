#include<bits/stdc++.h>
using namespace std;
bool found=false;
void dfs(unordered_map<int, vector<int>>&v,int curr,int parent ,vector<int>&path,vector<bool>&visited)
{
	if(found==true)
	{
		return;
	}
	if(visited[curr]==true)
	{
		if(path.size()>2)
		{
			found=true;
			int len=1;
			vector<int> ans;
			ans.push_back(curr);
			for(int i=path.size()-1;i>=0;i--)
			{
				if(path[i]==curr)
				{
					break;
				}
				len++;
				ans.push_back(path[i]);
			}
			ans.push_back(curr);
			cout<<len<<endl;
			for(auto i:ans)
			{
				cout<<i<<" ";
			}
			return;
		}
	}
	visited[curr]=true;
	path.push_back(curr);
	for(auto i:v[curr])
	{
		if(i==parent)
		{
			continue;
		}
		dfs(v,i,curr,path,visited);
	}
	path.pop_back();
}
int main()
{
	int n,m;
	cin>>n>>m;
	unordered_map<int, vector<int>>v;
	for(int i=1;i<=m;i++)
	{
		int s,e;
		cin>>s>>e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	//~ for(auto i:v)
	//~ {
		//~ cout<<i.first<<"->";
		//~ for(auto j:i.second)
		//~ {
			//~ cout<<j<<"->";
		//~ }
		//~ cout<<endl;
	//~ }
	vector<bool> visited(n+1,false);
	vector<int> path;
	for(int i=1;i<=n;i++)
	{
		if(found==true)
		{
			continue;
		}
		if(visited[i]==true)
		{
			continue;
		}
		dfs(v,i,-1,path,visited);
	}
	if(found==false)
	cout<<"No Cycle";
}
