import java.util.ArrayList;
import java.util.List;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}


class Solution {

    List<TreeNode> listSubs = new ArrayList<>();

    void getNodes(TreeNode root, int key) {

        TreeNode subRoot = root;

        if(root != null) {
            int cut = root.val;

            if(cut == key) {
                listSubs.add(subRoot);
            }

            getNodes(root.left, key);
            getNodes(root.right, key);
        }
    }

    boolean subRootSame(TreeNode root, TreeNode subRoot) {

        boolean res = true;

        if(subRoot != null && root != null) {
            if(subRoot.val != root.val) {
                return false;
            }

            res = res && subRootSame(root.right, subRoot.right);
            res = res && subRootSame(root.left, subRoot.left);
        }
        if(subRoot == null && root != null) {
            return false;
        }
        if(subRoot != null && root == null) {
            return false;
        }

        return res;
    }

    public boolean isSubtree(TreeNode root, TreeNode subRoot) {

        getNodes(root, subRoot.val);

        boolean res = false;

        if(listSubs.size() == 0) {
            return false;
        }

        for(var r : listSubs) {
            res = res || subRootSame(r, subRoot);
        }

        return res;
    }
}