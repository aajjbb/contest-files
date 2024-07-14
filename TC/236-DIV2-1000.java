// 03-06-2012 13:58:05+01:00	Submit	aajjbb	1000	323.61
import java.util.*;

public class ComputerExpert {
	public static final char OR = '/';
	public static final char AND = ',';

	public String[] operate(String[] facts, String[] rules) {
		Set r = new TreeSet();
  		r.addAll(Arrays.asList(facts));
	    boolean changed = true;

	    while(changed){
        	changed = false;
	        for(int i = 0; i<rules.length; i++){
    	        String[] sp = rules[i].split(" -> ");
	            if(tr(r,sp[0])){
    	            changed |= r.add(sp[1]);
        	    }
	        }
	    }
	    r.removeAll(Arrays.asList(facts));
	    ArrayList al = new ArrayList(r);
	    return (String[])al.toArray(new String[0]);
	}
	boolean tr(Set s, String r){
    	String[] sp = r.split(",");
	    for(int i = 0; i<sp.length; i++){
	        String[] s2 = sp[i].split("/");
    	    Set t = new TreeSet(Arrays.asList(s2));
        	t.retainAll(s);
	        if(t.size()==0)return false;
	    }
	    return true;
	}
}

// Powered by FileEdit