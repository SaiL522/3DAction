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
	//�e�탌���_�����O���[�h�̑ޔ�
	glPushAttrib(GL_ENABLE_BIT);
	//���C�e�B���O�𖳌��ɂ���
	glDisable(GL_LIGHTING);
	//���o�b�t�@�𖳌��ɂ���
	glDisable(GL_DEPTH_TEST);
	//�ʉȃ����O�𖳌��ɂ���
	glDisable(GL_CULL_FACE);
	//�J�����g�J���[���擾����
	GScolor currentColor;
	glGetFloatv(GL_CURRENT_COLOR, (GLfloat*)&currentColor);
	//�e�N�X�`�����o�C���h����
	gsBindTexture(_id);
	//�����ϊ��s��̑ޔ�
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	//�����ϊ��s��̐ݒ�
	glLoadIdentity();

	gluOrtho2D(0, CAST_GL_DOUBLE(Screen::WIDTH), CAST_GL_DOUBLE(Screen::HEIGHT), 0);

	//���f���r���[�ϊ��s��̑ޔ�
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	//�ϊ��s��̏�����
	glLoadIdentity();
	//���s�ړ��ʂ̐ݒ���s��
	glTranslatef(_position.x, _position.y, 0.f);
	//��]�p�x�̐ݒ���s��
	glRotatef(_rotation, 0.f, 0.f, 1.f);
	//�g��k�����s��
	glScalef(_scale.x, _scale.y, 0.f);
	//�o�C���h���̃e�N�X�`���̕��ƍ������擾
	GLsizei s_texWidth;
	GLsizei s_texHeight;
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &s_texWidth);
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &s_texHeight);
	//���S�ʒu�̕␳���s��
	GSvector3 center = {
		_center.x * s_texWidth,
		_center.y * s_texHeight,
		0.f
	};
	glTranslatef(-center.x, -center.y, 0.f);
	//���_�J���[�̐ݒ�
	glColor4fv((GLfloat*)_color);
	//�e�N�X�`�����W�̌v�Z���s��
	GSrect rect;
	rect.left = _rect.left / s_texWidth;
	rect.top = _rect.top / s_texHeight;
	rect.right = _rect.right / s_texWidth;
	rect.bottom = _rect.bottom / s_texHeight;
	GLfloat f_width = std::abs(_rect.right - _rect.left);
	GLfloat f_height = std::abs(_rect.bottom - _rect.top);
	//�l�p�`�̕`��
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
	//���f���r���[�ϊ��s��𕜋A
	glPopMatrix();
	//�����ϊ��s��𕜋A
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	//���f���r���[�ϊ��s��ɐݒ�
	glMatrixMode(GL_MODELVIEW);
	//�J�����g�J���[�𕜋A����
	glColor4fv((GLfloat*)&currentColor);
	//�����_�����O���[�h�̕��A
	glPopAttrib();
}
