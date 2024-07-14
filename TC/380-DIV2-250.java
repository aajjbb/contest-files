// 09-06-2012 12:52:43+01:00	Submit	aajjbb	250	204.16
import java.util.*;
import java.math.*;

public class LuckyTicketSubstring {
  public int maxLength(String s) {
    int longest = 0;
    for(int i = 0; i < s.length(); i++) {
      for(int j = i + 1; j < s.length(); j++) if((j - i + 1) % 2 == 0) {
	  int len = j - i + 1;
	  int left = 0, right = 0;
	  for(int k = i; k < i + len / 2; k++) left += s.charAt(k) - '0';
	  for(int k = i + len / 2; k <= j; k++) right+= s.charAt(k) - '0';
	  System.out.println(i + " " + j + " " + left + " " + right);
	  if(left == right) longest = Math.max(longest, j - i + 1);
	}
    }
    return longest;
  }
}


// Powered by FileEdit
