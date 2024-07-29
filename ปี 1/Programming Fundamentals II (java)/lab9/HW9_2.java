import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;
public class HW9_2 extends JPanel
{
    private final ArrayList<Point> points = new ArrayList<>();
    public HW9_2()
    {
        addMouseMotionListener(
        new MouseMotionAdapter() 
        {
            public void mouseDragged(MouseEvent event)
            {
                points.add(event.getPoint());
                repaint();
            }
        }
        );
    }
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        for(Point point : points)
        g.fillRoundRect(point.x, point.y, 4, 4,4,4);
    }
    public static void main(String[] args) 
    {
        HW9_2 panel = new HW9_2(); 
        JLabel label =new JLabel("click the mouse to makeline",SwingConstants.CENTER);
        label.setFont(new Font("Arial", Font.PLAIN, 20));
        label.setVisible(true);
        JFrame frame = new JFrame();
        frame.add(label,BorderLayout.SOUTH);
        frame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
        frame.add(panel);
        frame.setSize( 600,480 ); 
        frame.setVisible( true );
    }
}