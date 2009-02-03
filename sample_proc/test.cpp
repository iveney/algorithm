#include <stdio.h>
class Member
{
public:
	virtual void answer(){printf("member\n");}	
};

class Teacher:public Member
{
	public:
	void answer(){printf("Teacher\n");}
};

class Student:public Member
{
	public:
	void answer(){printf("Student\n");}
};

int main()
{
	Member m;
	Teacher t;
	Student s;
	Member * p = &m;
	p->answer();
	p=&t;
	p->answer();
	p=&s;
	p->answer();
	return 0;
}
