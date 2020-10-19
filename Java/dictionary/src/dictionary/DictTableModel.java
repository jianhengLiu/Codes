package dictionary;

import java.util.List;

import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableModel;

public class DictTableModel extends DefaultTableModel{

	public DictTableModel(List<Word> list) {
		String[] column = {"中文单词","英文单词"};
		Object[] object = list.toArray();
		String[] strs = new String[object.length];
		for (int i = 0; i < object.length; i++)
		{
		strs[i] = object[i].toString();
		}
		for(String info:strs)
		{ 
			 String[] args=info.split(","); //把学生信息拆分为数组,传递给args数组.
			 this.addRow(args);
		}
	}
        
}
