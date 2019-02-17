#include<bits\stdc++.h>
#include<stdio.h>
using namespace std;

#define ERROR 0.2
#define ArraySize 4




//��ʮ�ĵ��㷨--��ٷ�
class  TwentyFourAlgorithm
{
public:
	//Ĭ�Ϲ��캯��
	 TwentyFourAlgorithm();
	~ TwentyFourAlgorithm();
	//���ι���
	TwentyFourAlgorithm(double *numb);
	//�Ƿ�������24�㣿
	 bool IsTwentyFour(int num);
	 //�����ǰ��ʽ
	 void printCurrentFormula();

private:
	//����û��������ֵ�����
	double *number;
	double *copynumber;
	//�����ʾ�Ľ����ʽ
	string *formula;
	string *copyformula;
	//��ӡ��ǰ����
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
	 cout << "��ǰ��������Ϊ��	";
	 for (int i = 0; i < ArraySize; i++)
	 {
		 cout << copynumber[i] << "		";
	 }
	 cout << endl;
 }

 void TwentyFourAlgorithm::printCurrentFormula()
 {
	 cout << "��ǰ��ʽΪ		" << formula[0] << endl;
 }
 //�Ƿ�������24�㣿
 bool TwentyFourAlgorithm::IsTwentyFour(int num)
{
	if (num > ArraySize)
	{
		cout << "�������ָ�����СԽ�磡" << endl;
		return false;
	}

	//����ǰֻʣһ�����֣����������Ƿ�Ϊ24��true:false
	if (num == 1) {
		return (abs(copynumber[0] - 24) <= ERROR);
	}
		

	//˫��ѭ����num�����ֽ�������������
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			double firstNum, secondNum;
			string firstFormula, secondFormula;

			//��ȡ�������������
			firstNum = copynumber[i];
			secondNum = copynumber[j];
	
			//�����´μ���ʱû�м��������
			if (j != num - 1) {
				copynumber[j] = copynumber[num - 1];
			}


			//��ʽ
			firstFormula = formula[i];
			secondFormula = formula[j];
			if (j != num - 1) {
				formula[j] = formula[num - 1];
			}
			//�ӷ���ʽ
			formula[i] = "(" + firstFormula + "+" + secondFormula + ")"; 
			copynumber[i] = firstNum + secondNum;
			//����ݹ�鿴��ǰѡ��ӷ�ģʽʱ��ʣ��������Ƿ������ϳ�24��
			if (IsTwentyFour(num - 1)){
				return true;
			}
				
			//���ӷ��ݹ鲻�ɣ������������������ͬ��

			//���� 
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

			//�˷�
			formula[i] = "(" + firstFormula + "*" + secondFormula + ")";
			copynumber[i] = firstNum * secondNum;
			if (IsTwentyFour(num - 1)) {
				return true;
			}
			//����
			if (secondNum != 0) {
				formula[i] = "(" + firstFormula + "/" + secondFormula + ")"; // ���������ܷ���  
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
			//������޷��ɹ����������ݣ�������һ�ֵ���ϡ�   
			copynumber[i] = firstNum;
			copynumber[j] = secondNum;
			formula[i] = firstFormula;
			formula[j] = secondFormula;
		}
	}	
	return false;
}
