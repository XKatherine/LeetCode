#include<iostream>
#include<cmath>

class Solution {
public:
    int divide(int dividend, int divisor) {
		if(dividend == 0 || divisor == 0) return 0;
		bool isNeg = true;
		int ans = 0;
		if((dividend>0 && divisor>0) ||(dividend<0 && divisor<0)){
			isNeg = false;
		}
		if(dividend==INT_MIN&&divisor==-1) return INT_MAX;
		dividend = std::abs(dividend);
		divisor = std::abs(divisor);
		while(dividend-divisor>=0){
			dividend -= divisor;
			++ans;
		}
		return isNeg?ans*(-1):ans;
    }
};

int main(){
	Solution s;
	int divident;
	int divisor;
	while(std::cin>>divident){
		std::cin>>divisor;
		std::cout<<s.divide(divident, divisor)<<std::endl;
	}
}
