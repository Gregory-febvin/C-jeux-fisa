#include "../include/selectionlvl.h"

SelectionLvl::SelectionLvl(sf::RenderWindow* window) : window(window)
{

}

void SelectionLvl::selectionJeu()
{

	int continuer = 1;
	Menu menu(window);
	menu.create_chapter_menu();

	// On fait tourner le programme jusqu'� ce que la fen�tre soit ferm�e
	while (continuer == 1) {
		// On inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window->close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					menu.clearMenu();
					return;
				}
			}
			menu.select_chapter_menu(event);
		}

		// Effacement et dessin
		window->clear();
		menu.draw();
		window->display();
	}

}

void SelectionLvl::selectionEdition() {

    int continuer = 1;
	Menu menu(window);
	menu.create_chapter_menu();

    // On fait tourner le programme jusqu'� ce que la fen�tre soit ferm�e
	while (continuer == 1) {
		// On inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window->close();
				return;
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					menu.clearMenu();
					return;
				}
			}
			menu.select_editor_menu(event);
		}

		// Effacement et dessin
		window->clear();
		menu.draw();
		window->display();
	}
}

/*void SelectionLvl::regle() {

    int continuer = 1;

    // Chargement des textures du Menu de selection de niveau
    sf::Texture textureRegle;
    sf::Sprite regle;

    textureRegle.loadFromFile("./assets/textures/regle.png");
    regle.setTexture(textureRegle);

    // On fait tourner le programme jusqu'� ce que la fen�tre soit ferm�e
    while (continuer == 1) {
        // On inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    continuer = 0;
                }
            }
            window.draw(regle);
            window.display();
        }
        window.clear(sf::Color::Black);
    }
}*/