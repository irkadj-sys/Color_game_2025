// OptDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Color.h"
#include "OptDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptDlg dialog


COptDlg::COptDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COptDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COptDlg)
	m_human = -1;
	//}}AFX_DATA_INIT
}


void COptDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptDlg)
	DDX_Radio(pDX, IDC_HUMAN, m_human);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COptDlg, CDialog)
	//{{AFX_MSG_MAP(COptDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptDlg message handlers

void COptDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

BOOL COptDlg::OnInitDialog() 
{
	// TODO: Add extra initialization here
	
	return CDialog::OnInitDialog();  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
