//�ַ���ģʽƥ���㷨KMP
//��������ָ��i,j:
//i��ʾ��ǰ���ڴ�����Ӵ���ĩβ��j��ʾ��ǰ����ǰ׺��ĩβ
//i�� 1��ʼ������j��ʼֵΪ 0 

//���巽ʽ��next[0]=0 
void buildNext(int m, int* next, char* pattern){
	int j = 0;
	next[0] = 0;//��ʼ���� 
	for(int i = 1; i < m; i++){
		//��ƥ��ʱ���� j 
		while(j > 0 && pattern[i] != pattern[j]){
			j = next[j-1];
		}
		//ƥ��ʱ���� j 
		if(pattern[i] == pattern[j]){
			j++;
		}
		//��¼ next[i] 
		next[i] = j;
	} 	
} 


//���巽ʽ��next[0]=-1

void buildNextplus(int m, int *next[], char* pattern){
	int j = -1;
	next[0] = -1;
	for(int i = 1; i < m; i++){
		while(j>=0 && pattern[i] != pattern[j+1]){
			j = next[j];
		}
		if (pattern[i] == pattern[j]){
			j++;
		}
		next[i] = j;
	}
}
//���ֶ��巽ʽ�򻯻���ʱ�ı߽��������� j = -1 ʱ������ͳһ����ģʽ��
//��ͷ��ʼƥ���������������� j>0 ���ж�
//��Σ�����ƥ�乤���У�����ָ��i��ģʽ��ָ��j���ƶ��߼����Գ� 










