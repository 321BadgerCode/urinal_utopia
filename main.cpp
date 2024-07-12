#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Urinal{
	string layout;
	int index;
	int neighbors;

	Urinal():layout(""),index(0){
		neighbors = 0;
	}
	Urinal(string layout2):layout(layout2),index(0){
		neighbors = get_neighbors(layout);
	}
	Urinal(string layout2,int i):layout(layout2),index(i){
		neighbors = get_neighbors(layout);
	}
	int get_neighbors(string layout){
		int count = 0;
		if(index!=0&&layout[index-1]!='0'){
			count++;
		}
		if(index!=layout.size()-1&&layout[index+1]!='0'){
			count++;
		}
		return count;
	}
	operator int() const {
		int rating = 5;
		if(layout[index]!='0'){
			return -1;
		}
		if(index!=0||index!=layout.size()-1){
			rating-=1;
		}
		rating-=neighbors;
		return rating;
	}
	operator string() const {
		string out;
		for(int i=0;i<layout.size();++i){
			if(i==index){
				out+="\033[1;31m"+string(1,layout[i])+"\033[0m";
			} else {
				out+=layout[i];
			}
		}
		return out;
	}
};

Urinal get_best_urinal(const vector<char>& status){
	int n=status.size();
	Urinal urinals[status.size()];
	pair<int,int> best_urinal=make_pair(-1,0);

	for(int i=0;i<n;++i){
		urinals[i]=Urinal(string(status.begin(),status.end()),i);
		if(best_urinal.first==-1||urinals[i]>urinals[best_urinal.first]){
			best_urinal=make_pair(i,urinals[i]);
		}
	}

	return urinals[best_urinal.first];
}

int main(int argc,char** argv){
	if(argc!=2){
		cout<<"Usage: "<<argv[0]<<" <urinal layout>"<<endl;
		return 1;
	}
	vector<char> layout(argv[1],argv[1]+strlen(argv[1]));
	Urinal best_urinal=get_best_urinal(layout);
	if(best_urinal==-1){
		cout<<"FULL HOUSE!!! No available urinals :("<<endl;
	} else {
		cout<<"The best urinal is: "<<(string)best_urinal<<endl;
	}
	return 0;
}
/*
TODO:
./a.out -l 101001 -f 2,5 -h 5'6,6'3,5'8


Usage: ./a.out [options]

Options:
-l: Layout
-f: Friends [optional]
-h: Height [optional]
*/