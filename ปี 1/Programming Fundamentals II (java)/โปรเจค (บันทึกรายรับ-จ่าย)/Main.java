// กฤษณพงษ์ เพ็งบุญ 6330300038
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.util.ArrayList;
public class Main extends JFrame
{
    private JTextField textField1,textField2,textField3;
    private ArrayList<Topic> topic = new ArrayList<Topic>();
    public static void main(String[] args) 
    {
        new Main();
    }
    public Main() //หน้าแรก
    {
        Container c = getContentPane();
        c.setLayout(new FlowLayout());
        JButton btn1 = new JButton("New Topic!!!");
        c.add(btn1);
        setSize(480,360);
        setVisible(true);
        setResizable(false);
        btn1.addActionListener(new ActionListener() //กดสร้างหัวข้อใหม่
        {
            public void actionPerformed(ActionEvent e) 
            {
                c.removeAll();newtopicpage(c);
            }
        }
        );
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);    
    }
    public void newtopicpage(Container c) //หน้าสร้างหัวข้อใหม่
    {
        JPanel panel = new JPanel();
        panel.setPreferredSize(new Dimension(400, 360));
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
        c.add(panel);
        JLabel topicnah = new JLabel("Topic Name");topicnah.setAlignmentX(Component.CENTER_ALIGNMENT);
        panel.add(topicnah);
        textField1 = new JTextField(25);textField1.setMaximumSize(textField1.getPreferredSize());
        textField1.setAlignmentX(Component.CENTER_ALIGNMENT);
        panel.add(textField1);
        JButton btn3 = new JButton("OK!!!");btn3.setAlignmentX(Component.CENTER_ALIGNMENT);
        panel.add(btn3);
        JButton btn = new JButton("back");btn.setAlignmentX(Component.CENTER_ALIGNMENT);
        panel.add(btn);
        btn.addActionListener(new ActionListener()  //กดกลับ
        {
            public void actionPerformed(ActionEvent e) 
            {
                c.removeAll();mainpage(c);
            }
        }
        );
        setVisible(true);
        btn3.addActionListener(new ActionListener() //กดตกลง
        {
            public void actionPerformed(ActionEvent e) 
            {
                topic.add(new Topic(textField1.getText()));
                c.removeAll();mainpage(c);
            }
        }
        );
    }
    public void mainpage(Container c)  //หน้าหลัก
    { 
        JPanel panel = new JPanel();
        panel.setPreferredSize(new Dimension(400, 360));
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
        JButton btn1 = new JButton("New Topic!!!");btn1.setAlignmentX(Component.CENTER_ALIGNMENT);
        panel.add(btn1);
        ArrayList<JButton> alltop = new ArrayList<JButton>();
        for (int i = 0; i < topic.size(); i++)    //สร้างปุ่มตามหัวข้อที่มี
        {
            // ข้อ 3 ตวจสอบชื่อว่าเป็น none หรือเปล่า ถ้าเป็นข้ามหัวข้อนั้น(ไม่ต้องทำอะไร)
            JButton btn = new JButton(topic.get(i).gettopic());btn.setAlignmentX(Component.CENTER_ALIGNMENT);
            alltop.add(btn);
            panel.add(alltop.get(i));
            alltop.get(i).addActionListener(new ActionListener()  //กดปุ่มตามื่อหัวข้อ
            {
                public void actionPerformed(ActionEvent e) 
                {
                    c.removeAll();;
                    addinfo(topic.get(alltop.indexOf(e.getSource())),c);
                }
            } 
            );
        }
        JButton btn2 = new JButton("conclude!!!");btn2.setAlignmentX(Component.CENTER_ALIGNMENT);
        panel.add(btn2);
        c.add(panel);
        setVisible(true);
        btn1.addActionListener(new ActionListener() //ปุ่มสร้างหัวข้อใหม่
        {
            public void actionPerformed(ActionEvent e) 
            {
                c.removeAll();newtopicpage(c);
            }
        }
        );
        btn2.addActionListener(new ActionListener()  //ปุ่มสรุปผล
        {
            public void actionPerformed(ActionEvent e) 
            {
                c.removeAll();
                conclude(c);
            }
        } 
        );
    }
    public void addinfo(Topic q,Container c)    //หน้าเพิ่มข้อมูลรายรับ
    {
        JPanel panel = new JPanel();panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
        c.add(panel);
        JLabel amount = new JLabel("Amount");
        panel.add(amount);
        textField1 = new JTextField(25);
        panel.add(textField1);
        JLabel note = new JLabel("Note");
        panel.add(note);
        textField2 = new JTextField(25);
        panel.add(textField2);        
        JLabel cardnum = new JLabel("Card number");
        panel.add(cardnum);
        textField3 = new JTextField(25);
        panel.add(textField3);
        JButton btn3 = new JButton("Credit");
        panel.add(btn3);
        JButton btn4 = new JButton("Realmoney");
        panel.add(btn4);
        JButton btn5 = new JButton("Orther");
        panel.add(btn5); 
        JLabel blank = new JLabel("      ");
        panel.add(blank);
        JButton back = new JButton("back");
        panel.add(back);
        // ข้อ 2 เพิ่มคำสั่งสำหรับสร้างปุ่มตรงนี้ + addActionlistener ในการกดปุ่มแล้วลบหัวข้อนั้น
        // ข้อ 3 เปลี่ยนจากลบหัวข้อเเป็นเปลี่ยนชื่อหัวข้อเป็น none (ไม่ต้องทำอะไร)
        back.addActionListener(new ActionListener()  //กลับ
        {
            public void actionPerformed(ActionEvent e) 
            {
                c.removeAll();mainpage(c);
            }
        }
        );
        setVisible(true);
        btn3.addActionListener(new ActionListener()  //บัตร
        {
            public void actionPerformed(ActionEvent e) 
            {
                q.addincome(new Credit(Double.valueOf(textField1.getText()),textField2.getText(),textField3.getText()));;
                c.removeAll();mainpage(c);
            }
        }
        );
        btn4.addActionListener(new ActionListener()  //เงินสด
        {
            public void actionPerformed(ActionEvent e) 
            {
                q.addincome(new Realmoney(Double.valueOf(textField1.getText()),textField2.getText()));;
                c.removeAll();mainpage(c);
            }
        }
        );
        btn5.addActionListener(new ActionListener() //อื่นๆ
        {
            public void actionPerformed(ActionEvent e) 
            {
                q.addincome(new OrtherIncome(Double.valueOf(textField1.getText()),textField2.getText()));;
                c.removeAll();mainpage(c);
            }
        }
        );
    }
    public void conclude(Container c) //หน้าสรุป
    {
        JPanel panel = new JPanel();panel.setPreferredSize(new Dimension(400, 360));
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
        c.add(panel);
        String[] column = {"Note","Income"};
        for (int i = 0; i < topic.size(); i++) //หัวข้อทั้งหมด
        {
            // ข้อ 3 ตวจสอบชื่อว่าเป็น none หรือเปล่า ถ้าเป็นข้ามหัวข้อนั้น
            JLabel label = new JLabel(topic.get(i).gettopic());label.setAlignmentX(Component.CENTER_ALIGNMENT);
            panel.add(label);
            String[][] data = new String[topic.get(i).getlistlenght()+1][2]; 
            for (int j = 0; j < topic.get(i).getlistlenght(); j++)    //รายรับทั้งหมดของหัวข้อนั้น
            {
                data[j][0] = topic.get(i).getmoney(j).getnote()+"   "+topic.get(i).getmoney(j).getcardnum();
                data[j][1] = (String) (topic.get(i).getmoney(j).gettotal()+"");
            }
            data[topic.get(i).getlistlenght()][0] = "Total";
            data[topic.get(i).getlistlenght()][1] = (String) (topic.get(i).allincome()+"");
            JTable table = new JTable(data,column);
            // ข้อ 1 เพิ่ม checkbox ที่มีชื่อ note
            panel.add(table);
        }
        JButton btn3 = new JButton("back");btn3.setAlignmentX(Component.CENTER_ALIGNMENT);
        panel.add(btn3);
        btn3.addActionListener(new ActionListener() //กลับ
        {
            public void actionPerformed(ActionEvent e) 
            {                
                c.removeAll();mainpage(c);
            }
        }
        );
        // ข้อ 1 เพิ่มปุ่ม delete + addActionlistener เมื่อกดแล้วลบเงินในตาม checkbox ที่ติ๊กไว้
        setVisible(true);
    }
}