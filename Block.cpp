// Block.cpp: implementation of the Block class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "square.h"
#include "Block.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Block::Block()
{
  isFill=0;
  color=0;
}

Block::~Block()
{

}
