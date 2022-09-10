import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

class Solution {

    public boolean isAnagram(String s, String p, HashMap<Character, Integer> hash2, HashSet<Character> hashSet, int[] newIndex) {

        char[] charsS = s.toCharArray();
        char[] charsP = p.toCharArray();

        int ns = charsS.length;
        int nt = charsP.length;

        if(ns != nt) {
            return false;
        }

        HashMap<Character, Integer> hash1 = new HashMap<>();

        int index = 0;
        for(var c : charsS) {
            if(!hashSet.contains(c)) {
                newIndex[0] = index;
                return false;
            }
            index++;
            Integer num = hash1.get(c);
            if(num == null) {
                hash1.put(c, 0);
            }
            else if(num != null) {
                hash1.replace(c, num + 1);
            }
        }

        for(var c : hashSet) {
            Integer num1 = hash1.get(c);
            Integer num2 = hash2.get(c);
            if(num1 == null || num2 == null || !num1.equals(num2)) {
                return false;
            }
        }

        return true;
    }

    HashMap<Character, Integer> initHashMap(String p) {
        HashMap<Character, Integer> hash = new HashMap<>();

        char[] charsP = p.toCharArray();

        for(var c : charsP) {
            Integer num = hash.get(c);
            if(num == null) {
                hash.put(c, 0);
            }
            else if(num != null) {
                hash.replace(c, num + 1);
            }
        }

        return hash;
    }

    HashSet<Character> initHashSet(String p) {
        HashSet<Character> hashSet = new HashSet<>();

        char[] charsP = p.toCharArray();

        for(var c : charsP) {
            hashSet.add(c);
        }

        return hashSet;
    }

    public List<Integer> findAnagrams(String s, String p) {

        List<Integer> list = new ArrayList<>();

        // Get map and set for storing chars in anagram
        HashMap<Character, Integer> hash = initHashMap(p);
        HashSet<Character> hashSet = initHashSet(p);

        int lenP = p.length();
        int lenS = s.length();

        // Compute starting indices of all anagrams
        for(int i = 0; i + lenP <= lenS; ++i) {
            int[] newIndex = new int[1];
            String substr = s.substring(i, i + lenP);
            boolean isA = isAnagram(substr, p, hash, hashSet, newIndex);
            if(isA) {
                // Check if neighboring start index is also anagram
                while(i + lenP < lenS && s.charAt(i) == s.charAt(i + lenP)) {
                    list.add(i);
                    i++;
                }
                // Add start index to result list
                list.add(i);
                i++;
            }
            // If not an anagram set i to next index with char in p
            if(!isA && newIndex[0] > i) {
                i = newIndex[0] + 1;
            }
        }

        return list;
    }
}