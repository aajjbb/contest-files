// 10-12-2012 19:20:26+01:00	Submit	aajjbb	250	247.89
import java.util.*;

public class SMSLanguage {
	public String translate(String text) {
		text = text.replaceAll("[.,?!]", "");
		text = text.toLowerCase();
		text = text.replaceAll("and", "&");
		text = text.replaceAll("ate", "8");
		text = text.replaceAll("at", "@");
		text = text.replaceAll("you", "U");
		return text;
	}
}


// Powered by FileEdit