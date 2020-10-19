import javax.swing.*;
public class JFrameDemo1 extends JFrame {
    public JFrameDemo1()
    {
    	super("第一个窗体");
    	setLocation(200,200);
    	setSize(400,300);
    	setDefaultCloseOperation(3);
    	setVisible(true);
    }
    public static void main (String[] args)
    {
    	new JFrameDemo1();
    }
}
