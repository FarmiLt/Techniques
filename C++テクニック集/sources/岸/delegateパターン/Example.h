/************************************************

技術名		 : 

記述者		 : 岸　将史
記述者更新日 : 2015/01/22

用途		 : Delegateパターンの使用例です

=================================================

編集者		 : 
編集者更新日 : 2015/○○/××

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
// イベントを発生させるクラス //
////////////////////////////////
class C_Entity{
public:
	// 型省略
	using list = std::list<IC_BaseDelegate*>;

	C_Entity(){}	// コンストラクタ
	

	// デストラクタ
	~C_Entity(){
		auto iter = m_delegatorList.begin();

		while( iter != m_delegatorList.end() ){
			// 削除
			Dispose::SAFE_DELETE( *iter );
			iter = m_delegatorList.erase( iter );
		}
	}


	// 実行処理
	void Execute(){
		auto iter = m_delegatorList.begin();

		while( iter != m_delegatorList.end() ){
			(*(*iter))();
			++ iter;
		}
	}


	// setアクセサ
	void SetEventHandler( IC_BaseDelegate* pDelegator ){
		m_delegatorList.push_back( pDelegator );
	}


private:
	// メンバ変数
	list	m_delegatorList;

};



//////////////////////////
// イベントを持つクラス //
//////////////////////////
class Sato{
public:
	void Kill(){
		std::cout << "コロス" << std::endl;
	}
};


class Shinmiya{
public:
	void Call(){
		std::cout << "ちんこ" << std::endl;
	}
};



////////////////
// 実行例
////////////////
void delegate_main(){
	// イベントを持つオブジェクト
	Sato sato;
	Shinmiya chinko;
	// デリゲータを作る
	IC_BaseDelegate* pDelegatorSato = C_Delegate<Sato>::CreateDelegator( &sato, &Sato::Kill );
	IC_BaseDelegate* pDelegatorChinko = C_Delegate<Shinmiya>::CreateDelegator( &chinko, &Shinmiya::Call );

	// イベントを発生させるオブジェクト
	C_Entity classroom56;
	// オブジェクトにイベントだけ渡す
	classroom56.SetEventHandler( pDelegatorSato );
	classroom56.SetEventHandler( pDelegatorChinko );

	// イベント実行
	classroom56.Execute();
}