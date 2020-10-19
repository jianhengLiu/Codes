package dictionary;

import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

public class AddFrame extends JFrame {
	Directory my;
	JTextField txtCword;
	JTextField txtEword;
	JButton btnAdd;
	JButton btnClose;

	public AddFrame(Directory my) {
		this.my = my;
		initControl();
		initFrame();
	}

	public void initControl() {
		JLabel lblcword = new JLabel("中文单词");
		add(lblcword);

		txtCword = new JTextField();
		add(txtCword);
		JLabel lbleword = new JLabel("英文单词");
		add(lbleword);
		txtEword = new JTextField();
		add(txtEword);
		btnAdd = new JButton("add");
		btnClose = new JButton("Close");
		add(btnAdd);
		add(btnClose);
		btnAdd.addActionListener((ActionListener) new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				Word word = new Word();
				word.setEWord(txtCword.getText());
				word.setCWord(txtEword.getText());
				my.add(word);
				JOptionPane.showMessageDialog(null, "词典添加成功", "提示框", JOptionPane.INFORMATION_MESSAGE);
				txtCword.setText("");
				txtEword.setText("");
				System.out.println(word);
			}
		});
		btnClose.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0)
			{
				setVisible(false);
			}
		});
	}

	public void initFrame() {
		setTitle("Add a word");
		setSize(270, 100);
		setLocation(300, 300);
		setLayout(new GridLayout(3, 2));
		setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
		setVisible(true);
	}
}