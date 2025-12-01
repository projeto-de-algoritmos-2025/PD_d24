// link da questao: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

#include <bits/stdc++.h>

using namespace std;


class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        const int INF = 100000000;
        vector<int> distMinima(V, INF);
        vector<int> anterior(V, -1); 
        
        distMinima[src] = 0;
        
        for (int i = 1; i < V; ++i) {
            bool mudou = false;
            
            for (const auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int peso = edge[2];
                
                if (distMinima[u] != INF && distMinima[v] > distMinima[u] + peso) {
                    distMinima[v] = distMinima[u] + peso;
                    anterior[v] = u;
                    mudou = true;
                }
            }
            
            if (!mudou) {
                break;
            }
        }
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int peso = edge[2];
            
            if (distMinima[u] != INF && distMinima[v] > distMinima[u] + peso) {
                return {-1};
            }
        }
        
        return distMinima;
    }
};
