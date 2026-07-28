/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, int> subtree;
    int sub(TreeNode* root){
        if(root == NULL) return 0 ;
        int l = sub(root->left);
        int r = sub(root->right);
        subtree[root] = max(l,r) + 1 ;
        return subtree[root];
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int ,int>mp; // stores depth of nodes
        queue<TreeNode*> q ; // performs bfs
        unordered_map<int,int> best;
        unordered_map<int,int> secondBest;
        unordered_map<int,int> bestNode;
        q.push(root);
        mp[root->val] = 0 ;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0 ; i < n ; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    mp[node->left->val] = mp[node->val]+ 1;
                    q.push(node->left);
                }
                if(node->right){
                    mp[node->right->val] = mp[node->val]+1;
                    q.push(node->right);
                }
            }
        }
        vector<int> ans ;
        sub(root);
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            int d = mp[node->val];
            int val = d + subtree[node] - 1;

            if(best.find(d) == best.end()){
                best[d] = val;
                secondBest[d] = -1;
                bestNode[d] = node->val;
            }
            else if(val > best[d]){
                secondBest[d] = best[d];
                best[d] = val;
                bestNode[d] = node->val;
            }
            else if(val > secondBest[d]){
                secondBest[d] = val;
            }

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        for(int x : queries){
            int d = mp[x];
            if(bestNode[d] == x)ans.push_back(max(d - 1, secondBest[d]));
            else ans.push_back(best[d]);
        }
        return ans ;
    }
};