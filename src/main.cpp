#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include <iostream>
#include <string>
#include <sstream>

void updateTitle(bool enabled, unsigned int frequency)
{
	std::stringstream titleStream;

	if (enabled)
		titleStream << "AutoClicker | Enabled | Frequency: " << frequency << "ms";
	else
		titleStream << "AutoClicker | Disabled | Frequency: " << frequency << "ms";

	SetConsoleTitle(titleStream.str().c_str());
}

void menu()
{
	updateTitle(false, 1);
	printf("Press 'X' to enable and 'Z' to disable.\n");
	printf("Press UP/DOWN arrow keys to increase/decrease the frequency.\n");
	printf("Press '0' to set the frequency to 0.\n");
	printf("Press 'Q' to quit.\n");
}
 
void clicker()
{
	bool click = false;
    bool isRunning = true;
	unsigned int freq = 1;
 
	while (isRunning)
	{
		if (GetAsyncKeyState('X'))
		{
			click = true; 
			updateTitle(click, freq);
		}
		else if (GetAsyncKeyState('Z'))
		{
			click = false;
			updateTitle(click, freq);
		}

        if (GetAsyncKeyState('Q'))
		{
			isRunning = false;
		}

		if (GetAsyncKeyState(VK_UP))
		{
			freq++;
			Sleep(10);
			updateTitle(click, freq);
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			if (freq > 1)
			{
				freq--;
				Sleep(10);
				updateTitle(click, freq);
			}
		}

		if (GetAsyncKeyState('0'))
		{
			freq = 1;
			Sleep(10);
			updateTitle(click, freq);
		}

		if (click)
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			Sleep(freq); //you can adjust the speed of the click here
		}
	}
}		
 
int main()
{
	menu();
	clicker();
 
	return 0;
}