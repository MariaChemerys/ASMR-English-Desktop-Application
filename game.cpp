#include "game.h"
#include"game_buttons.h"

using namespace std;
using namespace sf;

void game::initialize_var()
{
	this->window = nullptr;

	//game logic
	this->endGame = false;
	this->trigger_spawn_timer = 10.f;
	this->trigger_spawn_timer_max = 10.f;
	this->trigger_spawn_timer = this->trigger_spawn_timer_max;
	this->max_triggers = 4;
	this->mouse_held = false;
	this->quit = false;
}

void game::initialize_win()
{
	this->videomode.height = 1080;
	this->videomode.width = 1935;

	this->window = new RenderWindow (this->videomode, "ASMR English", Style::Default);
	this->window->setFramerateLimit(100);
}

void game::initialize_fonts()
{
	if (!this->font.loadFromFile("Fonts/HazelnutMilkTeaBold-p76vy.ttf"))
	{
		cout << "Font is not loading" << endl;
	}
}

void game::initialize_text_and_background()
{
	//instructions text
	this->instructions_text.setFont(this->font);
	this->instructions_text.setCharacterSize(40);
	this->instructions_text.setFillColor(Color(107, 67, 228, 255));
	this->instructions_text.setString("NONE");
	this->instructions_text.setPosition(1310, 20);

	//alphabet
	for (int i = 0, c=1, letter_pos_x = 1310, letter_pos_y = 150; i < 26; i++, c++)
	{
		this->letter_text_array[i].setFont(this->font);
		this->letter_text_array[i].setFillColor(Color::Black);
		this->letter_text_array[i].setCharacterSize(120);
		this->letter_text_array[i].setPosition(letter_pos_x, letter_pos_y);

		if (c % 6 != 0)
		{
			letter_pos_x += 100;
		}
		else 
		{
			letter_pos_x = 1310;
			letter_pos_y += 130;
		}
	}

	//alphabet background
	alphabet_bg.setSize(Vector2f(700, 1080));
	alphabet_bg.setPosition(1270, 0);
	alphabet_bg_texture.loadFromFile("Textures/alphabet background.jpg");
	alphabet_bg.setTexture(&alphabet_bg_texture);

	//trigger background
	trigger_bg.setSize(Vector2f(1270, 1080));
	trigger_bg_texture.loadFromFile("Textures/trigger background.jpg");
	trigger_bg.setPosition(0, 0);
	trigger_bg.setTexture(&trigger_bg_texture);

	//game over text
	this->game_over_text.setFont(this->font);
	this->game_over_text.setCharacterSize(150);
	this->game_over_text.setFillColor(Color(255, 250, 209, 255));
	this->game_over_text.setString("Congratulations!\nYou completed the alphabet.");
	this->game_over_text.setOutlineColor(Color(122, 25, 178, 170));
	this->game_over_text.setOutlineThickness(10);
	this->game_over_text.setPosition(this->window->getSize().x/2.f - this->game_over_text.getGlobalBounds().width/2.f,
this->window->getSize().y / 2.f - this->game_over_text.getGlobalBounds().height / 2.f);

	//game over background
	game_over_bg.setSize(Vector2f(1930, 1080));
	game_over_bg_texture.loadFromFile("Textures/foam-texture.jpg");
	game_over_bg.setTexture(&game_over_bg_texture);
}

