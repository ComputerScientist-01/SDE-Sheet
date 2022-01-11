Floyd's Algorithm will be used for an O(n) implementation
aka Hare and Tortoise Algo
```
int slow = nums[0];
int fast = nums[0];
do {
slow = nums[slow];
fast = nums[nums[fast]];
} while (slow != fast);
​
fast = nums[0];
while (slow != fast) {
slow = nums[slow];
fast = nums[fast];
}
return slow;
```