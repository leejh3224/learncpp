/*
  why it was important?
  programmers used to get most of their resources eg. memories in old days.
  for example, boolean values takes 1 bit of memory but takes 1 byte to store it into memory.
  if you use bitwise operator, you can save up to 7 bits of memory.
  however, bitwise operations are rarely used in general programming but it's still relavant in game programming
  or embedded system and scientific programs which deals with huge amount of data thus needs great optimization.

  4 bit examples
  3 = 0011
  3 << 1 = 0110 = 6
  3 << 2 = 1100 = 12
  3 << 3 = 1000 = 8 -> we lost 1 because there are only 4 bits to store value.
  if there were enough bits like 8 or more, the result should be 24.

  left shift moves entire bits to the n left position and it means times 2^n to your number.
  because in 0011, it is 2^1 + 2^0 and after 3 << 1, it is 2^2 + 2^1 which is equivalent to 3 times 2.

  >>: does exatly opposite of << (divides by z^n)
  ~: not operator, filps each bit into 0 or 1.
  &, |: works similarly to their logical AND or OR counterparts.
  ^: xor(exclusive or), if only one of two bits is true then it's true.
  it returns 0 if it was given itself.(1 1 -> 0, 0 0 -> 0)
  ex) 1 0 -> 1, 1 1 -> 0, 0 0 -> 0 
*/
