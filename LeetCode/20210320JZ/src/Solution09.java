import java.util.Deque;
import java.util.Stack;

class Solution09{
    Stack< Integer > stack1;
    Stack < Integer > stack2;

    public Solution09() {
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }

    public void appendTail(int value) {
        stack1.add(value);
    }

    public int deleteHead() {
        if(stack2.isEmpty()){
            if(stack1.isEmpty())
                return -1;
            while(!stack1.isEmpty()){
                stack2.add(stack1.pop());
            }
        }
        return stack2.pop();
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */