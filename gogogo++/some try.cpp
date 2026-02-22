#include"gogogo++.h"
class hello
{
private:
	int num;
	int value;
	std::string word;
public:
	hello(int num) :num(num), value(50), word("nihao")
	{
		std::cout << "这个类创建了!"<<std:: endl;
	}
	void show()
	{
		std::cout << num;
	}
};
int main()
{
	hello first(100);
	hello second(50);
	//first = first + second;
	first.show();
	std::string word("hello");
	std::vector<int>vec(50, 2);
	for (auto index=vec.begin();index!=vec.end();index++)
	{
		std::cout << *index << std::endl;
	}
}