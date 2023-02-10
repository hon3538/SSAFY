// 이진트리 형태로 생각해보면 됩니다.
  

// 입력받은 숫자들 중 몇 개를 뽑아서

// 더했을 때 값이 10~20 되는 조합이 총 몇 가지 인지 Counting 해주세요

// (Backtracking으로 구현 해 주세요)

// 입력이 1 3 5 7 9 라면

// 첫번째 Level에서는 숫자 1을 쓸지 or 말지

// 두번째 Level에서는 숫자 3을 쓸지 or 말지

// 세번째 Level에서는 숫자 5를 쓸지 or 말지

// 네번째 Level에서는 숫자 7를 쓸지 or 말지

// 다섯번째 Level에서는 숫자 9를 쓸지 or 말지
// #include <iostream>
// using namespace std;

// int vect[5];
// int cnt;

// void run(int level, int sum)
// {
// 	if (level == 5) {
// 		if (sum >= 10 && sum <= 20) {
// 			cnt++;
// 		}
// 		return;
// 	}

// 	run(level + 1, sum + vect[level]);
// 	run(level + 1, sum + 0);
// }

// int main()
// {
// 	for (int i = 0; i < 5; i++) {
// 		cin >> vect[i];
// 	}

// 	run(0, 0);

// 	cout << cnt;

// 	return 0;
// }