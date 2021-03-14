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
glm::vec2 Collision::getVector()
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


//速度を取得
glm::vec2 Collision::getSpeed()
{
	return *Speed;
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
void Collision::setVector(glm::vec2 *vec)
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



//速度を設定
void Collision::setSpeed(glm::vec2 *spp)
{
	Speed = spp;
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
	


	if ((col.getMax().x > box.mMin->x && box.mMax->x> col.getMin().x)
		&& (col.getMax().y > box.mMin->y - getSpeed().y && box.mMax->y - getSpeed().y > col.getMin().y))
	{		
		setCol(true);				//当たり判定を設定
		setColTag(col.getMyTag());	//タグを取得
		col.setColTag(getMyTag());	//タグを設定

		printf("X\n");
		if (getTriggerType() == false)
		{

			if (getVector().x > 0) 
			{
				glm::vec2 size = getMax() - getMin();
				glm::vec2 pos = col.getMin() - size;
				pos.y = getMin().y;

				setMinValue(pos);
			}



		}

	}
	else if ((col.getMax().x > box.mMin->x && box.mMax->x > col.getMin().x)
		&& (col.getMax().y > box.mMin->y && box.mMax->y > col.getMin().y)) 
	{

		setCol(true);				//当たり判定を設定
		setColTag(col.getMyTag());	//タグを取得
		col.setColTag(getMyTag());	//タグを設定

		printf(" Y\n");


		if (getTriggerType() == false)
		{

		}

	}
	else {





		//交差していない		
		setCol(false);
		setColTag(Tag::Invalid);
		col.setColTag(Tag::Invalid);
	}
	
}


// #################################### 取得　関係

//最大値を取得
glm::vec2 BoxCollision::getMax()
{
	return *box.mMax;
}

//最小値を取得
glm::vec2 BoxCollision::getMin()
{
	return *box.mMin;
}




// #################################### 設定　関係

//最大値を設定
void BoxCollision::setMax(glm::vec2 *max)
{
	box.mMax = max;
}

//最小値を設定
void BoxCollision::setMin(glm::vec2 *min)
{
	box.mMin = min;
}

//最大値の値を設定
void BoxCollision::setMaxValue(glm::vec2& max)
{
	*box.mMax = max;
}

//最小値の値を設定
void BoxCollision::setMinValue(glm::vec2& min)
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

	float c = sqrt((col.getCenter().x - getCenter().x) * (col.getCenter().x - getCenter().x) +
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
			float len = sqrt((col.getCenter().x - getCenter().x) * (col.getCenter().x - getCenter().x) +
				(col.getCenter().y - getCenter().y) * (col.getCenter().y - getCenter().y));
			//printf("len %d\n",len);

			float m = (col.getRadius() + getRadius()) - len;	//めり込み量

//			printf("いいい %d\n", getRadius());
//			printf("ああああ %d\n", col.getRadius());

//			printf("m %f\n",m);
			
			glm::vec2 vec = getVector();
			vec = vec * -1.0f;	//ベクトルを反転
			printf("vec : %.2f , %.2f \n", vec.x, vec.y);

			vec = glm::normalize(vec);
			vec.x = vec.x * m;
			vec.y = vec.y * m;
//			printf("vec : %.2f , %.2f \n", vec.x, vec.y);


			
			glm::vec2 p = getCenter() += (vec);
			//printf("p : %d , %d \n",p.x,p.y);
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
float CircleCollision::getRadius()
{
	return *sp.mRadius;
}

//位置取得
glm::vec2 CircleCollision::getCenter()
{
	return *sp.mCenter;
}

/// #################################### 設定　関係

//半径　設定　ポインタ
void CircleCollision::setRadius(float *r)
{
	sp.mRadius = r;
}

//位置　設定　ポインタ
void CircleCollision::setCenter(glm::vec2 *pos)
{
	sp.mCenter = pos;
}

//半径 値を設定
void CircleCollision::setRadiusValue(float r)
{
	*sp.mRadius = r;
}

//位置　値を設定
void CircleCollision::setCenterValue(glm::vec2 pos)
{
	*sp.mCenter = pos;
}




 