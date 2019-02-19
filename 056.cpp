#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	static bool comp(Interval l, Interval r){
		return l.start < r.start;
	}
    vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.size() < 2) return intervals;

		vector<Interval> ret;
		sort(intervals.begin(), intervals.end(), comp);

		Interval last = intervals[0];
		for (int i = 1; i < intervals.size(); ++i) {
			if(intervals[i].start <= last.end && intervals[i].end > last.end)
				last = Interval(last.start, intervals[i].end);
			else if(intervals[i].start > last.end){
				ret.push_back(last);
				last = intervals[i];
			}
		}
		ret.push_back(last);
		return ret;
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin,line)){
		replace(line.begin(), line.end(), '[', ' ');
		replace(line.begin(), line.end(), ']', ' ');
		replace(line.begin(), line.end(), ',', ' ');

		istringstream is(line);
		vector<Interval> v;
		int start;
		int end;
		while(is >> start){
			is >> end;
			v.push_back(Interval(start, end));
		}

		vector<Interval> ans = s.merge(v);
		for(auto i : ans)
			cout<< i.start <<" "<< i.end <<endl;
	}
}
