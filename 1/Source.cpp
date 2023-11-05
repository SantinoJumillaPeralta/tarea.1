#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "Ventana con Crosshair");
    sf::Texture textura;

    if (!textura.loadFromFile("crosshair.png")) {
        return -1;
    }

    sf::Sprite mirilla(textura);
    mirilla.setOrigin(textura.getSize().x / 2, textura.getSize().y / 2);

    while (ventana.isOpen()) {
        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                ventana.close();
            }
        }

        mirilla.setPosition(ventana.getSize().x / 2, ventana.getSize().y / 2);

        ventana.clear(sf::Color::Black);
        ventana.draw(mirilla);
        ventana.display();
    }

    return 0;
}
