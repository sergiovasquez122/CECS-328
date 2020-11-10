public class Node{

    Node left, right;
    int key;
    int height;

    Node(int key, int height, Node left, Node right){
        this.key = key;
        this.height = height;
        this.left = left;
        this.right = right;
    }
}