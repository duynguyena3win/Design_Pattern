#include <stdio.h>
#include "Array.h"
#include <conio.h>

void main()
{
	Array<int>* MyArray = new Array<int>();
	MyArray->Add(0);
	MyArray->Show();

	MyArray->Add(8);
	MyArray->Show();

	MyArray->Add(2);
	MyArray->Show();

	
	MyArray->Add(3);
	MyArray->Show();

	MyArray->Add(4);
	MyArray->Show();
	MyArray->Clear();
	printf(" %d ", MyArray->IsEmpty());
	_getch();
}