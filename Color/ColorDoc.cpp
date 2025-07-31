// ColorDoc.cpp : implementation of the CColorDoc class
//

#include "stdafx.h"
#include "Color.h"

#include "ColorDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorDoc

IMPLEMENT_DYNCREATE(CColorDoc, CDocument)

BEGIN_MESSAGE_MAP(CColorDoc, CDocument)
	//{{AFX_MSG_MAP(CColorDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorDoc construction/destruction

CColorDoc::CColorDoc()
{
	// TODO: add one-time construction code here

}

CColorDoc::~CColorDoc()
{
}

BOOL CColorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CColorDoc serialization

void CColorDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CColorDoc diagnostics

#ifdef _DEBUG
void CColorDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CColorDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CColorDoc commands
