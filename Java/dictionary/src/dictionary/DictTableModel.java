package dictionary;

import java.util.List;

import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableModel;

public class DictTableModel extends DefaultTableModel{

	public DictTableModel(List<Word> list) {
		String[] column = {"���ĵ���","Ӣ�ĵ���"};
		Object[] object = list.toArray();
		String[] strs = new String[object.length];
		for (int i = 0; i < object.length; i++)
		{
		strs[i] = object[i].toString();
		}
		for(String info:strs)
		{ 
			 String[] args=info.split(","); //��ѧ����Ϣ���Ϊ����,���ݸ�args����.
			 this.addRow(args);
		}
	}
        
}
