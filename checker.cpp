#include <bits/stdc++.h>
using namespace std;

void sleep(int s){

	clock_t start_t,end_t;

	start_t = clock();
	end_t = clock();

	while((end_t - start_t)/CLOCKS_PER_SEC < s){
		end_t = clock();
	}
}

int main(){
	
	printf(".....");
	sleep(3);
	char x = 8;
	for(int i=0;i<5;i++){
		printf("%c",x);
	}
	printf("#");
}