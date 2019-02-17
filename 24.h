#include<bits\stdc++.h>
#include<stdio.h>
using namespace std;

#define ERROR 0.2
#define ArraySize 4




//二十四点算法--穷举法
class  TwentyFourAlgorithm
{
public:
	//默认构造函数
	 TwentyFourAlgorithm();
	~ TwentyFourAlgorithm();
	//含参构造
	TwentyFourAlgorithm(double *numb);
	//是否可以组成24点？
	 bool IsTwentyFour(int num);
	 //输出当前算式
	 void printCurrentFormula();

private:
	//存放用户生成数字的数组
	double *number;
	double *copynumber;
	//存放显示的结果算式
	string *formula;
	string *copyformula;
	//打印当前数据
	void printCurrentNum();
};

TwentyFourAlgorithm::TwentyFourAlgorithm(double *numb)
{
	number = new double[ArraySize];
	copynumber = new double[ArraySize];
	formula = new string[ArraySize];
	copyformula = new string[ArraySize];
	number = numb;
	memcpy(copynumber,number,sizeof(double)*ArraySize);


	for (int i = 0; i < ArraySize; i++)
	{
		bool record = true;
		char buffer[20];
		sprintf(buffer, "%f", numb[i]);

		for each(char c in buffer)
		{
			if (c != '.')
			{
				if (record)
				formula[i] += c;
			}
			else
			{
				record=false;
			}
		}
	}
	memcpy(copyformula, formula, sizeof(string)*ArraySize);

	printCurrentNum();
}

 TwentyFourAlgorithm::TwentyFourAlgorithm()
 {
	 number = new double[ArraySize];
	 copyformula = new string[ArraySize];
	 formula = new string[ArraySize];
	 copynumber = new double[ArraySize];
	 for (int i = 0; i < ArraySize; i++)
	 {
		 number[i] = 0;
		 copynumber[i] = 0;
	 }
	 printCurrentNum();
 }

 TwentyFourAlgorithm::~ TwentyFourAlgorithm()
{
	delete number;
	delete copynumber;
	delete formula;
	delete copyformula;
}

 void TwentyFourAlgorithm::printCurrentNum()
 {
	 cout << "当前输入数据为：	";
	 for (int i = 0; i < ArraySize; i++)
	 {
		 cout << copynumber[i] << "		";
	 }
	 cout << endl;
 }

 void TwentyFourAlgorithm::printCurrentFormula()
 {
	 cout << "当前算式为		" << formula[0] << endl;
 }
 //是否可以组成24点？
 bool TwentyFourAlgorithm::IsTwentyFour(int num)
{
	if (num > ArraySize)
	{
		cout << "输入数字个数大小越界！" << endl;
		return false;
	}

	//若当前只剩一个数字，检测该数字是否为24？true:false
	if (num == 1) {
		return (abs(copynumber[0] - 24) <= ERROR);
	}
		

	//双层循环将num个数字进行所有情况组合
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			double firstNum, secondNum;
			string firstFormula, secondFormula;

			//获取组合中两个数字
			firstNum = copynumber[i];
			secondNum = copynumber[j];
	
			//保留下次计算时没有计算的数据
			if (j != num - 1) {
				copynumber[j] = copynumber[num - 1];
			}


			//算式
			firstFormula = formula[i];
			secondFormula = formula[j];
			if (j != num - 1) {
				formula[j] = formula[num - 1];
			}
			//加法算式
			formula[i] = "(" + firstFormula + "+" + secondFormula + ")"; 
			copynumber[i] = firstNum + secondNum;
			//进入递归查看当前选择加法模式时，剩余的数字是否可以组合成24点
			if (IsTwentyFour(num - 1)){
				return true;
			}
				
			//若加法递归不成，则尝试其他情况，以下同理

			//减法 
			formula[i] = "(" + firstFormula + "-" + secondFormula + ")"; 
			copynumber[i] = firstNum - secondNum;
			if (IsTwentyFour(num - 1)) {
				return true;
			}
			formula[i] = "(" + secondFormula + "-" + firstFormula + ")";
			copynumber[i] = secondNum - firstNum;
			if (IsTwentyFour(num - 1)) {
				return true;
			}

			//乘法
			formula[i] = "(" + firstFormula + "*" + secondFormula + ")";
			copynumber[i] = firstNum * secondNum;
			if (IsTwentyFour(num - 1)) {
				return true;
			}
			//除法
			if (secondNum != 0) {
				formula[i] = "(" + firstFormula + "/" + secondFormula + ")"; // 看看除法能否算  
				copynumber[i] = firstNum / secondNum;
				if (IsTwentyFour(num - 1)) {
					return true;
				}
			}


			if (firstNum != 0) {
				formula[i] = "(" + secondFormula + "/" + firstFormula + ")";
				copynumber[i] = secondNum / firstNum;
				if (IsTwentyFour(num - 1)) {
					printCurrentNum();
					printCurrentFormula();
					return true;
				}
			}
			//情况都无法成功，重置数据，进行下一轮的组合。   
			copynumber[i] = firstNum;
			copynumber[j] = secondNum;
			formula[i] = firstFormula;
			formula[j] = secondFormula;
		}
	}	
	return false;
}
