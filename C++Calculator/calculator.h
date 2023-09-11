class calculator
{
protected:
	float number1;
	float number2;

public:
	calculator();
	~calculator();
	
	void input();
	void menuDisplay(void);
	void selectOperation();

	float sum(float, float);
	float diff(float, float);
	float product(float, float);
	float div(float, float);
};
