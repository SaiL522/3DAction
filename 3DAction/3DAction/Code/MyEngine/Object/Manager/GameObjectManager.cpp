#include "GameObjectManager.h"
#include "..\Interface\IGameObject.h"
#include "..\..\FrameWork\Renderer.h"
#include <algorithm>
#include <functional>

//コンストラクタ
GameObjectManager::GameObjectManager()
{
}

//開始
void GameObjectManager::start()
{
}

//更新
void GameObjectManager::update(float _deltaTime)
{
	std::for_each(
		m_objs.begin(),
		m_objs.end(),
		std::bind(std::mem_fn(&IGameObject::update), std::placeholders::_1, _deltaTime)
	);

	collision();

	addObject();
}

//描画
void GameObjectManager::draw(const Renderer & _renderer)
{
	std::for_each(
		m_objs.begin(),
		m_objs.end(),
		std::bind(std::mem_fn(&IGameObject::draw), std::placeholders::_1, _renderer)
	);
}

//終了
void GameObjectManager::end()
{
	m_objs.clear();
}

//オブジェクトの追加
void GameObjectManager::add(std::unique_ptr<IGameObject>* _object)
{
	m_newObjs.emplace_back(std::move(*_object));
}

//衝突判定
void GameObjectManager::collision()
{
	for (Obj_List::iterator i = m_objs.begin(); i != m_objs.end(); i++) {
		for (Obj_List::iterator j = m_objs.begin(); j != m_objs.end(); j++) {
			(*i)->collision((*(*j).get()));
		}
	}
}

//オブジェクトを追加
void GameObjectManager::addObject()
{
	for (Obj_List::iterator i = m_newObjs.begin(); i != m_newObjs.end(); i++)
	{
		(*i)->start();

		m_objs.emplace_back(std::move(*i));
	}

	m_newObjs.clear();
}
