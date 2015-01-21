// Rectangle

#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
  int N; scanf("%d", &N);
  vector<pair<int, int> > points;

  for(int i = 0; i < N; i++){
    int x, y; scanf("%d %d", &x, &y);
    points.push_back(make_pair(x, y));
  }
  points.push_back(make_pair(0, 0));
  points.push_back(make_pair(100000, 0));

  sort(points.begin(), points.end());

  int maxArea = -1;
  N += 2;

  for(int i = 1; i < N; i++){
    int x = points[i].first, y = points[i].second;
    if(x < (N - 1) && x == points[i + 1].first){
      continue;
    }
    else {
      int tempArea = (x - points[i - 1].first) * 500;
      if(tempArea > maxArea) maxArea = tempArea;
    }
  }

  for(int i = 1; i < N - 1; i++){
    int y = points[i].second;
    int right = i, left = i;
    while(points[right].second >= y){
      right++;
    }
    while(points[left].second >= y){
      left--;
    }

    int tempArea = (points[right].first - points[left].first) * y;
    if(tempArea > maxArea) maxArea = tempArea;
  }

  printf("%d\n", maxArea);
}
