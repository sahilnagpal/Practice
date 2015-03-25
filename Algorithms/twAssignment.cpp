#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <vector>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

struct talk {
	string topic;
	int talk_length;
};

typedef struct talk Talk;

bool compareTalkLength(const Talk* a, const Talk* b) {
	return a->talk_length < b->talk_length;
}

int extractTalkLength(string line) {
	string value;
	int i;
	
	for(i = line.find_last_of(' ') + 1; i < line.length() ; i++) {
		if( isdigit(line[i]) )
			value += line[i];
		else break;
	}

	if(value.length() == 0) value = "1";

	if(line[i] == 'l')
		return (atoi(value.c_str()) * 5);
	else
		return atoi(value.c_str());
}

/*long long schedule(int rem_minutes, int index, vector<Talk*>& talks) {
	if(rem_minutes < 0) return 0;
	if(rem_minutes == 0) return 1;
	if(index < 0) return 0;
	return schedule(rem_minutes - talks[index]->talk_length, index - 1, talks) + schedule(rem_minutes, index - 1, talks); 
}*/

int main() {
	int i = 0;

	/* open the file using the infile command */
	fstream infile("input.txt");
	string line;

	vector<Talk*> talks;
	Talk* temp;
	
	while(getline(infile, line)) {
		temp = new Talk;

		temp->topic = line;
		temp->talk_length = extractTalkLength(line);
		
		talks.push_back(temp);
	}

	sort(talks.begin(), talks.end(), compareTalkLength);

	vector<Talk*>::iterator it;
	for(it = talks.begin(); it < talks.end(); it++) {
		cout << (*it)->topic << ", " << (*it)->talk_length << endl;
	}
	
	//cout << schedule(180, talks.size() - 1, talks) << endl;
}