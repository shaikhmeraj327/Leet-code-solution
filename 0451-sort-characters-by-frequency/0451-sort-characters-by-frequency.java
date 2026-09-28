class Solution {
    public String frequencySort(String s) {
        int[] freq=new int[256];
        int n=s.length();
        for(int i=0;i<n;i++){
            freq[s.charAt(i)]++;
        }
        // maxHeap
        PriorityQueue<Character>pq=new PriorityQueue<>((a,b)->freq[b]-freq[a]);
        for(int i=0;i<256;i++){
            if(freq[i]>0){
                pq.add((char)i);
            }
        }
        StringBuilder sb=new StringBuilder();
        while(!pq.isEmpty()){
            char ch=pq.peek();
            int count=freq[ch];
            pq.remove();
            while(count>0){
                sb.append(ch);
                count--;
            }


        }
        return sb.toString();
    
    }
}