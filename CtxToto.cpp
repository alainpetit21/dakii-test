#include "lib.h"
#include "libTypes.h"
#include "libMacros.h"
#include "libMath.h"
#include "libMngInput.h"
#include "dfcApp.h"
#include "CtxToto.h"

PROFILER_INC

void
CCtxToto::Init(void)
{
	SetNbChilds(32);
}

void
CCtxToto::Activate(void)
{
//CMng3D	*pMng3D=  (CMng3D*)GetMng3D();

	CContext::Activate();

	m_cam	= (CCamera3D*)FindByID("Camera3D");
	m_pHero	= (CEntity*)FindByID("Remi_Hero");
	m_pHero->SetAnimationSpeed(1.0f);
	m_pHero->SetState(6);

	m_pHero2= (CEntity*)FindByID("Remi_Hero2");
	m_pHero3= (CEntity*)FindByID("Remi_Hero3");

	m_pHero2->m_isCollidable= true;
	m_pHero3->m_isCollidable= true;

	m_pHero2->SetVelX(float(-1.0));
	m_pHero3->SetVelX(float(1.0));

	SetMouse(m_pHero);
//	m_pCube= (CEntity3D*)FindByID("Cube3D");
//	m_pCube->SetPos(0.0f, 0.0f, 100.0f);
//	m_pCube->SetScale(1.0f, 1.0f, 1.0f);
//	m_pCube->SetAngle(0, 0, 0);

	m_pFrameRate= new CLabel;
	m_pFrameRate->SetPos(-512, -384, 0);
	m_pFrameRate->SetTextID("FPS");
	m_pFrameRate->SetText("0.0");
	m_pFrameRate->SetFont(CFont::Find("Font8.font"));
	AddChild(m_pFrameRate, false);

	m_delay= 0;

//	m_vbTest= pMng3D->CreateVB(4);
//	TVertex *retvb= m_vbTest->Lock();

//	memset(retvb, 0, sizeof(TVertex)*4);
//	retvb[0].x	= 0;
//	retvb[0].y	= 0;
//	retvb[0].z	= 0;
//	retvb[1].x	= 1;
//	retvb[1].y	= 0;
//	retvb[1].z	= 0;
//	retvb[2].x	= 0;
//	retvb[2].y	= 1;
//	retvb[2].z	= 0;
//	retvb[3].x	= 1;
//	retvb[3].y	= 1;
//	retvb[3].z	= 0;
//	retvb[0].x	= -0.5;
//	retvb[0].y	= 1;
//	retvb[0].z	= 0;
//	retvb[1].x	= -0.5;
//	retvb[1].y	= 0;
//	retvb[1].z	= 0;
//	retvb[2].x	= 0;
//	retvb[2].y	= 1;
//	retvb[2].z	= 1;
//	retvb[3].x	= 0;
//	retvb[3].y	= 0;
//	retvb[3].z	= 1;

//	m_vbTest->Unlock();

//	m_ibTest= pMng3D->CreateIB(6);
//	u16 *retib= m_ibTest->Lock();

//	retib[0]= 3;
//	retib[1]= 1;
//	retib[2]= 2;
//	retib[3]= 2;
//	retib[4]= 1;
//	retib[5]= 0;

//	m_vbTest->Unlock();

//	m_test= new CEntity3D;
//	m_test->m_pVb= m_vbTest;
//	m_test->m_pIb= m_ibTest;
//	AddChild(m_test, false);

	m_cam->SetPos(0, 0, 1);
	m_cam->SetAngle(0, 0, 0);

	nCptFrame= 0;

	m_pMusic.LoadInstance("Music1.sound");
	m_pMusic.Play();

	m_pSound.LoadInstance("CollisionWalls.sound");

	//Benchmark DString.cpp
//	u32 i= 0;
//	PROFILER_BEFORE;
//	while(i < 4000000){
//		CDString test("Bonjour Toto");
//		++i;
//	}
//	PROFILER_AFTER("Benchmark:\t", "\n");

//	PROFILER_BEFORE;
//	while(i < 10000){
//		CMngIO	*mngIO	= GetMngIO();
//		io 		fichier;
//		u32		size;
//		char 	*chaine;
//
//		helper_OpenScript(fichier, mngIO, "AppTest.application");
//
//		size	= mngIO->GetSize(fichier);
//		chaine	= new char[size+1];
//		chaine[size]= 0;
//
//		mngIO->Read(fichier, chaine, size);
//		mngIO->Close(fichier);
//
//		/* Parse the xml*/
//		m_pXml= new CXml(chaine);
//		delete []chaine;
//
//		delete m_pXml;
//		++i;
//	}
//	PROFILER_AFTER("Benchmark:\t", "\n");

//	PROFILER_BEFORE;
//	i= 0;
//	while(i < 100){
//		TGAImg		img;
//
//		img.Load("TestUncompressed.tga");
//		++i;
//	}
//	PROFILER_AFTER("Benchmark TestUncompressed:\t", "\n");
//	PROFILER_BEFORE;
//	i= 0;
//	while(i < 100){
//		TGAImg		img;
//
//		img.Load("TestRLE.tga");
//		++i;
//	}
//	PROFILER_AFTER("Benchmark TestRLE:\t", "\n");
//	PROFILER_BEFORE;
//	i= 0;
//	while(i < 100){
//		TGAImg		img;
//
//		img.Load("TestIndexed.tga");
//		++i;
//	}
//	PROFILER_AFTER("Benchmark TestIndexed:\t", "\n");
//	PROFILER_BEFORE;
//	i= 0;
//	while(i < 100){
//		TGAImg		img;
//
//		img.Load("TestIndexedRLE.tga");
//		++i;
//	}
//	PROFILER_AFTER("Benchmark TestIndexedRLE:\t", "\n");
//	PROFILER_BEFORE;
//	i= 0;
//	while(i < 100){
//		PNGImg		img;
//
//		img.Load("TestPNGLevel0.png");
//		++i;
//	}
//	PROFILER_AFTER("Benchmark TestPNGLevel0:\t", "\n");
//	PROFILER_BEFORE;
//	i= 0;
//	while(i < 100){
//		PNGImg		img;
//
//		img.Load("TestPNGLevel1.png");
//		++i;
//	}
//	PROFILER_AFTER("Benchmark TestPNGLevel1:\t", "\n");
//	PROFILER_BEFORE;
//	i= 0;
//	while(i < 100){
//		PNGImg		img;
//
//		img.Load("TestPNGLevel2.png");
//		++i;
//	}
//	PROFILER_AFTER("Benchmark TestPNGLevel2:\t", "\n");
//	PROFILER_BEFORE;
//	i= 0;
//	while(i < 100){
//		PNGImg		img;
//
//		img.Load("TestPNGLevel3.png");
//		++i;
//	}
//	PROFILER_AFTER("Benchmark TestPNGLevel3:\t", "\n");
//	PROFILER_BEFORE;
//	i= 0;
//	while(i < 100){
//		PNGImg		img;
//
//		img.Load("TestPNGLevel4.png");
//		++i;
//	}
//	PROFILER_AFTER("Benchmark TestPNGLevel4:\t", "\n");
//	PROFILER_BEFORE;
//	i= 0;
//	while(i < 100){
//		PNGImg		img;
//
//		img.Load("TestPNGLevel5.png");
//		++i;
//	}
//	PROFILER_AFTER("Benchmark TestPNGLevel5:\t", "\n");
//	PROFILER_BEFORE;
//	i= 0;
//	while(i < 100){
//		PNGImg		img;
//
//		img.Load("TestPNGLevel6.png");
//		++i;
//	}
//	PROFILER_AFTER("Benchmark TestPNGLevel6:\t", "\n");
//	PROFILER_BEFORE;
//	i= 0;
//	while(i < 100){
//		PNGImg		img;
//
//		img.Load("TestPNGLevel7.png");
//		++i;
//	}
//	PROFILER_AFTER("Benchmark TestPNGLevel7:\t", "\n");
//	PROFILER_BEFORE;
//	i= 0;
//	while(i < 100){
//		PNGImg		img;
//
//		img.Load("TestPNGLevel8.png");
//		++i;
//	}
//	PROFILER_AFTER("Benchmark TestPNGLevel8:\t", "\n");
//	PROFILER_BEFORE;
//	i= 0;
//	while(i < 100){
//		PNGImg		img;
//
//		img.Load("TestPNGLevel9.png");
//		++i;
//	}
//	PROFILER_AFTER("Benchmark TestPNGLevel9:\t", "\n");
//	PROFILER_BEFORE;
//	i= 0;
//	while(i < 100){
//		PNGImg		img;
//
//		img.Load("TestPNGIndexedLevel0.png");
//		++i;
//	}
//	PROFILER_AFTER("Benchmark TestPNGIndexedLevel0:\t", "\n");
//	PROFILER_BEFORE;
//	i= 0;
//	while(i < 100){
//		PNGImg		img;
//
//		img.Load("TestPNGIndexedLevel1.png");
//		++i;
//	}
//	PROFILER_AFTER("Benchmark TestPNGIndexedLevel1:\t", "\n");
//	PROFILER_BEFORE;
//	i= 0;
//	while(i < 100){
//		PNGImg		img;
//
//		img.Load("TestPNGIndexedLevel2.png");
//		++i;
//	}
//	PROFILER_AFTER("Benchmark TestPNGIndexedLevel2:\t", "\n");
//	PROFILER_BEFORE;
//	i= 0;
//	while(i < 100){
//		PNGImg		img;
//
//		img.Load("TestPNGIndexedLevel3.png");
//		++i;
//	}
//	PROFILER_AFTER("Benchmark TestPNGIndexedLevel3:\t", "\n");
//	PROFILER_BEFORE;
//	i= 0;
//	while(i < 100){
//		PNGImg		img;
//
//		img.Load("TestPNGIndexedLevel4.png");
//		++i;
//	}
//	PROFILER_AFTER("Benchmark TestPNGIndexedLevel4:\t", "\n");
//	PROFILER_BEFORE;
//	i= 0;
//	while(i < 100){
//		PNGImg		img;
//
//		img.Load("TestPNGIndexedLevel5.png");
//		++i;
//	}
//	PROFILER_AFTER("Benchmark TestPNGIndexedLevel5:\t", "\n");
//	PROFILER_BEFORE;
//	i= 0;
//	while(i < 100){
//		PNGImg		img;
//
//		img.Load("TestPNGIndexedLevel6.png");
//		++i;
//	}
//	PROFILER_AFTER("Benchmark TestPNGIndexedLevel6:\t", "\n");
//	PROFILER_BEFORE;
//	i= 0;
//	while(i < 100){
//		PNGImg		img;
//
//		img.Load("TestPNGIndexedLevel7.png");
//		++i;
//	}
//	PROFILER_AFTER("Benchmark TestPNGIndexedLevel7:\t", "\n");
//	PROFILER_BEFORE;
//	i= 0;
//	while(i < 100){
//		PNGImg		img;
//
//		img.Load("TestPNGIndexedLevel8.png");
//		++i;
//	}
//	PROFILER_AFTER("Benchmark TestPNGIndexedLevel8:\t", "\n");
//	PROFILER_BEFORE;
//	i= 0;
//	while(i < 100){
//		PNGImg		img;
//
//		img.Load("TestPNGIndexedLevel9.png");
//		++i;
//	}
//	PROFILER_AFTER("Benchmark TestPNGIndexedLevel9:\t", "\n");

}

