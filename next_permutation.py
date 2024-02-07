def nextPermutation(nums):
    for i in range(len(nums)):
        if nums[i] < nums[i+1] or i<len(nums)-1:
            break
        else:
            return nums[::-1]
            
    min_ind = i+1
    for j in range(i+1, len(nums)):
        if nums[j] < nums[min_ind]:
            min_ind = j
            nums[min_ind], nums[i] = nums[i], nums[min_ind]
    nums = nums[0:i]+nums[i+1::-1]
    return nums
    
nums = [2,1,4,5,6]
print(nextPermutation(nums))