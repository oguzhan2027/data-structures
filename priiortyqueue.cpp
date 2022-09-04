#include<iostream>
#include <queue>
using namespace std;

int main() {

  // int tipinde bir kuyruk yap�yoruz
  priority_queue<int> numbers;

  // priority_queue elemanlar� ekliyoruz
  numbers.push(1);
  numbers.push(20);
  numbers.push(7);

  cout << "Priority Queue: ";

  // ekranda g�sterme i�lemi yap�yoruz
  while(!numbers.empty()) {
    cout << numbers.top() << ", ";   
    numbers.pop();
  }

  cout << endl;

  return 0;
}
