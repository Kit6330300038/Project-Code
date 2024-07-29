import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class HW8_1 extends JFrame 
{
    private JTextField textField1;
    public HW8_1()
    {
        super( "Homework8.1" );
        Container c = getContentPane();
        c.setLayout( new FlowLayout() );
        Font font1 = new Font("Courier New", Font.BOLD, 20);
        textField1 = new JTextField(25);
        textField1.setFont(font1);
        c.add(textField1);
        textField1.addActionListener( new ActionListener() 
        {
            public void actionPerformed(ActionEvent action)
            { 
                System.out.println(new String(textField1.getText()));
            }
        } );
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(480,360);
        JButton btn1 = new JButton("Delete");
        c.add(btn1);
        setVisible(true);
        btn1.addActionListener(new ActionListener() 
        {
            public void actionPerformed(ActionEvent e) 
            {
                textField1.setText("");
            }
        }
        );}
    public static void main(String[] args) 
    {
        new HW8_1() ;
    }
}