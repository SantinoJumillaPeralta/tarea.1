#include <SFML/Graphics.hpp>
#include <vector>

int main() {
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "Arrastrar puntos");
    std::vector<sf::CircleShape> puntos(4);

    for (int i = 0; i < 4; ++i) {
        puntos[i].setRadius(5);
        puntos[i].setFillColor(sf::Color::Red);

        switch (i) {
        case 0:
            puntos[i].setPosition(0, 0);
            break;
        case 1:
            puntos[i].setPosition(800 - puntos[i].getRadius() * 2, 0);
            break;
        case 2:
            puntos[i].setPosition(0, 600 - puntos[i].getRadius() * 2);
            break;
        case 3:
            puntos[i].setPosition(800 - puntos[i].getRadius() * 2, 600 - puntos[i].getRadius() * 2);
            break;
        }
    }

    sf::Vector2f offset;
    bool arrastrando = false;
    int puntoArrastrado = -1;

    while (ventana.isOpen()) {
        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                ventana.close();
            }
            else if (evento.type == sf::Event::MouseButtonPressed) {
                if (evento.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i posicionMouse = sf::Mouse::getPosition(ventana);

                    for (int i = 0; i < 4; ++i) {
                        if (puntos[i].getGlobalBounds().contains(posicionMouse.x, posicionMouse.y)) {
                            arrastrando = true;
                            puntoArrastrado = i;
                            offset = sf::Vector2f(posicionMouse) - puntos[i].getPosition();
                            break;
                        }
                    }
                }
                else if (evento.type == sf::Event::MouseButtonReleased) {
                    if (evento.mouseButton.button == sf::Mouse::Left) {
                        arrastrando = false;
                        puntoArrastrado = -1;
                    }
                }
            }
        }

        if (arrastrando && puntoArrastrado != -1) {
            sf::Vector2i posicionMouse = sf::Mouse::getPosition(ventana);
            puntos[puntoArrastrado].setPosition(sf::Vector2f(posicionMouse) - offset);
        }

        ventana.clear();
        for (int i = 0; i < 4; ++i) {
            ventana.draw(puntos[i]);
        }

        ventana.display();
    }

    return 0;
}

