BaseClass
{
public:
	void display(int)	//overridden Function
	{
	....
	}
};

DerivedClass : public BaseClass
{
public:
	void display(int)	//overriding Function
	{
	.....
	}
};

BaseClass obj;
obj.display();

BaseClass obj;
obj.display();

BaseClass obj1 = DerivedClass();
obj1.display();
