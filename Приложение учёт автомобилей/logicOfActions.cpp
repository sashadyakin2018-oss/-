#include "logicOfActions.h"
#include "actions.h"
#include "globals.h"

#include <Windows.h>


void logicOfActions(int& action)
{
	system("cls");

	if (action == 1)
	{
		regist();
	}
	else if (action == 2)
	{
		changeEntry();
	}
	else if (action == 3)
	{
		deleteEntry();
	}
	else if (action == 4)
	{
		showAllEntries();
	}
	else if (action == 5)
	{
		search();
	}

}