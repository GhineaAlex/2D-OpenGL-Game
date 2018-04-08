#include <iostream>
#include "Engine/Engine.h"

#include "Engine/Grafica/Sprite.h"
#include "Engine/Input/Mouse.h"
#include "Joc\Joc.h"
#include "Engine/Input/Tastatura.h"
using namespace std;

int main()
{
	Engine engine;
	engine.InitEngine((char*)"Joc");
	
	Sprite testSprite = Sprite("Assets/Biplane.png", Vector3p(300, 300, 0) );
	Sprite test = Sprite("Assets/mountain.png", Vector3p(50, 100, 0));

	Joc player(testSprite);

	testSprite.setScalare(1);
	test.setScalare(1);
	//delta multiplicata cu viteza 
	while (true)
	{

		
		engine.Refresh();
		test.Refresh();

		player.Refresh();
		
		//testSprite.TranslateTo( (float)Mouse::getMouseX(), (float)Mouse::getMouseY() );


		if (Mouse::butonApasat(GLFW_MOUSE_BUTTON_LEFT)) //buton mouse stanga
		{
			player.getSprite().RotitCu(10000);
			//testSprite.RotateLa(10);
		}

		if (Mouse::butonApasat(GLFW_MOUSE_BUTTON_RIGHT)) //buton mouse dreapta
		{
			player.getSprite().RotitCu(-10000);
		}
		
		if (Tastatura::key(GLFW_KEY_W)) 
		{
			
			//player.getSprite().TranslateSus();
			player.getRigid().Forta(Vector3p(0, 0.1, 0));

		}
		if (Tastatura::key(GLFW_KEY_S))
		{
			player.getRigid().Forta(Vector3p(0, -0.1, 0));
			//player.getSprite().TranslateJos();

		}

		if (Tastatura::key(GLFW_KEY_A))
		{
			player.getRigid().Forta(Vector3p(-50, 0, 0));
			//player.getSprite().TranslateStg();

		}
		if (Tastatura::key(GLFW_KEY_D))
		{
			player.getRigid().Forta(Vector3p(50, 0, 0));
			//player.getSprite().TranslateDr();
		}
		
		//if (Tastatura::Key(GLFW_KEY_W))
		
		engine.incepeRender();

		player.Render();
		test.Render();
		engine.termRender();
	}
}