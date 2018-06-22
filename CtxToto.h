#ifndef CTX_TOTO_H
#define CTX_TOTO_H

#include "dfcContext.h"
#include "dfcEntity.h"
#include "dfc3DEntity.h"
#include "dfcLabel.h"
#include "dfcMusic.h"

class CCtxToto : public CContext
{
public:
	CCtxToto(const char* p_pRes):CContext(p_pRes){};

	virtual void Init(void);
	virtual void Activate(void);
	virtual void Deactivate(void);
	virtual void Manage(unsigned long p_nTimeTick);
	virtual void Update(void);

	CEntity		*m_pHero;
	CEntity		*m_pHero2;
	CEntity		*m_pHero3;
	CEntity3D	*m_pCube;
	CLabel		*m_pFrameRate;

	char		tickDiff[128];
	u8			m_delay;

	CVertexBuffer	*m_vbTest;
	CIndexBuffer	*m_ibTest;
	CEntity3D		*m_test;

	CCamera3D		*m_cam;
	int				nCptFrame;

	CMusic			m_pMusic;
	CSound			m_pSound;
};

#endif //CTX_TOTO_H
