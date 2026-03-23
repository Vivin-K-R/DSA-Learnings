#include<iostream>
#include<vector>


bool dfs(std::vector<bool>& visited,std::vector<bool>& path,std::vector<std::vector<int>>& adj,int node){
    visited[node]=true;
    path[node]=true;

    for(int i : adj[node]){
        if(!visited[i]){
            if(dfs(visited,path,adj,i)) return true;
        }

        else if(path[i]) return true;
    }

    path[node]=false;
    return false;
}


bool isCyclic(std::vector<std::vector<int>>& adj){
    std::vector<bool>visited(adj.size(),false);
    std::vector<bool>path(adj.size(),false);

    for(int i=0;i<adj.size();i++){
        if(!visited[i]){
            if(dfs(visited,path,adj,i)) return true;
        }
    }
    return false;
}



int main() {
    std::vector<std::vector<int>> adj = {{1},{2},{0, 3}};

    std::cout << (isCyclic(adj) ? "true" : "false") << std::endl;
    return 0;
}

