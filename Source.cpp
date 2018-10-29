#include <iostream>
#include <iomanip>
#include <vector>
#include <conio.h>
#include <algorithm>

void fill_v(std::vector<float> &v);
void print_v(std::vector<float> const&v);
void sort4(std::vector<float> &v);
void plus_ariph(std::vector<float> &v);

int num_sum(int n);
void sort_num(std::vector<float> &v);
void del_part(std::vector<float> &v);
void mult_min(std::vector<float> &v);
void mult_ariph(std::vector<float> &v);

struct cmp {
	bool operator()(float a, float b) {
		return (num_sum((int)a) < num_sum((int)b));
	}
};

int main() {
	std::vector<float> v1(4);

	fill_v(v1);
	print_v(v1);
	sort_num(v1);
	print_v(v1);


	_getch();
	return 0;
}

void fill_v(std::vector<float> &v) {
	for (int i = 0; i < v.size(); i++) {
		v.at(i) = (rand() % 100 + 1) + (float)(rand() % 99 + 1) / 100;
	}
}

void print_v(std::vector<float>const &v) {
	std::cout << std::fixed;
	std::cout.precision(1);
	for (size_t i = 0; i < v.size(); i++) {
		std::cout << std::setw(5) << v.at(i) << " ";
	}std::cout << std::endl << std::endl;
}
//v10
void sort4(std::vector<float> &v) {
	int frst = 0, scd = 4;
	for (int i = 0; i < (v.size()) / 4; i++) {
		std::sort(v.begin() + frst, v.begin() + scd);
		frst = frst + 4;
		frst + 4 <= v.size() ? scd = frst + 4 : scd = v.size();
	}
}
//v1
void plus_ariph(std::vector<float> &v) {
	int s = 0;
	for_each(v.begin(), v.end(), [&s](float val) { s = s + val;});
	s = s / v.size();
	for_each(v.begin(), v.end(), [s](float & val) {val = val + s; });
}
//v2
void mult_min(std::vector<float> &v) {
	int min = INT_MIN;
	for_each(v.begin(), v.end(), [&min](float val) { if (val < min) min = val; });
	for_each(v.begin(), v.end(), [min](float & val) {val *= min; });
}
//v3
void mult_ariph(std::vector<float> &v) {
	float sum = 0.0;
	for_each(v.begin(), v.end(), [&sum](float val) { if ( (int)val % 2 == 0) sum += val; });
	float ariph = sum / v.size();
	for_each(v.begin(), v.end(), [ariph](float & val) {if ( (int)val % 3 == 0) val = val*ariph; });
}
//v4
void del_part(std::vector<float> &v) {
	float max = INT_MIN;
	for_each(v.begin(), v.end(), [&max](float val) { if (val > max) max = val; });
	for_each(v.begin(), v.end(), [max](float & val) { val = val / (max/2); });
}
//v5
void sort_num(std::vector<float> &v) {
	std::sort(v.begin(), v.end(), cmp());
}

int num_sum(int n) {
	int sum = 0;
	while (n != 0){
		sum += n % 10;
		n /= 10;
	}
	return sum;
}