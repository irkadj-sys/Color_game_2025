// ColorView.cpp : implementation of the CColorView class
//

#include "stdafx.h"
#include "Color.h"

#include "ColorDoc.h"
#include "ColorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorView

IMPLEMENT_DYNCREATE(CColorView, CView)

BEGIN_MESSAGE_MAP(CColorView, CView)
	//{{AFX_MSG_MAP(CColorView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorView construction/destruction

CColorView::CColorView()
{
	// TODO: add construction code here

}

CColorView::~CColorView()
{
}

BOOL CColorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CColorView drawing

void CColorView::OnDraw(CDC* pDC)
{
	CColorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CColorView diagnostics

#ifdef _DEBUG
void CColorView::AssertValid() const
{
	CView::AssertValid();
}

void CColorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CColorDoc* CColorView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CColorDoc)));
	return (CColorDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CColorView message handlers
