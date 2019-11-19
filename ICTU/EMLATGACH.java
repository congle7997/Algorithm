package test;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Test {
	public static BigInteger fibo(int n) {
		BigInteger a[] = new BigInteger[109];
		
		a[0] = new BigInteger("1");
		a[1] = new BigInteger("1");
		
		for (int i = 2; i <= n; i++) {
			a[i] = new BigInteger("0");
			a[i] = a[i - 1].add(a[i - 2]);
		}
		
		return a[n];
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int T;
		T = sc.nextInt();
		
		for (int i = 0; i < T; i++) {
			int n;
			n = sc.nextInt();
			
			String s = fibo(n).toString();
			System.out.println(s);
		}
		
	}
}
