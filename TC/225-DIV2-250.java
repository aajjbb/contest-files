// 09-03-2012 20:16:26+01:00	Submit	aajjbb	250	125.31
import java.util.*;
import java.math.*;

public class SignatureDecorator {
	public String applyDecoration(String name, String[] commands, String[] decorations) {
		String pre = "", end = "";
		for(int i = 0; i < commands.length; i++) {
			if(commands[i].equals("surround")) {
				name += reverse(decorations[i]);
				name = decorations[i] + name;
			} else if(commands[i].equals("prepend")) {
				name = decorations[i] + name;
			} else {
				name = name + decorations[i];
			}
		}
		return name;
	}
	public String reverse(String s) {
		return new StringBuilder(s).reverse().toString();
	}
}

// Powered by FileEdit