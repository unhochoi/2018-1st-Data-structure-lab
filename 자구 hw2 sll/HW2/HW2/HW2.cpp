
//학생 이름의 알파벳 오름차순으로 리스트를 만들어서 출력하라.
//A 성적을 받은 사람만 출력하라.
//name1과 name2 합쳐 하나의 리스트 만들고, cs 전공만 출력 

#include <iostream>
#include <string>
using namespace std;

struct Node {		//Name, ID number, Major, Grade 정보를 저장하는 구조체 Node이다.
	char name;
	int id;
	std::string major = "";
	char grade;
	Node* next;			//다음 주솟값

};

class List		//함수 내용을 담고 있는 클래스
{
private:
	Node * head;
public:
	List() { head = 0; }
	void insertNode(struct Node num);		//노드 삽입 역할을 해주는 함수
	void print();							//노드를 출력 해주는 함수
	bool isEmpty();							//list가 비었는지 확인해주는 함수
	void gradeprint(char grade);			//원하는 성적을 출력해주는 함수 
	void majorprint(std::string major);		//Data1과 Data2를 합쳐 만든 리스트에서 원하는 전공을 출력할 때 사용.
};

bool List::isEmpty()
{
	if (head == 0)				//head가 0이라면
		return true;
	else                        //head가 있다면
		return false;
}
void List::insertNode(struct Node num)		//인자로 name,id,major,grade를 가지고 있는 구조체를 받아 노드를 만드는 insertNode 함수.
{
	Node* temp = new Node();				//노드 성질을 가지고 있는 temp 변수 선언.
	temp->name = num.name;					//temp 노드 안에 있는 name을 받은 구조체의 name으로 설정 
	temp->id = num.id;						//temp 노드 안에 있는 id를 받은 구조체의 id로 설정
	temp->major = num.major;				//temp 노드 안에 있는 major를 받은 구조체의 major로 설정
	temp->grade = num.grade;				//temp 노드 안에 있는 grade를 받은 구조체의 grade로 설정
	Node* p = NULL;							//노드 성질을 가진 변수 p 선언
	Node* q = NULL;							//노드 성질을 가진 변수 q 선언 
	if (head == 0)			//현재 head가 없다면
	{
		head = temp;		//temp를 head로 만든다.
	}
	else if (temp->name <= head->name) {		//temp의 name보다 head의 name이 클 경우 head 앞에 temp가 삽입된다.
		temp->next = head;				//temp의 이후 주소값은 head를 뜻하게 된다.
		head = temp;					//head는 temp가 된다.
	}
	else   {					//위의 조건에 해당하지 않는다면 적절한 중간 위치에 temp가 삽입 된다.

		p = head;				//변수 p에 head를 복사한다.

		while ((p != 0) && (p->name < temp->name))		//변수 p가 0이고 temp의 name이 클 때 까지 노드를 찾아간다. 
		{
			q = p;									// 변수 q에 p값을 복사한다.
			p = p->next;							// 변수 p에 p 이후 노드를 가리키는 주소를 넣는다.
		}
		if (p != 0) {						//p가 비어있지 않을 경우 즉, 반복문이 중간에 멈췄을 경우
			temp->next = p;					//temp의 이후 주솟값에는 p를 삽입
			q->next = temp;					//q의 이후 주솟값은 temp가 된다.
		}
		else{					//p가 비어있을 경우 즉, 끝까지 찾았을 경우.
			q->next = temp;				//q의 이후 주솟 값에 temp를 삽입
		}
	}
}

void List::print()		//이름 오름차순 출력 함수 
{
	Node *p = NULL;		//노드 성질을 가진 변수 p를 설정해 NULL 값으로 초기화 시켜준다.

	if (!isEmpty())		//리스트가 비어있지 않다면 실행
	{
		p = head;		//변수 p에 head를 복사한다.
		cout << "-----  Forward List  -----\n";
		while (p != 0)		//p가 0이 아닐 때 까지.
		{
			std::cout << p->name << " " << p->id << " " << p->major << " " << p->grade << std::endl;		//name,id,major,grade 출력
			p = p->next;																				//p에 다음노드 정보를 넘겨준다.
		}
		cout << endl;
	}
	else        //리스트가 비어 있다면
		cout << "List is empty!\n";
}

void List::gradeprint(char grade)		//A 성적 출력 함수 
{
	Node *p = NULL;				//노드 성질을 가진 변수 p를 설정해 NULL 값으로 초기화 시켜준다.
	if (!isEmpty())				//리스트가 비어있지 않다면 실행
	{
		p = head;				//변수 p에 head를 복사한다.
		cout << "-----  Grade List  -----\n";
		while (p != 0)			//p가 0이 아닐 때 까지.
		{
			if (p->grade == grade) {		//p의 grade가 받은 grade 인자와 같다면 
				std::cout << p->name << " " << p->id << " " << p->major << " " << p->grade << std::endl;			//name,id,major,grade 출력
			}
			p = p->next;			//p에 다음노드 정보를 넘겨준다.
		}
		cout << endl;
	}
	else               //리스트가 비어 있다면
		cout << "List is empty!\n";
}

void List::majorprint(std::string major)		//name1과 name2 합쳐 만든 리스트의 major 출력 
{
	Node *p = NULL;				//노드 성질을 가진 변수 p를 설정해 NULL 값으로 초기화 시켜준다.
	if (!isEmpty())				//리스트가 비어있지 않다면 실행
	{
		p = head;				//변수 p에 head를 복사한다.
		cout << "-----  major List  -----\n";
		while (p != 0)			//p가 0이 아닐 때 까지.
		{
			if (p->major == major) {		//p의 grade가 받은 grade 인자와 같다면 
				std::cout << p->name << " " << p->id << " " << p->major << " " << p->grade << std::endl;			//name,id,major,grade 출력
			}
			p = p->next;			//p에 다음노드 정보를 넘겨준다.
		}
		cout << endl;
	}
	else               //리스트가 비어 있다면
		cout << "List is empty!\n";
}
int main() {

	FILE *f;
	f = fopen("Data1.txt", "r");		//“Data1” 파일을 불러온다.

	struct Node name[10];	//구조체 Node의 성질을 가진 name 10개를 생성한다.


	List mList;		//List 클래스 속성을 가지는 변수 mList를 선언한다.


	for (int i = 0; i < 8; ++i) {
		char buf[10];			//major를 입력받을 buf 선언 
		int n = 0;
		fscanf(f, "%s %d %s %s", &name[i].name, &name[i].id, buf, &name[i].grade);		//파일로부터 name,id,major,grade를 입력받는다.
		while (buf[n] != NULL)
		{
			name[i].major += buf[n];		//major에 방금 받은 buf 삽입
			++n;
		}
		mList.insertNode(name[i]);		//구조체 넣는다.
	}

	mList.print();		//1번 문제 출력

	mList.gradeprint('A');		//2번 문제 출력 

	FILE *f1;
	f1 = fopen("Data2.txt", "r");

	struct Node name1[10];

	for (int j = 0; j < 3; ++j) {
		char buf[10];			//major를 입력받을 buf 선언 
		int n = 0;
		fscanf(f1, "%s %d %s %s", &name1[j].name, &name1[j].id, buf, &name1[j].grade);		//파일로부터 name,id,major,grade를 입력받는다.
		while (buf[n] != NULL)
		{
			name1[j].major += buf[n];		//major에 방금 받은 buf 삽입
			++n;
		}
		mList.insertNode(name1[j]);		//구조체 넣는다.
	}

	mList.majorprint("CS");		//3번 문제 출력 

}

