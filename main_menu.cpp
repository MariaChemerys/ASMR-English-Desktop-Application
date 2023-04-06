#include "main_menu.h"

mainmenu::mainmenu(double w, double h) {
	if (!font.loadFromFile("Fonts/HazelnutMilkTeaBold-p76vy.ttf"))
	{
		cout << "No font" << endl;
	}

	//Menu Options

	//Play
	main_menu[0].setFont(font);
	main_menu[0].setFillColor(Color(107, 67, 228, 255));
	main_menu[0].setString("Play");
	main_menu[0].setCharacterSize(100);
	main_menu[0].setPosition(875, 300);


	//About
	main_menu[1].setFont(font);
	main_menu[1].setFillColor(Color(107, 67, 228, 190));
	main_menu[1].setString("About");
	main_menu[1].setCharacterSize(100);
	main_menu[1].setPosition(850, 450);

	//Exit
	main_menu[2].setFont(font);
	main_menu[2].setFillColor(Color(107, 67, 228, 190));
	main_menu[2].setString("Exit");
	main_menu[2].setCharacterSize(100);
	main_menu[2].setPosition(890, 600);

	mainmenuchosen = 0;
}

mainmenu::~mainmenu()
{

}

void mainmenu::draw(RenderWindow& window) {
	for (int i = 0; i < maximum_main_menu; i++)
	{
		window.draw(main_menu[i]);
	}
}

void mainmenu::MoveUp()
{
	if (mainmenuchosen - 1 >= 0)
	{
		main_menu[mainmenuchosen].setFillColor(Color(107, 67, 228, 150));
		mainmenuchosen--;
		main_menu[mainmenuchosen].setFillColor(Color(107, 67, 228, 255));
	}

}

void mainmenu::MoveDown()
{
	if (mainmenuchosen + 1 < maximum_main_menu)
	{
		main_menu[mainmenuchosen].setFillColor(Color(107, 67, 228, 150));
		mainmenuchosen++;
		main_menu[mainmenuchosen].setFillColor(Color(107, 67, 228, 255));
	}
}