#pragma once
#include <string>
#include <mutex>
#include "ThreadSafeVector.h"

class GameObject;

enum class SceneState
{
	Enabled,
	Disabled,
	Unloaded,
	Loading,
	Unloading
};

class Scene
{
public:
	Scene();
	virtual ~Scene() = default;

	void loadAssets();
	void loadGameObjects();
	void unloadAssetsAndGameObjects();

	void enable();
	void disable();
	
	ThreadSafeVector<GameObject*>& getGameObjects();
	SceneState getSceneState() const;
	float getPercentLoaded() const;

protected:
	void addAsset(const std::string& assetName);

private:
	std::vector<std::string> assets;
	ThreadSafeVector<GameObject*> gameObjects;
	SceneState sceneState;
	int assetsLoaded;
};
