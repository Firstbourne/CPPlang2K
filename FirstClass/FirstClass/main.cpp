#include <iostream>

class Coordinates {
	int x, y;
public:

	Coordinates() : x(11), y(17) {

	};

	Coordinates(const Coordinates& coord) {
		x = coord.x;
		y = coord.y;	
	}

	Coordinates(int _x, int _y) {
		x = _x;
		y = _y;
	}

	void set_coord(int st, int nd) {
		x = st;
		y = nd;
	}


	Coordinates& operator+(Coordinates& coord) {
		x += coord.x;
		y += coord.y;
	}

	Coordinates& operator-(Coordinates& coord) {
		x -= coord.x;
		y -= coord.y;
	}

	friend std::ostream& operator <<(std::ostream& out, Coordinates& coord) {
		out << "X: " << coord.x << "Y: " << coord.y;
		return out;
	}

	void CPrint() {
		std::cout << "X: " << x << "\n" << "Y: " << y << "\n";
	}
};


int main(int argc, const char* argv[]) {

	int usr_x, usr_y;

	std::cout << "Hello! System coord is:" << std::endl;
	Coordinates c = Coordinates();
	c.CPrint();

	std::cout << "Enter your coords(x, y): ";
	std::cin >> usr_x;
	std::cin >> usr_y;
	std::cout << "Your coords: X - " << usr_x << " Y - " << usr_y << std::endl;
	Coordinates user_coord;
	user_coord.set_coord(usr_x, usr_y);

}