// 01-02-2012 03:12:57+01:00	Submit	aajjbb	1000	828.03
import java.util.*;

public class CompilingDecksWithJokers {
  public int maxCompleteDecks(int[] cards, int jokers) {
    int low = 0, high = cards[cards.length - 1] + jokers + 1, mid;

    while(low + 1 < high) {
      mid = (low +  high) >>> 1;
      long need = 0;

      for(int i = 0; i < cards.length; i++) {
	if(cards[i] < mid) {
	  need += (mid - cards[i]);
	}
      }
      boolean possible = (need <= mid && need <= jokers);

      if(possible) {
	low = mid;
      } else {
	high = mid;
      }
    }
    return low;
  }
}

// Powered by FileEdit
