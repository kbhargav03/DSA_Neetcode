#include <vector>
#include <unordered_map>

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
    
};

class Solution {
    private:

        unordered_map<Node*, Node*> clonedNodes;

        Node* cloneUsingDFS(Node* node) {
            if(clonedNodes.find(node) != clonedNodes.end()) {
                return clonedNodes[node];
            }

            Node* clonedNode = new Node(node->val);

            clonedNodes[node] = clonedNode;

            for(Node* neighbor : node->neighbors) {
                clonedNode->neighbors.push_back(cloneUsingDFS(neighbor));
            }

            return clonedNode;
        }

    public:
        Node* cloneGraph(Node* node) {
            if(node == nullptr) {
                return nullptr;
            }

            return cloneUsingDFS(node);
        }
    
        void printGraph(Node* node) {
            if(node == nullptr) {
                cout << "Graph is empty.";
                return;
            }

            unordered_set<Node*> visited;
            queue<Node*> nodesToVisit;

            visited.insert(node);
            nodesToVisit.push(node);

            while(!nodesToVisit.empty()) {
                Node* currentNode = nodesToVisit.front();
                nodesToVisit.pop();

                cout << "Node " << currentNode->val << ": ";

                for(Node* neighbor : currentNode->neighbors) {
                    cout << neighbor->val << " ";

                    if(visited.find(neighbor) == visited.end()) {
                        visited.insert(neighbor);
                        nodesToVisit.push(neighbor);
                    }
                }
                cout << '\n';
            }
        }
        int main() {
            Node* node1 = new Node(1);
            Node* node2 = new Node(2);
            Node* node3 = new Node(3);
            Node* node4 = new Node(4);

            node1->neighbors = {node2, node4};
            node2->neighbors = {node1, node3};
            node3->neighbors = {node2, node4};
            node4->neighbors = {node1, node3};

            Solution solution;
            Node* clonedGraph = solution.cloneGraph(node1);

            cout << "Original graph:\n";
            printGraph(node1);

            cout << "\nCloned graph:\n";
            printGraph(clonedGraph);

            cout << "\nOriginal starting node address: " << node1 << '\n';
            cout << "Cloned starting node address:   " << clonedGraph << '\n';

            return 0;
        }
};