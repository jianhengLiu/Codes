package dictionary;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.Point;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class About extends JFrame {
	public About() {
		initFrame();
	}

	public void initFrame() {
		setTitle("About");
		setLayout(new BorderLayout());
		JLabel aboutword =  new JLabel("<html><body>" + "词典程序"+ "<br>" + "Updated on 2018.3.31."+ "<br>" + "by Chris.");
		add(aboutword,BorderLayout.CENTER);
		JButton btnClose = new JButton("Close");
		add(btnClose, BorderLayout.SOUTH);
		setSize(250, 200);
		setLocation(About.getMidDimesion(new Dimension(300, 300)));
		//setLayout(new GridLayout(3, 2));  将界面分块
		setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
		setVisible(true);
		btnClose.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0)
			{
				setVisible(false);
			}
		});
	}

	public static Point getMidDimesion(Dimension d) {
		Point p = new Point();
		Dimension dim = Toolkit.getDefaultToolkit().getScreenSize();
		p.setLocation((dim.width - d.width) / 2, (dim.height - d.height) / 2);
		return p;
	}
}
