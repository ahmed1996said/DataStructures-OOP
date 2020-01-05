#ifndef ECE309_RECTANGLE_H
#define ECE309_RECTANGLE_H

class Rectangle {
private:
    int width;
    int length;
public:
    Rectangle(int w=0, int l=0) { width = w; length = l;}
    int getWidth() { return width; }
    int getLength() { return length; }
    int area();
};
#endif //HWTRIAL_RECTANGLE_H
