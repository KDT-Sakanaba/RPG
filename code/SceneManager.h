#pragma once
#include <memory>
#include <algorithm>
#include "View.h"

class SceneManager;

class Scene
{
protected:
	std::shared_ptr<View> view;
public:
	Scene(std::shared_ptr<View> view_ptr) {
		view = view_ptr;
	}
	virtual ~Scene() = default;
	virtual void Init() = 0;
	virtual void Update(SceneManager* manager) = 0;
	virtual void Exit() = 0;
};

class SceneManager 
{

	std::unique_ptr<Scene> currentState;

public:

	SceneManager() {}

	// ƒV[ƒ“•ÏX
	void ChangeScene(std::unique_ptr<Scene> newState) 
	{
		if (currentState) {
			currentState->Exit();
		}
		currentState = std::move(newState);
		currentState->Init();
	}
	void Update() {
		if (currentState)
		{
			return;
		}
		currentState->Update();
	}

};