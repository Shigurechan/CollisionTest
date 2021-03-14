#include "Collision.hpp"
#include "Entry.hpp"


/*####################################################
* 当たり判定の基底クラス
######################################################*/

//コンストラクタ
Collision::Collision()
{
	col_TagType = Tag::Invalid;	//取得　タグ
	my_TagType = Tag::Invalid;	//自身　タグ

	IsTrigger = false;		//トリガータイプ
	isCol = false;			//交差したかどうか？
	Vector = nullptr;		//方向
}

// #################################### 取得　関係

//トリガータイプを取得
bool Collision::getTriggerType()
{
	return IsTrigger;
}

//取得したタイプを取得
Tag Collision::getTag()
{
	return col_TagType;
}

//方向を取得
glm::ivec2 Collision::getVector()
{
	return *Vector;
}

//タイプを取得
Tag Collision::getMyTag()
{
	return my_TagType;
}

//当たったかどうか？
bool Collision::getCol()
{
	return isCol;
}

// #################################### 設定　関係

//トリガータイプを設定
void Collision::setTriggerType(bool tri)
{
	IsTrigger = tri;
}

//タグタイプを設定
void Collision::setTag(Tag type)
{	
	my_TagType = type;
}

//オブジェクトタイプを設定
void Collision::setVector(glm::ivec2 *vec)
{
	Vector = vec;
}

//当たり判定のタグを設定
void Collision::setColTag(Tag type)
{
	col_TagType = type;
}

//当たり判定のタグを設定
void Collision::setCol(bool b)
{
	isCol = b;
}


//デストラクタ
Collision::~Collision()
{

}


/*##############################################################################################################################################*/

/*####################################################
* 矩形の当たり判定
######################################################*/

//コンストラクタ
BoxCollision::BoxCollision()
{
	box.mMax = nullptr;	//AABB初期化
	box.mMin = nullptr;	//AABB初期化
}



void BoxCollision::Intersect(BoxCollision& col)
{
	if ((col.getMax().x > box.mMin->x && box.mMax->x > col.getMin().x)
		&& (col.getMax().y > box.mMin->y && box.mMax->y > col.getMin().y))
	{
		
		setCol(true);				//当たり判定を設定
		setColTag(col.getMyTag());	//タグを取得
		col.setColTag(getMyTag());	//タグを設定

		if (getTriggerType() == false)
		{

			//めり込み量を修正
			if (getVector() == VECTOR_RIGHT)
			{
				glm::ivec2 b = *box.mMax - *box.mMin;
				box.mMin->x = (col.getMin().x - b.x);

			}
			else if (getVector() == VECTOR_LEFT)
			{
			
				box.mMin->x = (col.getMax().x);

			}
			else if (getVector() == VECTOR_UP)
			{
				//printf("ううう\n");
				glm::ivec2 b = *box.mMax - *box.mMin;
				box.mMin->y = (col.getMin().y + b.y + 1);

			}
			else if (getVector() == VECTOR_DOWN)
			{
				//printf("111\n");

				glm::ivec2 b = *box.mMax - *box.mMin;

				box.mMin->y = (col.getMin().y - b.y);

			}
			else if (getVector() == VECTOR_NONE)
			{
				//ベクトルが設定されていないとき
				
				if (col.getVector() == VECTOR_RIGHT)
				{		
					glm::ivec2 b = col.getMax() - col.getMin();
					glm::ivec2 t = col.getMin();
					t.x = box.mMin->x - b.x;
					col.setMinValue(t);
				}
				else if (col.getVector() == VECTOR_LEFT)
				{	
					glm::ivec2 t = col.getMin();
					t.x = box.mMax->x;
					col.setMinValue(t);
				}
				else if (col.getVector() == VECTOR_UP)
				{
					glm::ivec2 b = col.getMax() - col.getMin();
					glm::ivec2 t = col.getMin();
					t.y = box.mMax->y;
					col.setMinValue(t);

				}
				else if (col.getVector() == VECTOR_DOWN)
				{
					glm::ivec2 b = col.getMax() - col.getMin();
					glm::ivec2 t = col.getMin();
					t.y = box.mMin->y - b.y;
					col.setMinValue(t);

				}	
			}
		}
	}
	else
	{
		//交差していない
		
		setCol(false);
		setColTag(Tag::Invalid);
		col.setColTag(Tag::Invalid);
	}
}


