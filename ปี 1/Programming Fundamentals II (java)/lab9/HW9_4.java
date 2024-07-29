import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class HW9_4 extends JFrame
{
public HW9_4() 
{
super("Calculator");
Container c = getContentPane();
c.setBackground(Color.gray);
JPanel pc = new JPanel();
JTextField show = new JTextField("");
show.setPreferredSize(new  Dimension(200,30));
show.setBackground(Color.WHITE);
pc.add(show);

JPanel p1 = new JPanel();
p1.setLayout( new BoxLayout(p1, BoxLayout.Y_AXIS));
JButton button1 = new JButton("Cls");
JButton button2 = new JButton("7");
JButton button3 = new JButton("4");
JButton button4 = new JButton("1");
JButton button5 = new JButton("0");  
p1.add(button1);p1.add(button2);
p1.add(button3);p1.add(button4);
p1.add(button5);

JPanel p2 = new JPanel();
p2.setLayout( new BoxLayout(p2,BoxLayout.Y_AXIS));
JButton button6 = new JButton("Close");
JButton button7 = new JButton("/");
JButton button8 = new JButton("*");
JButton button9 = new JButton("-");
JButton button10 = new JButton("+");  
p2.add(button6);p2.add(button7);
p2.add(button8);p2.add(button9);
p2.add(button10);

JPanel p3 = new JPanel();
p3.setLayout( new GridLayout(0,2));
JButton button11 = new JButton("Bck");
JLabel blabel = new JLabel("   ");
JButton button13 = new JButton("8");
JButton button14 = new JButton("9");
JButton button15 = new JButton("5");  
JButton button16 = new JButton("6");
JButton button17 = new JButton("2");
JButton button18 = new JButton("3");
JButton button19 = new JButton(".");
JButton button20 = new JButton("=");  
p3.add(button11);p3.add(blabel);
p3.add(button13);p3.add(button14);
p3.add(button15);p3.add(button16);
p3.add(button17);p3.add(button18);
p3.add(button19);p3.add(button20);

c.add(p1, BorderLayout.WEST);
c.add(p2, BorderLayout.EAST);
c.add(pc, BorderLayout.NORTH);
c.add(p3, BorderLayout.CENTER);
button1.addActionListener(new ActionListener(){
    public void actionPerformed(ActionEvent event) {
        show.setText("   ");;
    }
});
button2.addActionListener(new ActionListener(){
    public void actionPerformed(ActionEvent event) {
        show.setText(button2.getText());;
    }
});
button3.addActionListener(new ActionListener(){
    public void actionPerformed(ActionEvent event) {
        show.setText(button3.getText());;
    }
});
button4.addActionListener(new ActionListener(){
    public void actionPerformed(ActionEvent event) {
        show.setText(button4.getText());;
    }
});
button5.addActionListener(new ActionListener(){
    public void actionPerformed(ActionEvent event) {
        show.setText(button5.getText());;
    }
});
button6.addActionListener(new ActionListener(){
    public void actionPerformed(ActionEvent event) {
        show.setText(button6.getText());;
    }
});
button7.addActionListener(new ActionListener(){
    public void actionPerformed(ActionEvent event) {
        show.setText(button7.getText());;
    }
});
button8.addActionListener(new ActionListener(){
    public void actionPerformed(ActionEvent event) {
        show.setText(button8.getText());;
    }
});
button9.addActionListener(new ActionListener(){
    public void actionPerformed(ActionEvent event) {
        show.setText(button9.getText());;
    }
});
button10.addActionListener(new ActionListener(){
    public void actionPerformed(ActionEvent event) {
        show.setText(button10.getText());;
    }
});button11.addActionListener(new ActionListener(){
    public void actionPerformed(ActionEvent event) {
        show.setText(button11.getText());;
    }
});
button13.addActionListener(new ActionListener(){
    public void actionPerformed(ActionEvent event) {
        show.setText(button13.getText());;
    }
});button14.addActionListener(new ActionListener(){
    public void actionPerformed(ActionEvent event) {
        show.setText(button14.getText());;
    }
});button15.addActionListener(new ActionListener(){
    public void actionPerformed(ActionEvent event) {
        show.setText(button15.getText());;
    }
});button16.addActionListener(new ActionListener(){
    public void actionPerformed(ActionEvent event) {
        show.setText(button16.getText());;
    }
});button20.addActionListener(new ActionListener(){
    public void actionPerformed(ActionEvent event) {
        show.setText(button20.getText());;
    }
});button17.addActionListener(new ActionListener(){
    public void actionPerformed(ActionEvent event) {
        show.setText(button17.getText());;
    }
});button18.addActionListener(new ActionListener(){
    public void actionPerformed(ActionEvent event) {
        show.setText(button18.getText());;
    }
});button19.addActionListener(new ActionListener(){
    public void actionPerformed(ActionEvent event) {
        show.setText(button19.getText());;
    }
});

setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
pack();
setResizable(false); // disable window resizing
setLocationRelativeTo(null); 
setVisible(true);
}
public static void main(String[] args) 
{
new HW9_4() ;
}
}