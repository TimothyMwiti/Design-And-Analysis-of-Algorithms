class Solution {
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.pushDominoes("RR.L"));
        System.out.println(solution.pushDominoes(".L.R...LR..L.."));

        System.out.println(solution.pushDominoesFaster("RR.L"));
        System.out.println(solution.pushDominoesFaster(".L.R...LR..L.."));

    }

    public String pushDominoes(String dominoes) {
        return new String(pushDominoes(dominoes.toCharArray()));
    }

    public String pushDominoesFaster(String dominoes) {
        int n = dominoes.length();
        if (n <= 1)
            return dominoes;

        int[] left = new int[n], right = new int[n];

        // scan left
        int curDist = -1;

        for (int i = n-1; i >=0; i--) {
            if (dominoes.charAt(i) == 'L') {
                curDist = 1;
            } else if (dominoes.charAt(i) == 'R') {
                curDist = -1;
            } else {
                if (curDist == -1)
                    left[i] = -1;
                else if (curDist > 0){
                    left[i] = curDist;
                    curDist++;
                }
            }
        }

        curDist = -1;
        for (int i = 0; i < n; i++) {
            if (dominoes.charAt(i) == 'R') {
               curDist = 1;
            } else if (dominoes.charAt(i) == 'L') {
                curDist = -1;
            } else {
                if (curDist == -1)
                    right[i] = -1;
                else if (curDist > 0) {
                    right[i] = curDist;
                    curDist++;
                }
            }
        }

        char[] newStr = new char[n];

        for (int i = 0; i < n; i++) {
            if (dominoes.charAt(i) == 'R' || dominoes.charAt(i) == 'L')
                newStr[i] = dominoes.charAt(i);
            else if (left[i] == -1 && right[i] != -1)
                newStr[i] = 'R';
            else if (left[i] != -1 && right[i] == -1)
                newStr[i] = 'L';
            else if (left[i] > right[i])
                newStr[i] = 'R';
            else if (right[i] > left[i])
                newStr[i] = 'L';
            else
                newStr[i] = '.';
        }


        return new String(newStr);
    }

    public char[] pushDominoes(char[] dominoes) {
        int n = dominoes.length;

        if (n <= 1)
            return dominoes;
    
        boolean hasChanged = false;
        boolean prevWasPushed = false;

        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'L' || dominoes[i] == 'R') {
                prevWasPushed = false;
                continue;
            }
            
            boolean forceFromLeft = i > 0 && dominoes[i-1] == 'R' && !prevWasPushed;
            boolean forceFromRight = i < dominoes.length -1 && dominoes[i+1] == 'L';

            if (forceFromLeft && !forceFromRight) {
                dominoes[i] = 'R';
                prevWasPushed = true;
                hasChanged = true;
            } else if (!forceFromLeft && forceFromRight) {
                dominoes[i] = 'L';
                prevWasPushed = true;
                hasChanged = true;
            } else {
                prevWasPushed = false;
            }

        }


        if (hasChanged)
            return pushDominoes(dominoes);

        else
            return dominoes;
    }
}
