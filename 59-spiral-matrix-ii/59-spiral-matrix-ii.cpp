class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
	{
        vector<vector<int>> matrix( n , vector<int> (n));
        int rmin=0;
        int rmax=n-1;
        int cmin=0;
        int cmax=n-1;
        int value = 1;
        int totalelements=(n*n);
        int count=0;
       
        
        while(count<totalelements)
	    {
			 //top
			for(int c=cmin;c<=cmax && count<totalelements;c++)
			{
				count++;
            	matrix[rmin][c]=value++;
            }
			rmin++;
      
			//right
			for(int r=rmin;r<=rmax && count<totalelements;r++)
			{
				count++;
            	matrix[r][cmax]=value++;
        	}
        	cmax--;
      
        	//bottom
        	for(int c=cmax;c>=cmin && count<totalelements;c--)
			{
                count++;
            	matrix[rmax][c]=value++;
        	}
        	rmax--;
     
        	//left
            for(int r=rmax;r>=rmin && count<totalelements;r--)
			{
                count++;
            	matrix[r][cmin]=value++;
        	}
          	cmin++;
        }
        return matrix;
    }
};