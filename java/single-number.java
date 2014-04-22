public class Solution {
    public int singleNumber(int[] A) {
        int XOR = 0;
        for(int i: A)
            XOR ^= i;
        return XOR;
    }
}
