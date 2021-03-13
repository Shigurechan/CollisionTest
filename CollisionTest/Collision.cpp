#include "Collision.hpp"
#include "Entry.hpp"
//�R���X�g���N�^
Box_Collision::Box_Collision()
{
	col_TagType = Tag::Invalid;	//�擾�@�^�O
	my_TagType = Tag::Invalid;	//���g�@�^�O

	mIsTrigger = false;		//�g���K�[�^�C�v
	isCol = false;			//�����������ǂ����H
}

//��`���m�̌�������
void Box_Collision::Intersect( Box_Collision &a)
{
	if ((a.getPosition().x + a.getSize().x > mPosition->x && mPosition->x + mSize->x > a.getPosition().x)
		&& (a.getPosition().y + a.getSize().y > mPosition->y && mPosition->y + mSize->y > a.getPosition().y))
	{

		col_TagType = a.getMyTag();	//�^�O���擾
		a.setColTag(getMyTag());	//�^�O��ݒ�
		
		if (mIsTrigger == false) 
		{

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
			else if (*mVector == VECTOR_NONE)
			{
				//�x�N�g�����ݒ肳��Ă��Ȃ��Ƃ�
	
				//�߂荞�ݗʂ��C��
				if (a.getVector() == VECTOR_RIGHT)
				{
					mPosition->x = a.getPosition().x + a.getSize().x;
				}
				else if (a.getVector() == VECTOR_LEFT)
				{
					mPosition->x = a.getPosition().x - a.getSize().x;
				}
				else if (a.getVector() == VECTOR_UP)
				{
					mPosition->y = a.getPosition().y - a.getSize().y;
				}
				else if (a.getVector() == VECTOR_DOWN)
				{
					mPosition->y = a.getPosition().y + a.getSize().y;
				}
			}
		}	
	}
	else
	{
		//�������Ă��Ȃ�
		
		col_TagType = Tag::Invalid;
		a.setColTag(Tag::Invalid);	
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
	return col_TagType;
}

//�������擾
glm::ivec2 Box_Collision::getVector()
{
	return *mVector;
}

//�^�C�v���擾
Tag Box_Collision::getMyTag()
{
	return my_TagType;
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
	my_TagType = type;
}

//�I�u�W�F�N�g�^�C�v��ݒ�
void Box_Collision::setVector(glm::ivec2 *vec)
{
	mVector = vec;
}

//�����蔻��̃^�O��ݒ�
void Box_Collision::setColTag(Tag type)
{
	col_TagType = type;
}

//�f�X�g���N�^
Box_Collision::~Box_Collision()
{

}