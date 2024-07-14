// 2013-02-26T16:46:30+01:00
import java.util.*;
import java.math.*;

public class Birthday {
	public String getNext(String date, String[] birthdays) {
		int N = birthdays.length;
		Date[] dates = new Date[N];

		for(int i = 0; i < N; i++) {
			dates[i] = new Date(birthdays[i].split("\\s")[0]);
		}

		Arrays.sort(dates, new Comparator<Date>() {
			public int compare(Date a, Date b) {
				if(a.month == b.month && a.day == b.day) return 0;
				if(a.month != b.month) {
					if(a.month < b.month) return -1;
					else return 1;
				} else {
					if(a.day < b.day) return -1;
					else return 1;
				}
			}
		});
		for(int i = 0; i < N; i++) {
			if(compare(new Date(date), dates[i]) <= 0) {
				return dates[i].month_rep + "/" + dates[i].day_rep;
			}
		}
		return dates[0].month_rep + "/" + dates[0].day_rep;
	}

	public int compare(Date a, Date b) {
		if(a.month == b.month && a.day == b.day) return 0;
		if(a.month != b.month) {
			if(a.month < b.month) return -1;
			else return 1;
		} else {
			if(a.day < b.day) return -1;
			else return 1;
		}
	}

	static class Date {
		int day, month;
		String day_rep, month_rep;
		Date(String str) {
			day = Integer.parseInt(str.substring(3));
			day_rep = str.substring(3);

			month = Integer.parseInt(str.substring(0, 2));
			month_rep = str.substring(0, 2);
		}
	}
}


// Powered by FileEdit