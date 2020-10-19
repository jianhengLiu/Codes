package dictionary;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Point;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.table.DefaultTableModel;

public class QueryFrame extends JFrame {
	int n = 0;
	private Directory my;
	JFrame f = new JFrame();
	JTextField txtQuery;
	JButton btnQuery, btnClose, btndel;
	JTable table;
	DefaultTableModel dataModel;
	
	public QueryFrame(Directory my) {
		this.my = my;
		initControl();
		initFrame();
	}

	public void initTable() {
		String[] column = {"中文单词","英文单词"};
		dataModel = new DefaultTableModel(column,0);
		table = new JTable();
		table.setPreferredScrollableViewportSize(new Dimension(550, 30));
		table.setModel(dataModel);
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setViewportView(table);
		add(scrollPane, BorderLayout.CENTER);
		
		Object[] object = my.getWordList().toArray();
		String[] strs = new String[object.length];
		for (int i = 0; i < object.length; i++)
		{
		strs[i] = object[i].toString();
		}
		for(String info:strs)
		{ 
			 String[] args=info.split(","); //把学生信息拆分为数组,传递给args数组.
			 dataModel.addRow(args);
		}
	}

	private void initControl() {
		setLayout(new BorderLayout());
		JPanel panel1 = new JPanel();
		panel1.setLayout(new FlowLayout(FlowLayout.CENTER));
		panel1.add(new JLabel("Query word:"));
		txtQuery = new JTextField(10);
		panel1.add(txtQuery);
		btnQuery = new JButton("查询");
		panel1.add(btnQuery);
		btnQuery.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				Word word = my.searchWord(txtQuery.getText());
				if (word == null)
					JOptionPane.showMessageDialog(QueryFrame.this, "无此单词");
				else 
				{
					Object[] object1 = my.getWordList().toArray();
					if (n == 0)
					{
					    for (int i = object1.length-1;i >= 0;i--)
					        dataModel.removeRow(i);
					    n++;
					}
					else
						dataModel.removeRow(0);
					List<Word> list = new ArrayList<Word>();
					list.add(word);
					Object[] object2 = list.toArray();
					String[] strs = new String[object2.length];
					for (int i = 0; i < object2.length; i++)
					{
					strs[i] = object2[i].toString();
					}
					for(String info:strs)
					{ 
						 String[] args=info.split(","); //把信息拆分为数组,传递给args数组.
						 dataModel.addRow(args);
					}
				}
			}
		});
		add(panel1, BorderLayout.NORTH);
		initTable();
		JPanel panel2 = new JPanel();
		panel2.setLayout(new FlowLayout(FlowLayout.RIGHT));
		btnClose = new JButton("close");
		btnClose.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				setVisible(false);
			}
		});
		btndel = new JButton("Delete word");
		btndel.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				int row = table.getSelectedRow();
				if (row == -1) {
					JOptionPane.showMessageDialog(QueryFrame.this, "请选择要删除的行！");
				}
				else 
				{
					int col = table.getSelectedColumn();
					my.del(col-1);
					//dataModel.removeRow(col);
				}
			}
		});
		panel2.add(btndel);
		panel2.add(btnClose);
		add(panel2, BorderLayout.SOUTH);
	}

	public void initFrame() {
		setTitle("查找单词");
		this.setSize(400, 500);
		setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
		setLocation(SwingUI.getMidDimesion(new Dimension(400, 500)));
		this.setVisible(true);
	}

	public static Point getMidDimesion(Dimension d) {
		Point p = new Point();
		Dimension dim = Toolkit.getDefaultToolkit().getScreenSize();
		p.setLocation((dim.width - d.width) / 2, (dim.height - d.height) / 2);
		return p;
	}
}