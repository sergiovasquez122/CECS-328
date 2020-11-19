import java.util.ArrayList;
import java.util.Scanner;

public class AVLTree {

    private Node root;


    public void insert(int key){
        root = insert(root, key);
    }

    private int findMin(){
        return findMin(root).key;
    }

    private Node findMin(Node x){
        if(x.left == null) return x;
        return findMin(x.left);
    }

    private int findMax(){
        return findMax(root).key;
    }

    private Node findMax(Node x){
        if(x.right == null) return x;
        return findMax(x.right);
    }

    private Node deleteMin(Node x){
        if(x.left == null) return x.right;
        x.left = deleteMin(x.left);
        return x;
    }

    private Node insert(Node x, int key){
        if(x == null) return new Node(key, 0, null, null);
        if(x.key < key) x.right = insert(x.right, key);
        else if(x.key > key) x.left = insert(x.left, key);
        x.height = Math.max(height(x.left), height(x.right)) + 1;
        return rebalance(x);
    }

    private Node lr(Node x){
        Node y = x.right;
        x.right = y.left;
        y.left = x;
        x.height = Math.max(height(x.left), height(x.right)) + 1;
        y.height = Math.max(height(y.left), height(y.right)) + 1;
        return y;
    }

    private Node rr(Node x){
        Node y = x.left;
        x.left = y.right;
        y.right = x;
        x.height = Math.max(height(x.left), height(x.right)) + 1;
        y.height = Math.max(height(y.left), height(y.right)) + 1;
        return y;
    }

    private Node rebalance(Node x){
        if(height(x.left) - height(x.right) > 1){
            if(height(x.left.right) >= height(x.left.left)){
                x.left = lr(x.left);
            }
            x = rr(x);
        } else if(height(x.right) - height(x.left) > 1){
            if(height(x.right.left) >= height(x.right.right)){
                x.right = rr(x.right);
            }
            x = lr(x);
        }
        return x;
    }

    private void delete(int key){
        root = delete(root, key);
    }

    private Node delete(Node x,int key){
      if(x == null) return null;
      if(x.key < key) x.right = delete(x.right, key);
      else if(x.key > key) x.left = delete(x.left, key);
      else {
          Node t = x;
          x = findMin(t.right);
          x.right = deleteMin(t.right);
          x.left = t.left;
      }
      x.height = Math.max(height(x.left), height(x.right)) + 1;
      return rebalance(x);
    }

    private int height(Node n){
        if(n == null) return -1;
        return n.height;
    }

    public int height(){
        return height(root);
    }

    public Iterable<Integer> keysInOrder(){
        ArrayList<Integer> items = new ArrayList<>();
        traversal(items, root);
        return items;
    }

    private void printTree(){
        BTreePrinter.printNode(root);
    }

    private void inorderTraversal(Node x){
        if(x == null) return;
        inorderTraversal(x.left);
        System.out.print(x.key + " ");
        inorderTraversal(x.right);
    }

    private void inorderTraversal(){
        inorderTraversal(root);
    }

    private void traversal(ArrayList<Integer> items, Node x){
        if(x == null) return;
        traversal(items, x.left);
        items.add(x.key);
        traversal(items, x.right);
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        AVLTree avlTree = new AVLTree();
        do{
            System.out.println("Enter integers and press any other keys with enter to stop: ");
            int x = input.nextInt();
            avlTree.insert(x);
            avlTree.printTree();
        } while(input.hasNextInt());
        for(int x : avlTree.keysInOrder())
            System.out.println(x);
    }
}