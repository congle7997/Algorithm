package test;

import java.util.Scanner;

public class Test {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		char a[] = null;

		if ((s.charAt(0) - 48) < 6) {
			a = new char[s.length() - 1];
			for (int i = 0; i < s.length() - 1; i++) {
				a[i] = '8';
			}
			a.toString();
			System.out.println(a);
		} else if (s.charAt(0) - 48 > 8) {
			a = new char[s.length()];
			for (int i = 0; i < s.length(); i++) {
				a[i] = '8';
			}
			a.toString();
			System.out.println(a);
		} else if ((s.charAt(0) - 48) == 7) {
			a = new char[s.length()];
			a[0] = '6';
			for (int i = 1; i < s.length(); i++) {
				a[i] = '8';
			}
			a.toString();
			System.out.println(a);
		} else if ((s.charAt(0) - 48) == 6 || (s.charAt(0) - 48) == 8) {
			int flag = 0;
			char numberFlag = '0';
			char numberPre[] = null;
			char numberRest = '0';

			int count = 0;
			for (int i = 0; i < s.length(); i++) {
				if (s.charAt(i) == '6' || s.charAt(i) == '8') {
					count++;
				}
			}
			if (count == s.length()) {
				System.out.println(s);
			} else {
				for (int k = 1; k < s.length(); k++) {
					if ((s.charAt(k) - 48) >= 6) {
						if (s.substring(0, k + 1).contains("7")) {
							numberPre = s.substring(0, s.indexOf('7')).toCharArray();
							flag = s.indexOf('7');
							numberFlag = '6';
							numberRest = '8';
							createNumber(numberPre, flag, numberFlag, numberRest, s.length());
						} else if (s.substring(0, k + 1).contains("9")) {
							numberPre = s.substring(0, s.indexOf('9')).toCharArray();
							flag = s.indexOf('9');
							numberFlag = '8';
							numberRest = '8';
							createNumber(numberPre, flag, numberFlag, numberRest, s.length());
						} else if (s.charAt(k) == '6' || s.charAt(k) == '8') {
							continue;
						}
						break;
					} else if ((s.charAt(k) - 48) < 6) {
						if (s.substring(0, k + 1).contains("8")) {
							numberPre = s.substring(0, s.substring(0, k+1).lastIndexOf('8')).toCharArray();
							flag = s.substring(0, k + 1).lastIndexOf('8');
							numberFlag = '6';
							numberRest = '8';
							createNumber(numberPre, flag, numberFlag, numberRest, s.length());
						}else {
							a = new char[s.length() - 1];
							for (int i = 0; i < s.length() - 1; i++) {
								a[i] = '8';
							}
							a.toString();
							System.out.println(a);
						}
						break;
					}
				}
			}
		}
	}

	public static void createNumber(char numberPre[], int flag, char numberFlag, char numberRest, int length) {
		char a[] = new char[length];
		for (int i = 0; i < flag; i++) {
			a[i] = numberPre[i];
		}
		a[flag] = numberFlag;
		for (int i = flag + 1; i < length; i++) {
			a[i] = numberRest;
		}

		a.toString();
		System.out.println(a);
	}
}
