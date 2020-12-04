#include "Game.h"

Game::Game() {}

Game::~Game() {}

Sprite* sprite;
Sprite* sprite2;

int Game::initialize()
{
	sprite = new Sprite(renderer);
	sprite2 = new Sprite(renderer);

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
		if (input->getKeyPress(FunctionKey::ESCAPE)) window->setWindowShouldClose(true);

		//transform
		if (input->getKeyPress(PrintableKey::W))
		{
			transY += 0.01f;
			sprite->translateBounds(0.0f, 0.01f);
		}
		if (input->getKeyPress(PrintableKey::S))
		{
			transY -= 0.01f;
			sprite->translateBounds(0.0f, -0.01f);
		}
		if (input->getKeyPress(PrintableKey::D))
		{
			transX += 0.01f;
			sprite->translateBounds(0.01f, 0.0f);
		}
		if (input->getKeyPress(PrintableKey::A))
		{
			transX -= 0.01f;
			sprite->translateBounds(-0.01f, 0.0f);
		}
		if (input->getKeyPress(PrintableKey::X)) transZ += 0.001f;
		if (input->getKeyPress(PrintableKey::Z)) transZ -= 0.001f;

		//rotate
		if (input->getKeyPress(PrintableKey::U)) rotateX += 0.01f;
		if (input->getKeyPress(PrintableKey::J)) rotateX -= 0.01f;
		if (input->getKeyPress(PrintableKey::I)) rotateY += 0.01f;
		if (input->getKeyPress(PrintableKey::K)) rotateY -= 0.01f;
		if (input->getKeyPress(PrintableKey::O)) rotateZ += 0.01f;
		if (input->getKeyPress(PrintableKey::L)) rotateZ -= 0.01f;

		//scale
		if (input->getKeyPress(FunctionKey::UP))
		{
			scaleX += 0.001f;
			scaleY += 0.001f;
			scaleZ += 0.001f;
		}

		if (input->getKeyPress(FunctionKey::DOWN))
		{
			scaleX -= 0.001f;
			scaleY -= 0.001f;
			scaleZ -= 0.001f;
		}

		//clear screen
		renderer->clearBackground();

		//view
		renderer->setView(renderer->getShaderProgram(), renderer->getView());

		//proj
		renderer->setProj(renderer->getShaderProgram(), renderer->getProj());

		//------
		//Sprite
		//Sprite load texture
		sprite->loadTexture("res/assets/AprobamePorfa.jpg", RGB);

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
		sprite2->loadTexture("res/assets/dragon.png", RGBA);

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
	if (sprite) delete sprite;
	if (sprite2) delete sprite2;

	return 0;
}