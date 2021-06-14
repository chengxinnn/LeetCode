#pragma once
#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <cstdlib>
#include <ctime>
using namespace std;

class Buffers
{
public:
	Buffers(int s, int items, int ctems) :begin(0), end(0), size(s), buffered(0), buffer(size),\
		item(0), item_to_produce(items), ctem(0), ctem_to_consume(ctems)
	{

	}

	void producer()
	{
		while (item < item_to_produce)
		{
			{
				//unique_lock<mutex>lck(go);
				produce(item);
				cout << "Thread Producer" << this_thread::get_id() << " generate " << item++ << endl;
			}
		}
	}

	void consumer()
	{
		while (ctem < ctem_to_consume)
		{
			{
				int num;
				consume(num);
				cout << "Thread Consumer" << this_thread::get_id() << " consume " << num << endl;
			}
		}
	}


private:

	void produce(int& n)
	{
		unique_lock<mutex> lck(m);
		not_full.wait(lck, [=]() {return buffered < size; });

		buffer[end] = n;
		end = (end + 1) % size;

		buffered++;
		lck.unlock();
		not_empty.notify_one();

	}

	void consume(int & num)
	{
		unique_lock<mutex>lck(m);
		not_empty.wait(lck, [=]() {return buffered > 0; });

		num = buffer[begin];
		begin = (begin + 1) % size;

		buffered--;
		ctem++;
		lck.unlock();
		not_full.notify_one();
	}

	int begin;
	int end;
	int size;
	int buffered;

	int item;
	int item_to_produce;
	int ctem;
	int ctem_to_consume;
	vector<int>buffer;

	mutex m;
	mutex go;
	condition_variable not_full;
	condition_variable not_empty;


};

// how to express 1 generated later
/*
Main thread id is : 1068
Thread Producer11268 generate 0
Thread Consumer16816 consume 0
Thread Consumer17856 consume 1
Thread Producer11268 generate 2
Thread Consumer13608 consume 2
Thread Producer11268 generate 3
Thread Consumer16816 consume 3
Thread Producer11268 generate 4
Thread Consumer17856 consume 4
Thread Producer11268 generate 5
Thread Consumer13608 consume 5
Thread Producer11268 generate 6
Thread Producer11268 generate 7
Thread Consumer17856 consume 7
Thread Consumer16816 consume 6
Thread Producer23844 generate 1
Thread Producer11268 generate 8
Thread Producer23844 generate 9
Thread Producer23844 generate 11
Thread Producer23844 generate 12
Thread Consumer13608 consume 8
Thread Consumer13608 consume 11
Thread Consumer13608 consume 12
Thread Consumer13608 consume 13
Thread Producer23844 generate 13
Thread Consumer16816 consume 10
Thread Consumer17856 consume 9
Thread Producer11268 generate 10
Thread Producer23844 generate 14
Thread Consumer13608 consume 14
*/

//========================philosopher===============
class chop
{
public:
	bool used = false;
	int id;
	mutex m;
	chop(int i):id(i){}
};


class philosopher
{
public:
	philosopher()
	{
		for (int i = 0; i < 5; i++)
			chops[i] =new chop(i + 1);
	}
	void take(int i)
	{
		while(1)
		{
			chop*l = chops[(i) % 5], *r = chops[(i + 1) % 5];
			unique_lock<mutex>lck(l->m);
			not_full.wait(lck, [&]() {return eating < 2 && r->used == false; });

			cout << "Philosopher \t" << this_thread::get_id() <<" \tis eating with " << l->id <<"  " <<  r->id << endl;
			eating++;
			l->used = true;
			r->used = true;

			//cout << " \tpush down chops" << l->id << "  " << r->id << endl;
			eating--;
			l->used = false;
			r->used = false;

			lck.unlock();

			int time = rand() % 2000 + i * 1000;
			cout <<  " \t\t\tthink  " << time << " s" << endl;
			this_thread::sleep_for(chrono::duration<int, milli>(time));
		}

	}
private:
	int eating = 0;

	chop *chops[5];
	mutex loc;
	condition_variable  not_full;

};

void ini1()
{
	
	cout << "Main thread id is : " << this_thread::get_id() << endl;
	Buffers b(10, 15, 15);
	
	thread p1 = thread(&Buffers::producer, &b);
	thread p2 = thread(&Buffers::producer, &b);
	thread c1 = thread(&Buffers::consumer, &b);
	thread c2 = thread(&Buffers::consumer, &b);
	thread c3 = thread(&Buffers::consumer, &b);

	p1.join();
	p2.join();
	c1.join();
	c2.join();
	c3.join();
}

void ini2()
{
	cout << "Main thread id is : " << this_thread::get_id() << endl;
	srand(time(0));
	philosopher ps;
	thread p1 = thread(&philosopher::take, &ps, 1);
	thread p2 = thread(&philosopher::take, &ps, 2);
	thread p3 = thread(&philosopher::take, &ps, 3);
	thread p4 = thread(&philosopher::take, &ps, 4);
	thread p5 = thread(&philosopher::take, &ps, 5);
	p1.join();
	p2.join();
	p3.join();
	p4.join();
	p5.join();
}



void ini()
{
	ini2();
}