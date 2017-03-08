#pragma once

#include <gslib.h>
#include "../ID/GameTag.h"

class Renderer;

/**
@interface
@brief ゲームオブジェクトインターフェイス
@author 有冨勇帆
@date 2017/03/07
*/
class IGameObject
{
public:
	/**
	@fn
	@brief デストラクタ
	*/
	virtual ~IGameObject() = default;
	/**
	@fn
	@brief 開始
	*/
	virtual void start() = 0;
	/**
	@fn
	@brief 更新
	*/
	virtual void update(float _deltaTime) = 0;
	/**
	@fn
	@brief 描画
	*/
	virtual void draw(const Renderer& _renderer) = 0;
	/**
	@fn
	@brief 衝突判定
	*/
	virtual void collision(const IGameObject& _other) = 0;
	/**
	@fn
	@brief オブジェクトの位置を返す
	@return オブジェクトの位置
	*/
	virtual GSvector2 Pos() const = 0;
	/**
	@fn
	@brief オブジェクトの半径を返す
	@return オブジェクトの半径
	*/
	virtual float R() const = 0;
	/**
	@fn
	@brief オブジェクトのタグを返す
	@return オブジェクトのタグ
	*/
	virtual GameTag Tag() const = 0;
};