//字符串模式匹配算法KMP
//定义两个指针i,j:
//i表示当前正在处理的子串的末尾，j表示当前最长相等前缀的末尾
//i从 1开始遍历，j初始值为 0 

//定义方式：next[0]=0 
void buildNext(int m, int* next, char* pattern){
	int j = 0;
	next[0] = 0;//初始条件 
	for(int i = 1; i < m; i++){
		//不匹配时回溯 j 
		while(j > 0 && pattern[i] != pattern[j]){
			j = next[j-1];
		}
		//匹配时增加 j 
		if(pattern[i] == pattern[j]){
			j++;
		}
		//记录 next[i] 
		next[i] = j;
	} 	
} 


//定义方式：next[0]=-1

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
//这种定义方式简化回溯时的边界条件：当 j = -1 时，可以统一处理模式串
//从头开始匹配的情况，避免额外的 j>0 的判断
//其次，这种匹配工程中，主串指针i和模式串指针j的移动逻辑更对称 










