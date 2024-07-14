// 09-19-2011 19:05:53+01:00	Submit	aajjbb	250	75.00
public class MagicSquare{
	public int missing(int[] square){
		int[][] board = new int[3][3];
		int col = 0;
		int b = 0, total = 0;

		int c = 0;
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				board[i][j] = square[c];
				c++;
			}
		}
		for(int x = 0; x < square.length; x++) {
			if(square[x] != -1) b += square[x];
		}
		for(int i = 0; i < 3; i++) {
			int temp = 0;
			boolean has = false;
			for(int j = 0; j < 3; j++) {
				if(board[i][j] != -1) {
					temp += board[i][j];
				} else {
					has = true;
					break;
				}
			}
			if(has == false) {
				total = temp * 3;
				return total - b;
			} else {
				continue;
			}
		}
		return 0;
	}
}
// Powered by FileEdit