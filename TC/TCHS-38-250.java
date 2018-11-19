// Submitted 09-08-2011

import java.util.*;

public class JoshString {
    public String isJoshString(String s) {
        char[] alphabet = new char[] {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

        int total = 0;

        for(int i = 0; i < s.length(); i++) {
            for(int j = 1; j < alphabet.length; j++) {
                if(s.charAt(i) == alphabet[j]) {
                    total += j;
                }
            }
        }
        if(isPrime(total) == true) {
            return "YES";
        } else {
            return "NO";
        }
    }

    public boolean isPrime(int n) {
        for (int i=2; i<n; i++)
            if(n%i==0) return false;
        return true;
    }
}


// Powered by FileEdit
