#include<conio.h>
#include<iostream>
using namespace std;
class Time
{
	int hrs, min, sec;
public:
	Time()
	{
		hrs = min = sec = 0;
	}
	Time(int h, int m, int s)
	{
		hrs = h; min = m; sec = s;
	}
	void addTime(Time &t1, Time &t2)
	{
		hrs = t1.hrs + t2.hrs;
		min = t1.min + t2.min;
		sec = t1.sec + t2.sec;
	}
	void displayTime()
	{
		cout << "Time is- " << hrs << ":" << min << ":" << sec;
	}
};
void main()
{
	Time t1(24,20,50);
	Time t2(49, 3,55 );
	Time t3;
	t3.addTime(t1, t2);
	t3.displayTime();
	_getch();
}