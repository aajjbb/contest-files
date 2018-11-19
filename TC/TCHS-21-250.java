// Submitted in 22-07-2011 09:17:49
import java.util.*;

public class PostOffice {
    public int matchAddress(String address1, String address2) {
        char[] ad1 = address1.toCharArray();
        char[] ad2 = address2.toCharArray();
        List<String> temp1 = new ArrayList<String>();
        List<String> temp2 = new ArrayList<String>();

        for(int i = 0; i < ad1.length; i++) {
            if(ad1[i] == ' ' == false) {
                temp1.add(""+ad1[i]);
            }
        }
        for(int i = 0; i < ad2.length; i++) {
            if(ad2[i] == ' ' == false) {
                temp2.add(""+ad2[i]);
            }
        }

        for(int i = 0; i < Math.min(temp1.size(), temp2.size()); i++) {
            if(!temp1.get(i).equalsIgnoreCase(temp2.get(i))) {
                return i;
            }
        }
        if(temp1.size() != temp2.size()) {
            return Math.min(temp1.size(), temp2.size());
        } else {
            return -1;
        }
    }
}


// Powered by FileEdit
