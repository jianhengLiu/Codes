import java.awt.*;
import javax.swing.*;
public class SwiPanel {
    public static void main(String[] args)
    {
    	JPanel pan = new JPanel();
    	JFrame f = new JFrame("我的框架");
    	Container con = f.getContentPane();
    	JTextField jf1=new JTextField("第一个文本框",20);
    	JTextField jf2=new JTextField("第二个文本框",20);
    	JButton jbt = new JButton("确认");
    	pan.add(jf1);
    	pan.add(jf2);
    	pan.add(jbt);
    	con.add(pan);
    	f.setLocation(300,200);
    	f.setSize(300,200);
    	f.setDefaultCloseOperation(3);
    	f.setVisible(true);
    }
}
