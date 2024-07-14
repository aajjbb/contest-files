// 09-22-2012 22:51:42+01:00	Submit	aajjbb	250	247.74
import java.util.*;

public class StringMult {
	public String times(String sFactor, int iFactor) {
		if(iFactor == 0 || sFactor.equals("")) return "";
		String ans = "";
		if(iFactor < 0) {
			sFactor = new StringBuilder(sFactor).reverse().toString();
		}
		iFactor = Math.abs(iFactor);
		for(int i = 0; i < iFactor; i++) ans += sFactor;
		return ans;
	}
}


// Powered by FileEdit