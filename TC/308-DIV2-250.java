// 09-04-2012 20:32:19+01:00	Submit	aajjbb	250	249.35
import java.util.*;
import java.math.*;

public class MedianOfNumbers {
	public int findMedian(int[] numbers) {
		if(numbers.length == 1) return numbers[0];
		if(numbers.length % 2 == 0) return -1;
		Arrays.sort(numbers);
		return numbers[numbers.length / 2];
	}
}


// Powered by FileEdit
