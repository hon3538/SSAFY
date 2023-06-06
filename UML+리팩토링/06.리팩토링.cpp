
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::string;
using std::vector;
int splitAndSum(string text)
{
    if (text.empty())
        return 0;
    return sum(split(text));
}
vector<string> split(string text)
{
    vector<string> values;
    text += "-";

    int head = 0, tail = 0, size = 0;
    while (1)
    {
        tail = text.find("-", head);
        if (tail == -1)
            break;
        size = tail - head;
        values.push_back(text.substr(head, size));
        head = tail + 1;
    }
    return values;
}
int sum(vector<string> values)
{
    int result = 0;
    for (int i = 0; i < values.size(); i++)
    {
        result += stoi(values[i]);
    }
    return result;
}
int main()
{
    cout << splitAndSum("100-10-20");
    return 0;
}

/* 기존 코드
#include<iostream>
#include<vector>
#include<string>
using std::cout;
using std::string;
using std::vector;
int splitAndSum(string text)
{
    int result = 0;
    if (text.empty())
    {
        result = 0;
    }
    else { // 위에서 return 을 사용하여 else 를 없앤다
        //split 부분도 함수로 빼서 들여쓰기를 없앤다
        vector<string> values;
        text += "-";
        // split
        int a = 0, b = 0; //변수명 및 함수명은 명확히 알아볼 수 있게 바꾼다.
        while (1) {
            b = text.find("-", a);
            if (b == -1) break;
            string temp = text.substr(a, b - a);
            values.push_back(temp);
            a = b + 1;
        }
        // sum
        for (int i = 0; i < values.size(); i++) { //함수로 빼서, 들여쓰기를 없앤다
            int temp = stoi(values[i]); //string to int 메서도와, sum 메서드를 분리한다 (optional)
            result += temp; //헷갈리게하는 임시 변수는 지운다.
        }
    }
    return result; // 의미파악에 도움이 되지 않는 변수 제거
}
int main()
{
    cout << splitAndSum("100-10-20");
    return 0;
}
*/