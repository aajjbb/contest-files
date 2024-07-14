// 2011-08-23T22:59:02+01:00
import java.util.*;

public class CorruptMages {
	public int minimalNumber(int[] power) {
		int ans = 0;
		int buff = 0;
		power = insertionSortReversed(power);

		for(int i = 0; i < power.length; i++) {
			ans += 1 + power[i];
			buff++;
			if(ans >= power.length) {
				return buff;
			}
		}
		return buff;
	}

	public int[] insertionSortReversed(int[] num) {
		int insert = 0;
		for(int i = 1; i < num.length; i++) {
			insert = num[i];
			int moveItem = i;

			while (moveItem > 0 && num[moveItem - 1] < insert) {
				num[moveItem] = num[moveItem - 1];
					moveItem--;
			}
			num[moveItem] = insert;
		}
		return num;
	}
}

// Powered by FileEdit
