#pragma once


#include<SFML/Graphics.hpp>
#include<iostream>

using namespace std;
using namespace sf;

class Game_button {
public:
	Game_button() {}

	Game_button(string t, Vector2f size, int char_size, Color bgcolor, Color text_color)
	{
		text.setString(t);
		text.setFillColor(text_color);
		text.setCharacterSize(char_size);

		button.setSize(size);
		button.setFillColor(bgcolor);
	}

	void set_font(Font& font)
	{
		text.setFont(font);
	}
	void setBackColor(Color color)
	{
		button.setFillColor(color);
	}

	void setTextColor(Color color)
	{
		button.setFillColor(color);
	}

	void setPosition(Vector2f pos)
	{
		button.setPosition(pos);

		float xpos = 1545;
		float ypos = 865;

		text.setPosition(xpos, ypos);
	}

	void drawTo(RenderWindow& window)
	{
		window.draw(button);
		window.draw(text);
	}

	bool is_mouse_over(RenderWindow& window)
	{
		float mousex = Mouse::getPosition(window).x;
		float mousey = Mouse::getPosition(window).y;

		float btnposx = button.getPosition().x;
		float btnposy = button.getPosition().y;

		float btnxposwidth = button.getPosition().x + button.getLocalBounds().width;
		float btnyposheight = button.getPosition().y + button.getLocalBounds().height;

		if (mousex<btnxposwidth && mousex>btnposx && mousey<btnyposheight && mousey>btnposy)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	RectangleShape button;
	Text text;
};