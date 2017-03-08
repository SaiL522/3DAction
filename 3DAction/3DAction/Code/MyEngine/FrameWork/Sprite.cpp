#include "Sprite.h"
#include "..\Def\GameDef.h"
#include <algorithm>

#define CAST_GL_DOUBLE(_x)(static_cast<GLdouble>(_x))

Sprite::Sprite()
{
}

Sprite::~Sprite()
{
}

void Sprite::DrawSprite2D(
	GSuint _id, 
	const GSvector2 & _position, 
	const GSrect & _rect, 
	const GSvector2 & _center, 
	const GSvector2 & _scale, 
	const GSfloat _rotation, 
	const GScolor & _color)
{
	//各種レンダリングモードの退避
	glPushAttrib(GL_ENABLE_BIT);
	//ライティングを無効にする
	glDisable(GL_LIGHTING);
	//ｚバッファを無効にする
	glDisable(GL_DEPTH_TEST);
	//面科リングを無効にする
	glDisable(GL_CULL_FACE);
	//カレントカラーを取得する
	GScolor currentColor;
	glGetFloatv(GL_CURRENT_COLOR, (GLfloat*)&currentColor);
	//テクスチャをバインドする
	gsBindTexture(_id);
	//透視変換行列の退避
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	//透視変換行列の設定
	glLoadIdentity();

	gluOrtho2D(0, CAST_GL_DOUBLE(Screen::WIDTH), CAST_GL_DOUBLE(Screen::HEIGHT), 0);

	//モデルビュー変換行列の退避
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	//変換行列の初期化
	glLoadIdentity();
	//平行移動量の設定を行う
	glTranslatef(_position.x, _position.y, 0.f);
	//回転角度の設定を行う
	glRotatef(_rotation, 0.f, 0.f, 1.f);
	//拡大縮小を行う
	glScalef(_scale.x, _scale.y, 0.f);
	//バインド中のテクスチャの幅と高さを取得
	GLsizei s_texWidth;
	GLsizei s_texHeight;
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &s_texWidth);
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &s_texHeight);
	//中心位置の補正を行う
	GSvector3 center = {
		_center.x * s_texWidth,
		_center.y * s_texHeight,
		0.f
	};
	glTranslatef(-center.x, -center.y, 0.f);
	//頂点カラーの設定
	glColor4fv((GLfloat*)_color);
	//テクスチャ座標の計算を行う
	GSrect rect;
	rect.left = _rect.left / s_texWidth;
	rect.top = _rect.top / s_texHeight;
	rect.right = _rect.right / s_texWidth;
	rect.bottom = _rect.bottom / s_texHeight;
	GLfloat f_width = std::abs(_rect.right - _rect.left);
	GLfloat f_height = std::abs(_rect.bottom - _rect.top);
	//四角形の描画
	glBegin(GL_QUADS);
	glTexCoord2f(rect.left, rect.top);
	glVertex2f(0, 0);
	glTexCoord2f(rect.left, rect.bottom);
	glVertex2f(0, f_height);
	glTexCoord2f(rect.right, rect.bottom);
	glVertex2f(f_width, f_height);
	glTexCoord2f(rect.right, rect.top);
	glVertex2f(f_width, 0);
	glEnd();
	//モデルビュー変換行列を復帰
	glPopMatrix();
	//透視変換行列を復帰
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	//モデルビュー変換行列に設定
	glMatrixMode(GL_MODELVIEW);
	//カレントカラーを復帰する
	glColor4fv((GLfloat*)&currentColor);
	//レンダリングモードの復帰
	glPopAttrib();
}
