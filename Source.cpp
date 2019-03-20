#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

double const a = 0.01;
double const b = 0.1;
double const c = -0.99;
double const d = -1;
double const q = 0.2;

double f(double x) {
	return a * x * x * x + b * x * x + c * x + d;
}

double df(double x) {
	return 3 * a * x * x + 2 * b * x + c;
} 

double phi(double x) {
	return f(x) + x;
}

void newton(double x0, double eps) {
	double cur_x;
	double next_x = x0;
	int cnt = 0;
	do {
		cur_x = next_x;
		next_x = cur_x - f(cur_x) / df(cur_x);
		cnt++;
	} while (abs(next_x - cur_x) >= eps);
	cout << "newton: " << cnt << endl;
	cout << next_x << endl;
}

void iter(double x0, double eps) {
	double cur_x;
	double next_x = x0;
	int cnt = 0;
	do {
		cur_x = next_x;
		next_x = phi(cur_x);
		cnt++;
	} while (abs(next_x - cur_x) >= eps * (1 - q) / q);
	cout << "iter: " << cnt << endl;
	cout << next_x << endl;
}

void bin(double l, double r, double eps) {
	double m;
	int cnt = 0;
	while (r - l > eps) {
		m = (l + r) / 2;
		if ((f(m) < 0) ^ (f(r) < 0)) {
			l = m;
		} else {
			r = m;
		}
		cnt++;
	}
	cout << "bin: " << cnt << endl;
	cout << m << endl;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	double eps = 1e-6;

	newton(-0.8, eps);
	cout << endl;

	iter(-0.8, eps);
	cout << endl;

	bin(-1.1, -0.8, eps);
	bin(-16, -15, eps);
	bin(6, 7, eps);
	cout << endl;
}