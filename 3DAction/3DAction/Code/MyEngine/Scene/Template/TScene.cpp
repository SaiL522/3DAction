#include "TScene.h"

//コンストラクタ
TScene::TScene() :
	m_isEnd(false)
{
}

//開始
void TScene::start()
{
}

//更新
void TScene::update(float _deltaTime)
{
}

//描画
void TScene::draw(const Renderer & _renderer)
{
}

//終了
void TScene::end()
{
}

//終了したか？
bool TScene::isEnd()
{
	return false;
}

//次のシーン
SceneID TScene::next()
{
	return SceneID();
}
