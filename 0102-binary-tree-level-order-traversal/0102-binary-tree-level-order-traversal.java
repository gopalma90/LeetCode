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
    public List<List<Integer>> levelOrder(TreeNode root) {
      Queue<List<TreeNode>> listQueue = new ArrayDeque<>();
    List<List<Integer>> retval = new ArrayList<>();
    if(root == null)
    {
      return Collections.EMPTY_LIST;
    }

    listQueue.add(List.of(root));

    retval.add(List.of(root.val));
    while(!listQueue.isEmpty())
    {
      List<TreeNode> currLevel = listQueue.poll();

      List<TreeNode> newList = new ArrayList<>();
      List<Integer> retList = new ArrayList<>();
      for( int i = 0; i < currLevel.size(); i++)
      {
        if(currLevel.get(i).left != null)
        {
          newList.add(currLevel.get(i).left);
          retList.add(currLevel.get(i).left.val);
        }
        if(currLevel.get(i).right != null)
        {
          newList.add(currLevel.get(i).right);
          retList.add(currLevel.get(i).right.val);
        }
      }
      if(!newList.isEmpty())
      {
        listQueue.add(newList);
        retval.add(retList);
      }

    }
    return retval;


    }
}