void game::initialize_triggers()
{
	this->bubble_texture.loadFromFile("Textures/bubblepic.png");
	this->sponge_texture.loadFromFile("Textures/sponge.png");
	this->glass_texture.loadFromFile("Textures/glass.png");
	this->foam_texture.loadFromFile("Textures/foam D.png");
	this->blender_texture.loadFromFile("Textures/blender E.png");
	this->oil_texture.loadFromFile("Textures/oil F.png");
	this->aerosol_texture.loadFromFile("Textures/aerosol G.png");
	this->slime_texture.loadFromFile("Textures/slime H.png");
	this->hairbrush_texture.loadFromFile("Textures/hairbrush I.png");
	this->towel_texture.loadFromFile("Textures/towel J.png");
	this->soap_texture.loadFromFile("Textures/soap K.png");
	this->glitter_texture.loadFromFile("Textures/glitter L.png");
	this->keyboard_texture.loadFromFile("Textures/keyboard M.png");
	this->cosmetic_bag_texture.loadFromFile("Textures/cosmetic bag N.png");
	this->cotton_candy_texture.loadFromFile("Textures/cotton candy O.png");
	this->notebook_texture.loadFromFile("Textures/notebook P.png");
	this->crystal_texture.loadFromFile("Textures/crystal Q.png");
	this->computer_mouse_texture.loadFromFile("Textures/computer mouse R.png");
	this->candle_texture.loadFromFile("Textures/candle S.png");
	this->ice_texture.loadFromFile("Textures/ice T.png");
	this->kinetic_sand_texture.loadFromFile("Textures/kinetic sand U.png");
	this->rose_texture.loadFromFile("Textures/rose V.png");
	this->light_bulb_texture.loadFromFile("Textures/light bulb W.png");
	this->gel_texture.loadFromFile("Textures/gel X.png");
	this->can_texture.loadFromFile("Textures/can Y.png");
	this->ball_texture.loadFromFile("Textures/ball Z.png");
}

void game::initialize_sounds()
{
	this->bubbleb.loadFromFile("Audio/bubble.wav");
	this->spongeb.loadFromFile("Audio/sponge.wav");
	this->glassb.loadFromFile("Audio/glass.wav");
	this->foamb.loadFromFile("Audio/foam.wav");
	this->blenderb.loadFromFile("Audio/blender.wav");
	this->oilb.loadFromFile("Audio/oil.wav");
	this->aerosolb.loadFromFile("Audio/aerosol.wav");
	this->slimeb.loadFromFile("Audio/slime.wav");
	this->hairbrushb.loadFromFile("Audio/hairbrush.wav");
	this->towelb.loadFromFile("Audio/towel.wav");
	this->soapb.loadFromFile("Audio/soap.wav");
	this->glitterb.loadFromFile("Audio/glitter.wav");
	this->keyboardb.loadFromFile("Audio/keyboard.wav");
	this->cosmetic_bagb.loadFromFile("Audio/cosmetic bag.wav");
	this->cotton_candyb.loadFromFile("Audio/cotton candy.wav");
	this->notebookb.loadFromFile("Audio/notebook.wav");
	this->crystalb.loadFromFile("Audio/crystal.wav");
	this->computer_mouseb.loadFromFile("Audio/computer mouse.wav");
	this->candleb.loadFromFile("Audio/candle.wav");
	this->iceb.loadFromFile("Audio/ice.wav");
	this->kinetic_sandb.loadFromFile("Audio/kinetic sand.wav");
	this->roseb.loadFromFile("Audio/rose.wav");
	this->light_bulbb.loadFromFile("Audio/light bulb.wav");
	this->gelb.loadFromFile("Audio/gel.wav");
	this->canb.loadFromFile("Audio/can.wav");
	this->ballb.loadFromFile("Audio/ball.wav");
}

game::game()
{
	this->initialize_var();
	this->initialize_win();
	this->initialize_triggers();
	this->initialize_fonts();
	this->initialize_text_and_background();
	this->initialize_sounds();
}

game::~game()
{
	delete this->window;
}

//accessors
const bool game::running() const
{
	return this->window->isOpen();
}

const bool game::get_end_game() const
{
	return this->endGame;
}

const bool game::get_quit() const
{
	return this->quit;
}

