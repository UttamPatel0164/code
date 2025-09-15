Linked List Group Reverse
Difficulty: HardAccuracy: 57.08%Submissions: 260K+Points: 8Average Time: 30m
You are given the head of a Singly linked list. You have to reverse every k node in the linked list and return the head of the modified list.
Note: If the number of nodes is not a multiple of k then the left-out nodes at the end, should be considered as a group and must be reversed.

Examples:

Input: k = 2,
   
Output: 2 -> 1 -> 4 -> 3 -> 6 -> 5
Explanation: Linked List is reversed in a group of size k = 2.
   
Input: k = 4,
   
Output: 4 -> 3 -> 2 -> 1 -> 6 -> 5
Explanation: Linked List is reversed in a group of size k = 4.
   
Constraints:
1 ≤ size of linked list ≤ 105
0 ≤ node->data ≤ 106
1 ≤ k ≤ size of linked list 
Expected Complexities
/*node class of the linked list
class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}

*/

class Solution {
    public static Node reverseKGroup(Node head, int k) {
        // code here
         Node curr=head, prev=null;
        while(curr!=null){
          Node nth=findNth(curr,k);
          if(nth==null){
              Node rev= reverseList(curr);
              if(prev!=null) prev.next=rev;
              else return rev;
              break;
          }
          Node nthNext=nth.next;
          nth.next=null;
          Node rhead= reverseList(curr);
          if(curr==head) head=rhead;
          else prev.next=rhead;
          prev=curr;
          curr=nthNext;
        }
        return head;
    }
    public static Node findNth(Node curr, int n){
        for(int i=0;i<n-1;i++){
            if(curr==null) return null;
            curr=curr.next;
        }
        return curr;
    }
    public static Node reverseList(Node curr){
        Node prev=null,next=null;
        while(curr!=null){
            next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
}