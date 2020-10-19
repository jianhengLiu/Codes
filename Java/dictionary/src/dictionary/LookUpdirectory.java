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
			System.out.println("1.�鵥��\n2.�ӵ���\n3.ɾ������\n4.�鿴���е���\n5.�޸ĵ���\n0.�˳�\n");
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
				System.out.println("���ʱ������е��ʣ�");
				my.listAllWord();
			}
			if (choice == '5') {
				showUpdate();
			}
		} while (choice != '0');
	}

	public void welcome() {
		System.out.println("************");
		System.out.println("��ӭʹ�ôʵ�");
		System.out.println("************");
	}

	public void bye() {
		System.out.println("*********");
		System.out.println("Bye Bye.");
		System.out.println("*********");
	}

	public void showWord() {
		System.out.println("������Ҫ���ҵĵ��ʣ�");
		String str = input.nextLine();
		Word w = my.searchWord(str);
		if (w != null) {
			System.out.println("���ҵĵ��ʵ���Ӣ�ĺ��壺");
			System.out.println(w);
		} else {
			System.out.println("�������û�в鵽");
		}
	}

	public void showAdd() {
		System.out.println("������Ҫ��ӵ��ʵ����ĺ��壺");
		String cStr = input.nextLine();
		System.out.println("������Ҫ��ӵ��ʵ�Ӣ�ĺ��壺");
		String eStr = input.nextLine();
		Word word = new Word(eStr, cStr);
		if (my.add(word))
			System.out.println("������ӳɹ���");
		else
			System.out.println("�ʵ����ˣ��������ʧ�ܣ�");
	}

	public void showDel() {
		System.out.println("������Ҫɾ���ĵ��ʵĺ��壺");
		String str = input.nextLine();
		boolean f = my.delWord(str);
		if (f)
			System.out.println("ɾ���ɹ���");
		else
			System.out.println("ɾ��ʧ�ܣ�");
	}

	public void showUpdate() {
		System.out.println("�����޸ĵ��ʵ�Ӣ�ĺ��壡");
		System.out.println("������Ҫ�޸ĵ��ʵ����ĺ��壺");
		String cStr = input.nextLine();
		System.out.println("�������޸ĵ��ʵĺ���:");
		String eStr = input.nextLine();
		Word word = new Word(eStr, cStr);
		if (my.updateWord(word))
			System.out.println("�����޸ĳɹ���");
		else
			System.out.println("�ʵ�û�д˵��ʣ��޸�ʧ�ܣ�");
	}
}
