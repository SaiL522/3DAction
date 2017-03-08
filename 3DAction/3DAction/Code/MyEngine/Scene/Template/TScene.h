#pragma once

#include "..\Interface\IScene.h"

/**
@class
@brief テンプレートシーンクラス
@author 有冨勇帆
@date 2017/03/08
*/
class TScene :
	public IScene
{
public:
	/**
	@fn
	@brief コンストラクタ
	@author 有冨勇帆
	@date 2017/03/08
	*/
	TScene();
	//開始
	virtual void start() override;
	//更新
	virtual void update(float _deltaTime) override;
	//描画
	virtual void draw(const Renderer & _renderer) override;
	//終了
	virtual void end() override;
	//終了したか？
	virtual bool isEnd() override;
	//次のシーン
	virtual SceneID next() override;
private:
	bool m_isEnd;
};