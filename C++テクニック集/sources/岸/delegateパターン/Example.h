/************************************************

�Z�p��		 : 

�L�q��		 : �݁@���j
�L�q�ҍX�V�� : 2015/01/22

�p�r		 : Delegate�p�^�[���̎g�p��ł�

=================================================

�ҏW��		 : 
�ҏW�ҍX�V�� : 2015/����/�~�~

************************************************/
#pragma once
#include "Delegater.h"
#include <iostream>
#include <string>


namespace Dispose{
	template<typename T>
	static const void SAFE_DELETE( T*& p ){
		delete p;
		p = nullptr;
	}
}


////////////////////////////////
// �C�x���g�𔭐�������N���X //
////////////////////////////////
class C_Entity{
public:
	// �^�ȗ�
	using list = std::list<IC_BaseDelegate*>;

	C_Entity(){}	// �R���X�g���N�^
	

	// �f�X�g���N�^
	~C_Entity(){
		auto iter = m_delegatorList.begin();

		while( iter != m_delegatorList.end() ){
			// �폜
			Dispose::SAFE_DELETE( *iter );
			iter = m_delegatorList.erase( iter );
		}
	}


	// ���s����
	void Execute(){
		auto iter = m_delegatorList.begin();

		while( iter != m_delegatorList.end() ){
			(*(*iter))();
			++ iter;
		}
	}


	// set�A�N�Z�T
	void SetEventHandler( IC_BaseDelegate* pDelegator ){
		m_delegatorList.push_back( pDelegator );
	}


private:
	// �����o�ϐ�
	list	m_delegatorList;

};



//////////////////////////
// �C�x���g�����N���X //
//////////////////////////
class Sato{
public:
	void Kill(){
		std::cout << "�R���X" << std::endl;
	}
};


class Shinmiya{
public:
	void Call(){
		std::cout << "����" << std::endl;
	}
};



////////////////
// ���s��
////////////////
void delegate_main(){
	// �C�x���g�����I�u�W�F�N�g
	Sato sato;
	Shinmiya chinko;
	// �f���Q�[�^�����
	IC_BaseDelegate* pDelegatorSato = C_Delegate<Sato>::CreateDelegator( &sato, &Sato::Kill );
	IC_BaseDelegate* pDelegatorChinko = C_Delegate<Shinmiya>::CreateDelegator( &chinko, &Shinmiya::Call );

	// �C�x���g�𔭐�������I�u�W�F�N�g
	C_Entity classroom56;
	// �I�u�W�F�N�g�ɃC�x���g�����n��
	classroom56.SetEventHandler( pDelegatorSato );
	classroom56.SetEventHandler( pDelegatorChinko );

	// �C�x���g���s
	classroom56.Execute();
}