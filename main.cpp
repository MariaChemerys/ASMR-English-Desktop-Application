#include<SFML/Graphics.hpp>
#include "main_menu.h"
#include "main_menu_buttons.h"
#include "game.h"

using namespace sf;
using namespace std;

int main()
{
	RenderWindow MENU(VideoMode(1935, 1080), "ASMR English", Style::Default);

	mainmenu main_menu(MENU.getSize().x, MENU.getSize().y);

	//Game title
	Font font;
	if (!font.loadFromFile("Fonts/HazelnutMilkTeaBold-p76vy.ttf"))
	{
		cout << "No font" << endl;
	}
	Text game_title;
	game_title.setFont(font);
	game_title.setString("ASMR English");
	game_title.setPosition(450, 50);
	game_title.setFillColor(Color(255, 250, 209, 255));
	game_title.setCharacterSize(200);
	game_title.setOutlineColor(Color(122, 25, 178, 170));
	game_title.setOutlineThickness(10);

	//Author
	Text author;
	author.setFont(font);
	author.setString("© By Mariia Chemerys");
	author.setPosition(790, 930);
	author.setFillColor(Color(122, 25, 178, 170));
	author.setCharacterSize(40);

	//Guidelines
	Text guideline_vocabulary, guideline_writing, guideline_triggers;

	//Vocabulary
	guideline_vocabulary.setFont(font);
	guideline_vocabulary.setString("Learn English\nalphabet \nwith pleasure");
	guideline_vocabulary.setPosition(235, 630);
	guideline_vocabulary.setFillColor(Color(254, 83, 81, 170));
	guideline_vocabulary.setCharacterSize(50);

	//Writing
	guideline_writing.setFont(font);
	guideline_writing.setString("Practice your\nmemorizing\nskills");
	guideline_writing.setPosition(1250, 320);
	guideline_writing.setFillColor(Color(190, 235, 244, 170));
	guideline_writing.setCharacterSize(50);

	//Triggers
	guideline_triggers.setFont(font);
	guideline_triggers.setString("Enjoy ASMR\n   triggers");
	guideline_triggers.setPosition(1370, 620);
	guideline_triggers.setFillColor(Color(255, 205, 160, 170));
	guideline_triggers.setCharacterSize(50);

	//Menu background
	RectangleShape menu_background;
	menu_background.setSize(Vector2f(1930, 1080));
	Texture menu_background_texture;
	menu_background_texture.loadFromFile("Textures/salmon-oil-drops-water-surface.jpg");
	menu_background.setTexture(&menu_background_texture);

	//Play background
	RectangleShape play_background;
	play_background.setSize(Vector2f(1930, 1080));
	Texture play_background_texture;
	play_background_texture.loadFromFile("Textures/foam-texture.jpg");
	play_background.setTexture(&play_background_texture);

	//About background
	RectangleShape about_background;
	about_background.setSize(Vector2f(1930, 1080));
	Texture about_background_texture;
	about_background_texture.loadFromFile("Textures/marble-compostion-with-colorful-style.jpg");
	about_background.setTexture(&about_background_texture);

	//About text
	Text about_text;
	about_text.setFont(font);
	about_text.setString("ASMR English is a game for children who want to learn English alphabet. Its main\n"
		                 "purpose is to help children memorize letters. ASMR sounds are used in the game to\n"
		                 "calm them during the process of learning. This contributes to better memorization.\n"
		                 "The player should catch the falling ASMR triggers. Each of them has a corresponding\n"
		                 "letter. In order to win, the player must catch each letter at least once. If you\n"
		                 "have any questions concerning the game, feel free to contact the developer using\n"
		                 "e - mail address maria1chemerys@gmail.com");
	about_text.setPosition(20, 300);
	about_text.setFillColor(Color(122, 25, 178, 170));
	about_text.setCharacterSize(55);

	Text about_header_text;
	about_header_text.setFont(font);
	about_header_text.setString("About ASMR English");
	about_header_text.setPosition(350, 30);
	about_header_text.setFillColor(Color(255, 250, 209, 255));
	about_header_text.setCharacterSize(160);
	about_header_text.setOutlineColor(Color(122, 25, 178, 170));
	about_header_text.setOutlineThickness(10);

	//Main menu buttons

	//Play button
	Button play_button({ 230, 125 }, Color(255, 153, 137, 255));
	play_button.setPosition({ 850, 310 });

	//About button
	Button about_button({ 230, 125 }, Color(255, 153, 137, 255));
	about_button.setPosition({ 850, 450 });

	//Exit button
	Button exit_button({ 230, 125 }, Color(255, 153, 137, 255));
	exit_button.setPosition({ 850, 600 });

	//Window loop
	while (MENU.isOpen())
	{
		Event main_menu_event;

		while (MENU.pollEvent(main_menu_event))
		{
			switch (main_menu_event.type)
			{
			case Event::KeyReleased:
				switch (main_menu_event.key.code)
				{
				case Keyboard::Up:
					main_menu.MoveUp();
					break;
				case Keyboard::Down:
					main_menu.MoveDown();
					break;
				case Keyboard::Return:
				{
					switch (main_menu.get_mainmenuchosen())
					{
					case 0:
					{
						//initialize srand
						srand(static_cast<unsigned>(time(NULL)));

						game game;
						//game loop
						while (game.running()&&!game.get_quit())
						{
							//update
							game.update();

							//render
							game.render();
						}
						break;
					}
					case 1:
					{
						RenderWindow About(VideoMode(1935, 1080), "ASMR English");
						while (About.isOpen())
						{
							Event about_event;

							while (About.pollEvent(about_event))
							{
								switch (about_event.type)
								{
								case Event::Closed:
									About.close();
									break;
								}
							}

							About.clear();
							About.draw(about_background);
							About.draw(about_text);
							About.draw(about_header_text);
							About.display();
						}
						cout << "About button pressed" << endl;
						break;
					}
					case 2:
						cout << "Exit button pressed" << endl;
						MENU.close();
						break;
					}
				}
					break;
				}
				break;
			case Event::MouseMoved:
			{
				if (play_button.is_mouse_over(MENU))
				{
					play_button.setBackColor(Color(255, 153, 137, 65));
				}
				else
				{
					play_button.setBackColor(Color(255, 153, 137, 140));
				}

				if (about_button.is_mouse_over(MENU))
				{
					about_button.setBackColor(Color(255, 153, 137, 65));
				}
				else
				{
					about_button.setBackColor(Color(255, 153, 137, 140));
				}
				
				if (exit_button.is_mouse_over(MENU))
				{
					exit_button.setBackColor(Color(255, 153, 137, 65));
				}
				else
				{
					exit_button.setBackColor(Color(255, 153, 137, 140));
				}

				Cursor cursor;
				if (play_button.is_mouse_over(MENU) || about_button.is_mouse_over(MENU) || exit_button.is_mouse_over(MENU))
				{
					cursor.loadFromSystem(sf::Cursor::Hand);
					MENU.setMouseCursor(cursor);
				}
				else
				{
					cursor.loadFromSystem(sf::Cursor::Arrow);
					MENU.setMouseCursor(cursor);
				}
				break;
			}
			case Event::MouseButtonPressed:
			{
				if (play_button.is_mouse_over(MENU))
				{
					srand(static_cast<unsigned>(time(NULL)));

					game game;
					//game loop
					while (game.running() && !game.get_quit())
					{
						//update
						game.update();

						//render
						game.render();
					}
					break;
				}
				if (about_button.is_mouse_over(MENU))
				{
					RenderWindow About(VideoMode(1935, 1080), "ASMR English");
					while (About.isOpen())
					{
						Event about_event;

						while (About.pollEvent(about_event))
						{
							switch (about_event.type)
							{
							case Event::Closed:
								About.close();
								break;
							}
						}

						About.clear();
						About.draw(about_background);
						About.draw(about_text);
						About.draw(about_header_text);
						About.display();
					}
				}
				if (exit_button.is_mouse_over(MENU))
				{
					MENU.close();
				}
				break;
			}

			case Event::Closed:
				MENU.close();
				break;
			}
		}
		MENU.clear();
		MENU.draw(menu_background);
		MENU.draw(game_title);
		MENU.draw(author);
		MENU.draw(guideline_vocabulary);
		MENU.draw(guideline_writing);
		MENU.draw(guideline_triggers);
		main_menu.draw(MENU);
		play_button.drawTo(MENU);
		about_button.drawTo(MENU);
		exit_button.drawTo(MENU);
		MENU.display();
	}
	return 0;
}