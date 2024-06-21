import java.util.*;

public class A_Temperature {
    
    // Node class definition
    static class Node {
        int data;
        Node left, right;
        
        Node(int data) {
            this.data = data;
            left = right = null;
        }
    }
    
    // Function to create a binary tree from an array
    public static Node createTree(int a[], int i) {
        if (i >= a.length || a[i] == -1) return null;
        Node newNode = new Node(a[i]);
        newNode.left = createTree(a, 2*i+1);
        newNode.right = createTree(a, 2*i+2);
        return newNode;
    }
    
    // Function to calculate the total burning time
    public static long findTemperature(Node root, int[] initialVertexValues) {
        if (root == null) return 0;
        
        // Using BFS to calculate time required for burning
        Queue<Node> queue = new LinkedList<>();
        Map<Node, Integer> burningTime = new HashMap<>();
        
        // Initialize burning time for initial nodes
        for (int value : initialVertexValues) {
            findStartingNode(root, value, queue, burningTime);
        }
        
        long totalTime = 0;
        while (!queue.isEmpty()) {
            Node curr = queue.poll();
            int time = burningTime.get(curr);
            totalTime += (long) curr.data * time;
            
            if (curr.left != null && !burningTime.containsKey(curr.left)) {
                queue.add(curr.left);
                burningTime.put(curr.left, time + 1);
            }
            
            if (curr.right != null && !burningTime.containsKey(curr.right)) {
                queue.add(curr.right);
                burningTime.put(curr.right, time + 1);
            }
        }
        
        return totalTime;
    }
    
    // Helper function to find the starting node for BFS
    private static void findStartingNode(Node root, int value, Queue<Node> queue, Map<Node, Integer> burningTime) {
        if (root == null) return;
        
        if (root.data == value) {
            queue.add(root);
            burningTime.put(root, 0);
            return;
        }
        
        findStartingNode(root.left, value, queue, burningTime);
        findStartingNode(root.right, value, queue, burningTime);
    }
    
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt(); // size of the array a[]
        int k = sc.nextInt(); // size of the array b[]
        
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        
        int[] b = new int[k];
        for (int i = 0; i < k; i++) {
            b[i] = sc.nextInt();
        }
        
        sc.close();
        
        Node root = createTree(a, 0);
        long result = findTemperature(root, b);
        
        System.out.println(result);
    }
}
