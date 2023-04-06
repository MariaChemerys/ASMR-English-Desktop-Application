#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#define maximum_main_menu 3

class mainmenu
{
public:
	mainmenu(double w, double h);

	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();

	int get_mainmenuchosen()
	{
		return mainmenuchosen;
	}

	int MainMenuPressed()
	{
		return mainmenuchosen;
	}
	~mainmenu();

private:
	int mainmenuchosen;
	Font font;
	Text main_menu[maximum_main_menu];
};