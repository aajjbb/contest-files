import java.util.*;
import java.math.*;

public class ToastXRaspberry {
	public int apply(int upper_limit, int layer_count) {
		if(layer_count < upper_limit) return 1;
		return (int) (layer_count / upper_limit) + (layer_count % upper_limit == 0 ? 0 : 1);
	}	
}

// Powered by FileEdit
