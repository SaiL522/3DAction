#pragma once

#include "..\Interface\IGameObject.h"

/**
@class
@brief テンプレートゲームオブジェクトクラス
@author 有冨勇帆
@date 2017/03/07
*/
class TGameObject :
	public IGameObject
{
public:
	/**
	@fn
	@brief コンストラクタ
	*/
	TGameObject();
	//開始
	virtual void start() override;
	//更新
	virtual void update(float _deltaTime) override;
	//描画
	virtual void draw(const Renderer & _renderer) override;
	//衝突判定
	virtual void collision(const IGameObject & _other) override;
	//オブジェクトの位置
	virtual GSvector2 Pos() const override;
	//オブジェクトの半径
	virtual float R() const override;
	// IGameObject を介して継承されました
	virtual GameTag Tag() const override;
protected:
	GameTag m_tag; //オブジェクトのタグ
	GSvector2 m_pos; //オブジェクトの位置
	float m_r; //オブジェクトの半径
};