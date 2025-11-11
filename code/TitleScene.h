#include "SceneManager.h"
#include <memory>

class Title : public Scene
{
	
	int keyPress;
public:

	void Init() override;
	void Update(SceneManager* manager) override;
	void Exit() override;
};
