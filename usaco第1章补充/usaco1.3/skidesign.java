/*
    ID: silentf1
    LANG: JAVA
    PROG: skidesign
 */

import java.io.*;
import java.util.Scanner;

public class skidesign {
    private static int n;
    private static int[] seg = {0, 17};
    private static int ans = Integer.MAX_VALUE;
    private static int[] mount = new int[1000];

    public static void main (String[] args) throws IOException{
        Scanner in = new Scanner(new File("skidesign.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("skidesign.out")));
        n = in.nextInt();

        for(int i = 0; i < n; i++){
            mount[i] = in.nextInt();
        }

        for (int temp; seg[1] <= 100; seg[0]++, seg[1]++) {
            temp = 0;
            for (int i = 0; i < n; i++){
                if(mount[i] > seg[1]){
                    temp += (mount[i] - seg[1]) * (mount[i] - seg[1]);
                } else if (mount[i] < seg[0]){
                    temp += (mount[i] - seg[0]) * (mount[i] - seg[0]);
                }
            }
            ans = Math.min(temp, ans);
        }

        out.println(ans);
        out.close();
    }
}
