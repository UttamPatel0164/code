Reverse a Doubly Linked List
Difficulty: EasyAccuracy: 70.38%Submissions: 193K+Points: 2Average Time: 15m
You are given the head of a doubly linked list. You have to reverse the doubly linked list and return its head.

Examples:

Input:
   
Output: 5 <-> 4 <-> 3
Explanation: After reversing the given doubly linked list the new list will be 5 <-> 4 <-> 3.
   
Input: 
   
Output: 196 <-> 59 <-> 122 <-> 75
Explanation: After reversing the given doubly linked list the new list will be 196 <-> 59 <-> 122 <-> 75.
   
Constraints:
1 ≤ number of nodes ≤ 106
0 ≤ node->data ≤ 104
/*
class Node {
    int data;
    Node next;
    Node prev;

    Node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}
*/
class Solution {
    public Node reverse(Node head) 
    {
        Node temp=null;
        Node curr=head;
        Node prev=null;
        while(curr!=null)
        {
            temp=curr;
            curr=curr.next;
            temp.prev=temp.next;
            temp.next=prev;
            prev=temp;
            
            
        }
        head=temp;
        return head;
        
    }
}