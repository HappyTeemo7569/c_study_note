#include<iostream.h> 
#include<math.h> 
class Rectangle {
public:
	Rectangle(double, double, double, double);
	Rectangle();
	double Width();
	double Height();
	double Girth();
	double Area();
private:
	double x0, y0, x1, y1;
};
Rectangle::Rectangle(double a, double b, double c, double d) {
	x0 = a;
	y0 = b;
	x1 = c;
	y1 = d;
}
Rectangle::Rectangle() {
	cout << "输入矩形左下角坐标" << endl;
	cin >> x0 >> y0;
	cout << "再输入矩形右上角坐标" << endl;
	cin >> x1 >> y1;
}
double Rectangle::Width() {
	return fabs(x1 - x0);
}
double Rectangle::Height() {
	return fabs(y1 - y0);
}
double Rectangle::Girth() {
	return (this->Width() + this->Height()) * 2;
}
double Rectangle::Area() {
	return this->Width()*this->Height();
}
void main() {
	Rectangle test(0.11, 100, 56, 999.154);
	cout << "矩形长为:" << test.Width() << "  " << "宽为:" << test.Height() << endl
		<< "矩形周长为:" << test.Girth() << endl
		<< "矩形面积为:" << test.Area() << endl;
}