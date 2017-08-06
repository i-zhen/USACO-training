/*
    ID: silentf1
    LANG: JAVA
    PROG: wormhole
 */

import java.io.*;
import java.util.Scanner;

public class wormhole {
    private static int n;
    private static int[][] hole = new int[12][2];
    private static int[] nextRight = new int[12];
    private static int[] partner = new int[12];

    private static boolean cycleExists(){
        for (int i = 0; i < n; i++){
            int pos = i;
            for(int j = 0; j < n; j++){
                pos = nextRight[partner[pos]];
                if(pos == -1) break;
            }
            if(pos != -1) return true;
        }
        return false;
    }

    private static int match(){
        int i, total = 0;

        for(i = 0; i < n; i++){
            if(partner[i] == -1) break;
        }

        if(i >= n){
            if(cycleExists()) return 1;
            return 0;
        }

        for(int j = i + 1; j < n; j++)
            if(partner[j] == -1){
                partner[i] = j;
                partner[j] = i;
                total += match();
                partner[i] = partner[j] = -1;
            }

        return total;
    }

    public static void main (String[] args) throws IOException{
        Scanner in = new Scanner(new File("wormhole.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("wormhole.out")));
        n = in.nextInt();

        for(int i = 0; i < n; i++){
            hole[i][0] = in.nextInt();
            hole[i][1] = in.nextInt();
            nextRight[i] = -1;
            partner[i] = -1;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(hole[i][0] < hole[j][0] && hole[i][1] == hole[j][1]){
                    if(nextRight[i] == -1 ||
                            hole[j][0] - hole[i][0] < hole[nextRight[i]][0] - hole[i][0])
                        nextRight[i] = j;
                }
            }
        }

        out.println(match());
        out.close();
    }
}
