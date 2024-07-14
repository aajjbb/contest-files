// 12-11-2012 19:29:03+01:00	Submit	aajjbb	250	245.59
import java.util.*;
import java.math.*;

public class HiddenMessage {
	public String getMessage(String text) {
		String ans = "";

		String[] array = text.split("\\s");

		for(int i = 0; i < array.length; i++) if(!array[i].equals("")) ans += array[i].charAt(0);

		return ans;
	}
}

// Powered by FileEdit