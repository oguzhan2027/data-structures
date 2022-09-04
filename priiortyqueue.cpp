#include<iostream>
#include <queue>
using namespace std;

int main() {

  // int tipinde bir kuyruk yapýyoruz
  priority_queue<int> numbers;

  // priority_queue elemanlarý ekliyoruz
  numbers.push(1);
  numbers.push(20);
  numbers.push(7);

  cout << "Priority Queue: ";

  // ekranda gösterme iþlemi yapýyoruz
  while(!numbers.empty()) {
    cout << numbers.top() << ", ";   
    numbers.pop();
  }

  cout << endl;

  return 0;
}
