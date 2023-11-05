#include <SFML/Graphics.hpp>
#include <vector>

int main() {
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "Círculos Rojo y Azul");

    sf::Texture texturaRoja, texturaAzul;
    if (!texturaRoja.loadFromFile("rcircle.png") || !texturaAzul.loadFromFile("bcircle.png")) {
        return -1;
    }

    sf::Sprite spriteRojo(texturaRoja);
    sf::Sprite spriteAzul(texturaAzul);

    std::vector<sf::Sprite> circulos;

    while (ventana.isOpen()) {
        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                ventana.close();
            }

            if (evento.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f posicion(static_cast<float>(evento.mouseButton.x), static_cast<float>(evento.mouseButton.y));
                sf::Sprite sprite;

                if (evento.mouseButton.button == sf::Mouse::Left) {
                    sprite = spriteRojo;
                }
                else if (evento.mouseButton.button == sf::Mouse::Right) {
                    sprite = spriteAzul;
                }

                sprite.setPosition(posicion);
                circulos.push_back(sprite);
            }
        }

        ventana.clear(sf::Color::White);
        for (const auto& circulo : circulos) {
            ventana.draw(circulo);
        }

        ventana.display();
    }

    return 0;
}
