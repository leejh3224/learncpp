#include <iostream>

/*
 * concept of pointers
 * meaning: pointer = address of memory pointing at.
 * *pointer = value of pointing variable.
 * 
 * int *ptr = x; -> initializing pointer with *, not related to the value.
 * &ptr = ptr -> both are same as ptr itself is a pointer holding memory address
 * 
 */

// in c++, array passed into function is treated as pointers not array.
void printSize(int *array)
{
  // sizeof pointer, not array!
  std::cout << sizeof(array) << "\n";
}

int main()
{
  int arr[]{1, 2, 3, 4, 5};

  // sizeof array
  std::cout << sizeof(arr) << "\n";

  printSize(arr);

  return 0;
}

// array and pointers
#include <iostream>

// parameter ptr contains a copy of the array's address
void changeArray(int *ptr)
{
  // so changing an array element changes the _actual_ array
  // and array's value is identical to the value of first element
  *ptr = 5;
}

int main()
{
  int array[] = {1, 1, 2, 3, 5, 8, 13, 21};
  std::cout << "Element 0 has value: " << array[0] << '\n';

  changeArray(array);

  // not array[0] is changed into 5!
  std::cout << "Element 0 has value: " << array[0] << '\n';

  return 0;
}

// pointer arithmetic
#include <iostream>

int main()
{
  int array[5] = {9, 7, 5, 3, 1};

  std::cout << &array[1] << '\n'; // print memory address of array element 1
  std::cout << array + 1 << '\n'; // print memory address of array pointer + 1

  std::cout << array[1] << '\n';     // prints 7
  std::cout << *(array + 1) << '\n'; // prints 7 (note the parenthesis required here)

  return 0;
}