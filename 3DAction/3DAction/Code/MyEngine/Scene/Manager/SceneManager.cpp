#include "SceneManager.h"
#include "..\Interface\IScene.h"
#include <algorithm>
#include <functional>
#include <iostream>

//コンストラクタ
SceneManager::SceneManager() :
	m_scenes(),
	m_currentScene(SceneID::NONE)
{
}

//開始
void SceneManager::start()
{
}

//更新
void SceneManager::update(float _deltaTime)
{
	if (m_currentScene == SceneID::NONE) return;

	m_scenes.at(m_currentScene)->update(_deltaTime);

	change();
}

//描画
void SceneManager::draw(const Renderer& _renderer)
{
	if (m_currentScene == SceneID::NONE) return;

	m_scenes.at(m_currentScene)->draw(_renderer);
}

//終了
void SceneManager::end()
{
}

//シーンの追加
void SceneManager::addScene(SceneID _id, std::unique_ptr<IScene>* _scene)
{
	(*_scene)->start();
	m_scenes.insert(std::make_pair(_id, std::move(*_scene)));
}

//シーン切り替え
void SceneManager::changeScene(SceneID _id)
{
	SceneID previousScene = m_currentScene;
	m_currentScene = _id;

	if (m_currentScene == SceneID::NONE) return;

	m_scenes.at(m_currentScene)->start();

	if (previousScene == SceneID::NONE) return;

	m_scenes.at(previousScene)->end();
}

//シーン切り替え
void SceneManager::change()
{
	if (m_scenes.at(m_currentScene)->isEnd() == false) return;

		changeScene( m_scenes.at(m_currentScene)->next());
}
