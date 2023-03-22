
#include <vector>
#include <map>
#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
    friend ostream& operator<<(ostream& os, const Node& node);
};
Node* cloneGraph(Node* node);
Node* cloneGraph(Node* node, map<Node*, Node*>* m);
Node* createGraph(int* vals, int** edges, int n);
void bfs(Node* node);
void freeGraph(Node* node);

Node* cloneGraph(Node* node) {
    map<Node*, Node*>* m = new map<Node*, Node*>();
    node = cloneGraph(node, m);
    delete m;
    return node;
}

Node* cloneGraph(Node* node, map<Node*, Node*>* m) {
    if(m->find(node) != m->end()) return (*m)[node];
    (*m)[node] = new Node(node->val);
    for(Node* neighbor : node->neighbors){
        (*m)[node]->neighbors.push_back(cloneGraph(neighbor, m));
    }
    return (*m)[node];
}

ostream& operator<<(ostream& os, const Node& node) {
  os << node.val << " -> {";
  if(0 < node.neighbors.size()) os << node.neighbors[0]->val;
  for(int i = 1; i < node.neighbors.size(); i++){
    os << ", " << node.neighbors[i]->val;
  }
  os << "}";
  return os;
}

Node* createGraph(int* vals, int* edges, int n){
    if(!n) return NULL;
    Node* nodes[n];
    for(int i = 0; i < n; i++){
        nodes[i] = new Node(vals[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(edges[i*n+j]) nodes[i]->neighbors.push_back(nodes[j]);
        }
    }
    return nodes[0];
}

void bfs(Node* node){
    map<Node*, int> colors = map<Node*, int>();
    queue<Node*> queue;
    queue.push(node);
    colors[node] = 1;
    while(!queue.empty()){
        node = queue.front();
        queue.pop();
        cout << *node << endl;
        for(Node* neighbor : node->neighbors){
            if(!colors[neighbor]){
                queue.push(neighbor);
                colors[neighbor] = 1;
            }
        }
    }
}

void freeGraph(Node* node){
    map<Node*, int> colors = map<Node*, int>();
    queue<Node*> queue;
    queue.push(node);
    colors[node] = 1;
    while(!queue.empty()){
        node = queue.front();
        queue.pop();
        for(Node* neighbor : node->neighbors){
            if(!colors[neighbor]){
                queue.push(neighbor);
                colors[neighbor] = 1;
            }
        }
        delete node;
    }
}

int main(){
    int vals[] = {0,1,2,3};
    int edges[] = {0,1,1,0,0,0,0,1,0,1,0,0,1,0,0,0};
    cout << "generating graph." << endl;
    Node* graph = createGraph(vals, edges, 4);
    cout << "printing graph." << endl;
    bfs(graph);
    cout << "cloning graph." << endl;
    Node* cloned = cloneGraph(graph);
    cout << "printing clone." << endl;
    bfs(cloned);
    cout << "cleaning memory." << endl;
    freeGraph(graph);
    freeGraph(cloned);
    return 0;
}