import java.awt.*;
import java.awt.event.*;
import java.awt.geom.Point2D;
import java.awt.event.ActionEvent;
import  java.awt.event.ActionListener;
import javax.swing.*;
import java.awt.geom.Path2D;
import java.util.ArrayList;
public class MainFraim extends JFrame{
    MainFraim()
    {
        super();
        setSize(300,300);
        setTitle("Test Frame");
        setLocaion((int)(Toolkit.getDefaultToolkit().getScreenSize().width/2-150),
                (int)(Toolkit.getDefaultToolkit().getScreenSize().height/2-150));


        setVisible(true);
    }
    private ArrayList list=new ArrayList();
    public void addPoint(poin)

}
class TestPanel extends JPanel
{

}
class MyMouseClick extends MouseAdapter
{
    MainFraim frame;
    MyMouseClick(MainFraim frame)
    {
        super();
        this.frame=frame;
    }
    public void mouseClicked(MouseEvent e)
    {
        super.mouseClicked(e);
        frame.addPoint(new Point2D((float)e.getX(),(float)e.getY()));
        frame.repaint();
    }

}