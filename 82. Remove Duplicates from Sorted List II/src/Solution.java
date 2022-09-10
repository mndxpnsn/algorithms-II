import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class ListNode {
      int val;
      ListNode next;
      ListNode() {}
      ListNode(int val) { this.val = val; }
      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 }
class Solution {
    public ListNode deleteDuplicates(ListNode head) {

        HashMap<Integer, Integer> hash = new HashMap<>();

        ListNode track = head;

        // Store frequency of nodes with values val
        while(track != null) {
            Integer freq = hash.get(track.val);
            if(freq == null) {
                hash.put(track.val, 1);
            }
            else if(freq != null) {
                freq++;
                hash.replace(track.val, freq);
            }
            track = track.next;
        }

        List<ListNode> list = new ArrayList<>();

        track = head;

        while(track != null) {
            Integer freq = hash.get(track.val);
            if(freq == 1) {
                list.add(track);
            }
            track = track.next;
        }

        for(int i = 0; i < list.size() - 1; ++i) {
            ListNode elem1 = list.get(i);
            ListNode elem2 = list.get(i + 1);
            elem1.next = elem2;
        }

        if(list.size() != 0) {
            list.get(list.size() - 1).next = null;
        }

        if(list.size() == 0) {
            return null;
        }

        if(list.size() == 1) {
            return list.get(0);
        }

        return list.get(0);
    }
}