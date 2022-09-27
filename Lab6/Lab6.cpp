// CGT 215
// Lab 6
// Gabby Willard

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

// Main
int main() {

	// Variables
	string background = "images1/backgrounds/prague.png";
	string foreground = "images1/characters/Rey_green_screen.png";

	// Error Messages
	Texture backgroundTex;
	if (!backgroundTex.loadFromFile(background)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Texture foregroundTex;
	if (!foregroundTex.loadFromFile(foreground)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}

	// Texture the Images
	Image backgroundImage;
	backgroundImage = backgroundTex.copyToImage();
	Image foregroundImage;
	foregroundImage = foregroundTex.copyToImage();
	Vector2u sz = backgroundImage.getSize();

	// Recolor the background
	Color green = foregroundImage.getPixel(0, 0);
	for (int y = 0; y < sz.y; y++) {
		for (int x = 0; x < sz.x; x++) {
			// Color objects store the individual channel values like example.r example.g and example.b
			// These two loops will run the code inside for each pixel in the background image
			// You can access the current pixel at x,y like so:
			Color c_front = foregroundImage.getPixel(x, y);
			Color c_back = backgroundImage.getPixel(x, y);
			backgroundImage.setPixel(x, y, c_back);
			// Set the forground image green color to the background image color
			if (c_front == green) {
				foregroundImage.setPixel(x, y, c_back);
			}
		}
	}

	// By default, just show the foreground image
	RenderWindow window(VideoMode(1024, 768), "Here's the output");
	Sprite sprite1;
	Texture tex1;
	tex1.loadFromImage(foregroundImage);
	sprite1.setTexture(tex1);
	window.clear();
	window.draw(sprite1);
	window.display();
	while (true);
}