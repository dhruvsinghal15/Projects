#include&lt;bits/stdc++.h&gt;
using namespace std;
void dfs(vector&lt;int&gt; adj[],vector&lt;bool&gt; &amp;visited,int node)
{
int child,size=adj[node].size();
for(int i=0;i&lt;size;i++)
{
child=adj[node][i];
if(visited[child])
continue;
cout&lt;&lt;child&lt;&lt;&quot; &quot;;
visited[child]=true;
dfs(adj,visited,child);
}
return;
}
int main()
{
int n;
cout&lt;&lt;&quot;No. of vertices: &quot;;
cin&gt;&gt;n;
vector&lt;int&gt; adj[n];
int edges;
cout&lt;&lt;&quot;Enter no of edges: &quot;;
cin&gt;&gt;edges;

int a,b;
for(int i=0;i&lt;edges;i++)
{
cin&gt;&gt;a&gt;&gt;b;
adj[a].push_back(b);
adj[b].push_back(a);
}
vector&lt;bool&gt; visited(n,false);
visited[0]=true;
dfs(adj,visited,0);
return 0;
}