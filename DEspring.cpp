#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;


const float m = 2.0, b = 2.0;
// analytic solution
float f(float t) { return 0.2 * exp(-0.5 * t) * sin(8 * t); }
int main() {
	float dt = 0.01, k; // [sec]
	float x2, x1 = 0.2, x0 = 0.2;
	k = 25.7 / (0.7 - 0.5); // spring coefficient

	ofstream xx("spring.txt");
	xx << setw(10) << 0.0 << " " << setw(10) << x0 << " " << f(0.0) << endl;
	xx << setw(10) << dt << " " << setw(10) << x1 << " " << f(dt) << endl;
	for (float t = 2 * dt; t < 5.0; t += dt) {
		x2 = x1 + dt * (dt / m * (-k * x1 - b * (x1 - x0) / dt) + (x1 - x0) / dt);
		xx << setw(10) << t << " " << setw(10) << x2 << " " << f(t) << endl;
		x0 = x1;    x1 = x2;
	}
	xx.close();
	return 123;
}
