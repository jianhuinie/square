// GameBox.cpp: implementation of the GameBox class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "square.h"
#include "GameBox.h"
#include "time.h"
#include "mmsystem.h"
#pragma comment (lib,"Winmm.lib")
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


unsigned short Block2Int(Block a[][4], unsigned short &n) {
	n = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (a[i][j].isFill) {
				n |= (1 << (i + 4 + j));
			}
		}
	}
	return n;
}
void Int2Block(Block a[][4], unsigned short n) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if ( ((n >> (i * 4 + j)) & 1) ) {
				a[i][j].isFill = 1;
			} else a[i][j].isFill = 0;
			a[i][j].color = 4;
		}
	}
}
void RotateBlock(Block a[][4], unsigned short &n) {
	Block b[4][4];
	memcpy(b, a, sizeof(Block) * 16);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a[j][4 - i - 1] = b[i][j];
		}
	}
	Block2Int(a, n);
}
//音乐线程函数
DWORD WINAPI PlayMusic(LPVOID lpParameter){
  PlaySound((LPCTSTR)IDR_WAVE1, AfxGetInstanceHandle(), SND_RESOURCE|SND_ASYNC|SND_LOOP); 
  return 0;
}
GameBox::GameBox()
{
    randBlock.clear();
	randBlock.push_back(0x4444);
	randBlock.push_back(0x0270);
	randBlock.push_back(0x0660);
	randBlock.push_back(0x0C60);
	randBlock.push_back(0x06C0);
	randBlock.push_back(0x0E20);
	randBlock.push_back(0x0E80);
	idNow = idNext = 0;
	srand((unsigned)time(NULL));
	px=-4;
	py=3;
	score=0;
	scores[0]= 0;
	scores[1]= 10;
	scores[2]= 30;
	scores[3]= 60;
	scores[4]= 120;
	CreateThread(NULL, 0, PlayMusic, this, 0, 0);//播放音乐

}
GameBox::~GameBox()
{

}

void GameBox::CreateNext()
{
	memset(bNext, 0, sizeof(Block) * 16);
	idNext = randBlock[rand() % randBlock.size()];
	Int2Block(bNext, idNext);
	int cl = rand() % 7+1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (bNext[i][j].isFill == 1)
				bNext[i][j].color = cl;
			else bNext[i][j].color = 0;
		}
	}
}

 

bool GameBox::CanDown()
 {
 	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i < 3 && bNow[i + 1][j].isFill) continue;
			if (!bNow[i][j].isFill) continue;
			int a = px + i, b = py + j;
			if (a < 0) continue;
			if (a + 1 >= 20 || bGame[a + 1][b].isFill) {
				return false;
			}
		}
	}
	return true;
}

void GameBox::Down()
{
	if(CanDown()){
      px++;
	}
	else
	ClearRow();
	 
}

bool GameBox::CanLeft()
{
	for (int i = 0; i < 4; i++) {
     	for (int j = 0; j < 4; j++) {
	if (j > 0 && bNow[i][j - 1].isFill) continue;
	if (!bNow[i][j].isFill) continue;
	int a = px + i, b = py + j;
	if (b <= 0) return false;
	if (bGame[a][b - 1].isFill) return false;
	}
	}
	return true;
}

void GameBox::MoveLeft()
{
	if(CanLeft()){
      py--;
	}
}

bool GameBox::CanRight()
{
    for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (j < 3 && bNow[i][j + 1].isFill) continue;
			if (!bNow[i][j].isFill) continue;
			int a = px + i, b = py + j;
			if (b >= 9) return false;
			if (bGame[a][b + 1].isFill) return false;
		}
	}
	return true;
}

void GameBox::MoveRight()
{
	if(CanRight()){
     py++;
	}
}

bool GameBox::CanRotate()
{
  if (!idNow) return false;
	Block rb[4][4];
	unsigned short irb = idNow;
	memcpy(rb,bNow, sizeof(Block) * 16);
	RotateBlock(rb, irb);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a = px + i, b = py + j;
			if (a < 0) continue;
			if (rb[i][j].isFill) {
				if ((b < 0 || b >= 10 || a >= 20) || ((!bNow[i][j].isFill) && bGame[a][b].isFill)) {
					return false;
				}
			}
		}
	}
	return TRUE;
}

void GameBox::Rotate()
{
 
	if (CanRotate()) {
		 
		RotateBlock(bNow, idNow);
	}
	Block2Int(bNow, idNow);
}

void GameBox::ClearRow()
{
	int i;
	int m,n;//行列
	int iNum;
	int iRow;//消去多少行
	
 	iRow=0;
	//第19行，是最底一行
	for(m=19;m>0;m--)
	{
		iNum=0;
		for(n=0;n<10;n++)
		{
		    if(bGame[m][n].isFill)
			iNum++;
		}
		//消去一行
		if(iNum==10)
		{
			iRow++;//统计消去多少行			

			for(i=m;i>0;i--)
			{
				memcpy(bGame[i],bGame[i-1],10*sizeof(Block));//移动
				pf->Invalidate();
			
			}
			                                //memset(bGame[0],0,10*sizeof(Block));
			m++;//重要，再次检测这一行
		}
		if(iNum==0)
		{
			break;//空行，不再判断
		}
	}
	score+= scores[iRow];//增加分数
}
