import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import javax.swing.border.EmptyBorder;

public class TreeGUI extends JFrame {

    private JPanel contentPane;
    public BinaryTree tree;
    public BinaryTreeView view;

    public TreeGUI(BinaryTree tree) {
        setTitle("Binary tree");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        setBounds(550, 200, 850, 600);
        contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        contentPane.setLayout(new BorderLayout(0, 0));
        view = new BinaryTreeView(tree);

        contentPane.add(view);
        setContentPane(contentPane);
        this.tree = tree;
        setVisible(true);
    }
}

class BinaryTreeView<T> extends JPanel {
    private BinaryTree tree; // A binary tree to be displayed
    private JTextField jtfKey = new JTextField(5);
    private PaintTree paintTree = new PaintTree();
    private JButton jbtInsert = new JButton("Insert");
    private JButton jbtDelete = new JButton("Delete");
    private JButton jbtFind = new JButton("Find");
    private JButton jbtPreOrder = new JButton("PreOrder");
    private JButton jbtInOrder = new JButton("InOrder");
    private JButton jbtPostOrder = new JButton("PostOrder");
    private JButton jbtSum=new JButton("Sum");
    private JTextArea jTextArea=new JTextArea();

    /** Construct a view for a binary tree */
    public BinaryTreeView(BinaryTree tree) {
        this.tree = tree; // Set a binary tree to be displayed
        setUI();
    }

