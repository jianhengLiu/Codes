import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.Vector;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

public class Test8 implements ActionListener {

    JTable table = null;
    DefaultTableModel defaultModel = null;

    public Test8() {
        JFrame f = new JFrame();
        Object[][] p = {
                { "����", new Integer(91), new Integer(1949), new Integer(1910) },
                { "��ѧ��", new Integer(82), new Integer(1969), new Integer(1510) },
                { "÷��", new Integer(47), new Integer(1957), new Integer(1040) },
                { "����", new Integer(61), new Integer(1957), new Integer(1180) },
                { "���", new Integer(90), new Integer(1987), new Integer(1770) }, };
        String[] n = { "����", "����", "��������", "нˮ" };
        // ����һ��Ĭ�ϵı��ģ��
        defaultModel = new DefaultTableModel(p, n);
        table = new JTable(defaultModel);
        table.setPreferredScrollableViewportSize(new Dimension(400, 80));
        JScrollPane s = new JScrollPane(table);
        JPanel panel = new JPanel();
        JButton b = new JButton("������");
        panel.add(b);
        b.addActionListener(this);
        b = new JButton("ɾ����");
        panel.add(b);
        b.addActionListener(this);

        Container contentPane = f.getContentPane();
        contentPane.add(panel, BorderLayout.NORTH);
        contentPane.add(s, BorderLayout.CENTER);
        f.setTitle("AddRemoveCells");
        f.pack();
        f.setVisible(true);
        f.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getActionCommand().equals("������")) {
            // ������"������"��ť�󣬻��ڱ�������һ��
            defaultModel.addRow(new Vector());
        }
        if (e.getActionCommand().equals("ɾ����")) {
            // ������"ɾ����"��ť�󣬻��ڱ���ɾ����ѡ�е�һ�У�����������һ��Ϊ��ǰ��
            int rowcount = defaultModel.getRowCount() - 1;
            // getRowCount����������rowcount<0�����Ѿ�û������
            if (rowcount >= 0) {
                defaultModel.removeRow(rowcount);
                defaultModel.setRowCount(rowcount);
                /**
                 * ɾ���бȽϼ򵥣�ֻҪ��DefaultTableModel��removeRow��������
                 * ɾ������Ϻ������������������Ҳ����ʹ��DefaultTableModel��setRowCount()���������õ�ǰ��
                 */
            }
        }
        table.revalidate();
    }

    public static void main(String[] args) {
        new Test8();
    }

}

