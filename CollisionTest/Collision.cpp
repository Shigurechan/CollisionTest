#include "Collision.hpp"
#include "Entry.hpp"
//コンストラクタ
Box_Collision::Box_Collision()
{
	TagType = Tag::Invalid;	//タグ
	mIsTrigger = false;		//トリガータイプ
}

//矩形同士の交差判定
void Box_Collision::Intersect( Box_Collision &a)
{
	if ((a.getPosition().x + a.getSize().x > mPosition->x && mPosition->x + mSize->x > a.getPosition().x)
		&& (a.getPosition().y + a.getSize().y > mPosition->y && mPosition->y + mSize->y > a.getPosition().y))
	{
		printf("true\n");

		if (mIsTrigger == false) 
		{
			printf("mIsTriggeer = false\n");
			//めり込み量を修正
			if (*mVector == VECTOR_RIGHT)
			{
				mPosition->x = a.getPosition().x - a.getSize().x;
			}
			else if (*mVector == VECTOR_LEFT)
			{
				mPosition->x = a.getPosition().x + a.getSize().x;
			}
			else if (*mVector == VECTOR_UP)
			{
				mPosition->y = a.getPosition().y + a.getSize().y;
			}
			else if (*mVector == VECTOR_DOWN)
			{
				mPosition->y = a.getPosition().y - a.getSize().y;
			}

			
			TagType = a.getTag();	//タグを取得


		}
		else
		{

		}





		//return true;
	}
	else
	{
		TagType = Tag::Invalid;
		//printf("false\n");

		//return false;
	}
}

// #################################### 取得　関係

//トリガータイプを取得
bool Box_Collision::getTrigger()
{
	return mIsTrigger;
}


//座標を取得
glm::ivec2 Box_Collision::getPosition()
{
	return *mPosition;
}

//サイズを取得
glm::ivec2 Box_Collision::getSize()
{
	return *mSize;
}

//取得したタイプを取得
Tag Box_Collision::getTag()
{
	return TagType;
}

//方向を取得
glm::ivec2 Box_Collision::getVector()
{
	return *mVector;
}

//タイプを取得
Tag Box_Collision::getMyTag()
{
	return isGetTagType;
}


// #################################### 設定　関係

//トリガータイプを設定
void Box_Collision::setTrigger(bool tri)
{
	mIsTrigger = tri;
}

//座標を設定
void Box_Collision::setPosition(glm::ivec2 *pos)
{
	mPosition = pos;
}

// サイズを設定
void Box_Collision::setSize(glm::ivec2 *size)
{
	mSize = size;
}

//オブジェクトタイプを設定
void Box_Collision::setTag(Tag type)
{
	TagType = type;
}

//オブジェクトタイプを設定
void Box_Collision::setVector(glm::ivec2 *vec)
{
	mVector = vec;
}


//デストラクタ
Box_Collision::~Box_Collision()
{

}