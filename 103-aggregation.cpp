#include <iostream>
#include <string>
#include <vector>

class Teacher
{
private:
  std::string m_name;

public:
  Teacher(std::string name)
      : m_name(name)
  {
  }

  std::string getName() { return m_name; }
};

class Department
{
private:
  std::vector<Teacher *> m_teacher;

public:
  Department()
  {
  }

  void add(Teacher *teacher)
  {
    m_teacher.push_back(teacher);
  }

  friend std::ostream &operator<<(std::ostream &out, const Department &dept)
  {
    out << "Department: ";
    for (unsigned int count = 0; count < dept.m_teacher.size(); ++count)
      out << dept.m_teacher[count]->getName() << ' ';
    out << '\n';

    return out;
  }
};

int main()
{
  // Create a teacher outside the scope of the Department
  Teacher *t1 = new Teacher("Bob"); // create a teacher
  Teacher *t2 = new Teacher("Frank");
  Teacher *t3 = new Teacher("Beth");

  Department dept; // create an empty Department
  dept.add(t1);
  dept.add(t2);
  dept.add(t3);

  std::cout << dept;

  std::cout << t1->getName() << " still exists!\n";
  std::cout << t2->getName() << " still exists!\n";
  std::cout << t3->getName() << " still exists!\n";

  delete t1;
  delete t2;
  delete t3;

  return 0;
}