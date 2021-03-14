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

	mVector = VECTOR_NONE;
	
	/*
	mCol.setCenter(&colPos);
	r  = mSize.x;
	printf("R: %d\n",r);
	mCol.setRadius(&r);
	*/

	mCol.setMin(&mPosition);
	Max = mPosition + mSize;
	mCol.setMax(&Max);


}

//�X�V
void Enemy::Update()
{
	//printf("Enemy: %d\n",mCol.getTag());
	//colPos = mPosition + (mSize / 2);

	Max = mPosition + mSize;

}

//�`��
void Enemy::Draw()
{
//	DrawCircle(colPos.x, colPos.y, 100, GetColor(200,0,0), true);

	DrawBox(mPosition.x, mPosition.y, mPosition.x + mSize.x, mPosition.y + mSize.y, GetColor(200, 0, 0), true);
//	DrawFormatString(0, 32, GetColor(200, 0, 0), "# Enemy Position: %d , %d", mPosition.x, mPosition.y);

}


Enemy::~Enemy()
{

}