void game::spawn_trigger()
{
	//spawns triggers and sets their types, textures and positions randomly
	
	this->trigger.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x/1.5 - this->trigger.getGlobalBounds().width)),
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().y/1.5 - this->trigger.getGlobalBounds().height))
	);
	

	//randomize trigger type
	int trigger_type = rand() % 26;
	switch (trigger_type)
	{
	case 0:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(bubble_texture);
		this->triggers.push_back(this->trigger);
		break;
	case 1:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(glass_texture);
		this->triggers.push_back(this->trigger);
		break;
	case 2:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(sponge_texture);
		this->triggers.push_back(this->trigger);
		break;
	case 3:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(foam_texture);
		this->triggers.push_back(this->trigger);
		break;
	case 4:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(blender_texture);
		this->triggers.push_back(this->trigger);
		break;
	case 5:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(oil_texture);
		this->triggers.push_back(this->trigger);
		break;
	case 6:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(aerosol_texture);
		this->triggers.push_back(this->trigger);
		break;
	case 7:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(slime_texture);
		this->triggers.push_back(this->trigger);
		break;
	case 8:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(hairbrush_texture);
		this->triggers.push_back(this->trigger);
		break;
	case 9:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(towel_texture);
		this->triggers.push_back(this->trigger);
		break;
	case 10:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(soap_texture);
		this->triggers.push_back(this->trigger);
		break;
	case 11:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(glitter_texture);
		this->triggers.push_back(this->trigger);
		break;
	case 12:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(keyboard_texture);
		this->triggers.push_back(this->trigger);
		break;
	case 13:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(cosmetic_bag_texture);
		this->triggers.push_back(this->trigger);
		break;
	case 14:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(cotton_candy_texture);
		this->triggers.push_back(this->trigger);
		break;
	case 15:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(notebook_texture);
		this->triggers.push_back(this->trigger);
		break;
	case 16:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(crystal_texture);
		this->triggers.push_back(this->trigger);
		break;
	case 17:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(computer_mouse_texture);
		this->triggers.push_back(this->trigger);
		break;
	case 18:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(candle_texture);
		this->triggers.push_back(this->trigger);
		break;
	case 19:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(ice_texture);
		this->triggers.push_back(this->trigger);
		break;
	case 20:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(kinetic_sand_texture);
		this->triggers.push_back(this->trigger);
		break;
	case 21:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(rose_texture);
		this->triggers.push_back(this->trigger);
		break;
	case 22:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(light_bulb_texture);
		this->triggers.push_back(this->trigger);
		break;
	case 23:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(gel_texture);
		this->triggers.push_back(this->trigger);
		break;
	case 24:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(can_texture);
		this->triggers.push_back(this->trigger);
		break;
	case 25:
		this->trigger.setScale(Vector2f(1.f, 1.f));
		this->trigger.setTexture(ball_texture);
		this->triggers.push_back(this->trigger);
		break;
	default:
		break;
	}
}

void game::poll_events()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case Event::Closed:
			this->window->close();
			break;
		case Event::KeyPressed:
			if (this->ev.key.code == Keyboard::Escape)
				this->window->close();
		}
	}
}

void game::upd_mouse_positions()
{
	//updates the mouse positions
	this->mouse_pos_window = Mouse::getPosition(*this->window);
	this->mouse_pos_view = this->window->mapPixelToCoords(this->mouse_pos_window);
}

void game::upd_text()
{
	stringstream instructions_string;

	instructions_string << "Complete the alphabet.\nCatch all items with letters to win!";

	this->instructions_text.setString(instructions_string.str());

	for (int i = 0; i < 26; i++)
	{
		this->letter_text_array[i].setString(string_letter_array[i]);
	}
}

