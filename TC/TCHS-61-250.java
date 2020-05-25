import java.util.*;

public class MagicSpell {
	public String fixTheSpell(String spell) {
		String mem = "";
		String ret = "";
		
		for(int i = 0; i < spell.length(); i++) { 
			if(spell.charAt(i) == 'A') { 
				mem += 'A'; 
			} if(spell.charAt(i) == 'Z')  { 
				mem += 'Z'; 
			}
		}
		
		StringBuilder build = new StringBuilder(mem).reverse();
		
		String rev = build.toString();
		
		int cont = 0;
		
		for(int i = 0; i < spell.length(); i++) {
			if(spell.charAt(i) == 'A' || spell.charAt(i) == 'Z') {
				ret += rev.charAt(cont) + "";
				cont++;
			} else {
				ret += spell.charAt(i) + "";
			}
		}		
	 return ret;
	}
}
