#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "constantes.h"
#include "selectionlvl.h"
#include "fichier.h"
#include "audio.h"

int main(int argc, char **argv) {
	using namespace std;
	Audio audio;

	sf::RenderWindow window(sf::VideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32), "Hero Quest");

	if (!audio.loadMusic("src/audio/Title_Theme.ogg")) {
		cout << "La musique n'a pas charg�e";
	}
	else {
		audio.playMusic();
	}

	sf::Texture texture;
	if (!texture.loadFromFile("src/img/caisse.png")) // permet de charger la texture
	{
		cout << "La texture n'a pas charg�e";
	}

	sf::Texture texturemenu;
	if (!texturemenu.loadFromFile("src/img/menu.png"))
	{
		cout << "La texture n'a pas charg�e";
	}

	// Chargement de la texturesdu menu
	sf::Sprite sprite;
	sprite.setTexture(texturemenu);
	// Modification la position absolue
	sprite.setPosition(sf::Vector2f(0.f, 0.f)); 

	// On fait tourner le programme jusqu'� ce que la fen�tre soit ferm�e
	while (window.isOpen()) {
		// On inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
				if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					window.close();
				}
				if (event.key.code == sf::Keyboard::Num1 || event.key.code == sf::Keyboard::Numpad1) {
					audio.stopMusic();
					selectionJeu(&window);
				}
				if (event.key.code == sf::Keyboard::Num2 || event.key.code == sf::Keyboard::Numpad2) {
					audio.stopMusic();
					selectionEdition(&window);
				}
				if (event.key.code == sf::Keyboard::Num3 || event.key.code == sf::Keyboard::Numpad3) {
					audio.stopMusic();
					regle(&window);
				}
			}
		}

		window.clear(sf::Color::Black);
		window.draw(sprite);
		window.display();
	}
		return 0;
}