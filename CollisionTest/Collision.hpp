#ifndef ___COLLISION_HPP_
#define ___COLLISION_HPP_

#include "glm/glm.hpp"
//#include "MapChip.hpp"

//前方宣言
typedef enum class Tag
{
	Player,
	Enemy,
	Wall,
	Item,
	None,

	Invalid,
}Tag;

/*####################################################
* 矩形同士の当たり判定 
######################################################*/
class Box_Collision
{
public:
	Box_Collision();	//コンストラクタ
	~Box_Collision();	//デストラクタ
	
	void Intersect(Box_Collision &a);	//交差判定

	//取得　関係
	bool getTrigger();			//トリガータイプを取得
	glm::ivec2 getPosition();	//座標を取得
	glm::ivec2 getSize();		//サイズを取得
	Tag getTag();		//取得したタイプを取得
	Tag getMyTag();		//タイプを取得

	glm::ivec2 getVector();		//方向を取得

	//設定　関係


	void setPosition(glm::ivec2 *pos);	//座標を設定
	void setSize(glm::ivec2 *size);		//サイズを設定
	void setVector(glm::ivec2 *vec);	//方向設定



	void setTrigger(bool tri);			//トリガータイプを設定



	



	void setTag(Tag type);	//オブジェクトタイプを設定
	
protected:

private:

	bool mIsTrigger;		//トリガータイプかどうか？
	Tag TagType;	//タグ
	Tag isGetTagType; //取得したタグ
	glm::ivec2 *mPosition;	//座標
	glm::ivec2 *mSize;		//サイズ
	glm::ivec2 *mVector;	//方向



};


#endif