#pragma once
#include <queue>
#include <exception>

using namespace std;

template <typename T> class CStack
{
public:
	CStack(void);
	~CStack(void);

	void appendTail(const T& node);
	T deleteHead();

private:
	queue<T> queue1;
	queue<T> queue2;
};

template <typename T> CStack<T>::CStack(void)
{
}

template <typename T> CStack<T>::~CStack(void)
{
}

template <typename T> void CStack<T>::appendTail(const T& node)
{
	if(queue2.size() <= 0)
		queue1.push(node);
	else
		queue2.push(node);
}

template <typename T> T CStack<T>::deleteHead()
{
	T head;
	if(queue1.size() > 0 && queue2.size() <= 0) {
		while(queue1.size()-1 > 0) {
			T& data = queue1.front();
			queue1.pop();
			queue2.push(data);
		}
		head = queue1.front();
		queue1.pop();
	}
	else if(queue1.size() <= 0 && queue2.size() > 0) {
		while(queue2.size()-1 > 0) {
			T& data = queue2.front();
			queue2.pop();
			queue1.push(data);
		}
		head = queue2.front();
		queue2.pop();
	}
	else
		throw new exception("stack is empty");

	return head;
}
