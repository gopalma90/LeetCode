/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
 import static java.lang.Math.abs;

class Solution {
    public boolean isBalanced(TreeNode root) {
        if(root == null)
            return true;

        if(abs(heightOf(root.left) - heightOf(root.right))> 1)
                return false;

        if(isBalanced(root.left) && isBalanced(root.right))
        {
            return true;
        }
        else
            return false;
        
       
    }

  int heightOf(TreeNode node) {
    if(node == null)
      return 0;
    return 1 + Math.max(heightOf(node.left), heightOf(node.right));
  }
}