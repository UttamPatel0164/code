Merge K sorted linked lists
Difficulty: MediumAccuracy: 57.01%Submissions: 115K+Points: 4Average Time: 60m
Given an array arr[] of n sorted linked lists of different sizes. Your task is to merge all these lists into a single sorted linked list and return the head of the merged list.

Examples:

Input:
   
Output: 1 -> 2 -> 3 -> 4 -> 7 -> 8 -> 9
Explanation: The arr[] has 3 sorted linked list of size 3, 3, 1.
1st list: 1 -> 3 -> 7
2nd list: 2 -> 4 -> 8
3rd list: 9
The merged list will be: 
    
Input:
   
Output: 1 -> 3 -> 4 -> 5 -> 6 -> 8
Explanation: The arr[] has 3 sorted linked list of size 2, 1, 3.
1st list: 1 -> 3
2nd list: 8
3rd list: 4 -> 5 -> 6
The merged list will be: 
    /*
class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}
*/

class Solution {
    public Node merge(Node h1,Node h2)
    {
        Node temp=new Node(-1);
        Node ans=temp;
        while(h1!=null && h2!=null)
        {
            if(h1.data<h2.data)
            {
                temp.next=h1;
                h1=h1.next;
            }
            else
            {
                temp.next=h2;
                h2=h2.next;
                
            }
            temp=temp.next;
        }
        if(h1!=null)temp.next=h1;
        if(h2!=null)temp.next=h2;
        return ans.next;
    }
    Node mergeKLists(Node[] a) 
    {
        if (a == null || a.length == 0) return null;
        int n=a.length;
        Node ans=a[0];
        for(int i=1;i<n;i++)
        {
            ans=merge(ans,a[i]);
        }
        return ans;
        
    }
}