#include "Collision.hpp"
#include "Entry.hpp"
//コンストラクタ
Box_Collision::Box_Collision()
{
	col_TagType = Tag::Invalid;	//取得　タグ
	my_TagType = Tag::Invalid;	//自身　タグ

	IsTrigger = false;		//トリガータイプ
	isCol = false;			//交差したかどうか？
}
/*
//矩形同士の交差判定
void Box_Collision::Intersect( Box_Collision &a)
{
	if ((a.getPosition().x + a.getSize().x > Position->x && Position->x + Size->x > a.getPosition().x)
		&& (a.getPosition().y + a.getSize().y > Position->y && Position->y + Size->y > a.getPosition().y))
	{
		isCol = true;
		col_TagType = a.getMyTag();	//タグを取得
		a.setColTag(getMyTag());	//タグを設定
		
		if (IsTrigger == false) 
		{

			//めり込み量を修正
			if (*Vector == VECTOR_RIGHT)
			{
				Position->x = a.getPosition().x - a.getSize().x;
			}
			else if (*Vector == VECTOR_LEFT)
			{
				Position->x = a.getPosition().x + a.getSize().x;
			}
			else if (*Vector == VECTOR_UP)
			{
				Position->y = a.getPosition().y + a.getSize().y;
			}
			else if (*Vector == VECTOR_DOWN)
			{
				Position->y = a.getPosition().y - a.getSize().y;
			}
			else if (*Vector == VECTOR_NONE)
			{
				//ベクトルが設定されていないとき
	
				//めり込み量を修正
				if (a.getVector() == VECTOR_RIGHT)
				{
					Position->x = a.getPosition().x + a.getSize().x;
				}
				else if (a.getVector() == VECTOR_LEFT)
				{
					Position->x = a.getPosition().x - a.getSize().x;
				}
				else if (a.getVector() == VECTOR_UP)
				{
					Position->y = a.getPosition().y - a.getSize().y;
				}
				else if (a.getVector() == VECTOR_DOWN)
				{
					Position->y = a.getPosition().y + a.getSize().y;
				}
			}
		}	
	}
	else
	{
		//交差していない
		isCol = false;
		col_TagType = Tag::Invalid;
		a.setColTag(Tag::Invalid);	
	}
}
*/
// #################################### 取得　関係

//トリガータイプを取得
bool Box_Collision::getTrigger()
{
	return IsTrigger;
}


//座標を取得
glm::ivec2 Box_Collision::getPosition()
{
	return *Position;
}

//サイズを取得
glm::ivec2 Box_Collision::getSize()
{
	return *Size;
}

//取得したタイプを取得
Tag Box_Collision::getTag()
{
	return col_TagType;
}

//方向を取得
glm::ivec2 Box_Collision::getVector()
{
	return *Vector;
}

//タイプを取得
Tag Box_Collision::getMyTag()
{
	return my_TagType;
}

//当たったかどうか？
bool Box_Collision::getCol()
{
	return isCol;
}

// #################################### 設定　関係

//トリガータイプを設定
void Box_Collision::setTrigger(bool tri)
{
	IsTrigger = tri;
}

//座標を設定
void Box_Collision::setPosition(glm::ivec2 *pos)
{
	Position = pos;
}

// サイズを設定
void Box_Collision::setSize(glm::ivec2 *size)
{
	Size = size;
}

//オブジェクトタイプを設定
void Box_Collision::setTag(Tag type)
{	
	my_TagType = type;
}

//オブジェクトタイプを設定
void Box_Collision::setVector(glm::ivec2 *vec)
{
	Vector = vec;
}

//当たり判定のタグを設定
void Box_Collision::setColTag(Tag type)
{
	col_TagType = type;
}

//デストラクタ
Box_Collision::~Box_Collision()
{

}








/*
//矩形同士の交差判定
void Box_Collision::Intersect(Box_Collision& a)
{
	if ((a.getPosition().x + a.getSize().x > Position->x && Position->x + Size->x > a.getPosition().x)
		&& (a.getPosition().y + a.getSize().y > Position->y && Position->y + Size->y > a.getPosition().y))
	{
		isCol = true;
		col_TagType = a.getMyTag();	//タグを取得
		a.setColTag(getMyTag());	//タグを設定

		if (IsTrigger == false)
		{

			//めり込み量を修正
			if (*Vector == VECTOR_RIGHT)
			{
				Position->x = a.getPosition().x - a.getSize().x;
			}
			else if (*Vector == VECTOR_LEFT)
			{
				Position->x = a.getPosition().x + a.getSize().x;
			}
			else if (*Vector == VECTOR_UP)
			{
				Position->y = a.getPosition().y + a.getSize().y;
			}
			else if (*Vector == VECTOR_DOWN)
			{
				Position->y = a.getPosition().y - a.getSize().y;
			}
			else if (*Vector == VECTOR_NONE)
			{
				//ベクトルが設定されていないとき

				//めり込み量を修正
				if (a.getVector() == VECTOR_RIGHT)
				{
					Position->x = a.getPosition().x + a.getSize().x;
				}
				else if (a.getVector() == VECTOR_LEFT)
				{
					Position->x = a.getPosition().x - a.getSize().x;
				}
				else if (a.getVector() == VECTOR_UP)
				{
					Position->y = a.getPosition().y - a.getSize().y;
				}
				else if (a.getVector() == VECTOR_DOWN)
				{
					Position->y = a.getPosition().y + a.getSize().y;
				}
			}
		}
	}
	else
	{
		//交差していない
		isCol = false;
		col_TagType = Tag::Invalid;
		a.setColTag(Tag::Invalid);
	}
}
*/