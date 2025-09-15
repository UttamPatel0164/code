Merge Sort for Linked List
Difficulty: MediumAccuracy: 74.76%Submissions: 80K+Points: 4Average Time: 30m
You are given the head of a linked list. You have to sort the given linked list using Merge Sort.

Examples:

Input:
    
Output: 10 -> 20 -> 30 -> 40 -> 50 -> 60
Explanation: After sorting the given linked list, the resultant list will be:
    
Input:
    
Output: 2 -> 5 -> 8 -> 9
Explanation: After sorting the given linked list, the resultant list will be:
    
Constraints:
1 ≤ number of nodes ≤ 105
0 ≤ node->data ≤ 106

/*
class Node {
    int data;
    Node next;

    Node(int key) {
        data = key;
        next = null;
    }
}
*/

class Solution {
    private Node merge(Node l1, Node l2) {
        Node dummy = new Node(0);
        Node tail = dummy;

        while (l1 != null && l2 != null) {
            if (l1.data < l2.data) {
                tail.next = l1;
                l1 = l1.next;
            } else {
                tail.next = l2;
                l2 = l2.next;
            }
            tail = tail.next;
        }


        if (l1 != null) tail.next = l1;
        else tail.next = l2;

        return dummy.next;
    }


    private Node getMiddle(Node head) {
        if (head == null) return head;

        Node slow = head, fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    public Node mergeSort(Node head) {
        if (head == null || head.next == null) return head;

        Node mid = getMiddle(head);
        Node nextOfMid = mid.next;
        mid.next = null;  
        Node left = mergeSort(head);
        Node right = mergeSort(nextOfMid);

        return merge(left, right);
    }
}