// #################################### 取得　関係

//最大値を取得
glm::ivec2 BoxCollision::getMax()
{
	return *box.mMax;
}

//最小値を取得
glm::ivec2 BoxCollision::getMin()
{
	return *box.mMin;
}




// #################################### 設定　関係

//最大値を設定
void BoxCollision::setMax(glm::ivec2 *max)
{
	box.mMax = max;
}

//最小値を設定
void BoxCollision::setMin(glm::ivec2 *min)
{
	box.mMin = min;
}

//最大値の値を設定
void BoxCollision::setMaxValue(glm::ivec2& max)
{
	*box.mMax = max;
}

//最小値の値を設定
void BoxCollision::setMinValue(glm::ivec2& min)
{
	*box.mMin = min;

}



//デストラクタ
BoxCollision::~BoxCollision()
{

}



/*##############################################################################################################################################*/

/*####################################################
*　球の当たり判定
######################################################*/


//コンストラクタ
CircleCollision::CircleCollision()
{

}

//デストラクタ
CircleCollision::~CircleCollision()
{

}

//交差判定
void CircleCollision::Intersect(CircleCollision& col)
{
	//printf("あああ%d\n",col.getRadius());
	//printf("あああ%d\n",getRadius());

	int c = sqrt((col.getCenter().x - getCenter().x) * (col.getCenter().x - getCenter().x) +
			(col.getCenter().y - getCenter().y) * (col.getCenter().y - getCenter().y));

	//printf("C:%d\n",c);
	if ( c <= (col.getRadius() + getRadius()) )
	{
//		printf("true\n");

		//タグと当たり判定
		setCol(true);				//当たり判定を設定
		setColTag(col.getMyTag());	//タグを取得
		col.setColTag(getMyTag());	//タグを設定

		if (getTriggerType() == false)
		{
			int len = sqrt((col.getCenter().x - getCenter().x) * (col.getCenter().x - getCenter().x) +
				(col.getCenter().y - getCenter().y) * (col.getCenter().y - getCenter().y));
			printf("len %d\n",len);

			float m = (col.getRadius() + getRadius()) - len;	//めり込み量

//			printf("いいい %d\n", getRadius());
//			printf("ああああ %d\n", col.getRadius());

//			printf("m %f\n",m);
			glm::vec2 BA = getCenter() - col.getCenter();	//BAのベクトル
//			printf("cccc  %f , %f\n", BA.x, BA.y);

			BA = glm::normalize(BA);	//正規化
//			printf("aaa %f , %f\n",BA.x,BA.y);
			BA = BA * -1.0f;	//ベクトルの反転
//			printf("bbb %f , %f\n", BA.x, BA.y);

			BA = BA * m;
			printf("BA %f , %f\n", BA.x, BA.y);

			glm::ivec2 pos = BA;
			glm::ivec2 p = getCenter() - pos;

			setCenterValue(p);



		}
	}
	else
	{
		//交差していない
	//	printf("false\n");

		//タグと当たり判定
		setCol(false);					//当たり判定を設定
		setColTag(Tag::Invalid);		//タグを取得
		col.setColTag(Tag::Invalid);	//タグを設定
	}
}


// #################################### 取得　関係

//半径取得
int CircleCollision::getRadius()
{
	return *sp.mRadius;
}

//位置取得
glm::ivec2 CircleCollision::getCenter()
{
	return *sp.mCenter;
}

/// #################################### 設定　関係

//半径　設定　ポインタ
void CircleCollision::setRadius(int *r)
{
	sp.mRadius = r;
}

//位置　設定　ポインタ
void CircleCollision::setCenter(glm::ivec2 *pos)
{
	sp.mCenter = pos;
}

//半径 値を設定
void CircleCollision::setRadiusValue(int r)
{
	*sp.mRadius = r;
}

//位置　値を設定
void CircleCollision::setCenterValue(glm::ivec2 pos)
{
	*sp.mCenter = pos;
}




 