import static java.lang.Math.abs;

class Solution {
    public double largestTriangleArea(int[][] points) {
      int size  = points.length;
      double maxArea = 0;
      for(int i = 0; i < size-2; i++)
      {
        for ( int j = i+1; j< size-1; j++)
        {
          for( int k = j+1; k < size; k++ )
          {
            double currArea = 0.5* abs(
                ( points[i][0] * (points[j][1]-points[k][1]) )  + 
                ( points[j][0] * (points[k][1]-points[i][1]) )  + 
                ( points[k][0] * (points[i][1]-points[j][1]) ) );
            
            if(currArea > maxArea )
              maxArea = currArea;
          }
        }
      }
      return maxArea;
    }


}