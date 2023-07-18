import time
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        self.nums = nums
        self.target = target
        print(self.target)
        output = []
        flag = False
        print(nums[0])
        for ind_i, i in enumerate(nums):
            print(i, "for1")
            
            for ind_j, j in enumerate(nums):
                print(j, "for2")
                if ind_j != ind_i:
                    print(j, "if2")
                    if i + j == target:
                        print("found")
                        output.append(ind_i)
                        output.append(ind_j)
                        flag = True
                        break
                else:
                    continue
                # if flag == True:
                #     break
            
            if flag == True:
                break

        
        return output
    

if __name__ == "__main__":
    start = time.time()
    sol = Solution()
    list = [-3,4,3,342,45,56,56,43,2324,3244,2490]
    targ = 0
    myout = sol.twoSum(list, targ)
    end = time.time()
    print(myout)
    print(end - start)
        
