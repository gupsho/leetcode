class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        xor = 0
        for i in A:
            xor = xor^i
        return xor
