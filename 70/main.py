class Solution:
    def climbStairs(self, n: int) -> int:
        if n==1:
            return 1
        elif n==2:
            return 2
        dp=[1,2]
        n-=2
        last1=0
        last2=1
        while n>0:
            dp.append(dp[last1]+dp[last2])
            last1=last2
            last2+=1
            n-=1
        return dp[last2]
    

print(Solution().climbStairs(3))