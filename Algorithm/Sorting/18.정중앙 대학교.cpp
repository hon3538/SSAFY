#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct cmp1
{
    bool operator()(int left, int right)
    {
        return left < right;
    }
};
struct cmp2
{
    bool operator()(int left, int right)
    {
        return left > right;
    }
};
int main()
{
    priority_queue<int, vector<int>, cmp1> pq_front; // 내림차순
    priority_queue<int, vector<int>, cmp2> pq_back;  // 오름차순
    int center = 500;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > center)
        {
            pq_back.push(a);
        }
        else
        {
            pq_front.push(a);
        }
        
        if (b > center)
        {
            pq_back.push(b);
        }
        else
        {
            pq_front.push(b);
        }

        if (pq_back.size() > pq_front.size())
        {
            pq_front.push(center);
            center = pq_back.top();
            pq_back.pop();
        }
        else if (pq_back.size() < pq_front.size())
        {
            pq_back.push(center);
            center = pq_front.top();
            pq_front.pop();
        }
        cout << center << '\n';
    }
    return 0;
}
/*
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> lheap; //max heap
priority_queue<int, vector<int>, greater<int>> rheap; //min heap
int mid;

void push(int v)
{
	if (mid > v) lheap.push(v);
	else rheap.push(v);
}

int main()
{
	mid = 500;
	
	int n;
	int a, b;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;

		push(a);
		push(b);

		if (lheap.size() > rheap.size()) {
			rheap.push(mid);
			mid = lheap.top();
			lheap.pop();
		}
		else if (lheap.size() < rheap.size()) {
			lheap.push(mid);
			mid = rheap.top();
			rheap.pop();
		}

		cout << mid << "\n";
	}
	

	return 0;
}
*/