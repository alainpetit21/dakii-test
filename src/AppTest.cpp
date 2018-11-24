#include "lib.h"
#include "libTypes.h"
#include "libMacros.h"
#include "AppTest.h"

#include "CtxToto.h"


CAppTest	*g_TheAppTest;

CAppTest::CAppTest():
CApp("AppTest.application")
{
}

void
CAppTest::OnPostCreate(void)
{
	Init(MAX_CTX);

	RegisterContext(CTX_TEST, new CCtxToto("CtxTest.context"));

	SetCurContext(CTX_TEST);

	CApp::OnPostCreate();
}

CApp*
newGameApp(void)
{
	return g_TheAppTest= new CAppTest();
}


ENTRY_POINT("Test");
