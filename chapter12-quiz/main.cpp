#include <iostream>
#include <vector>

class IShape
{
public:
  IShape()
  {
  }

  virtual std::ostream &print(std::ostream &out) const = 0;
  friend std::ostream &operator<<(std::ostream &out, IShape &s)
  {
    return s.print(out);
  };
  virtual ~IShape() {}
};

class Point
{
private:
  int m_x = 0;
  int m_y = 0;
  int m_z = 0;

public:
  Point(int x, int y, int z)
      : m_x(x), m_y(y), m_z(z)
  {
  }

  friend std::ostream &operator<<(std::ostream &out, const Point &p)
  {
    out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
    return out;
  }
};

class Triangle : public IShape
{
private:
  Point m_x;
  Point m_y;
  Point m_z;

public:
  Triangle(const Point x, const Point y, const Point z)
      : m_x{x}, m_y{y}, m_z{z}
  {
  }

  virtual std::ostream &print(std::ostream &out) const override final
  {
    out << "Triangle(" << m_z << ", " << m_y << ", " << m_z;
    return out;
  }

  virtual ~Triangle() {}
};

class Circle : public IShape
{
private:
  Point m_c;
  int m_radius;

public:
  Circle(Point c, int radius)
      : m_c{c}, m_radius{radius}
  {
  }

  virtual std::ostream &print(std::ostream &out) const override final
  {
    out << "Circle(" << m_c << ", "
        << "radius " << m_radius << ")";
    return out;
  }

  int getRadius() const { return m_radius; }

  virtual ~Circle() {}
};

int getLargestRadius(std::vector<IShape *> &v)
{
  int max = 0;
  for (int i = 0; i < v.size(); i++)
  {
    // dynamically cast Circle type to elements of vector
    Circle *c = dynamic_cast<Circle *>(v[i]);

    // it returns nullptr if it fails
    if (!c)
      continue;

    // if radius value is larger than max
    if (c->getRadius() > max)
      // that value is the largest radius
      max = c->getRadius();
  }
}

int main()
{
  std::vector<IShape *> v;
  v.push_back(new Circle(Point(1, 2, 3), 7));
  v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
  v.push_back(new Circle(Point(4, 5, 6), 3));

  for (const auto &shape : v)
    std::cout << *shape << "\n";

  std::cout << "The largest radius is: " << getLargestRadius(v) << "\n";

  // must delete newly allocated shape memory
  for (const auto &shape : v)
    delete shape;

  return 0;
}