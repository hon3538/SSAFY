#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v[101];

int main(){
    int n,citizen;
    cin>>n>>citizen;
    for(int i=0;i<citizen;i++){
        int num; 
        string s;
        cin>>num>>s;
        v[num].push_back(s);
    }
    int max=v[0].size();
    int maxIdx=0;
    for(int i=0;i<n;i++){
        if(max<v[i].size()){
            max=v[i].size();
            maxIdx=i;
        }
    }

    for(int i=0;i<v[maxIdx].size();i++){
        cout<<v[maxIdx][i]<<' ';
    }
    return 0;
}
/*
vector<string> line[110];
int bucket[110];

int main()
{
	int n, k;
	cin >> n >> k;

	int a;
	int maxIndex;
	string name;
	for (int i = 0; i < k; i++) {
		cin >> a >> name;
		line[a].push_back(name);
		
		bucket[a]++;
		if (bucket[maxIndex] < bucket[a]) {
			maxIndex = a;
		}
	}

	int ln = line[maxIndex].size();
	for (int i = 0; i < ln; i++) {
		cout << line[maxIndex][i] << " ";
	}

	return 0;
}
*/