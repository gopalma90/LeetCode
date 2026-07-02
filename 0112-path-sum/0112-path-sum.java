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

    private Integer currSum = 0;

    public boolean hasPathSum(TreeNode root, int targetSum) {
              
    if(root == null)
      return false;

    return preOrderTraversal( root,  targetSum);


    }


  public  boolean preOrderTraversal(TreeNode root, int targetSum)
  {
       if(root == null)
        return false;
    currSum += root.val;

    if(root.left!= null)
      {
        if (preOrderTraversal(root.left, targetSum))
        {
          return true;
        }
      }

      //System.out.println(" curr node val = " + root.val);

      if(root.left == null && root.right == null)
      {
        if(currSum == targetSum)
          return true;
        else
        {
          currSum -= root.val;
          return false;
        }
      }
       if(root.right!= null)
    {
      if(preOrderTraversal(root.right, targetSum))
        return true;
      else
      {
        currSum -= root.val;
        return false;
      }
    }
    else {
      currSum -= root.val;
      return false;
    }
  }


}