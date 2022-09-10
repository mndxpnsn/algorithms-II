class Solution {
    public boolean backspaceCompare(String s, String t) {

        char[] charsA = s.toCharArray();
        char[] charsB = t.toCharArray();

        int na = charsA.length;
        int nb = charsB.length;

        int countA = 0;
        int countAT = 0;
        for(int i = na - 1; i >= 0; --i) {
            if(charsA[i] == '#') {
                countA++;
                countAT++;
            }
            else {
                boolean hit = false;
                while(countA > 0 && i >= 0) {
                    while(charsA[i] == '#' && i > 0) {
                        countA++;
                        countAT++;
                        i--;
                    }
                    charsA[i] = '#';
                    countA--;
                    i--;
                    hit = true;
                    countAT++;
                }
                if(hit) {
                    i++;
                }

            }
        }

        int countB = 0;
        int countBT = 0;
        for(int i = nb - 1; i >= 0; --i) {
            if(charsB[i] == '#') {
                countB++;
                countBT++;
            }
            else {
                boolean hit = false;
                while(countB > 0 && i >= 0) {
                    while(charsB[i] == '#' && i > 0) {
                        countB++;
                        countBT++;
                        i--;
                    }
                    charsB[i] = '#';
                    countB--;
                    i--;
                    hit = true;
                    countBT++;
                }
                if(hit) {
                    i++;
                }
            }
        }

        char[] resA = new char[na - countAT];
        char[] resB = new char[nb - countBT];

        int indexA = 0;
        for(int i = 0; i < na; ++i) {
            if(charsA[i] != '#') {
                resA[indexA] = charsA[i];
                indexA++;
            }
        }

        int indexB = 0;
        for(int i = 0; i < nb; ++i) {
            if(charsB[i] != '#') {
                resB[indexB] = charsB[i];
                indexB++;
            }
        }

        if(resA.length != resB.length) {
            return false;
        }

        for(int i = 0; i < resA.length; ++i) {
            if(resA[i] != resB[i]) {
                return false;
            }
        }

        return true;
    }
}