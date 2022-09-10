import java.util.ArrayList;
import java.util.List;

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {

    class NodeD {
        public Node node;
        public int depth;
    }

    List<NodeD> list = new ArrayList<>();

    int maxDepth = 0;

    int max(int a, int b) {
        int res = 0;

        if(a > b) res = a;
        else res = b;

        return res;
    }

    void inOrderWalk(Node root, int depth) {

        if(root != null) {
            inOrderWalk(root.left, depth + 1);
            NodeD nodeLoc = new NodeD();
            nodeLoc.node = root;
            nodeLoc.depth = depth;
            maxDepth = max(maxDepth, depth);
            list.add(nodeLoc);
            inOrderWalk(root.right, depth + 1);
        }
    }

    public Node connect(Node root) {

        // Perform walk
        inOrderWalk(root, 0);

        List<List<Node>> listD = new ArrayList<>();

        for(int d = 0; d <= maxDepth; ++d) {
            List<Node> listLoc = new ArrayList<>();
            for(var e : list) {
                if(e.depth == d) {
                    listLoc.add(e.node);
                }
            }

            listD.add(listLoc);
        }

        for(var listElem : listD) {
            int len = listElem.size();
            for(int i = 0; i < len - 1; ++i) {
                listElem.get(i).next = listElem.get(i + 1);
            }
        }


        return root;
    }
}