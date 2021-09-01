#include <stdio.h>
#include <math.h>
int findClosestTwo(int num);
int estatePlanner(int m,int n);
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	//printf("Hello");
	printf("%d",estatePlanner(m,n));
	return 0;
}

int findClosestTwo(int num){
	int i = 0,check;
	while(pow(2,i)<=num){
		check = pow(2,i);
		i++;
	}
	return check;
}

int estatePlanner(int m,int n){
	static int count = 0;
	int size;
	/*if( m == 0 || n == 0){
		return 0;
	}*/
	if(m <= 1 || n <= 1){
		count += m*n;
		return 0;
	}else if(m == n && findClosestTwo(m) == m && findClosestTwo(n) == n){
		count++;
		return 1;
	}
	if(m>n){
		size = findClosestTwo(n);
	}else{
		size = findClosestTwo(m);
	}
	estatePlanner(size,size);
	estatePlanner(m-size,n);
	estatePlanner(size,n-size);
	return count;
}
