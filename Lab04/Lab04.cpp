﻿// Lab04.cpp: определяет точку входа для консольного приложения.
//

//У реченні присутні цитати, тобто підречення у лапках. Знайти найдовшу цитату та вивести її на екран.

#include "stdafx.h"

#include "string.h"
#include "math.h"

#define INIT_STRING_NAN(a, n)\
{\
	for (int i = 0; i < (n); ++i) {\
		(a)[i] = NAN;\
	}\
}

struct Quote {
	char qoute[100];
	int num;
};

int main()
{
	char str[500];
	Quote q, qtmp;
	q.num = 0;
	INIT_STRING_NAN(q.qoute, 100);
	gets_s(str);
	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] == '\"') {
			INIT_STRING_NAN(qtmp.qoute, 100);
			qtmp.num = -1;
			for (++i; i < strlen(str); ++i) {
				if (str[i] == '\"') {
					if (q.num < qtmp.num) {
						q.num = qtmp.num;
						strcpy_s(q.qoute, qtmp.qoute);
					}
					break;
				}
				++qtmp.num;
				qtmp.qoute[qtmp.num] = str[i];
			}
		}
	}
	printf("%s", q.qoute);
	getchar();
	return 0;
}
