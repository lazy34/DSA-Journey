//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool dfs(int start,vector<int>adj[],int color[],int col){
        color[start] = col;
        
        for(auto it : adj[start]){
            if(color[it]==-1){
                if(dfs(it,adj,color,!col)==false) return false;
            }
            
            else if(color[it] == col){
                return false;
            }
        }
        
        return true;
        
    }
    
public:
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    for(int i=0;i<V;i++){
	        color[i] = -1;
	    }
	    
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(dfs(i,adj,color,0)==false) return false;
	        }
	    }
	    
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends