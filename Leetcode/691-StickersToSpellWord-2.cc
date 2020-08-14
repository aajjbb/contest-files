class Solution {
public:
  static const int MAX_N = 51;
  static const int MAX_BITS = (1 << 15) + 1;
  static const int MAX_TRIES = 50;
    
  const int INF = 101010;
    
  int dp[MAX_BITS];
    
  int minStickers(vector<string>& stickers, string target) {
    const int n = target.size();
        
    memset(dp, 63, sizeof(dp));        
        
    dp[0] = 0;
        
    for (int i = 0; i < (1 << n); i++) {
      if (dp[i] >= INF) {
	continue;
      }
      for (int j = 0; j < stickers.size(); j++) {
	int new_mask = i;
                
	for (int k = 0; k < stickers[j].size(); k++) {                    
	  for (int l = 0; l < n; l++) {
	    if (new_mask & (1 << l)) {
	      continue;
	    }
	    if (stickers[j][k] == target[l]) {
	      new_mask |= (1 << l);
	      break;
	    }
	  }
	}
                
	dp[new_mask] = min(dp[new_mask], dp[i] + 1);
      }
    }
        
    int ans = dp[(1 << n) - 1];
        
    if (ans >= INF) {
      ans = -1;
    }
        
    return ans;
  }
    
  //     int func(int pos, int mask, const vector<string>& stickers, const string& target) {
  //         if (mask == (1 << target.size()) - 1) {
  //             return 0;
  //         } else if (pos == stickers.size()) {
  //             return INF;
  //         } else {
  //             int& ans = dp[pos][mask];
            
  //             if (ans == -1) {
  //                 ans = func(pos + 1, mask, stickers, target);
                
  //                 int new_mask = mask;

  //                 for (int i = 1; i <= MAX_TRIES; i++) {
  //                     int sticker_mask = 0;
                    
  //                     for (int k = 0; k < target.size(); k++) {
  //                         if (new_mask & (1 << k)) {
  //                             continue;
  //                         }
  //                         for (int j = 0; j < stickers[pos].size(); j++) {                        
  //                             if (sticker_mask & (1 << j)) {
  //                                 continue;
  //                             }
  //                             if (stickers[pos][j] == target[k]) {
  //                                 new_mask |= (1 << k);
  //                                 sticker_mask |= (1 << j);
  //                                 break;
  //                             }
  //                         }
  //                     }
                    
  //                     if (new_mask == mask) {
  //                         break;
  //                     }
                                      
  //                     ans = min(ans, i + func(pos + 1, new_mask, stickers, target));                                        
  //                 }                
  //             }
            
  //             return ans;
  //         }
  //     }
};