void
CCtxToto::Deactivate(void)
{
	CContext::Deactivate();
}

void
CCtxToto::Manage(unsigned long p_nTimeTick)
{
CMngInput *mngInput= GetMngInput();

	if(mngInput->IsLogicKeyDown(IK_ESCAPE))
		System_Quit();

	if(mngInput->IsMouseKeyDown(0) && m_pMouse)
	{
		CObj* pFound;

		if((pFound= FindAt(int(m_pMouse->GetIntPosX()), int(m_pMouse->GetIntPosY()), int(m_pMouse->GetPosZ()))))
			if(m_pMouse->GetNbChilds() == 0)
				m_pMouse->AddChild(RemoveChild(pFound), true);
	}
	else
	{
		if(m_pMouse && m_pMouse->m_arChilds && m_pMouse->m_arChilds[0])
			AddChild(m_pMouse->RemoveChild(m_pMouse->m_arChilds[0]), false);
	}

/*
	if(mngInput->IsKeyDown(IK_ARROWLEFT))
		m_pHero2->MoveToMap(m_pHero2->GetMapPosX()-1, m_pHero2->GetMapPosY(), m_pHero2->GetMapPosZ(), float(0.1f), float(2.0f), float(1.0));
	else if(mngInput->IsKeyDown(IK_ARROWRIGHT))
		m_pHero2->MoveToMap(m_pHero2->GetMapPosX()+1, m_pHero2->GetMapPosY(), m_pHero2->GetMapPosZ(), float(0.1f), float(2.0f), float(1.0));
	else if(mngInput->IsKeyDown(IK_ARROWUP))
		m_pHero2->MoveToMap(m_pHero2->GetMapPosX(), m_pHero2->GetMapPosY()-1, m_pHero2->GetMapPosZ(), float(0.1f), float(2.0f), float(1.0));
	else if(mngInput->IsKeyDown(IK_ARROWDOWN))
		m_pHero2->MoveToMap(m_pHero2->GetMapPosX(), m_pHero2->GetMapPosY()+1, m_pHero2->GetMapPosZ(), float(0.1f), float(2.0f), float(1.0));
	else if(mngInput->IsKeyDown(IK_SPACE))
		m_pHero2->MoveToMap(-19, -11, 12, 1, 4.0, 1.0);
	else if(mngInput->IsKeyDown(IK_RETURN)){
		m_pHero2->MoveToMap(-19, -10, 12, 1, 4.0, 1.0);
		CContext::Manage(p_nTimeTick);
		CContext::Manage(p_nTimeTick);
		CContext::Manage(p_nTimeTick);
		CContext::Manage(p_nTimeTick);
		m_pHero2->MoveToMap(-19, -12, 12, 1, 4.0, 1.0);
		CContext::Manage(p_nTimeTick);
		CContext::Manage(p_nTimeTick);
		CContext::Manage(p_nTimeTick);
		CContext::Manage(p_nTimeTick);
		m_pHero2->MoveToMap(-19, -11, 12, 1, 4.0, 1.0);
		CContext::Manage(p_nTimeTick);
		CContext::Manage(p_nTimeTick);
		CContext::Manage(p_nTimeTick);
		CContext::Manage(p_nTimeTick);
	}
*/
	if(mngInput->IsKeyDown(IK_ARROWLEFT))
		m_pHero2->SetPosX(m_pHero2->GetPosX()-1);
	else if(mngInput->IsKeyDown(IK_ARROWRIGHT))
		m_pHero2->SetPosX(m_pHero2->GetPosX()+1);
	else if(mngInput->IsKeyDown(IK_ARROWUP))
		m_pHero2->SetPosY(m_pHero2->GetPosY()-1);
	else if(mngInput->IsKeyDown(IK_ARROWDOWN))
		m_pHero2->SetPosY(m_pHero2->GetPosY()+1);

	if(mngInput->IsLogicKeyDown(IK_BTN_A)){
		m_pSound.Play();
	}

	nCptFrame++;
//	m_test->SetAngleX(toto);
//	m_test->SetAngleY(0);
//	m_test->SetAngleZ(float(nCptFrame)/100);
//	m_cam->SetAngle(0, 0, float(nCptFrame)/100);
//	m_test->SetPosZ(float(nCptFrame)/100);
//	m_test->SetPosZ(-1);

//	while(1){
//		TRAP_MSG();
//
//		GetMngGraphic()->BeginScene();
//		GetMngGraphic()->DrawBitmap(0, 0, 0, 640, 480, 0, 1.0f, 1, ((CBackgroundLayer*)FindByID("Back_CityDarkness_0"))->m_bitmap);
//		GetMngGraphic()->EndScene(0);
//	}
	CContext::Manage(p_nTimeTick);
}

void
CCtxToto::Update(void)
{
	CContext::Update();
}


