#include "TitleScene.h"
#include "View.h"
#include "Process.h"
#include "GameScene.h"

void Title::Init()
{

}

void Title::Update(SceneManager* manager)
{
	
	view->Start();

	std::cin >> keyPress;
	if (keyPress == 1) {
		manager->ChangeScene();
		keyPress = 0;
	}
}

void Title::Exit()
{
}
