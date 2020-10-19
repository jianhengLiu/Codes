package dictionary;

import java.util.Scanner;

public class LookUpdirectory {
	Directory my;
	Scanner input;

	public LookUpdirectory() {
		my = new Directory();
		input = new Scanner(System.in);
	}

	public void run() {
		welcome();
		lookup();
		bye();
	}

	public void lookup() {
		char choice;
		do {
			System.out.println("1.查单词\n2.加单词\n3.删除单词\n4.查看所有单词\n5.修改单词\n0.退出\n");
			choice = input.nextLine().charAt(0);
			if (choice == '1') {
				showWord();
			}
			if (choice == '2') {
				showAdd();
			}
			if (choice == '3') {
				showDel();
			}
			if (choice == '4') {
				System.out.println("单词本有下列单词：");
				my.listAllWord();
			}
			if (choice == '5') {
				showUpdate();
			}
		} while (choice != '0');
	}

	public void welcome() {
		System.out.println("************");
		System.out.println("欢迎使用词典");
		System.out.println("************");
	}

	public void bye() {
		System.out.println("*********");
		System.out.println("Bye Bye.");
		System.out.println("*********");
	}

	public void showWord() {
		System.out.println("请输入要查找的单词：");
		String str = input.nextLine();
		Word w = my.searchWord(str);
		if (w != null) {
			System.out.println("查找的单词的中英文含义：");
			System.out.println(w);
		} else {
			System.out.println("这个单词没有查到");
		}
	}

	public void showAdd() {
		System.out.println("请输入要添加单词的中文含义：");
		String cStr = input.nextLine();
		System.out.println("请输入要添加单词的英文含义：");
		String eStr = input.nextLine();
		Word word = new Word(eStr, cStr);
		if (my.add(word))
			System.out.println("单词添加成功！");
		else
			System.out.println("词典满了，单词添加失败！");
	}

	public void showDel() {
		System.out.println("请输入要删除的单词的含义：");
		String str = input.nextLine();
		boolean f = my.delWord(str);
		if (f)
			System.out.println("删除成功！");
		else
			System.out.println("删除失败！");
	}

	public void showUpdate() {
		System.out.println("仅能修改单词的英文含义！");
		System.out.println("请输入要修改单词的中文含义：");
		String cStr = input.nextLine();
		System.out.println("请输入修改单词的含义:");
		String eStr = input.nextLine();
		Word word = new Word(eStr, cStr);
		if (my.updateWord(word))
			System.out.println("单词修改成功！");
		else
			System.out.println("词典没有此单词，修改失败！");
	}
}
