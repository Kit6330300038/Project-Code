import java.awt.*;
import javax.swing.*;

public class HW9_1 extends JPanel
{
    public void paintComponent( Graphics g)
    {
        super.paintComponent(g);
 
        g.setColor(Color.YELLOW);        
        g.fillOval(10, 10, 200, 200);
        g.setColor(Color.BLACK);
        g.fillOval(55, 65, 30, 30);
        g.fillOval(135, 65, 30, 30);
        g.fillOval(50, 110, 120 , 60);
        g.setColor(Color.YELLOW);
        g.fillRect(50, 110, 120, 30);
        g.fillOval(50, 120, 120, 40);
        g.setColor(Color.cyan);
        g.fillOval(-30,-10, 300,70);
        g.setColor(Color.DARK_GRAY);
        g.fillRect(40, 185, 140, 20);
        g.fillOval(40, 185, 140, 40);
        g.setColor(Color.YELLOW);
        g.fillOval(40, 172, 140, 20);
    }
    public static void main(String[] args) 
    {
        HW9_1 panel = new HW9_1(); 
        JFrame frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(panel);
        frame.setSize( 230, 300 ); 
        frame.setVisible(true);
    }
}