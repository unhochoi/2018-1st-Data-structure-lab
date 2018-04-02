class Stack {
private:
	int top;

public:
	
	void push(int);
	char pop();
	bool isEmpty();
	bool isFull();
};

int top = -1;
char stack[80];
char buffer[80];

bool isEmpty()
{
	return (top == -1);
}
bool isFull() {
	return (top == 80);
}

void push(char num)
{
	stack[++top] = num;
}
char pop()
{
	return (stack[--top]);	//stack의 맨위에서 뺀 값.
}

