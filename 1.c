/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    assert(nums);
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] != target)continue;
            int* data = calloc(2, sizeof(int));
            data[0] = i;
            data[1] = j;
            *returnSize = 2;
            return data;
        }
    }
    *returnSize = 0;
    return  NULL;
}