void game::upd_triggers()
{
	//updating the timer for trigger spawning
	if (this->triggers.size() < this->max_triggers)
	{
		if (this->trigger_spawn_timer >= this->trigger_spawn_timer_max)
		{
			//spawn the trigger and reset the timer
			this->spawn_trigger();
			this->trigger_spawn_timer = 0.f;
		}
		else
			this->trigger_spawn_timer += 5.f;
	}

	//moving and updating the triggers
	for (int i=0; i < this->triggers.size(); i++)
	{
		bool deleted = false;
		//DIRECTION OF TRIGGERS
		this->triggers[i].move(0.f, 2.f);

		//if the trigger is on the top of the screen
		if (this->triggers[i].getPosition().y > this->window->getSize().y)
		{
			this->triggers.erase(this->triggers.begin() + i);
		}
	}

	//check if clicked upon
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (this->mouse_held == false)
		{
			this->mouse_held = true;
			bool deleted = false;
			for (size_t i = 0; i < this->triggers.size() && deleted == false; i++)
			{
				if (this->triggers[i].getGlobalBounds().contains(this->mouse_pos_view))
				{
					//highlight the letter
					if (this->triggers[i].getTexture() == &bubble_texture)
					{
						this->letter_text_array[0].setFillColor(Color(107, 67, 228, 255));
						this->sound.setBuffer(bubbleb);
						sound.play();
					}
					else if (this->triggers[i].getTexture() == &sponge_texture)
					{
						this->letter_text_array[1].setFillColor(Color(107, 67, 228, 255));
						this->sound.setBuffer(spongeb);
						sound.play();
					}
					else if (this->triggers[i].getTexture() == &glass_texture)
					{
						this->letter_text_array[2].setFillColor(Color(107, 67, 228, 255));
						this->sound.setBuffer(glassb);
						sound.play();
					}
					else if (this->triggers[i].getTexture() == &foam_texture)
					{
						this->letter_text_array[3].setFillColor(Color(107, 67, 228, 255));
						this->sound.setBuffer(foamb);
						sound.play();
					}
					else if (this->triggers[i].getTexture() == &blender_texture)
					{
						this->letter_text_array[4].setFillColor(Color(107, 67, 228, 255));
						this->sound.setBuffer(blenderb);
						sound.play();
					}
					else if (this->triggers[i].getTexture() == &oil_texture)
					{
						this->letter_text_array[5].setFillColor(Color(107, 67, 228, 255));
						this->sound.setBuffer(oilb);
						sound.play();
					}
					else if (this->triggers[i].getTexture() == &aerosol_texture)
					{
						this->letter_text_array[6].setFillColor(Color(107, 67, 228, 255));
						this->sound.setBuffer(aerosolb);
						sound.play();
					}
					else if (this->triggers[i].getTexture() == &slime_texture)
					{
						this->letter_text_array[7].setFillColor(Color(107, 67, 228, 255));
						this->sound.setBuffer(slimeb);
						sound.play();
					}
					else if (this->triggers[i].getTexture() == &hairbrush_texture)
					{
						this->letter_text_array[8].setFillColor(Color(107, 67, 228, 255));
						this->sound.setBuffer(hairbrushb);
						sound.play();
					}
					else if (this->triggers[i].getTexture() == &towel_texture)
					{
						this->letter_text_array[9].setFillColor(Color(107, 67, 228, 255));
						this->sound.setBuffer(towelb);
						sound.play();
					}
					else if (this->triggers[i].getTexture() == &soap_texture)
					{
						this->letter_text_array[10].setFillColor(Color(107, 67, 228, 255));
						this->sound.setBuffer(soapb);
						sound.play();
					}
					else if (this->triggers[i].getTexture() == &glitter_texture)
					{
						this->letter_text_array[11].setFillColor(Color(107, 67, 228, 255));
						this->sound.setBuffer(glitterb);
						sound.play();
					}
					else if (this->triggers[i].getTexture() == &keyboard_texture)
					{
						this->letter_text_array[12].setFillColor(Color(107, 67, 228, 255));
						this->sound.setBuffer(keyboardb);
						sound.play();
					}
					else if (this->triggers[i].getTexture() == &cosmetic_bag_texture)
					{
						this->letter_text_array[13].setFillColor(Color(107, 67, 228, 255));
						this->sound.setBuffer(cosmetic_bagb);
						sound.play();
					}
					else if (this->triggers[i].getTexture() == &cotton_candy_texture)
					{
						this->letter_text_array[14].setFillColor(Color(107, 67, 228, 255));
						this->sound.setBuffer(cotton_candyb);
						sound.play();
					}
					else if (this->triggers[i].getTexture() == &notebook_texture)
					{
						this->letter_text_array[15].setFillColor(Color(107, 67, 228, 255));
						this->sound.setBuffer(notebookb);
						sound.play();
					}
					else if (this->triggers[i].getTexture() == &crystal_texture)
					{
						this->letter_text_array[16].setFillColor(Color(107, 67, 228, 255));
						this->sound.setBuffer(crystalb);
						sound.play();
					}
					else if (this->triggers[i].getTexture() == &computer_mouse_texture)
					{
						this->letter_text_array[17].setFillColor(Color(107, 67, 228, 255));
						this->sound.setBuffer(computer_mouseb);
						sound.play();
					}
					else if (this->triggers[i].getTexture() == &candle_texture)
					{
						this->letter_text_array[18].setFillColor(Color(107, 67, 228, 255));
						this->sound.setBuffer(candleb);
						sound.play();
					}
					else if (this->triggers[i].getTexture() == &ice_texture)
					{
						this->letter_text_array[19].setFillColor(Color(107, 67, 228, 255));
						this->sound.setBuffer(iceb);
						sound.play();
					}
					else if (this->triggers[i].getTexture() == &kinetic_sand_texture)
					{
					this->letter_text_array[20].setFillColor(Color(107, 67, 228, 255));
					this->sound.setBuffer(kinetic_sandb);
					sound.play();
					}
					else if (this->triggers[i].getTexture() == &rose_texture)
					{
					this->letter_text_array[21].setFillColor(Color(107, 67, 228, 255));
					this->sound.setBuffer(roseb);
					sound.play();
					}
					else if (this->triggers[i].getTexture() == &light_bulb_texture)
					{
					this->letter_text_array[22].setFillColor(Color(107, 67, 228, 255));
					this->sound.setBuffer(light_bulbb);
					sound.play();
					}
					else if (this->triggers[i].getTexture() == &gel_texture)
					{
					this->letter_text_array[23].setFillColor(Color(107, 67, 228, 255));
					this->sound.setBuffer(gelb);
					sound.play();
					}
					else if (this->triggers[i].getTexture() == &can_texture)
					{
					this->letter_text_array[24].setFillColor(Color(107, 67, 228, 255));
					this->sound.setBuffer(canb);
					sound.play();
					}
					else if (this->triggers[i].getTexture() == &ball_texture)
					{
					this->letter_text_array[25].setFillColor(Color(107, 67, 228, 255));
					this->sound.setBuffer(ballb);
					sound.play();
					}

					//delete the trigger
					deleted = true;
					this->triggers.erase(this->triggers.begin() + i);
				}
			}
		}
	}
	else
	{
		this->mouse_held = false;
	}

}

