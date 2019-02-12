#include<vector>
#include<iostream>
using namespace std;

int main(){
	int row, col;
	cin>>row>>col;
	vector<vector<int>> v1(row);
	vector<int> v(10, 10);
	v[9] = 0;
	int a = v.back();
	v.pop_back();
	cout<<a<<endl;
}
