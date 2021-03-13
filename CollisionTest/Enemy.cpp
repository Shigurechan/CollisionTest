#include "Enemy.hpp"
#include "Entry.hpp"


Enemy::Enemy(Entry* e) : Actor(e)
{
	//�T�C�Y
	mSize.x = 100;
	mSize.y = 100;

	//�������W
	mPosition.x = (SCREEN_WIDTH / 2) - (mSize.x / 2);
	mPosition.y = (SCREEN_HEIGHT / 2) - (mSize.y / 2);

	
}

//�X�V
void Enemy::Update()
{
	
}

//�`��
void Enemy::Draw()
{
	DrawBox(mPosition.x, mPosition.y, mPosition.x + mSize.x, mPosition.y + mSize.y, GetColor(200, 0, 0), true);
	DrawFormatString(0, 32, GetColor(200, 0, 0), "# Enemy Position: %d , %d", mPosition.x, mPosition.y);

}


Enemy::~Enemy()
{

}
