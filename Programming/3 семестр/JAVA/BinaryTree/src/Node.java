public class Node<T> {
    public T iData;
    public Node<T> leftChild;
    public Node<T> rightChild;

    Node(T iData) {
        this.iData = iData;
        leftChild = null;
        rightChild = null;
    }
}