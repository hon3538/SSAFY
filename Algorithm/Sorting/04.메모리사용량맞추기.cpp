#include <iostream>

using namespace std;

int ans[4]={40,74,800,16};
int main(){
    int n;
    cin>>n;
    cout<<ans[n-1];
    return 0;
}

/*
#include <iostream>
using namespace std;

int data[10];
int main()
{
	return 0;
}


<2번문제>

#include <iostream>
using namespace std;
double data[3];
char vect[10];
int dt[10];
int main()
{
	return 0;
}


<3번문제> padding 포함

#include <iostream>
using namespace std;

struct Node
{
	int x;
	char t;
};

Node vect[100];
int main()
{

	return 0;
}


<4번문제> 64bit 컴파일 했을 때, padding 포함

#include <iostream>
using namespace std;

struct Node
{
	int x;
	char* next;
};

Node vect;
int main()
{

	return 0;
}
*/