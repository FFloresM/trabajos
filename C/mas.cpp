#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	string p = to_string(n);
	cout << p[2]<<" "<<p[1]<<" "<<p[0]<<endl;

	return 0;
}