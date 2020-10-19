package dictionary;

import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Point;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;

public class SwingUI extends JFrame {
	Directory my;
	JMenuItem addItem;
	JMenuItem queryItem;
	JMenuItem aboutItem;
	JMenuItem exitItem;
	JFrame file;

	public SwingUI(Directory my) {
		this.my = my;
		initMenu();
		initFrame();
	}

	public void initFrame() {
		setTitle("ÎÒµÄ´Êµä");
		this.setSize(400, 600);
		setDefaultCloseOperation(3);
		JPanel panel = new JPanel();
		panel.setLayout(new FlowLayout(FlowLayout.CENTER));
		JButton addfile = new JButton("Add Word File");
		JButton savefile = new JButton("Save Word File");
		panel.add(addfile);
		panel.add(savefile);
		add(panel);
		setLocation(SwingUI.getMidDimesion(new Dimension(400, 600)));
		this.setVisible(true);
	}

	public static Point getMidDimesion(Dimension d) {
		Point p = new Point();
		Dimension dim = Toolkit.getDefaultToolkit().getScreenSize();
		p.setLocation((dim.width - d.width) / 2, (dim.height - d.height) / 2);
		return p;
	}

	private void initMenu() {
		JMenuBar bar = new JMenuBar();
		JMenu dictMenu = new JMenu("Dict");
		JMenu sysMenu = new JMenu("Sys");
		addItem = new JMenuItem("Add");
		addItem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				AddFrame add = new AddFrame(my);
			}
		});
		queryItem = new JMenuItem("query");
		queryItem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				QueryFrame query = new QueryFrame(my);
			}
		});
		aboutItem = new JMenuItem("About");
		aboutItem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				About about = new About();
			}
		});
		exitItem = new JMenuItem("exti");
		exitItem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				System.exit(0);
			}
		});
		dictMenu.add(addItem);
		dictMenu.add(queryItem);
		sysMenu.add(aboutItem);
		sysMenu.add(exitItem);
		bar.add(dictMenu);
		bar.add(sysMenu);
		setJMenuBar(bar);
	}
}
