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
class Solution {

    public  Long prev = Long.MIN_VALUE;
    public boolean isValidBST(TreeNode root) {

        if(root == null || (root.left == null && root.right ==null))
            return true;
        
       return inOrderTraversal(root);
       
    }

    public boolean inOrderTraversal(TreeNode root)
    {
        if(root == null)
            return true;
        if( root.left!=null)
             if(!inOrderTraversal(root.left))
                return false;

        if(root.val <= prev) 
        {
            return false;
        }
        else {
            prev = Long.valueOf(root.val);
        }
        if(root.right!=null)
             if(!inOrderTraversal(root.right))
                return false;

        return true;
    }
}