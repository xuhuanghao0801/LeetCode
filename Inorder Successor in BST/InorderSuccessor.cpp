class Solution {
public:
 	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
 		if((!root) || (!p)) {
 			return NULL;
 		}
 		TreeNode* result = NULL;
 		if(p -> right) {
 			result = p -> right;
 			while(result -> left) {
 				reuslt = result -> left;
 			}
 			return result;
 		}
 		TreeNode* cur = root;
 		while((cur) && ((cur -> val) != (p -> val))) {
 			if((cur -> val) > (p -> val)) {
 				result = cur;
 				cur = cur -> left;
 			} else {
 				cur = cur -> right;
 			}
 		}
 		return result;
 	}
};