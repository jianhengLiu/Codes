package dictionary;

import java.util.ArrayList;
import java.util.List;

public class Directory {
	private List<Word> wordList;

	public Directory() {
		wordList = new ArrayList<Word>();
	}

	public void listAllWord() {
		for (int i = 0; i < wordList.size(); i++)
			System.out.println(wordList.get(i));
	}

	public boolean add(Word word) {
		wordList.add(word);
		return true;
	}

	public Word searchWord(String str) {
		for (int i = 0; i < wordList.size(); i++)
			if (((Word) wordList.get(i)).getCWord().equals(str)
					|| ((Word) wordList.get(i)).getEWord().equalsIgnoreCase(str))
				return (Word) wordList.get(i);
		return null;
	}

	public boolean updateWord(Word w) {
		int location = indexOf(w.getCWord());
		if (location < 0)
			return false;
		else {
			del(location);
			wordList.add(location, w);
			return true;
		}
	}

	public boolean delWord(String str) {
		int location = indexOf(str);
		return del(location);
	}

	public boolean del(int i) {
		if (i >= 0)
			wordList.remove(i);
		else
			return false;
		return true;
	}

	public int indexOf(String str) {
		if (str == null)
			return -1;
		for (int i = 0; i < wordList.size(); i++)
			if (wordList.get(i).getCWord().equals(str))
				return i;
		return -1;
	}

	public void setWordList(List list) {
		wordList = list;
	}

	public List<Word> getWordList() {
		return wordList;
	}
}
