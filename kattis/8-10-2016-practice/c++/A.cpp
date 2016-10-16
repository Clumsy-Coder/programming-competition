//DONE!!

/*
	program approach

	read the input. 
	add all correct submissions to a vector. use a struct to keep time, problem and status
		ignore existing correct submissions
	add all wrong submissions to a vector. use a struct to keep time, problem and status

	keep reading until -1 is inputted

	after reading the input, calc the total time and total solved
	ignore the submissions that the user gave up on.

	total time = solved submission time + number of times wrong submission for the same problem * penalty

	totaltime += right[i].timeEntry + findWrong(right[i].problem)*penalty;

	display total solved and total time.

	NOTE: this approach is probably overkill.

 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct submission{
	int timeEntry;
	string problem;
	string problemStat;
};

vector<submission> right;
vector<submission> wrong;

int const penalty = 20;

int findRight(string value){
	for(int unsigned i = 0; i < right.size(); i++){
		if(right[i].problem == value){
			return i;
		}
	}

	return -1;
}

int findWrong(string value){
	int timesWrong = 0;
	for (int unsigned i = 0; i < wrong.size(); i++)
	{
		if(wrong[i].problem == value){
			timesWrong++;
		}
	}

	return timesWrong;
}

void totalScore(){
	int numSolved = 0;
	int totalTime = 0;

	for (int i = 0; i < right.size(); i++)
	{
		//check if there were any wrong submissions.
		numSolved++;
		totalTime += right[i].timeEntry + findWrong(right[i].problem)*penalty;
	}

	cout << numSolved << " " << totalTime << endl;

}

int main(){
	int timeEntry = 0;
	string problem = "";
	string problemStat = "";

	while(true){
		cin >> timeEntry >> problem >> problemStat;

		if(timeEntry == -1){
			totalScore();
			break;
		}

		if(problemStat == "right"){
			if(findRight(problem) == -1){
				//numSolved++;
				//totalTime += timeEntry;
				right.push_back(submission());
				right[right.size() - 1].timeEntry = timeEntry;
				right[right.size() - 1].problem = problem;
				right[right.size() - 1].problemStat = problemStat;
			}
		}

		else if(problemStat == "wrong"){
			wrong.push_back(submission());
			wrong[wrong.size() - 1].timeEntry = timeEntry;
			wrong[wrong.size() - 1].problem = problem;
			wrong[wrong.size() - 1].problemStat = problemStat;
		}
	}

	return 0;

}//END METHOD main()