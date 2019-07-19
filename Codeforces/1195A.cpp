#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main(){
	double n, k, temp;
	cin >> n >> k;
	map<int, int> drinks;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		drinks[temp]++;
	}
	int drinkset = ceil((n/2));
	int totalStudents = 0;
	for(auto it : drinks){
		totalStudents += (it.second)/2;
	}
	int left = drinkset - totalStudents;
	totalStudents = totalStudents*2 + left;
	cout << totalStudents << endl;

}