#include <bits/stdc++.h>
using namespace std;

struct point{
	int x,y,z,id;
};

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	while(n != 0){

		vector<point> g;
		for(int i=0;i<n;i++){
			int x,y,z;
			cin >> x >> y >> z;
			point aux;
			aux.x = x;
			aux.y = y;
			aux.z = z;
			aux.id = i+1;
			g.push_back(aux);
		}

		point me;
		me.x = 0;
		me.y = 0;
		me.z = 0;

		for(int i=0;i<n;i++){
			double mini = 1e9 + 7;
			for(int j=0;j<n;j++){
				if(g[j].id == -1) continue;

				double dist = (g[j].x - me.x)*(g[j].x - me.x);
				dist += (g[j].y - me.y)*(g[j].y - me.y);
				dist += (g[j].z - me.z)*(g[j].z - me.z);

				dist = sqrt(dist);

				if(dist < mini){
					mini = dist;
					me.id = g[j].id;
				}
			}

			g[me.id-1].id = -1;

			if(i < n-1) cout << me.id << " ";
			else cout << me.id << endl;
		}

		cin >> n;
	}
}