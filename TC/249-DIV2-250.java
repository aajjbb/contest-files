// 2011-07-10T03:40:30+01:00

import java.util.*;

public class ChatTranscript {
  public int howMany(String[] t, String name) {
    int c = 0;
    for(String i: t) {
      if(i.startsWith(name+":")) { c++; }
    }
    return c;
  }
}

// Powered by FileEdit
