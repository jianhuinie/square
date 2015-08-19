// GameBox.h: interface for the GameBox class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAMEBOX_H__9958FB7C_2609_4313_99A3_0F7E73CBF1E7__INCLUDED_)
#define AFX_GAMEBOX_H__9958FB7C_2609_4313_99A3_0F7E73CBF1E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Block.h"
#include "StdAfx.h"
#include <vector>
using namespace std;
class GameBox  
{
public:
	GameBox();
	virtual ~GameBox();

public:
	int score;
	int scores[5];
	void ClearRow();
	void Rotate();
	bool CanRotate();
	void MoveRight();
	bool CanRight();
	void MoveLeft();
	bool CanLeft();
	void Down();
	bool CanDown();
	
	int px;
	int py;
	CDialog *pf;
	void CreateNext();
	Block bGame[20][10];
	Block bNext[4][4];
	Block bNow[4][4];
	unsigned short idNow;
	unsigned short idNext;
	vector<unsigned short> randBlock;
};

#endif // !defined(AFX_GAMEBOX_H__9958FB7C_2609_4313_99A3_0F7E73CBF1E7__INCLUDED_)
