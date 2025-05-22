#include "GameController.h"
#include <iostream>
int main()
{

	try
	{
		GameController game;
		game.run();
	}
	catch (...)
	{
		std::cerr << "Unknown error occurred." << std::endl;
	}
	
}
