#include <stdio.h>
#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return 0;
    }

    int* result = (int*)malloc((numsSize - k + 1) * sizeof(int));
    int* dq = (int*)malloc(numsSize * sizeof(int)); // stores indices
    int front = 0, rear = -1;
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        // Remove indices outside the current window
        if (front <= rear && dq[front] <= i - k)
            front++;

        // Remove indices whose corresponding values are less than nums[i]
        while (front <= rear && nums[dq[rear]] < nums[i])
            rear--;

        dq[++rear] = i;

        // Add to result only when first full window is seen
        if (i >= k - 1)
            result[(*returnSize)++] = nums[dq[front]];
    }

    free(dq); // clean up
    return result;
}
int main() {
    int nums[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    int returnSize;

    int* result = maxSlidingWindow(nums, sizeof(nums) / sizeof(nums[0]), k, &returnSize);

    printf("Sliding window maximums: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result); // free the result array
    return 0;
}
