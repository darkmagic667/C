#include <stdio.h>
#include <math.h>

int main(){
	int n;
	scanf("%d",&n);
		
	for(int i = 2;i<sqrt(n);i++){   // O(sqrt(n)) loop sqrt(n) times
		if(n%i == 0){ 
			printf("0");
			return 0;
		}
	}
	printf("1");
	return 0;
}