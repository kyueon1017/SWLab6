#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
const float PI = 3.141592, m = 0.1, b = 0.2, k = 10, w = 3 * sqrt(11);
using namespace std;

//analytic solution
float f(float t) {
	return exp(-t) * (cos(w * t) + (1 / w) * sin(w * t));
}

void numerical_sol(float a, float b, float c, float dt, float& x2, float& x1, float& x0) {
	x2 = (2 - (b * dt) / a - (c * dt * dt) / a) * x1 + (b * dt / a - 1) * x0;
	x0 = x1;
	x1 = x2;
}

int main() {
	float dt = 2 * PI / (20 * w);// T/ 20
	float x2, x1 = 1, x0 = 1;

	ofstream xx("under_damped_spring.txt");
	xx << 0.0 << " " << setw(10) << x0 << " " << f(0.0) << endl;
	xx << dt << " " << setw(10) << x1 << " " << f(dt) << endl;

	for (float t = 2 * dt; t < 4.0; t += dt) {
		numerical_sol(m, b, k, dt, x2, x1, x0);
		xx << t << " " << setw(10) << x2 << " " << f(t) << endl;
	}

	xx.close();
	return 0;
}
