#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class TallPeople{
public:
	vector< vector<int> > ppl;
	vector<int> getPeople(vector <string> people){
		int i;
		for(i=0;i<people.size();i++){
			char * str=people[i].c_str();
		}
		vector<int> v;
		return v;
	}

};

int main(){
	TallPeople p;
	string s[]={"9 2 3", "4 8 7"};
	vector<string> ppl(s,s+2);
	vector<int> v=p.getPeople(ppl);
	vector<int>::iterator i=v.begin();
	while(i!=v.end()){
		cout<<*i<<endl;
		i++;
	}
	return 0;
}
