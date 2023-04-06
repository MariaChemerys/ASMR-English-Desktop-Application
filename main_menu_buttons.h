#pragma once

#include<SFML/Graphics.hpp>
#include<iostream>

using namespace std;
using namespace sf;

class Button {
public:
	Button() {}

	Button(Vector2f size, Color bgcolor)
	{
		button.setSize(size);
		button.setFillColor(bgcolor);
	}

	void setBackColor(Color color)
	{
		button.setFillColor(color);
	}

	void setPosition(Vector2f pos)
	{
		button.setPosition(pos);

		float xpos = (pos.x + button.getGlobalBounds().width / 2);
		float ypos = (pos.y + button.getGlobalBounds().height / 2);
	}

	void drawTo(RenderWindow& window)
	{
		window.draw(button);
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
};