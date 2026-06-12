class Solution {
    public int[] plusOne(int[] actDigits) {
     
         int []digits = new int[actDigits.length+1];
    digits[0] = 0;
    System.arraycopy(actDigits, 0, digits, 1, actDigits.length);
    int size = digits.length;


    if (digits[size - 1] < 9)
    {
      digits[size - 1] = digits[size - 1] + 1;
    }
    else
    {
      digits[size - 1] = 0;
      incrementPos(size - 2, digits);
    }

    if(digits[0] == 0)
    {
      int []newarr = new int[digits.length-1];
      System.arraycopy(digits, 1, newarr, 0, digits.length-1);
      return newarr;

    }
    else {
      return digits;
    }

    }


  private static void incrementPos(int pos, int []digits)
  {
    if(digits[pos] < 9 )
    {
      digits[pos] = digits[pos] + 1;
    }
    else {
      digits[pos] = 0;
      incrementPos(pos - 1, digits);
    }
  }
}