    /** Initialize UI for binary tree
     * @param <T>*/
    private <T> void setUI() {
        Node<T> treeRoot = tree.getRoot();
        this.setLayout(new BorderLayout());
        add(paintTree, BorderLayout.CENTER);
        JPanel panel = new JPanel();
        panel.add(new JLabel("Enter a top of the graph "));
        panel.add(jtfKey);
        panel.add(jbtInsert);
        panel.add(jbtDelete);
        panel.add(jbtFind);
        panel.add(jbtPreOrder);
        panel.add(jbtInOrder);
        panel.add(jbtPostOrder);
        panel.add(jbtSum);
        panel.add(jTextArea);
        add(panel, BorderLayout.SOUTH);

        jbtInsert.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {

                String data = jtfKey.getText();
                if (Character.isLetter(data.charAt(0))) {
                    String name = data.substring(0, data.indexOf(','));
                    int age = Integer.parseInt(data.substring(data.indexOf(',') + 1));
                    Person person = new Person(name, age);
                    if (tree.find(person) != null) { // key is not in the tree
                        JOptionPane.showMessageDialog(null,
                                person.getName() + " is in the tree");
                    }
                    else {
                        tree.insert(person); // Insert a key
                        paintTree.repaint(); // Redisplay the tree
                    }
                }
                else {
                    int key = Integer.parseInt(jtfKey.getText());
                    Number num = new Number(key);
                    if (tree.find(num) != null) { // key is not in the tree
                        JOptionPane.showMessageDialog(null,
                                num.getValue() + " is in the tree");
                    }
                    else {
                        tree.insert(num); // Insert a key
                        paintTree.repaint(); // Redisplay the tree
                    }
                }
            }
        });

        jbtDelete.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {

                String data = jtfKey.getText();
                if (Character.isLetter(data.charAt(0))) {
                    String name = data.substring(0, data.indexOf(','));
                    int age = Integer.parseInt(data.substring(data.indexOf(',') + 1));
                    Person person = new Person(name, age);
                    if (tree.find(person) == null) { // key is not in the tree
                        JOptionPane.showMessageDialog(null,
                                person.getName() + " isn't in the tree");
                    }
                    else {
                        tree.delete(person); // Delete a key
                        paintTree.repaint(); // Redisplay the tree
                    }
                }
                else {
                    int key = Integer.parseInt(jtfKey.getText());
                    Number num = new Number(key);
                    if (tree.find(num) == null) { // key is not in the tree
                        JOptionPane.showMessageDialog(null,
                                num.getValue() + " isn't in the tree");
                    }
                    else {
                        tree.delete(num); // Delete a node
                        paintTree.repaint(); // Redisplay the tree
                    }
                }
            }
        });

        jbtFind.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {

                String data = jtfKey.getText();
                if (Character.isLetter(data.charAt(0))) {
                    String name = data.substring(0, data.indexOf(','));
                    int age = Integer.parseInt(data.substring(data.indexOf(',') + 1));
                    Person person = new Person(name, age);
                    if (tree.find(person) == null) { // key is not in the tree
                        JOptionPane.showMessageDialog(null,
                                person.getName() + " isn't in the tree");
                    }
                    else {
                        tree.find(person); // Find a key
                        JOptionPane.showMessageDialog(null,
                                person.getName() + " is in the tree");
                    }
                }
                else {
                    int key = Integer.parseInt(jtfKey.getText());
                    Number num = new Number(key);
                    if (tree.find(num) == null) { // key is not in the tree
                        JOptionPane.showMessageDialog(null,
                                key + " isn't in the tree");
                    }
                    else {
                        tree.find(num); // Find a key
                        JOptionPane.showMessageDialog(null,
                                num.getValue() + " is in the tree");
                    }
                }
            }
        });

        jbtPreOrder.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tree.traverse(1);
                JOptionPane.showMessageDialog(null,
                        tree.getListTraverse());
                tree.clearList(tree.getListTraverse());
            }
        });

        jbtInOrder.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tree.traverse(2);
                JOptionPane.showMessageDialog(null,
                        tree.getListTraverse());
                tree.clearList(tree.getListTraverse());
            }
        });

        jbtPostOrder.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tree.traverse(3);
                JOptionPane.showMessageDialog(null,
                        tree.getListTraverse());
                tree.clearList(tree.getListTraverse());
            }
        });

        jbtSum.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                tree.traverse(2);
                Integer Sum=0;
                for (int i=0;i<tree.getListTraverse().size();i++) {
                    Sum += Integer.parseInt(tree.getListTraverse().get(i).toString());
                }
                jTextArea.setText(Sum.toString());
            }
        });

    }

    // Inner class PaintTree for displaying a tree on a panel
    class PaintTree extends JPanel {
        private int radius = 20; // Tree node radius
        private int vGap = 50; // Gap between two levels in a tree

        protected void paintComponent(Graphics g) {
            super.paintComponent(g);

            if (tree.getRoot() != null) {
                // Display tree recursively
                displayTree(g, tree.getRoot(), getWidth() / 2, 30,
                        getWidth() / 4);
            }
        }

        /** Display a subtree rooted at position (x, y) */
        private void displayTree(Graphics g, Node root,
                                 int x, int y, int hGap) {
            // Display the root
            g.drawOval(x - radius, y - radius, 2 * radius, 2 * radius);
            g.drawString(root.iData + "", x - 6, y + 4);

            if (root.leftChild != null) {
                // Draw a line to the left node
                connectLeftChild(g, x - hGap, y + vGap, x, y);
                // Draw the left subtree recursively
                displayTree(g, root.leftChild, x - hGap, y + vGap, hGap / 2);
            }

            if (root.rightChild != null) {
                // Draw a line to the right node
                connectRightChild(g, x + hGap, y + vGap, x, y);
                // Draw the right subtree recursively
                displayTree(g, root.rightChild, x + hGap, y + vGap, hGap / 2);
            }
        }

        /** Connect a parent at (x2, y2) with
         * its left child at (x1, y1) */
        private void connectLeftChild(Graphics g,
                                      int x1, int y1, int x2, int y2) {
            double d = Math.sqrt(vGap * vGap + (x2 - x1) * (x2 - x1));
            int x11 = (int)(x1 + radius * (x2 - x1) / d);
            int y11 = (int)(y1 - radius * vGap / d);
            int x21 = (int)(x2 - radius * (x2 - x1) / d);
            int y21 = (int)(y2 + radius * vGap / d);
            g.drawLine(x11, y11, x21, y21);
        }

        /** Connect a parent at (x2, y2) with
         * its right child at (x1, y1) */
        private void connectRightChild(Graphics g,
                                       int x1, int y1, int x2, int y2) {
            double d = Math.sqrt(vGap * vGap + (x2 - x1) * (x2 - x1));
            int x11 = (int)(x1 - radius * (x1 - x2) / d);
            int y11 = (int)(y1 - radius * vGap / d);
            int x21 = (int)(x2 + radius * (x1 - x2) / d);
            int y21 = (int)(y2 + radius * vGap / d);
            g.drawLine(x11, y11, x21, y21);
        }
    }
}