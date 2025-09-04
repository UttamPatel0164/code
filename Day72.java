Sum of Mode
Difficulty: HardAccuracy: 66.48%Submissions: 6K+Points: 8Average Time: 20m
Given an array arr[] of positive integers and an integer k. You have to find the sum of the modes of all the subarrays of size k.
Note: The mode of a subarray is the element that occurs with the highest frequency. If multiple elements have the same highest frequency, the smallest such element is considered the mode.

Examples:

Input: arr[] = [1, 2, 3, 2, 5, 2, 4, 4], k = 3
Output: 13
Explanation: The mode of each k size subarray is [1, 2, 2, 2, 2, 4] and sum of all modes is 13.
Input: arr[] = [1, 2, 1, 3, 5], k = 2
Output: 6
Explanation: The mode of each k size subarray is [1, 1, 1, 3] and sum of all modes is 6.
Constraints:
1 ≤ k ≤ arr.size() ≤105
1 ≤ arr[i] ≤ 105
class Solution {
    class pair{
        int f,v;
        pair(int f,int v){
            this.f=f;
            this.v=v;
        }
    }
    public int sumOfModes(int[] arr, int k) {
        HashMap<Integer,Integer>mp = new HashMap<>();
        PriorityQueue<pair>pq=new PriorityQueue<>((a,b)->{
           if(a.f==b.f)return a.v-b.v;
           return b.f-a.f;
        });
        int n=arr.length,r=0,j=0;
        for(int i=0;i<k;i++){
            mp.put(arr[i],mp.getOrDefault(arr[i],0)+1);
            pq.add(new pair(mp.get(arr[i]),arr[i]));
        }
        for(int i=k;i<n;i++){
            r+=pq.peek().v;
            mp.put(arr[j],mp.getOrDefault(arr[j++],0)-1); //remove
            mp.put(arr[i],mp.getOrDefault(arr[i],0)+1); // add
            pq.add(new pair(mp.get(arr[i]),arr[i])); // add
            while(mp.get(pq.peek().v)!=pq.peek().f) pq.remove(); //remove
        }
        r+=pq.peek().v;
        return r;
    }
}