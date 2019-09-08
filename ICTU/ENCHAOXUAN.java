package test;

import java.util.Scanner;

public class Test {

	public static void main(String[] args) {
		long a[] = new long[10000];
		for (int k = 0; k <= 10; k++) {
			a[k] = k;
			//System.out.println(a[k]);
		}
		for (int k = 11; k <= 100; k++) {
			long preNumber = a[k-1];
			String strPreNumber = String.valueOf(preNumber);

			int firstException = strPreNumber.charAt(0) - 48;
			int restException = strPreNumber.charAt(1) - 48;

			int firstNumber = 0;
			int restNumber = 0;
			String restNumberComplete = "";

			if ((firstException) < 9) {
				firstNumber = firstException + 1;
			} else {
				firstNumber = firstException + 1;
				while (!checkFirstNumber(firstNumber, firstException, restException)) {
					firstNumber += 1;
				}
			}

			for (int i = 0; i <= 9; i++) {
				if (i != firstException && i != restException) {
					restNumber = i;
					break;
				}
			}
			for (int i = 1; i < strPreNumber.length(); i++) {
				restNumberComplete += restNumber;
			}

			long numberOK = Long.parseLong(firstNumber + restNumberComplete);

			a[k] = numberOK;
			//System.out.println(a[k]);
		}

		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int k = 0; k < t; k++) {
			int x = sc.nextInt();
			System.out.println(a[x]);
		}


	}

	public static boolean checkFirstNumber(int firstNumber, int firstException, int restException) {
		String strFirstNumber = String.valueOf(firstNumber);
		String strFirstException = String.valueOf(firstException);
		String strRestException = String.valueOf(restException);

		if (strFirstNumber.contains(strFirstException) || strFirstNumber.contains(strRestException)) {
			return false;
		}

		return true;
	}
}
