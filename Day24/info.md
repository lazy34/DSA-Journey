## Date - [10-03-24]

## Topic Name

Graph

## Todays Goal

* Bellman ford Algo

## Code

```
class Solution {
public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices

    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;

        // Relax edges |V| - 1 times
        for (int i = 0; i < V - 1; i++) {
            for (auto it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];

                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Nth relaxation to check for negative edge cycle
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return {-1}; // Negative cycle found
            }
        }

        return dist;
    }
};
```
