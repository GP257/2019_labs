#include <iostream>
#include <memory>

class shape {
 public:
  shape() {}
  virtual bool inShape(const int ix, const int iy) = 0;
  virtual bool sameShape(const std::shared_ptr<shape> s) = 0;
};

class rectangle : public shape {
 public:
  rectangle(const int left, const int right, const int top, const int bot) {
    this->_left = left;
    this->_right = right;
    this->_top = top;
    this->_bot = bot;
  }
  virtual bool inShape(const int ix, const int iy) {
    if (ix >= this->_left && ix <= this->_right && iy >= this->_top &&
        iy <= this->_bot)
      return true;
    return false;
  }
  virtual bool sameShape(const std::shared_ptr<shape> s) {
    std::shared_ptr<rectangle> s2 = std::dynamic_pointer_cast<rectangle>(s);
    if (s2) return true;
    return false;
  }

 private:
  int _left, _right, _top, _bot;
};

class circle : public shape {
  public:
  circle(const int icX, const int icY, const float radius) {
    this->_icX = icX; 
    this->_icY = icY;
    this->_radius = radius;
  }
  virtual bool inShape(const int ix, const int iy) {
    if ((ix - this->_icX) * (ix - this->_icX) +
            (iy - this->_icY) * (iy - this->_icY) <=
        this->_radius * this->_radius)
      return true;
    return false;
  }
  virtual bool sameShape(const std::shared_ptr<shape> s) {
    std::shared_ptr<circle> s2 = std::dynamic_pointer_cast<circle>(s);
    if (s2) return true;
    return false;
  }

 private:
  int _icX, _icY, _radius;
};

int main(int argc, char **argv) {
    std::shared_ptr<rectangle> r(new rectangle (0,10,0,10)), r2(new rectangle(14,14,20,20));
    std::shared_ptr<circle> c(new circle(7,7,4.));
    
    std::cerr << "Is the point (2,2) inside the circle? " << c->inShape(2,2) << " - Inside the rectangle? "<< r->inShape(2,2) << std::endl;
    std::cerr << "Are c and r the same type of object? " << c->sameShape(r) << " - How about r and r2? "<< r->sameShape(r2) << std::endl;
}
