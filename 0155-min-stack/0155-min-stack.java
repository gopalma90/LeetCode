class StackMappings
{
    Integer value;
    Integer minValue;

    public StackMappings(Integer val, Integer minval)
    {
        this.value = val;
        this.minValue = minval;
    }

    public Integer getValue ()
    {
        return value;
    }

    public Integer getMinValue ()
    {
        return minValue;
    }
}
class MinStack {

    Stack<StackMappings> minStack;
    Integer currMinVal ;

    public MinStack() {
         minStack = new Stack<StackMappings>();
         currMinVal = Integer.MAX_VALUE;
    }
    
    public void push(int value) {
        if(minStack.empty())
        {
            currMinVal = Integer.MAX_VALUE;
        }
        if(currMinVal > value)
            currMinVal = value;
        
        minStack.push(new StackMappings(value, currMinVal));
    }
    
    public void pop() {
       if(!minStack.empty() )
      {
        minStack.pop();
        if(!minStack.empty())
        {
          StackMappings temp = topNode();
          currMinVal = temp.getMinValue();
        }
      }
        
    }
    
    public int top() {
        return minStack.peek().getValue().intValue();
    }
    
    private StackMappings topNode()
    {
        return minStack.peek();
    }

    public int getMin() {
      
        return topNode().getMinValue().intValue();
        
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(value);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */