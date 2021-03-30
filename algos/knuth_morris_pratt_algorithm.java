import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class KnuthMorrisPrattAlgorithm {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string to search for (needle): ");
        String needle = sc.nextLine();
        System.out.println();
        
        System.out.print("Enter the string to scan (haystack): ");
        String haystack = sc.nextLine();
        System.out.println();

        sc.close();
        
        List<Integer> matches = kmpSearch(needle, haystack);
        
        for (Integer x: matches) {
            System.out.println(x);
        }
    }


    public static List<Integer> kmpSearch(String needle, String haystack) {
        List<Integer> matches = new ArrayList<Integer>();
        int j = 0, k = 0;
        int[] needleTable = buildKmpTable(needle);
        
        int S = haystack.length(), N = needle.length();

        while (j < S) {
            if (needle.charAt(k) == haystack.charAt(j)) {
                j++;
                k++;

                if (k == N) {
                    matches.add(j-k);
                    k = needleTable[k-1];
                }
            } else {
                if (k != 0) {
                    k = needleTable[k-1];
                } else {
                    j++;
                }
            }
        }

        return matches;
    }
    
    public static int[] buildKmpTable(String needle) {
        int pos = 1, cnd = 0, N = needle.length();
        int[] table = new int[N];

        table[0] = 0;
        
        while (pos < N) {
            if (needle.charAt(pos) == needle.charAt(cnd)) {
                cnd++;
                table[pos++] = cnd++;
            } else {
                if (cnd != 0) {
                    cnd = table[cnd-1];
                } else {
                    table[pos++] = cnd;
                }
            }
        }
        
        return table;
    }
}
