#include "SceneManager.h"
#include "..\Interface\IScene.h"
#include <algorithm>
#include <functional>
#include <iostream>

//�R���X�g���N�^
SceneManager::SceneManager() :
	m_scenes(),
	m_currentScene(SceneID::NONE)
{
}

//�J�n
void SceneManager::start()
{
}

//�X�V
void SceneManager::update(float _deltaTime)
{
	if (m_currentScene == SceneID::NONE) return;

	m_scenes.at(m_currentScene)->update(_deltaTime);

	change();
}

//�`��
void SceneManager::draw(const Renderer& _renderer)
{
	if (m_currentScene == SceneID::NONE) return;

	m_scenes.at(m_currentScene)->draw(_renderer);
}

//�I��
void SceneManager::end()
{
}

//�V�[���̒ǉ�
void SceneManager::addScene(SceneID _id, std::unique_ptr<IScene>* _scene)
{
	(*_scene)->start();
	m_scenes.insert(std::make_pair(_id, std::move(*_scene)));
}

//�V�[���؂�ւ�
void SceneManager::changeScene(SceneID _id)
{
	SceneID previousScene = m_currentScene;
	m_currentScene = _id;

	if (m_currentScene == SceneID::NONE) return;

	m_scenes.at(m_currentScene)->start();

	if (previousScene == SceneID::NONE) return;

	m_scenes.at(previousScene)->end();
}

//�V�[���؂�ւ�
void SceneManager::change()
{
	if (m_scenes.at(m_currentScene)->isEnd() == false) return;

		changeScene( m_scenes.at(m_currentScene)->next());
}
