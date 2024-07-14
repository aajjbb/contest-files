// 09-15-2011 15:23:26+01:00	Submit	aajjbb	250	75.00
import java.util.*;

public class SearchBox {
	public int find(String text, String search, String wholeWord, int start) {
		int i = text.indexOf(search, start);

		if(wholeWord.equals("N") && i != -1) {
			return i;
		} else {
			text = " " + text + " ";
			search = " " + search + " ";
		}
		i = text.indexOf(search, start);
		return i;
	}
}


// Powered by FileEdit