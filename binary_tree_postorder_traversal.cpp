#include <iostream>
#include <vector>
#include <stack>


using std::cout;
using std::endl;
using std::vector;
using std::stack;

//Definition for binary tree
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
        public:
                vector<int> postorderTraversal(TreeNode *root) {
                        stack<TreeNode*> st;        
                        vector<int> res;
                        TreeNode* current=root;
                        while(current!=NULL)
                        {
                                TreeNode* left=current->left;
                                TreeNode* right=current->right;
                                if(left == NULL && right == NULL)
                                {
                                        res.push_back(current->val);
                                        if(st.size()==0)
                                                break;
                                        current = st.top();
                                        st.pop();
                                        continue;
                                }else
                                {
                                        current->left=NULL;
                                        current->right=NULL;
                                        st.push(current);
                                }
                                if(right != NULL)
                                        st.push(right);
                                if(left != NULL) 
                                        st.push(left);
                                if(st.size()==0)
                                        break;
                                current = st.top();
                                st.pop();
                        }
                        return res;
                }
};

int main(void){
}

