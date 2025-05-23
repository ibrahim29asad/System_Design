# Given an array of numbers and an integer ‘k’, rotate the array by ‘k’ places to the left.
# The following table shows the expected result for given input values:
# Input Values
	
# Expected Result

# edge case 
# if is empty nums return []
# if is length size 1 nums return nums
# if k % lenght(nums) = 0 nums

# Nums = [1, 2, 3] and k=1	
# [2, 3, 1]
# n - 1 placements

# Nums = [1, 2, 3] and k=2
# [3, 1, 2]
# n - 2 placemets


# Nums = [1, 2, 3] and k= 3
# [1, 2, 3]


# Nums = [1, 2, 3] and k=4
# [2, 3, 1]
 
# cycle go to the left while you incremtn upto k 

# time(n * k//n) n is the length of nums and k is the rotations
# Space O(1)

class Test:
    def RotateList(self, nums, k):
        
        len_nums = len(nums)
        if len_nums <= 1:
            return nums
        if len_nums%k == 0:
            return nums
        if k == 0:
            return nums
            
        # Nums = [1, 2, 3] and k=2
        # [3, 1, 2]    
        # I is placement 
        # let focus on moving 1
        # [2, 3, 1]
        
        # 1, i = 0 - 1 =
        # 2, i = 1 - 1 = 0
        # 3, i = 2 - 1 = 1 
        
        # 
        # number of rotations i need to make k // len(nums)
        # i have to focus on getting the next value
        k = k // len(nums)
        # if k is 5 i roate by 2 
        # 3 1 2

        # 1 2 3 
        # temp = 1
        # i = 3
        # nums[i] = 3
        # 2, 3, 3
        # len_nums-1 = 2
        # nums[len_nums-1] = temp
        # 2, 3, 1 
        for n in range(k):
            temp = nums[0]
            i = 0
            while i < len_nums-1: 
                nums[i] = nums[i+1]
                i += 1
            nums[len_nums-1] = temp
        # Space is Constant since im not adding any new DS
        # Time is k rotation * n rotations by n length of 
                 
        return nums

def __init__(self):
    print("Hello World")
    nums = [1, 2, 3]
    k = 2
    new_nums = self.RotateList(nums, k)
    print(new_nums)