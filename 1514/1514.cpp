#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // convert edge list representation into adjacency matrix
        int adj[n][n];
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]][edges[i][1]] = succProb[i];
        }
        // create arrays for which nodes are visited and the prob of reaching node
        bool visited[n];
        double nodeProb[n];
        // max heap of edges we need to compare
        bool greaterEdge()(int a, int b) { return succProb[a] > succProb[b]; };
        priority_queue<int, vector<int>, greaterEdge> edgeHeap;
        // 
        while(!edgeHeap.empty()) {
            edgeHeap.pop()
        }
    }
};

int main(int argc, char** argv) {
    int n = 0;
    vector<vector<int>> edges = {};
    vector<double> succProb = {};
    if(edges.size() != succProb.size()) {
        cout << "edges size must equal succProb size!" << endl;
        return 1;
    }
    cout << "max probability: " << maxProbability(n, edges, succProb, 0, 0) << endl;
    return 0;
}