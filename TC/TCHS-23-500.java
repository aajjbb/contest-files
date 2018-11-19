// Submitted in 05-07-2012 15:31:37
import java.util.*;

public class Apportionment {
    public long numberOfSquares(int N, int M) {
        long resp = 1;
   			for(long i = 1; i < N; i++) {
        		if(i * M % N == 0) {
           			resp += (long) (N - i + 1) * (long) (M - i * M / N + 1);
        		}
    		}
        return resp;
    }
}

// Powered by FileEdit,
