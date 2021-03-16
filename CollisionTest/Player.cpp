#include "Player.hpp"
#include "Entry.hpp"
#include "Collision.hpp"

Player::Player(Entry* e) : Actor(e)
{
	//�������W
	mPosition.x = 235;
	mPosition.y = 270;

	//�T�C�Y
	mSize.x = 100;
	mSize.y = 100;

	//�����蔻���ݒ�
	/*
	mCol.setCenter(&colPos);
	r = mSize.x;
	mCol.setRadius(&r);

	mCol.setVector(&mVector);
	*/
	Max = mPosition + mSize;
	mCol.setMin(&mPosition);
	mCol.setMax(&Max);

	mCol.setVector(&mVector);
	mCol.setSpeed(&mSpeed);

}


//�X�V
void Player::Update()
{
	mSpeed.x = 5;
	mSpeed.y = 5;

	if (Owner->InputKey->getKeyDownHold(KEY_INPUT_LEFT) > 0)
	{		
		mVector.x = -1;
	}
	else if (Owner->InputKey->getKeyDownHold(KEY_INPUT_RIGHT) > 0)
	{		
		mVector.x = 1;

	}
	else 
	{
		mVector.x = 0;
		mSpeed.x = 0;
		s = 0;
	}


	if (Owner->InputKey->getKeyDownHold(KEY_INPUT_UP) > 0)
	{
		mVector.y = -1;
	}
	else if(Owner->InputKey->getKeyDownHold(KEY_INPUT_DOWN) > 0)
	{
		mVector.y = 1;
	}
	else 
	{	
		mVector.y = 0;
		mSpeed.y = 0;

	}
	
	mPosition += mVector * mSpeed;	//���W�ړ�



//	colPos = mPosition + (mSize / 2);

	Max = mPosition + mSize;



}

//�`��
void Player::Draw()
{
//	DrawCircle(colPos.x, colPos.y, 100, GetColor(0, 200, 0), true);
	DrawBox(mPosition.x, mPosition.y, mPosition.x + mSize.x, mPosition.y + mSize.y,GetColor(0,255,0),true);
	//DrawFormatString(0,0,GetColor(0,255,0),"# Player Position: %d , %d",mPosition.x,mPosition.y);

}


Player::~Player()
{

}