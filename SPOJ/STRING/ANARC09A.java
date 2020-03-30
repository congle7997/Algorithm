package test;

import java.io.IOException;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class Main {
	public static void standardize(StringBuilder sb) {
		int i = sb.indexOf("{");
		int k = i + 1;
		while (i < sb.length()) {
			if (sb.charAt(i) == '{') {
				while (k < sb.length()) {
					if (sb.charAt(k) == '}') {
						sb.deleteCharAt(k);
						sb.deleteCharAt(i);
						// Khi không tìm thấy "{" nó sẽ trả ra -1 
						// và charAt(-1) gây ra lỗi
						if (sb.indexOf("{") != -1) {
							i = sb.indexOf("{") - 1;
							k = i + 1;
						}
						break;
					}
					k++;
				}
			}
			i++;
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int t = 0;
		while (true) {
			String s = sc.nextLine();
			if (s.contains("-")) {
				break;
			}

			StringBuilder sb = new StringBuilder(s);
			while (sb.indexOf(" ") != -1) {
				sb.deleteCharAt(sb.indexOf(" "));
			}
			
			if (sb.length() == 0) {
				System.out.println(0);
			} else {
				if (sb.indexOf("{") != -1) {
					standardize(sb);
				}
	
				
				int res = 0;
				while (true) {
					if (sb.indexOf("{") == -1 || sb.indexOf("}") == -1) {
						res += sb.length() / 2;
						break;
					} else {	
						sb.replace(0, 1, "{");
						standardize(sb);
						res += 1;
					}
				}
				
				System.out.println(++t + ". " + res);
			}	
		}	
	}
}
