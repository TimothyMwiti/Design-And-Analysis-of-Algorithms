import java.lang.Math;
import java.lang.Integer;


class MinStack {

    public static void main(String[] args) {
        MinStack stack = new MinStack();
        stack.push(-2);
        stack.push(0);
        stack.push(-3);
        System.out.println(stack.getMin());
        stack.pop();
        System.out.println(stack.top());
        System.out.println(stack.getMin());
    }

    int[] numsStack;
    int[] minStack;
    int currIndex;
    int currMin;

    public MinStack() {
        numsStack = new int[1000];
        minStack = new int[1000];
        currIndex = -1;
        currMin = Integer.MAX_VALUE;
    };

    public void push(int val) {
        if (currIndex == numsStack.length -1) {
            numsStack = expand(numsStack);
            minStack = expand(minStack);
        }

        numsStack[++currIndex] = val;
        currMin = Math.min(currMin, val);
        minStack[currIndex] = currMin;
    }

    public void pop() {
        if (currIndex == -1)
            return;
        currIndex--;
        
        if (currIndex == -1)
            currMin = Integer.MAX_VALUE;
        else
            currMin = minStack[currIndex];
    }

    public int top() {
        return numsStack[currIndex];
    }

    public int getMin() {
        return minStack[currIndex];
    }

    private int[] expand(int[] nums) {
        int currSize = nums.length;
        int nextSize = Math.min(Integer.MAX_VALUE, currSize * 2);

        int[] newNums = new int[nextSize];
        for (int i = 0; i < currSize; i++) {
            newNums[i] = nums[i];
        }

        return newNums;
    }


}
