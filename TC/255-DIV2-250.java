// 09-22-2011 01:07:39+01:00	Submit	aajjbb	250	243.22
import java.util.*;

public class SequenceOfNumbers {
	public String[] rearrange(String[] sequence) {

		for(int i = 1; i < sequence.length; i++) {
			int a = i;
			int b = Integer.parseInt(sequence[i]);
			String aux = sequence[i];
			while(a > 0 && Integer.parseInt(sequence[a - 1]) > b) {
				sequence[a] = sequence[a - 1];
				a--;
			}
			sequence[a] = aux;
		}
		return sequence;
	}
}

// Powered by FileEdit