package dictionary;

public class Word {
	private String eWord, cWord;

	public String getEWord() {
		return eWord;
	}

	public void setEWord(String word) {
		eWord = word;
	}

	public String getCWord() {
		return cWord;
	}

	public void setCWord(String word) {
		cWord = word;
	}

	public Word() {
		this("", "");
	}

	public Word(String eStr, String cStr) {
		this.eWord = eStr;
		this.cWord = cStr;
	}

	public String toString() {
		return eWord + "," + cWord;
	}
}