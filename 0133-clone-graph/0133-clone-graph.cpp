
class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;

        // If already cloned, return its copy
        if (mp.count(node))
            return mp[node];

        // Create a copy of the current node
        Node* clone = new Node(node->val);
        mp[node] = clone;

        // Clone all neighbors
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};

