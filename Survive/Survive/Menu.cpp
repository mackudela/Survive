#include "Menu.h"

Menu::Menu() : 
	position(0), 
	isPressed(false),
	isSelected(false)
{
	menuWindow = std::make_unique<sf::RenderWindow>();
	winClose = std::make_unique < sf::RectangleShape>();
	font = std::make_unique < sf::Font>();
	image = std::make_unique < sf::Texture>();
	background = std::make_unique < sf::Sprite>();

	setValues();
}

void Menu::loopEvents()
{
	sf::Event event;
	while (menuWindow->pollEvent(event)) 
	{
		if (event.type == sf::Event::Closed)
			menuWindow->close();

		mousePosition = sf::Mouse::getPosition(*menuWindow);
		mouseCords = menuWindow->mapPixelToCoords(mousePosition);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !isPressed)
		{
			if (position < 4) 
			{
				++position;
				isPressed = true;
				texts[position].setOutlineThickness(4);
				texts[position - 1].setOutlineThickness(0);
				isPressed = false;
				isSelected = false;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !isPressed) 
		{
			if (position > 1)
			{
				--position;
				isPressed = true;
				texts[position].setOutlineThickness(4);
				texts[position + 1].setOutlineThickness(0);
				isPressed = false;
				isSelected = false;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !isSelected)
		{
			isSelected = true;
			if (position == 4)
				menuWindow->close();
			if (position == 1)
			{
				Game game;
				game.run();
			}
			std::cout << options[position] << "\n";
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (winClose->getGlobalBounds().contains(mouseCords))
				menuWindow->close();
		}
	}
}

void Menu::draw()
{
	menuWindow->clear();
	menuWindow->draw(*background);

	for (auto text : texts)
	{
		menuWindow->draw(text);
	}
	menuWindow->display();
}

void Menu::runMenu()
{
	while (menuWindow->isOpen())
	{
		loopEvents();
		draw();
	}
}

void Menu::setValues()
{
	menuWindow->create(sf::VideoMode(1280, 720), "Survive Menu", sf::Style::Titlebar | sf::Style::Close);
	menuWindow->setPosition(sf::Vector2i(0, 0));

	if (!font->loadFromFile(fontPath))
		menuWindow->close();
	if (!image->loadFromFile(menuBackgroundPath))
		menuWindow->close();

	background->setTexture(*image);

	mousePosition = { 0, 0 };
	mouseCords = { 0, 0 };

	options = { "Survive", "Play", "Options", "About", "Exit" };
	texts.resize(5);
	cords = { {420,40},{610,191},{590,282},{600,370},{623,457} };
	textSizes = { 100, 28, 24, 24, 24 };

	for (int i = 0; i < texts.size(); i++)
	{
		texts[i].setFont(*font);
		texts[i].setString(options[i]);
		texts[i].setCharacterSize(textSizes[i]);
		texts[i].setOutlineColor(sf::Color::Black);
		texts[i].setPosition(cords[i]);
	}

	texts[1].setOutlineThickness(4);
	position = 1;

	winClose->setSize(sf::Vector2f(23, 26));
	winClose->setPosition(1178, 39);
	winClose->setFillColor(sf::Color::Transparent);
}
