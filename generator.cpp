#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int toInt(char x[]){

	int len = strlen(x);
	int ret = 0;
	for(int i=0;i<len;i++){
		ret *= 10;
		ret += x[i]-48;
	}

	return ret;
}

int main(int argc, char *argv[ ]){

	int t = toInt(argv[1]);

	if(t == 1){ // T = 3 e N = 5 e {x,y,z} E [-30,30]

		cout << 3 << endl;
		int tc = 3;
		while(tc--){
			int n = 5;
			cout << n << endl;
			for(int i=0;i<n;i++){
				for(int j=0;j<3;j++){
					int val = uniform_int_distribution<int>(-30,30)(rng);
					cout << val;
					if(j < 2) cout << " ";
					else cout << endl;
				}
			}
		}
	}
	else if(t == 2){ // T = 10000 e N = 100 e {x,y,z} E [-10000, 10000]
		int tc = 10000;
		cout << tc << endl;
		while(tc--){
			int n = 100;
			cout << n << endl;
			for(int i=0;i<n;i++){
				for(int j=0;j<3;j++){
					int val = uniform_int_distribution<int>(-10000,10000)(rng);
					cout << val;
					if(j < 2) cout << " ";
					else cout << endl;
				}
			}
		}
	}
	else{ // aleatorio
		int tc = uniform_int_distribution<int>(1,100)(rng);
		cout << tc << endl;
		while(tc--){
			int n = uniform_int_distribution<int>(1,100)(rng);
			cout << n << endl;
			for(int i=0;i<n;i++){
				for(int j=0;j<3;j++){
					int val = uniform_int_distribution<int>(-10000,10000)(rng);
					cout << val;
					if(j < 2) cout << " ";
					else cout << endl;
				}
			}
		}
	}
}