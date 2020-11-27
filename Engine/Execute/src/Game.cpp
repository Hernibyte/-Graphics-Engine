#include "Game.h"

Game::Game() {}

Game::~Game() {}

Shape* tri;
Sprite* sprite;
Sprite* sprite2;

int Game::initialize()
{
	tri = new Shape(renderer, GL_TRIANGLES);
	sprite = new Sprite(renderer, GL_QUADS);
	sprite2 = new Sprite(renderer, GL_QUADS);

	sprite->setBufferData();
	sprite2->setBufferData();

	//------
	//Set Sprite animation
	Animation* animation = new Animation();
	animation->AddFrame(0.0f, 0.0f, 640.0f, 360.0f, 1280.0f, 720.0f, 4.0f, 4, 2);
	animation->AddAnimation();
	animation->SetCurrentAnimation(0);
	sprite->setAnimation(animation);

	return 0;
}

void Game::update()
{
	while (!window->detecWindowShouldClose()) {
		//input
		if (glfwGetKey(window->getWin(), GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window->getWin(), true);

		//transform
		if (glfwGetKey(window->getWin(), GLFW_KEY_W) == GLFW_PRESS)
		{
			transY += 0.01f;
			sprite->translateBounds(0.0f, 0.01f);
		}
		if (glfwGetKey(window->getWin(), GLFW_KEY_S) == GLFW_PRESS)
		{
			transY -= 0.01f;
			sprite->translateBounds(0.0f, -0.01f);
		}
		if (glfwGetKey(window->getWin(), GLFW_KEY_D) == GLFW_PRESS)
		{
			transX += 0.01f;
			sprite->translateBounds(0.01f, 0.0f);
		}
		if (glfwGetKey(window->getWin(), GLFW_KEY_A) == GLFW_PRESS)
		{
			transX -= 0.01f;
			sprite->translateBounds(-0.01f, 0.0f);
		}
		if (glfwGetKey(window->getWin(), GLFW_KEY_X) == GLFW_PRESS) transZ += 0.001f;
		if (glfwGetKey(window->getWin(), GLFW_KEY_Z) == GLFW_PRESS) transZ -= 0.001f;

		//rotate
		if (glfwGetKey(window->getWin(), GLFW_KEY_U) == GLFW_PRESS) rotateX += 0.01f;
		if (glfwGetKey(window->getWin(), GLFW_KEY_J) == GLFW_PRESS) rotateX -= 0.01f;
		if (glfwGetKey(window->getWin(), GLFW_KEY_I) == GLFW_PRESS) rotateY += 0.01f;
		if (glfwGetKey(window->getWin(), GLFW_KEY_K) == GLFW_PRESS) rotateY -= 0.01f;
		if (glfwGetKey(window->getWin(), GLFW_KEY_O) == GLFW_PRESS) rotateZ += 0.01f;
		if (glfwGetKey(window->getWin(), GLFW_KEY_L) == GLFW_PRESS) rotateZ -= 0.01f;

		//scale
		if (glfwGetKey(window->getWin(), GLFW_KEY_UP) == GLFW_PRESS) {
			scaleX += 0.001f;
			scaleY += 0.001f;
			scaleZ += 0.001f;
		}
		if (glfwGetKey(window->getWin(), GLFW_KEY_DOWN) == GLFW_PRESS) {
			scaleX -= 0.001f;
			scaleY -= 0.001f;
			scaleZ -= 0.001f;
		}

		//clear screen
		renderer->clearBackground();

		//view
		renderer->setView(renderer->getShaderProgram(), renderer->getView()); // EN SETVIEW O SETPROJ ESTA EL PROBLEMA

		//proj
		renderer->setProj(renderer->getShaderProgram(), renderer->getProj());

		//------
		//Sprite
		//Sprite load texture
		sprite->loadTexture("res/assets/AprobamePorfa.jpg", GL_RGB);

		sprite->SetPosition(transX, transY, transZ);
		sprite->SetRotationX(rotateX);
		sprite->SetRotationY(rotateY);
		sprite->SetRotationZ(rotateZ);
		sprite->SetScale(scaleX, scaleY, scaleZ);

		//Model
		renderer->setModel(renderer->getShaderProgram(), sprite->getModel());
		renderer->drawTr();

		//------
		//Sprite2
		//Sprite load texture
		sprite2->loadTexture("res/assets/dragon.png", GL_RGBA);

		//Model
		renderer->setModel(renderer->getShaderProgram(), sprite2->getModel());
		renderer->drawTr();

		//------
		//Collision detection
		if (sprite->getBounds().min.x < sprite2->getBounds().max.x
			&&
			sprite->getBounds().max.x > sprite2->getBounds().min.x
			&&
			sprite->getBounds().min.y < sprite2->getBounds().max.y
			&&
			sprite->getBounds().max.y > sprite2->getBounds().min.y
			)
			std::cout << "Colliding: YES" << std::endl;
		else std::cout << "Colliding: NO" << std::endl;

		//------
		//Time update
		time->Tick();

		window->swapBuffers();
		window->pollEvents();
	}
}

int Game::terminate()
{
	if (tri) delete tri;
	if (sprite) delete sprite;
	if (sprite2) delete sprite2;

	return 0;
}