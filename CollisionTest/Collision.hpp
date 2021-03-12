#ifndef ___COLLISION_HPP_
#define ___COLLISION_HPP_

#include "glm/glm.hpp"
//#include "MapChip.hpp"

//�O���錾
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
* ��`���m�̓����蔻�� 
######################################################*/
class Box_Collision
{
public:
	Box_Collision();	//�R���X�g���N�^
	~Box_Collision();	//�f�X�g���N�^
	
	void Intersect(Box_Collision &a);	//��������

	//�擾�@�֌W
	bool getTrigger();			//�g���K�[�^�C�v���擾
	glm::ivec2 getPosition();	//���W���擾
	glm::ivec2 getSize();		//�T�C�Y���擾
	Tag getTag();		//�擾�����^�C�v���擾
	Tag getMyTag();		//�^�C�v���擾

	glm::ivec2 getVector();		//�������擾

	//�ݒ�@�֌W


	void setPosition(glm::ivec2 *pos);	//���W��ݒ�
	void setSize(glm::ivec2 *size);		//�T�C�Y��ݒ�
	void setVector(glm::ivec2 *vec);	//�����ݒ�



	void setTrigger(bool tri);			//�g���K�[�^�C�v��ݒ�



	



	void setTag(Tag type);	//�I�u�W�F�N�g�^�C�v��ݒ�
	
protected:

private:

	bool mIsTrigger;		//�g���K�[�^�C�v���ǂ����H
	Tag TagType;	//�^�O
	Tag isGetTagType; //�擾�����^�O
	glm::ivec2 *mPosition;	//���W
	glm::ivec2 *mSize;		//�T�C�Y
	glm::ivec2 *mVector;	//����



};


#endif