void game::update()
{
	this->poll_events();
	if (this->endGame == false)
	{
		this->upd_mouse_positions();

		this->upd_text();

		this->upd_triggers();
	}

	//if condition endgame == true
	for (int i = 0, colored_letter_counter = 0; i < 26; i++)
	{
		if (this->letter_text_array[i].getFillColor() == Color(107, 67, 228, 255))
		{
			colored_letter_counter++;
		}
		if (colored_letter_counter == 26)
		{
			this->endGame = true;
		}
	}
}

void game::render_text(RenderTarget& target)
{
	target.draw(this->instructions_text);

	for (int i = 0; i < 26; i++)
	{
		target.draw(this->letter_text_array[i]);
	}
}


void game::render_triggers(RenderTarget& target)
{
	for (auto& tr : this->triggers)
	{
		target.draw(tr);
	}
}

void game::render()
{
	this->window->clear();

	//drawing game objects
	this->window->draw(this->alphabet_bg);

	this->window->draw(this->trigger_bg);

	this->render_triggers(*this->window);

	this->render_text(*this->window);

	Game_button quit_button("Quit", { 240, 110 }, 80, Color(107, 67, 228, 100), Color(107, 67, 228, 255));
	quit_button.setPosition({ 1500, 860 });
	quit_button.set_font(this->font);
	quit_button.drawTo(*this->window);

	Cursor cursor;
	if (quit_button.is_mouse_over(*this->window))
	{
		cursor.loadFromSystem(sf::Cursor::Hand);
		this->window->setMouseCursor(cursor);
	}
	else
	{
		cursor.loadFromSystem(sf::Cursor::Arrow);
		quit_button.setBackColor(Color(107, 67, 228, 255));
		this->window->setMouseCursor(cursor);
	}

	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (quit_button.is_mouse_over(*this->window))
		{
			quit = true;
		}
	}

	//game over screen
	if (this->endGame == true)
	{
		this->window->clear();
		this->window->draw(this->game_over_bg);
		this->window->draw(this->game_over_text);
	}
	this->window->display();
}
