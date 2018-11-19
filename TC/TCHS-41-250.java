// Submitted 10-08-2011

import java.util.*;

public class MajorityElement {
    public int findMajorityElement(int[] a) {
        int mid = (a.length) / 2;
        int ret = -1;

        for(int i = 0; i < a.length; i++) {
            int temp = 0;
            for(int j = 0; j < a.length; j++) {
                if(a[i] == a[j]) {
                    temp++;
                }
            }
            if(temp > mid) {
                ret = a[i];
            }
        }
        if(ret == -1) {
            return -1;
        }
        return ret;
    }
}

// Powered by FileEdit
