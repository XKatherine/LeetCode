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
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) { 
		vector<Interval> ret;
		if(intervals.size() == 0) {
			ret.push_back(newInterval);
			return ret;
		}
		int begin, stop;

		int l = 0, r = intervals.size();
		while(l < r){
			int mid = (l + r)/2;
			if(intervals[mid].start == newInterval.start){
				begin = mid;
				break;
			}else if(intervals[mid].start < newInterval.start){
				if(mid + 1 == intervals.size() || intervals[mid+1].start > newInterval.start){
					begin = mid;
					break;
				}else
					l = mid + 1;
			}else{
				if(mid - 1 < 0  || intervals[mid-1].start < newInterval.start){
					begin = (mid - 1) < 0 ? 0 : mid - 1;
					break;
				}else
					r = mid;
			}
		}

		l = begin, r = intervals.size();
		while(l < r){
			int mid = (l + r)/2;
			if(intervals[mid].end == newInterval.end){
				stop = mid;
				break;
			}else if(intervals[mid].end < newInterval.end){
				if(mid + 1 == intervals.size() || intervals[mid+1].end > newInterval.end){
					stop = mid + 1 == intervals.size() ? intervals.size() - 1 : mid + 1;
					break;
				}else
					l = mid + 1;
			}else{
				if(mid - 1 < begin  || intervals[mid-1].end < newInterval.end){
					stop = mid;
					break;
				}else
					r = mid;
			}
		}

		int newStart = newInterval.start, newEnd = newInterval.end;
		if(intervals[begin].end >= newInterval.start) newStart = min(newStart, intervals[begin].start);
		else ++begin;
		if(intervals[stop].start <= newInterval.end) newEnd = max(newEnd, intervals[stop].end);
		else --stop;
		Interval add(newStart, newEnd);

		intervals.erase(intervals.begin()+begin, intervals.begin()+stop+1);
		intervals.insert(intervals.begin()+begin, add); 



		/*
		int begin = newInterval.start, int end;
		for(int i = 0; i < intervals.size(); ++i){
			if(intervals[i].end < newInterval.start)
				ret.push_back(intervals[i]);
			else if(intervals[i].start < intervals[i].start){
				begin = intervals[i[
				end = 
		
		}
		*/


		return intervals;
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

		int newStart, newEnd;
		cin >> newStart >> newEnd;
		Interval newInterval = Interval(newStart, newEnd);

		vector<Interval> ans = s.insert(v, newInterval);
		for(auto i : ans)
			cout<< i.start <<" "<< i.end <<endl;
	}
}
