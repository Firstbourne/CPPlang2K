#include <iostream>

class Coordinates {

	int x, y;

public:

	Coordinates() : x(11), y(17) {};

	Coordinates(const Coordinates& coord) {
		x = coord.x;
		y = coord.y;
	}

	void set_coordinates(int a, int b) {
		x = a;
		y = b;
	}

	int getx() const { return x; }
	int gety() const { return y; }

	Coordinates& operator +(const Coordinates& other) {
		Coordinates sum_coordinates;
		sum_coordinates.x = this->x + other.x;
		sum_coordinates.y = this->y + other.y;
		return sum_coordinates;
	}

	Coordinates& operator -(const Coordinates& other) {
		Coordinates dif_coordinates;
		dif_coordinates.x = other.x - this->x;
		dif_coordinates.y = other.y - this->y;
		return dif_coordinates;
	}

	Coordinates& operator =(const Coordinates& other) {
		Coordinates equal_coordinates;
		equal_coordinates.x = this->x = other.x;
		equal_coordinates.y = this->y = other.y;
		return equal_coordinates;
	}

	friend std::ostream& operator <<(std::ostream& out, Coordinates& coord) {
		out << "X : " << coord.x << "Y : " << coord.y;
		return out;
	}

	void CPrint() {
		std::cout << "Sys_X : " << x << "\n" << "Sys_Y : " << y << "\n";
	}
};

int main(int argc, const char* argv[]) {

	std::cout << "Hello, programm - Coord_Class : started." << std::endl;
	Coordinates coordinates = Coordinates();
	coordinates.CPrint();

	int user_x, user_y;
	std::cout << "Enter your coordinates (x, y) : " << std::endl;
	std::cin >> user_x;
	std::cin >> user_y;
	std::cout << "Your coordinates" << "\n" << "User_X : " << user_x << "\n" << "User_Y : " << user_y << "\n";
	
	Coordinates coord_1;
	coord_1.set_coordinates(user_x, user_y);

	Coordinates sum_coord = coord_1.operator+(Coordinates());
	std::cout << "Sum coordinates = " << sum_coord.getx() << " " << sum_coord.gety() << std::endl;

	Coordinates dif_coord = coord_1.operator-(Coordinates());
	std::cout << "Dif coordinates = " << dif_coord.getx() << " " << dif_coord.gety() << std::endl;
	
	Coordinates equal_coord = coord_1.operator=(Coordinates());
	std::cout << "Equal coordinates - " << equal_coord.getx() << " " << equal_coord.gety() << std::endl;
}