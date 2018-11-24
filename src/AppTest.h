#ifndef _TEST_APP_H
#define _TEST_APP_H

#include "dfcApp.h"


#define CTX_TEST	0
#define MAX_CTX		1

class CAppTest : public CApp
{
public:
	CAppTest();
	virtual ~CAppTest(){};

	virtual void OnPostCreate(void);
};

extern CAppTest *g_TheAppTest;

#endif //_TEST_APP_H
