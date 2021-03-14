import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Paint extends JPanel implements ActionListener, MouseListener, MouseMotionListener {
    protected int lastX, lastY, width, height;
    protected Color currColor = Color.black;
    protected JFrame frame;

    public Paint(JFrame frame, int width, int height) {
        this.frame = frame;
        this.width = width;
        this.height = height;
        enableEvents(AWTEvent.MOUSE_EVENT_MASK | AWTEvent.MOUSE_MOTION_EVENT_MASK);
        addMouseMotionListener(this);
        addMouseListener(this);
    }

    @Override
    public Dimension getPreferredSize() {
        return new Dimension(width, height);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String command = e.getActionCommand();
        if (command.equals("Clear")) {
            repaint();
        } else if (command.equals("Red")) {
            currColor = Color.red;
        } else if (command.equals("Blue")) {
            currColor = Color.blue;
        } else if (command.equals("Green")) {
            currColor = Color.green;
        } else if (command.equals("Black")) {
            currColor = Color.black;
        }
    }

    @Override
    public void mouseClicked(MouseEvent e) {

    }

    @Override
    public void mousePressed(MouseEvent e) {
        if ((e.getModifiersEx() & MouseEvent.BUTTON1) != 0) {
            return;
        }
        lastX = e.getX();
        lastY = e.getY();
    }

    @Override
    public void mouseReleased(MouseEvent e) {

    }

    @Override
    public void mouseEntered(MouseEvent e) {

    }

    @Override
    public void mouseExited(MouseEvent e) {

    }

    @Override
    public void mouseDragged(MouseEvent e) {
        if ((e.getModifiersEx() & MouseEvent.BUTTON1) != 0) {
            return;
        }
        Graphics graphics = getGraphics();
        graphics.setColor(currColor);
        graphics.drawLine(lastX, lastY, e.getX(), e.getY());
        lastX = e.getX();
        lastY = e.getY();
    }

    @Override
    public void mouseMoved(MouseEvent e) {

    }
}
