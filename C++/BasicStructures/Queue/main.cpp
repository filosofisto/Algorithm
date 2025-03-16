#include <iostream>
#include <memory>
#include "QueueArray.h"

using std::cout;
using std::endl;

int main()
{
  auto queue = std::make_unique<QueueArray<int>>();
  cout << *queue << '\n';  
  
  queue->enqueue(1);
  cout << *queue << '\n'; 

  queue->enqueue(2);
  cout << *queue << '\n'; 
  
  queue->dequeue();
  cout << *queue << '\n'; 
  
  queue->dequeue();
  cout << *queue << '\n'; 

	queue->enqueue(1);
  cout << *queue << '\n'; 

  queue->enqueue(2);
  cout << *queue << '\n'; 
  
  queue->dequeue();
  cout << *queue << '\n'; 
  
  queue->dequeue();
  cout << *queue << '\n'; 

  return EXIT_SUCCESS;
}
