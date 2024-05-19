// DFS - LIFO Stack
// https://leetcode.com/discuss/study-guide/1072548/a-beginners-guid-to-bfs-and-dfs

public void DFSInOrder(TreeNode root) {
    Stack<TreeNode> stack = new Stack<>();
    TreeNode current = root;
    stack.push(root);
    while(!stack.isEmpty()) {
        while(current.left != null) {
            current = current.left;                
            stack.push(current);                
        }
        current = stack.pop();
        System.out.print(current.value);
        if(current.right != null) {
            current = current.right;                
            stack.push(current);
        }
    }
}