#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <ctime>

using namespace std;

class Shape{

protected:
	double x, y;
	int c;

public:
	Shape(double x, double y){
		this->x = x;
		this->y = y;
	}

	virtual ~Shape() {}
	virtual double Square() = 0;
	virtual double Perimetr() = 0;
	
	void Color(){
		srand(time(0));
		c = rand() % 5;
		switch (c){
			case 0:{
				cout << "pink" << endl;
				break;
			}
			case 1:{
				cout << "green" << endl;
				break;
			}
			case 2:{
				cout << "blue" << endl;
				break;
			}
			case 3:{
				cout << "yelow" << endl;
				break;
			}
			case 4:{
				cout << "red" << endl;
				break;
			}
		}
	}

};

class Circle : public Shape{
private:
	double r;

public:
	Circle(double x, double y, double r) :Shape(x, y){
		this->r = r;
	}
	virtual ~Circle() {}
	virtual double Perimetr() {
		return (2 * acos(-1) * r);
	}
	virtual double Square() {
		return (acos(-1) * r * r);
	}
};

class Rect : public Shape{
private:
	double left_x, left_y;

public:
	Rect(double x, double y, double left_x, double left_y) :Shape(x, y){
		this->left_x = left_x;
		this->left_y = left_y;
	}
	virtual double Perimetr(){
		return (4 * (x - left_x) + 4 * (y - left_y));
	}
	virtual double Square(){
		return (4 * (x - left_x) * (y - left_y));
	}
};
int main(){
	setlocale(LC_ALL, "Russian");
	Shape* shapes[4];
	double a, b, c, m;
	int  i = 0;
	string value;

	cout << "Введите данные: " << endl;
	cout << "1 - circle " << endl;
	cout << "2 - rect" << endl;
	cin >> value;
	if (value == "circle"){
		while (cin >> a >> b >> c){
			shapes[i] = new Circle(a, b, c);
			cout << "Perimetr: ";
			cout << shapes[i]->Perimetr() << endl;
			cout << "Square: : ";
			cout << shapes[i]->Square() << endl;
			cout << "Color: ";
			shapes[i]->Color();
			delete shapes[i];
			i++;

		}
	}
	else{
		while (cin >> a >> b >> c >> m){
			shapes[i] = new Rect(a, b, c, m);
			cout << "Perimetr: ";
			cout << shapes[i]->Perimetr() << endl;
			cout << "Square: : ";
			cout << shapes[i]->Square() << endl;
			cout << "Color: ";
			shapes[i]->Color();
			delete shapes[i];
			i++;


		}
	}

	return 0;

}