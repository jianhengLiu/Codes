import java.awt.*;
import javax.swing.*;
public class SwiPanel {
    public static void main(String[] args)
    {
    	JPanel pan = new JPanel();
    	JFrame f = new JFrame("�ҵĿ��");
    	Container con = f.getContentPane();
    	JTextField jf1=new JTextField("��һ���ı���",20);
    	JTextField jf2=new JTextField("�ڶ����ı���",20);
    	JButton jbt = new JButton("ȷ��");
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
