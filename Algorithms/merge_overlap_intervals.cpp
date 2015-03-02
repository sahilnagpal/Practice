#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct interval {
	int start;
	int end;
};

typedef struct interval Interval;

bool cmpFunc(Interval i, Interval j) {
	return i.start < j.start ? true: false;
}

void mergeIntervals(vector<Interval>& intervals) {
	
	if(intervals.size() <= 0) return;
	sort(intervals.begin(), intervals.end(), cmpFunc);

	stack<Interval> s;
	s.push(intervals[0]);

	int size = intervals.size();
	for(int i = 1; i < size; i++) {
		Interval top = s.top();
		if(top.end < intervals[i].start) {
			s.push(intervals[i]);
		} else if(top.end < intervals[i].end) {
			s.pop();
			top.end = intervals[i].end;
			s.push(top);
		}
	}
	
	cout << "The merged intervals are:" << endl;
	while(!s.empty()) {
		Interval top = s.top(); s.pop();
		cout << "{" << top.start << ", " << top.end << "} "; 
	}
	cout << endl << endl;
}
 
int main() {
	Interval intervals[] = { {1, 3}, {2, 5}, {4, 8}, {12, 13} };
	vector<Interval> interval(intervals, intervals + 4);
	mergeIntervals(interval);
}