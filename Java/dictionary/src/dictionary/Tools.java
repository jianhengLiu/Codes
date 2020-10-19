package dictionary;
import java.util.*;
import java.io.*;
public class Tools {
	public static List readWord(String filename)
	{
		List list = new ArrayList();
		try {
			DataInputStream in = new DataInputStream(new BufferedInputStream(new FileInputStream(filename)));
			String word;
			String[] words;
			while((word = in.readLine()) != null)
			{
				words = word.split(",");
				list.add(new Word(words[0], words[1]));
			}
			in.close();
		}catch(IOException e) {
			e.printStackTrace();
		}finally {
			return list;
		}
	}
	public void putMap2Words(String fileName, List list)
	{
		try 
		{
			PrintStream out = new PrintStream (new FileOutputStream(fileName));
			for (int i = 0;i <= list.size(); i++)
			{
				String str = ((Word) list.get(i)).toString();
			}
			out.flush();
			out.close();
		}catch (IOException e) 
		{
			e.printStackTrace();
		}
	}
}
