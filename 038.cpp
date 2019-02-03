#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
      switch(n){
      case 1:
	return "1";
	break;
      case 2:
	return "11";
	break;
      case 3:
	return "21";
        break;
      case 4:
	return "1221";
	break;
      case 5:
	return "111221";
      default:
	return countAndSay(n-5)+countAndSay(5);
	break;
      }
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin,line)){
		int n;
		istringstream is(line);
		is>>n;
		cout<<s.countAndSay(n)<<endl;
	}
}
