#include "Collision.hpp"
#include "Entry.hpp"
//�R���X�g���N�^
Box_Collision::Box_Collision()
{
	TagType = Tag::Invalid;	//�^�O
	mIsTrigger = false;		//�g���K�[�^�C�v
}

//��`���m�̌�������
void Box_Collision::Intersect( Box_Collision &a)
{
	if ((a.getPosition().x + a.getSize().x > mPosition->x && mPosition->x + mSize->x > a.getPosition().x)
		&& (a.getPosition().y + a.getSize().y > mPosition->y && mPosition->y + mSize->y > a.getPosition().y))
	{
		printf("true\n");

		if (mIsTrigger == false) 
		{
			printf("mIsTriggeer = false\n");
			//�߂荞�ݗʂ��C��
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

			
			TagType = a.getTag();	//�^�O���擾


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

// #################################### �擾�@�֌W

//�g���K�[�^�C�v���擾
bool Box_Collision::getTrigger()
{
	return mIsTrigger;
}


//���W���擾
glm::ivec2 Box_Collision::getPosition()
{
	return *mPosition;
}

//�T�C�Y���擾
glm::ivec2 Box_Collision::getSize()
{
	return *mSize;
}

//�擾�����^�C�v���擾
Tag Box_Collision::getTag()
{
	return TagType;
}

//�������擾
glm::ivec2 Box_Collision::getVector()
{
	return *mVector;
}

//�^�C�v���擾
Tag Box_Collision::getMyTag()
{
	return isGetTagType;
}


// #################################### �ݒ�@�֌W

//�g���K�[�^�C�v��ݒ�
void Box_Collision::setTrigger(bool tri)
{
	mIsTrigger = tri;
}

//���W��ݒ�
void Box_Collision::setPosition(glm::ivec2 *pos)
{
	mPosition = pos;
}

// �T�C�Y��ݒ�
void Box_Collision::setSize(glm::ivec2 *size)
{
	mSize = size;
}

//�I�u�W�F�N�g�^�C�v��ݒ�
void Box_Collision::setTag(Tag type)
{
	TagType = type;
}

//�I�u�W�F�N�g�^�C�v��ݒ�
void Box_Collision::setVector(glm::ivec2 *vec)
{
	mVector = vec;
}


//�f�X�g���N�^
Box_Collision::~Box_Collision()
{

}