#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Camera.h"
#include "Time.h"

class Window
{
public:
	Window(sf::Vector2<unsigned int> resolution, std::string windowName);
	template<typename T>
	void Add( const std::shared_ptr<T> drawable)
	{
		if (!(std::is_base_of<sf::Drawable, T>::value)) 
			throw("Tried to push an undrawable object to the draw queue!");
		queue.push_back(drawable);
	}
	void Discard(int index);
	void Show();
	std::shared_ptr<sf::RenderWindow> GetRenderWindow();
	void SetCamera(Camera& cam);

private:
	std::shared_ptr<sf::RenderWindow> renderWindow;
	std::vector<std::shared_ptr<sf::Drawable>> queue;
	Camera camera;
private:
	sf::Event eventHnd;
};
