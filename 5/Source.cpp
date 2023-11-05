#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "Cambio de Tamaño de Ventana");

    while (ventana.isOpen()) {
        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                ventana.close();
            }
            else if (evento.type == sf::Event::Resized) {
                sf::Vector2u nuevoTamano = ventana.getSize();

                if (nuevoTamano.x < 100 || nuevoTamano.y < 100) {
                    if (nuevoTamano.x < 100) {
                        nuevoTamano.x = 100;
                    }
                    if (nuevoTamano.y < 100) {
                        nuevoTamano.y = 100;
                    }
                    ventana.setSize(nuevoTamano);
                }
                else if (nuevoTamano.x > 1000 || nuevoTamano.y > 1000) {
                    if (nuevoTamano.x > 1000) {
                        nuevoTamano.x = 1000;
                    }
                    if (nuevoTamano.y > 1000) {
                        nuevoTamano.y = 1000;
                    }
                    ventana.setSize(nuevoTamano);
                }
            }
        }

        ventana.clear(sf::Color::Black);
        ventana.display();
    }

    return 0;
}
