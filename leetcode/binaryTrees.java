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




    // isBalanced
    //

    public boolean isBalanced(TreeNode root) {
        if (root == null)
            return true;

        int left = getHeight(root.left);
        if (left < 0)
            return false;

        int right = getHeight(root.right);
        if (right < 0)
            return false;

        return Math.abs(left - right) <= 1;
    }

    private int getHeight(TreeNode root) {
        if (root == null)
            return 0;

        int childLeftHeight = getHeight(root.left);
        if (childLeftHeight < 0)
            return -1;
        int childRightHeight = getHeight(root.right);
        if (childRightHeight < 0)
            return -1;

        if (Math.abs(childLeftHeight - childRightHeight) > 1)
            return -1;

        return 1 + Math.max(childLeftHeight, childRightHeight);
    }
}
