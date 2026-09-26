class Solution {
    public void setZeroes(int[][] matrix) {
        int m=matrix.length;
        int n=matrix[0].length;
        ArrayList<Integer>row=new ArrayList<>();
        ArrayList<Integer>col=new ArrayList<>();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row.add(i);
                    col.add(j);
                }
            }
        }
        // making each row 0
        int m1=row.size();
        for(int i=0;i<m1;i++){
            for(int j=0;j<n;j++){
                int r=row.get(i);
                matrix[r][j]=0;
            }
        }
        // making each col 0
        int n1=col.size();
        for(int j=0;j<n1;j++){
            for(int i=0;i<m;i++){
                matrix[i][col.get(j)]=0;
            }
        }
    }
}