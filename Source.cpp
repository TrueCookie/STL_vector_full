#include <iostream>
#include <iomanip>
#include <vector>
#include <conio.h>
#include <algorithm>
#include <Windows.h>

void fill_v(std::vector<float> &v);
void print_v(std::vector<float> const&v);
void sort4(std::vector<float> &v);
void plus_ariph(std::vector<float> &v);
int num_sum(int n);
void sort_num(std::vector<float> &v);
void div_part(std::vector<float> &v);
void mult_min(std::vector<float> &v);
void mult_ariph(std::vector<float> &v);
void mult2_and_subtract_unnegative(std::vector<float> &v);
void mult_max_div_min(std::vector<float> &v);
void sum_min3(std::vector<float> &v);
void mult_min_max(std::vector<float> &v);

void menu(std::vector<float> &v);
int fool(const int beg, const int end);

struct cmp {
	bool operator()(float a, float b) {
		return (num_sum((int)a) < num_sum((int)b));
	}
};

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::vector<float> v1(8);

	fill_v(v1);
	print_v(v1);
	while (1) {
		menu(v1);
	}

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
//v1
void plus_ariph(std::vector<float> &v) {
	int s = 0;
	for_each(v.begin(), v.end(), [&s](float val) { s = s + val;});
	s = s / v.size();
	for_each(v.begin(), v.end(), [s](float & val) {val = val + s; });
}
//v2
void mult_min(std::vector<float> &v) {
	int min = INT_MAX;
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
void div_part(std::vector<float> &v) {
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
//v6
void mult_min_max(std::vector<float> &v) {
	float max = INT_MIN;
	for_each(v.begin(), v.end(), [&max](float val) { if (val > max) max = val; });
	int min = INT_MAX;
	for_each(v.begin(), v.end(), [&min](float val) { if (val < min) min = val; });
	for_each(v.begin(), v.end(), [min, max](float & val) { if (val < 0) val = val * min*max; });
}
//v7
void mult_max_div_min(std::vector<float> &v) {
	float max = INT_MIN;
	for_each(v.begin(), v.end(), [&max](float val) { if (val > max) max = val; });
	int min = INT_MAX;
	for_each(v.begin(), v.end(), [&min](float val) { if (val < min) min = val; });
	for_each(v.begin(), v.end(), [min, max](float & val) { val = val*max/min; });
}
//v8
void sum_min3(std::vector<float> &v) {
	int min0 = INT_MAX;
	for_each(v.begin(), v.end(), [&min0](float val) { if (val < min0) min0 = val; });
	int min1 = INT_MAX;
	for_each(v.begin(), v.end(), [&min1, min0](float val) { if (val < min1 && val != min0) min1 = val; });
	int min2 = INT_MAX;
	for_each(v.begin(), v.end(), [&min2, min1, min0](float val) { if (val < min2 && val != min0 && val != min1) min2 = val; });
	for_each(v.begin(), v.end(), [min2, min1, min0](float & val) { val = val + min0 + min1 + min2; });
}
//v9
void mult2_and_subtract_unnegative(std::vector<float> &v) {
	float sum_unnegative = 0;
	for_each(v.begin(), v.end(), [&sum_unnegative](float val) { if (val >= 0) sum_unnegative += val; });
	for (int i = 0; i < v.size(); i++) {
		if (i % 2 == 0) {
			v[i] -= sum_unnegative;
		}else {
			v[i] *= 2;
		}
	}
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

void menu(std::vector<float> &v) {
	std::cout << std::endl << " 0-Прибавить к каждому элементу массива среднее арифметическое его положительных элементов " <<
		std::endl << " 1-Каждый элемент массива должен быть умножен на минимальный элемент исходного массива " <<
		std::endl << " 2-Умножить элементы массива, делящиеся на 3 без остатка, на среднее арифметическое элементов массива, делящихся на 2 без остатка " <<
		std::endl << " 3- Разделить элементы массива на половину максимального элемента" <<
		std::endl << " 4- Отсортировать элементы массива в порядке возрастания суммы составляющих их цифр" <<
		std::endl << " 5- Умножить каждый отрицательный элемент массива на произведение максимального и минимального элементов исходного массива" <<
		std::endl << " 6- Умножить каждый элемент массива на максимальный элемент исходного массива и разделить на минимальный элемент исходного массива" <<
		std::endl << " 7- Прибавить к каждому элементу массива сумму трех минимальных элементов массива" <<
		std::endl << " 8- Элементы, стоящие на четных позициях массива умножить на 2, а из элементов, стоящих на нечетных позициях, вычесть сумму всех неотрицательных элементов" <<
		std::endl << " 9- Каждую четверку элементов массива (либо оставшуюся часть массива меньшей длины) отсортировать в порядке возрастания" << 
		std::endl << " 9- Выход" << std::endl;
	std::cout << "Выберите действие: ";
	int set;
	set = fool(0, 10);

	switch (set) {
	case 0: plus_ariph(v);
		print_v(v);
		break;
	case 1: mult_min(v);
		print_v(v);
		break;
	case 2: mult_ariph(v); 
		print_v(v);
		break;
	case 3: div_part(v);
		print_v(v);
		break;
	case 4: sort_num(v);
		print_v(v);
		break;
	case 5: mult_min_max(v);
		print_v(v);
		break;
	case 6: mult_max_div_min(v);
		print_v(v);
		break;
	case 7: sum_min3(v);
		print_v(v);
		break;
	case 8: mult2_and_subtract_unnegative(v);
		print_v(v);
		break;
	case 9: sort4(v);
		print_v(v);
		break;
	case 10: TerminateProcess(GetCurrentProcess(), 0);
		break;
	}
}

int fool(const int beg, const int end) {
	int val;
	std::cin >> val;
	while (val < beg || val > end) {
		std::cout << "Введено неверное число: ";
		std::cin >> val;
	}
	return val;
}