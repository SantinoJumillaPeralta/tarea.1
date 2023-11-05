#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "Mover Figuras");

    sf::Texture texturaCuadrado, texturaCirculo;
    if (!texturaCuadrado.loadFromFile("cuad_yellow.png") || !texturaCirculo.loadFromFile("rcircleg.png")) {
        return -1;
    }

    sf::Sprite sprite(texturaCuadrado);
    sprite.setScale(0.5f, 0.5f);
    bool esCuadrado = true;

    const float velocidadMovimiento = 5.0f;
    const sf::Vector2u ventanaSize = ventana.getSize();
    const float limiteX = ventanaSize.x - sprite.getGlobalBounds().width;
    const float limiteY = ventanaSize.y - sprite.getGlobalBounds().height;

    while (ventana.isOpen()) {
        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                ventana.close();
            }
            else if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Space) {
                if (esCuadrado) {
                    sprite.setTexture(texturaCirculo);
                    esCuadrado = false;
                }
                else {
                    sprite.setTexture(texturaCuadrado);
                    esCuadrado = true;
                }
            }
        }

        sf::Vector2f movimiento(0, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sprite.getPosition().x > 0) {
            movimiento.x = -velocidadMovimiento;
        }
        // (resto del código permanece igual)
    }

    return 0;
}
