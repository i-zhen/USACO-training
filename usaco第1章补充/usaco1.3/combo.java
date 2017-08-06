/*
    ID: silentf1
    LANG: JAVA
    PROG: combo
 */

import java.io.*;
import java.util.Scanner;

public class combo {
    private static int n;
    private static int comb = 0;
    private static int[] john = new int[3];
    private static int[] dial = new int[3];

    private static boolean checkDis(int a, int b){
        if (Math.abs(a - b) <= 2 || Math.abs(a - b) >= n - 2) return true;
        return false;
    }

    private static boolean check(int i, int j, int k, int[] target){
        if(checkDis(i, target[0]) && checkDis(j, target[1]) && checkDis(k, target[2]))
            return true;
        return false;
    }

    public static void main (String[] args) throws IOException{
        Scanner in = new Scanner(new File("combo.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("combo.out")));
        n = in.nextInt();
        john[0] = in.nextInt();
        john[1] = in.nextInt();
        john[2] = in.nextInt();
        dial[0] = in.nextInt();
        dial[1] = in.nextInt();
        dial[2] = in.nextInt();
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                for(int k = 1; k <= n; k++){
                    if(check(i, j, k, john) || check(i, j, k, dial))
                        comb++;
                }
            }
        }
        out.println(comb);
        out.close();
    }
}
