class Solution {
    public List<List<Integer>> generate(int numRows) {
        
    List<List<Integer>> retval = new ArrayList<>();

    retval.add(new ArrayList(List.of(1)));
    if(numRows == 1)
      return retval;

    retval.add(new ArrayList(List.of(1,1)));

    if(numRows == 2)
      return retval;


    for ( int i = 3; i <= numRows; i++)
    {
      List<Integer> currentArray = new ArrayList<>();
      currentArray.add(1);
      for ( int j = 1; j < i-1; j++)
      {

        currentArray.add( retval.get(i-2).get(j-1) +     retval.get(i-2).get(j)        );

      }
      currentArray.add(1);
      retval.add(currentArray);

    }
    return retval;

    }
}