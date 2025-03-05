int pivotIndex(int* nums, int numsSize) {
    int i;
    int sum=0;
    for(i = 0;i<numsSize;i++){
        sum += nums[i];
    }
    int left_sum = 0;
    for(i = 0;left_sum<sum/2;i++){//1、数组越界访问 
        if(left_sum+nums[i+1]=sum/2){
            return i;
        }
        left_sum += nums[i];
    }
    return -1;   
}
//2、逻辑条件错误 
//代码试图通过left_sum + nums[i+1] == sum/2 来判断枢轴索引
//但正确的条件应该是左侧等于右侧的和，即
//left_sum == sum - left_sum - nums[1]
//忽略奇数和处理：若总和sum为奇数，则不存在满足条件的枢纽索引
//但代码未处理这一情况，直接进入循环可能导致错误判断
//3、循环条件不严谨，循环终止条件left_sum < sum/2 可能导致
//提前退出，错过可能的解。例如，当总和为0时，所有元素的和为0
//但循环可能不会执行
//4、更新顺序错误
//代码在检查i是否为枢纽索引后，才将nums[i]加入left_num，
//这导致检查的是i+1位置的和，而非当前索引i的正确条件


//以下是修改后的正确代码
int pivotIndex(int* nums, int numsSize) {
    int total = 0;
    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
    }
    
    int left_sum = 0;
    for (int i = 0; i < numsSize; i++) {
        if (left_sum == total - left_sum - nums[i]) {
            return i;
        }
        left_sum += nums[i];
    }
    return -1;
} 
