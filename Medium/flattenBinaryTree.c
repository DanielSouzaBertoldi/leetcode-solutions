/******************************************************************************

Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

- Results (as of 2020-07-21):
Runtime: 12 ms (beats 5.83% of C submissions)
Memory Usage: 6.3 MB (beats 95.00% of C submissions)

*******************************************************************************/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void flatten(struct TreeNode* root) {
  if(!root || !root->left && !root->right)
    return NULL;
  
  if(root->left) {
    flatten(root->left);
    
    struct TreeNode *auxRight = root->right;
    root->right = root->left;
    root->left = NULL;
    
    struct TreeNode *auxLast = root->right;
    
    while(auxLast->right)
      auxLast = auxLast->right;
    
    auxLast->right = auxRight;
  }
  flatten(root->right);
}
