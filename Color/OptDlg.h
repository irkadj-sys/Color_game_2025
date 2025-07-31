#if !defined(AFX_OPTDLG_H__2566B114_2681_11D3_BAAA_444553540000__INCLUDED_)
#define AFX_OPTDLG_H__2566B114_2681_11D3_BAAA_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OptDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COptDlg dialog

class COptDlg : public CDialog
{
// Construction
public:
	COptDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COptDlg)
	enum { IDD = IDD_OPTDIALOG };
	int		m_human;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COptDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COptDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTDLG_H__2566B114_2681_11D3_BAAA_444553540000__INCLUDED_)
