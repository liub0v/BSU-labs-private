import javax.swing.*;
import java.awt.*;

public class Test extends JFrame {
    Test(String title) {
        super(title);
        Container container = getContentPane();
        Paint paint = new Paint(this, 600, 600);
        setPreferredSize(new Dimension(600, 500));

        JPanel buttonPanel = new JPanel();

        JButton buttonRed = new JButton("Red");
        container.add(buttonRed);
        buttonPanel.add(buttonRed);
        buttonRed.addActionListener(paint);

        JButton buttonBlue = new JButton("Blue");
        container.add(buttonBlue);
        buttonPanel.add(buttonBlue);
        buttonBlue.addActionListener(paint);

        JButton buttonGreen = new JButton("Green");
        container.add(buttonGreen);
        buttonPanel.add(buttonGreen);
        buttonGreen.addActionListener(paint);

        JButton buttonBlack = new JButton("Black");
        container.add(buttonBlack);
        buttonPanel.add(buttonBlack);
        buttonBlack.addActionListener(paint);

        JButton buttonClear = new JButton("Clear");
        container.add(buttonClear);
        buttonPanel.add(buttonClear);
        buttonClear.addActionListener(paint);

        container.add(buttonPanel, BorderLayout.SOUTH);
        container.add(paint, BorderLayout.CENTER);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }

    public static void main(String[] args) {
        new Test("Paint");
    }
}
