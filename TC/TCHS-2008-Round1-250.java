import java.util.*;

public class StudentEnrollment {
	public String[] checkClasses(String[] names, int[] spaces, String[] queries) {
		String[] ret = new String[queries.length];
		Arrays.fill(ret, "");
		
		for(int i = 0; i < queries.length; i++) {
			boolean found = false;
			for(int j = 0; j < names.length; j++) {
				if(names[j].equals(queries[i]) && spaces[j] >= 1) {
					ret[i] = "GOOD";
					spaces[j]--;
					found = true;
				} else if(names[j].equals(queries[i]) && spaces[j] <= 0) {
					ret[i] = "NOT GOOD";
					found = true;				
				}
			}	
			if(found == false) {
				ret[i] = "DOES NOT EXIST";		
			}	
		} 	
		return ret;
	}
}