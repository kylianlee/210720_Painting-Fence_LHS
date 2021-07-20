//
// Created by Kylian Lee on 2021/07/18.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> height;
int paint(int s, int t);

int main() {
  int planks;
  cin >> planks;
  for (int i = 0; i < planks; ++i) {
    int tmp;
    cin >> tmp;
    height.push_back(tmp);
  }
  cout << paint(0, height.size()) << endl;
  return 0;
}

int paint(int s, int t){    //  s 는 시작 인덱스, t 는 마지막 인덱스 + 1
  int plankNum = t - s;
  if(plankNum == 1)   //  울타리가 한 개이면 페인트칠 한번
    return 1;
  int min = 1000000001;
  for (int i = s; i < t; ++i) {   //  가로의 최솟값 찾는 반복
    if(height[i] < min)
      min = height[i];
  }
  int count = min;    //  페인트칠 최솟값만큼 함
  for (int i = s; i < t; ++i) {
    height[i] -= min;
  }
  int i = s;
  int j;
  while(i < t){   //  끊어진 울타리를 찾아서 재귀호출
    if(height[i] != 0){
      for (j = i + 1; j <= t; ++j) {
        if(height[j] == 0) {
          break;
        }
      }
      if(j == t + 1)
        j--;
      count += paint(i, j);
      i = j + 1;
    }
    else {
      i++;
      continue;
    }
  }
  return plankNum < count ? plankNum : count;
}
