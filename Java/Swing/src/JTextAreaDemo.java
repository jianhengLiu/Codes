import java.awt.*;
import javax.swing.*;
public class JTextAreaDemo {
    public JTextAreaDemo()
    {
    	JFrame f=new JFrame();
    	Container con=f.getContentPane();
    	JPanel pan=new JPanel();
    	JLabel jg = new JLabel("请录入：");
        JButton ok=new JButton("OK");
    	JButton cancel= new JButton("CANCEL");
    	JTextArea input = new JTextArea(5,20);
    	JScrollPane sp = new JScrollPane(input);
    	pan.add(jg);
    	pan.add(sp);
    	pan.add(ok);
    	pan.add(cancel);
    	con.add(pan);
    	f.setTitle("组建显示");
    	f.setLocation(300,200);
    	f.setSize(300,200);
    	f.setDefaultCloseOperation(3);
    	f.setVisible(true);
    }
    public static void main(String[] args)
    {
    	new JTextAreaDemo();
    }
}
