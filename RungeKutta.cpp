#include <iostream>
#define f(x,y) (y*y-x*x)/(y*y+x*x)
using namespace std;
class RungeKutta {
public:
	float x0, y0, xn, h, yn, k1, k2, k3, k4, k;
	int i, n;

	void RungeKuttaFunction() {
		cout << "x0 :" << endl;
		cin >> x0;
		cout << "y0 :" << endl;
		cin >> y0;
		cout << "xn = " << endl;
		cin >> xn;
		cout << "The number of iteration :" << endl;
		cin >> n;
		h = (xn - x0) / n;
		cout << "\n x0 \t y0 \t yn \n" << endl;
		cout << "________________________________\n";
		for (i = 0; i < n; i++) {
			k1 = h * (f(x0, y0));
			k2 = h * (f((x0 + h / 2), (y0 + k1 / 2)));
			k3 = h * (f((x0 + h / 2), (y0 + k2 / 2)));
			k4 = h * (f((x0 + h), (y0 + k3)));
			k = (k1 + 2 * k2 + 2 * k3 + k4)/6;
			yn = y0 + k;
			cout << x0 << "\t" << y0 << "\t "<< yn << endl;
			x0 += h;
			y0= yn;
		}
		cout << "\n when x=" << xn << "y= " << yn;
	}
};
int main()
{
	RungeKutta obj;

	obj.RungeKuttaFunction();
}