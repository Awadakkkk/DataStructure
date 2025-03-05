int pivotIndex(int* nums, int numsSize) {
    int i;
    int sum=0;
    for(i = 0;i<numsSize;i++){
        sum += nums[i];
    }
    int left_sum = 0;
    for(i = 0;left_sum<sum/2;i++){//1������Խ����� 
        if(left_sum+nums[i+1]=sum/2){
            return i;
        }
        left_sum += nums[i];
    }
    return -1;   
}
//2���߼��������� 
//������ͼͨ��left_sum + nums[i+1] == sum/2 ���ж���������
//����ȷ������Ӧ�����������Ҳ�ĺͣ���
//left_sum == sum - left_sum - nums[1]
//���������ʹ������ܺ�sumΪ�������򲻴���������������Ŧ����
//������δ������һ�����ֱ�ӽ���ѭ�����ܵ��´����ж�
//3��ѭ���������Ͻ���ѭ����ֹ����left_sum < sum/2 ���ܵ���
//��ǰ�˳���������ܵĽ⡣���磬���ܺ�Ϊ0ʱ������Ԫ�صĺ�Ϊ0
//��ѭ�����ܲ���ִ��
//4������˳�����
//�����ڼ��i�Ƿ�Ϊ��Ŧ�����󣬲Ž�nums[i]����left_num��
//�⵼�¼�����i+1λ�õĺͣ����ǵ�ǰ����i����ȷ����


//�������޸ĺ����ȷ����
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
