/************************************************

技術名		 : Delegateパターン

記述者		 : 岸　将史
記述者更新日 : 2015/01/22

用途		 : イベントを発生させる為だけに
			　 様々なオブジェクトのポインタを
			   持たせるのは馬鹿らしい。そこで、
			   発生させるイベントをリスト化し、
			   無駄な記述を省こう、というのが
			   このデザインパターンである。

=================================================

編集者		 : 
編集者更新日 : 2015/○○/××

************************************************/
#pragma once
#include <list>
#include <vector>


/****************************
*	デリゲート基盤クラス
****************************/
class IC_BaseDelegate{
public:
	IC_BaseDelegate(){}				// コンストラクタ
	virtual ~IC_BaseDelegate(){}	// デストラクタ
	
	// 演算子のオーバロード
	virtual void operator()(void) = 0;

};


/****************************
*	デリゲートクラス
****************************/
template<class T>
class C_Delegate : public IC_BaseDelegate{
public:
	// 関数ポインタ宣言
	typedef void (T::*Func)();


	// デリゲータ作成処理
	static IC_BaseDelegate* CreateDelegator( T* pObject, Func function );


	// 演算子のオーバロード
	void operator()( void ) override;


private:
	void SetData( T* pObject, Func function );


	// メンバ変数
	T*		m_pObject;
	Func	Function;
};


/*⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒ メソッド ⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒⇒*/


template<class T>
IC_BaseDelegate* C_Delegate<T>::CreateDelegator( T* pObject, Func function ){
	C_Delegate* pDelegator = new C_Delegate;
	pDelegator->SetData( pObject, function );

	return pDelegator;
}



template<class T>
void C_Delegate<T>::operator()( void ){
	// 関数の実行
	(m_pObject->*Function)();
}



template<class T>
void C_Delegate<T>::SetData( T* pObject, Func function ){
	m_pObject = pObject;
	Function = function;
}