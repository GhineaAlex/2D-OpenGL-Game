#include "../Engine/Grafica/Sprite.h"
#include "../Engine/Fizica/Rigid.h"

class Joc
{
public:

	Joc();
	Joc(Sprite _sprite);

	void Refresh();
	void Render();
	
	Sprite & getSprite();
	Rigid & getRigid();

private:
	Sprite sprite;
	Rigid rb;
};