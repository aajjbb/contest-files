public class FoxAndDoraemon {
	public int minTime(int[] workCost, int splitCost) {
		return 0;
	}

// CUT begin
	static void runTestcase(int __case) {
		switch (__case) {
			// Your custom testcase goes here
			case -1:
				//doTest(workCost, splitCost, expected, __case);
				break;

			case 0: {
				int workCost[] = new int[] {
					1, 2
				};
				int splitCost = 1000;
				int __excepted = 1002;
				doTest(workCost, splitCost, __excepted, __case);
				break;
			}
			case 1: {
				int workCost[] = new int[] {
					3, 6, 9, 12
				};
				int splitCost = 1000;
				int __excepted = 2012;
				doTest(workCost, splitCost, __excepted, __case);
				break;
			}
			case 2: {
				int workCost[] = new int[] {
					1000, 100, 10, 1
				};
				int splitCost = 1;
				int __excepted = 1001;
				doTest(workCost, splitCost, __excepted, __case);
				break;
			}
			case 3: {
				int workCost[] = new int[] {
					1712, 1911, 1703, 1610, 1697, 1612
				};
				int splitCost = 100;
				int __excepted = 2012;
				doTest(workCost, splitCost, __excepted, __case);
				break;
			}
			case 4: {
				int workCost[] = new int[] {
					3000, 3000, 3000, 3000, 3000, 3000, 3000, 3000, 3000, 3000
				};
				int splitCost = 3000;
				int __excepted = 15000;
				doTest(workCost, splitCost, __excepted, __case);
				break;
			}
			case 5: {
				int workCost[] = new int[] {
					58
				};
				int splitCost = 3600;
				int __excepted = 58;
				doTest(workCost, splitCost, __excepted, __case);
				break;
			}
			default: break;
		}
	}

	static void doTest(int[] workCost, int splitCost, int __expected, int caseNo) {
		long startTime = System.currentTimeMillis();
		Throwable exception = null;
		FoxAndDoraemon instance = new FoxAndDoraemon();
		int __result = 0;
		try {
			__result = instance.minTime(workCost, splitCost);
		}
		catch (Throwable e) { exception = e; }
		double elapsed = (System.currentTimeMillis() - startTime) / 1000.0;

		nAll++;
		System.err.print(String.format("  Testcase #%d ... ", caseNo));

		if (exception != null) {
			System.err.println("RUNTIME ERROR!");
			exception.printStackTrace();
		}
		else if (__result == __expected) {
			System.err.println("PASSED! " + String.format("(%.2f seconds)", elapsed));
			nPassed++;
		}
		else {
			System.err.println("FAILED! " + String.format("(%.2f seconds)", elapsed));
			System.err.println("           Expected: " + __expected);
			System.err.println("           Received: " + __result);
		}
	}

	static int nExample = 6;
	static int nAll = 0, nPassed = 0;

	public static void main(String[] args){
		System.err.println("FoxAndDoraemon (500 Points)");
		System.err.println();
		if (args.length == 0)
			for (int i = 0; i < nExample; ++i) runTestcase(i);
		else
			for (int i = 0; i < args.length; ++i) runTestcase(Integer.parseInt(args[i]));
		System.err.println(String.format("%nPassed : %d/%d cases", nPassed, nAll));

		int T = (int)(System.currentTimeMillis() / 1000) - 1382980572;
		double PT = T / 60.0, TT = 75.0;
		System.err.println(String.format("Time   : %d minutes %d secs%nScore  : %.2f points", T / 60, T % 60, 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))));
	}
// CUT end
}
