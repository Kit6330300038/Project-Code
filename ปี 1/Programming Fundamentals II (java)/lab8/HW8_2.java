import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class HW8_2 extends JFrame 
{
    private JTextField textField1,textField2;
    private JCheckBox check1, check2;
    private boolean s1=false,s2=false;
    private String a;
    public HW8_2()
    {
        super( "Homework8.2" );
        Container c = getContentPane();
        c.setLayout( new FlowLayout() );
        Font font1 = new Font("Courier New", Font.BOLD, 20);
        textField1 = new JTextField(25);
        textField1.setFont(font1);
        c.add(textField1);        
        JButton btn1 = new JButton("Clear");
        c.add(btn1);
        textField2 = new JTextField(25);
        textField2.setFont(font1);
        c.add(textField2);
        setSize(460,360);
        JButton btn2 = new JButton("Submit");
        c.add(btn2);
        check1 = new JCheckBox("Swap");c.add(check1);
        check2 = new JCheckBox("Modify on Swap");c.add(check2);
        JLabel label1 = new JLabel("",SwingConstants.CENTER);
        label1.setPreferredSize(new Dimension(480, 40));
        c.add(label1);
        setVisible(true);
        check1.addItemListener( new ItemListener() 
        {
            public void itemStateChanged(ItemEvent e)
            { 
                if (e.getStateChange() == e.SELECTED)
                {
                    s1=true;
                }
            else 
                {
                    s1=false;
                }  
            }
        } );
        check2.addItemListener( new ItemListener() 
        {
            public void itemStateChanged(ItemEvent e)
            { 
                if (e.getStateChange() == e.SELECTED)
                {
                    s2=true;
                }
            else 
                {
                    s2=false;
                }  
            }
        } );
        btn1.addActionListener(new ActionListener() 
        {
            public void actionPerformed(ActionEvent e) 
            {
                textField1.setText("");
                textField2.setText("");
                label1.setText("");
            }
        }
        );
        btn2.addActionListener(new ActionListener() 
        {
            public void actionPerformed(ActionEvent e) 
            {
                if (s1==true && s2 == true) 
                {
                    label1.setText(textField2.getText()+textField1.getText());
                    a = textField1.getText();
                    textField1.setText(textField2.getText());
                    textField2.setText(a);
                }
                else if (s1==true && s2 == false) 
                {
                    label1.setText(textField2.getText()+textField1.getText());
                }
                else
                {
                    label1.setText(textField1.getText()+textField2.getText());
                }
            }
        } 
        );
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String[] args) 
    {
        new HW8_2() ;
    }
}