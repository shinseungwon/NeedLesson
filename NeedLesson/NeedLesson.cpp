// NeedLesson.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "iostream"

int main()
{
	int size = 6;
	int problems[6] = {16,5,11,3,8,14};//ans = 3 5 8 11 14 16
	

	for (int i = 0; i < 6; i++)
		std::cout << problems[i]<<" ";
	std::cout << "\n\n";


	//이안에 코드

	//1.삽입정렬
	/*
	int temp = -1;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < i; j++) {
			
			if (problems[j] > problems[i]) {

				temp = problems[i];

				for (int k = i-1; k >= j; k--) 					
					problems[k + 1] = problems[k];
				
				problems[j] = temp;

				break;
			}
		}
	}
	*/
	//2.셸정렬

	/*
	int itv[3] = { 3,2,1 };
	int itvnum = 3;
	for (int i = 0; i < itvnum; i++) {
		int j = 0;
		while (j + itv[i] < size) {
			
			if (problems[j] > problems[j + itv[i]]) {
				int temp = -1;
				temp = problems[j];
				problems[j] = problems[j + itv[i]];
				problems[j + itv[i]] = temp;
			}
			j++;
		}
	}
	*/

	//3.선택정렬
	/*
	for (int i = 0; i < size;i++) {
		int min = problems[i];
		int minidx = i;
		for (int j = i; j < size; j++) {
			if (min > problems[j]) {
				min = problems[j];
				minidx = j;
			}
		}

		int temp = -1;
		temp = problems[i];
		problems[i] = problems[minidx];
		problems[minidx] = temp;

	}
	*/
	//4.버블정렬
	/*
	for (int i = 0; i < size - 1; i++) {
		for (int j = i; j < size - 1; j++) {
			if (problems[j] > problems[j + 1]) {
				int temp = -1;
				temp = problems[j];
				problems[j] = problems[j + 1];
				problems[j + 1] = temp;
			}
		}
	}
	*/

	//이안에 코드

	for (int i = 0; i < 6; i++)
		std::cout << problems[i]<<" ";

	std::cout << "\n";

    return 0;
}

