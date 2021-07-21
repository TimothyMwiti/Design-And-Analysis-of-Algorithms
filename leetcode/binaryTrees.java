class Solution {
    /**
     * https://leetcode.com/problems/symmetric-tree/
     */
    public boolean isSymmetric(TreeNode root) {
        if (root == null || (root.left == null && root.right == null))
            return true;
        else if ((root.left == null && root.right != null) || (root.left != null && root.right == null))
            return false;

        TreeNode rotatedRightTree = rotate(root.right);
        return compareTreesAreEqual(root.left, rotatedRightTree);
    }



    private TreeNode rotate(TreeNode root) {
        if (root == null)
            return null;

        TreeNode tempLeft = root.left;
        root.left = rotate(root.right);
        root.right = rotate(tempLeft);

        return root;
    }


    private boolean compareTreesAreEqual(TreeNode t, TreeNode s) {
        if (t == null)
            return s == null;
        else if (s == null)
            return false;

        return t.val == s.val && compareTreesAreEqual(t.left, s.left) && compareTreesAreEqual(t.right, s.right);
    }
}
