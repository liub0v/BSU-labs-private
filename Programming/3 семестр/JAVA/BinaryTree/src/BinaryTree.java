import java.util.ArrayList;

public class BinaryTree<T extends Comparable<T>> {
    private Node<T> root;
    private ArrayList<T> listTraverse = new ArrayList<>();

    public BinaryTree() {
        root = null;
    }

    public Node<T> getRoot() {
        return root;
    }

    public void setRoot(Node<T> root) {
        this.root = root;
    }

    public ArrayList<T> getListTraverse() {
        return listTraverse;
    }

    public void clearList(ArrayList<T> list) {
        list.clear();
    }

    public Node find(T key) {
        Node<T> current = root;
        while (key.compareTo(current.iData) != 0) {
            if (key.compareTo(current.iData) < 0)
                current = current.leftChild;
            else
                current = current.rightChild;
            if (current == null)
                return null;
        }
        return current;
    }

    public void insert(T id) {
        Node<T> newNode = new Node<>(id);
        if (root == null)
            root = newNode;
        else {
            Node<T> current = root;
            Node<T> parent;
            while (true) {
                parent = current;
                if (id.compareTo(current.iData) < 0) {
                    current = current.leftChild;
                    if (current == null) {
                        parent.leftChild = newNode;
                        return;
                    }
                } else {
                    current = current.rightChild;
                    if (current == null) {
                        parent.rightChild = newNode;
                        return;
                    }
                }
            }
        }
    }

    public boolean delete(T key) {
        Node<T> current = root;
        Node<T> parent = root;
        boolean isLeftChild = true;

        while (key.compareTo(current.iData) != 0) {
            parent = current;
            if (key.compareTo(current.iData) < 0) {
                isLeftChild = true;
                current = current.leftChild;
            } else {
                isLeftChild = false;
                current = current.rightChild;
            }
            if (current == null)
                return false;
        }
        if (current.leftChild == null && current.rightChild == null) {
            if (current == root)
                root = null;
            else if (isLeftChild)
                parent.leftChild = null;
            else
                parent.rightChild = null;
        } else if (current.rightChild == null)
            if (current == root)
                root = current.leftChild;
            else if (isLeftChild)
                parent.leftChild = current.leftChild;
            else
                parent.rightChild = current.leftChild;
        else if (current.leftChild == null)
            if (current == root)
                root = current.rightChild;
            else if (isLeftChild)
                parent.leftChild = current.rightChild;
            else
                parent.rightChild = current.rightChild;
        else {
            Node successor = getSuccessor(current);
            if (current == root)
                root = successor;
            else if (isLeftChild)
                parent.leftChild = successor;
            else
                parent.rightChild = successor;
            successor.leftChild = current.leftChild;
        }
        return true;
    }

    private Node<T> getSuccessor(Node<T> delNode) {
        Node<T> successorParent = delNode;
        Node<T> successor = delNode;
        Node<T> current = delNode.rightChild;
        while (current != null) {
            successorParent = successor;
            successor = current;
            current = current.leftChild;
        }
        if (successor != delNode.rightChild) {
            successorParent.leftChild = successor.rightChild;
            successor.rightChild = delNode.rightChild;
        }
        return successor;
    }

    public void traverse(int traverseType) {
        switch (traverseType) {
            case 1:
                preOrder(root);
                break;
            case 2:
                inOrder(root);
                break;
            case 3:
                postOrder(root);
                break;
        }
    }

    private void preOrder(Node<T> localRoot) {
        if (localRoot != null) {
            listTraverse.add(localRoot.iData);
            preOrder(localRoot.leftChild);
            preOrder(localRoot.rightChild);
        }
    }

    private void inOrder(Node<T> localRoot) {
        if (localRoot != null) {
            inOrder(localRoot.leftChild);
            listTraverse.add(localRoot.iData);
            inOrder(localRoot.rightChild);
        }
    }

    private void postOrder(Node<T> localRoot) {
        if (localRoot != null) {
            postOrder(localRoot.leftChild);
            postOrder(localRoot.rightChild);
            listTraverse.add(localRoot.iData);
        }
    }


}