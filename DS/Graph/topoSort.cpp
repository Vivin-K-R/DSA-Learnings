#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

void dfs(int node, vector<int>& visited,
         vector<vector<int>>& adj,
         stack<int>& st){

    visited[node]=1;

    for (int it : adj[node]){

        if (!visited[it]){

            dfs(it, visited, adj, st);
        }
    }

    st.push(node);
}

vector<int> topoSort(vector<vector<int>>& adj){

    int n = adj.size();

    stack<int> st;

    vector<int> vis(n,0);

    for (int i=0;i<n;i++){

        if (!vis[i]){

            dfs(i,vis,adj,st);
        }
    }

    vector<int> topo;

    while (!st.empty()){

        topo.push_back(st.top());

        st.pop();
    }

    return topo;
}


vector<int> Khans(vector<vector<int>>& adj){

    int v=adj.size();
    vector<int>indegree(v,0);
    vector<int>res;
    for(int i=0;i<v;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    queue<int>q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0) q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        res.push_back(node);

        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }

    return res;
}
void addEdge(vector<vector<int>>& adj,int u,int v){

    adj[u].push_back(v);
}

int main(){

    int n = 5;

    vector<vector<int>> adj(n);

    addEdge(adj,0,1);
    addEdge(adj,2,1);
    addEdge(adj,3,2);
    addEdge(adj,4,2);

    vector<int> res = Khans(adj);

    for (int vertex : res)

        cout<<vertex<<" ";

    cout<<endl;
}
