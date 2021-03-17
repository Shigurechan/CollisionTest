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


//交差判定
void BoxCollision::Intersect(BoxCollision& col)
{
	



	if ((col.getMax().x > box.mMin->x && box.mMax->x > col.getMin().x)
		&& (col.getMax().y > box.mMin->y && box.mMax->y > col.getMin().y))
	{

		setCol(true);				//当たり判定を設定
		setColTag(col.getMyTag());	//タグを取得
		col.setColTag(getMyTag());	//タグを設定

	
		if(getTriggerType() == false)
		{

			//サイズを取得
			 
			//相手
			glm::vec2 colSize = col.getMax() - col.getMin();
			colSize.x = colSize.x / 2;
			colSize.y = colSize.y / 2;

			//自分
			glm::vec2 boxSize = *box.mMax - *box.mMin;
			boxSize.x = boxSize.x / 2;
			boxSize.y = boxSize.y / 2;

			float colCenterX = (col.getMin().x + colSize.x);
			float colCenterY = (col.getMin().y + colSize.y);
			float boxCenterX = (box.mMin->x + boxSize.x);
			float boxCenterY = (box.mMin->y + boxSize.y);


			float deltaX = boxCenterX - colCenterX; //正ならboxが右にいる
			float deltaY = boxCenterY - colCenterY; //正ならboxが上にいる
			float adjust = 0.0;

			if (fabs(deltaX) < fabs(deltaY))
			{
			//	printf(", Y adjust \n");
				if (deltaY > 0)
				{
					adjust = col.getMax().y - box.mMin->y + 0.001f; // +する
				}
				else
				{
					adjust = -(box.mMax->y - col.getMin().y + 0.001f); // -する
				}
				box.mMin->y += adjust;
				box.mMax->y += adjust;
			}
			else
			{
			//	printf(", X adjust \n");
				if (deltaX > 0)
				{
					adjust = col.getMax().x - box.mMin->x + 0.001f; // +する

				}
				else
				{
					adjust = -(box.mMax->x - col.getMin().x + 0.001f); // -する
				}
				box.mMin->x += adjust;
				box.mMax->x += adjust;
			}
		}
		else {
			//Trigger true
		}
	}
	else
	{
		
		//当たってない時
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
		//	setCenterValue(p);



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


/*##############################################################################################################################################*/

/*####################################################
*　線分同士の当たり判定
######################################################*/

//コンストラクタ
SegmentCollision::SegmentCollision()
{

}


//線分と線分の当たり判定
bool SegmentCollision::SegmentCol(glm::vec2 a, glm::vec2 b, glm::vec2 c, glm::vec2 d) {

	float ta = (c.x - d.x) * (a.y - c.y) + (c.y - d.y) * (c.x - a.x);
	float tb = (c.x - d.x) * (b.y - c.y) + (c.y - d.y) * (c.x - b.x);
	float tc = (a.x - b.x) * (c.y - a.y) + (a.y - b.y) * (a.x - c.x);
	float td = (a.x - b.x) * (d.y - a.y) + (a.y - b.y) * (a.x - d.x);

	if ((tc * td < 0) && (ta * tb < 0))
	{
		return true;
	}
	else {
		return false;
	}
}

//線分と線分の交点座標
glm::ivec2 SegmentCollision::InterPos(glm::vec2 a, glm::vec2 b, glm::vec2 c, glm::vec2 d)
{
	float det = (a.x - b.x) * (d.y - c.y) - (d.x - c.x) * (a.y - b.y);
	float t = ((d.y - c.y) * (d.x - b.x) + (c.x - d.x) * (d.y - b.y)) / det;
	float x = t * a.x + (1.0 - t) * b.x;
	float y = t * a.y + (1.0 - t) * b.y;

	return glm::ivec2(x, y);
}


//交差判定
void SegmentCollision::Intersect(SegmentCollision& col)
{
	if (SegmentCol(*seg.mStart,*seg.mEnd,col.getStart(),col.getEnd()) == true)
	{
		glm::ivec2 pos = InterPos(*seg.mStart, *seg.mEnd, col.getStart(), col.getEnd());
		printf("pos: %d , %d\n",pos.x, pos.y);
		
	}
	else 
	{

	}

}

//取得　関係

//始点
glm::vec2 SegmentCollision::getStart()
{
	return *seg.mStart;
}


//終点
glm::vec2 SegmentCollision::getEnd()
{
	return *seg.mEnd;

}


//設定　関係

//始点
void SegmentCollision::setStart(glm::vec2* pos)
{
	seg.mStart = pos;
}

//終点
void SegmentCollision::setEnd(glm::vec2* pos)
{
	seg.mEnd = pos;

}




//デストラクタ
SegmentCollision::~SegmentCollision()
{

}
