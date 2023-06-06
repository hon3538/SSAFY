#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Sort { //interface(추상클래스)
public:
	virtual void sort(vector<int>*) = 0;
};
class BubbleSort : public Sort {
public:
	void sort(vector<int> *list) override {
		for (int i = list->size() - 1; i > 0; i--) {
			for (int j = 0; j < i; j++) {
				swap((*list)[j], (*list)[j + 1]);
			}
		}
	}
};
class SelectionSort : public Sort {
public:
	void sort(vector<int> *list) override {
		for (int i = 0; i < list->size(); i++) {
			int minn = (*list)[i];
			int location = i;
			for (int j = i + 1; j < (*list).size(); j++) {
				if (minn > (*list)[j]) {
					minn = (*list)[i];
					location = j;
				}
			}
			swap((*list)[i], (*list)[location]);
		}
	}
};
class SortPrinter {
public :
	void insert(int val) {
		list.push_back(val);
	}
	//select에서 sort 종류를 정하는 부분이 어디에 의존성을 가지게할지 정할 수 있음
	//지금처럼 string name으로 이름을 받고 select 함수 내에서 Sort 종류를 지정하게 할 수 있고
	//아니면 매개면수 자체를 Sort로 바로 받는 방법이 있음
	//-> main에서 select(new BubbleSort) 로 넘겨주면됨.. 근데 argument에 의존성이 너무
	//강함.. 나중에 다른 sort로 바꾸려하면 직접 찾아서 바꿔줘야됨.. 따라서 의존성을 
	//낮추기 위해 string 으로 받아서 유연하게 짜준다.
	void select(string name) {
		if (name == "Bubble") {
			s = new BubbleSort();
		}
		else if (name == "Selection") {
			s = new SelectionSort();
		}
	}
	void run() {
		s->sort(&list);
	}
	void show() {
		for (int i = 0; i < list.size(); i++) {
			cout << list[i] << ' ';
		}
	}
private:
	vector<int> list;
	Sort* s; //Sort 를 멤버변수로 가지고 있음, SortPrinter와 Sort는 has-a 관계를 가진다
    
};
int main() {
	SortPrinter* s = new SortPrinter();
	s->insert(3);
	s->insert(2);
	s->insert(5);
	s->insert(1);
	s->insert(7);
	s->insert(5);
	s->select("Selection");
	s->run();
	s->show();
	return 0;
}