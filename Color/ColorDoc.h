// ColorDoc.h : interface of the CColorDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COLORDOC_H__2566B10B_2681_11D3_BAAA_444553540000__INCLUDED_)
#define AFX_COLORDOC_H__2566B10B_2681_11D3_BAAA_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CColorDoc : public CDocument
{
protected: // create from serialization only
	CColorDoc();
	DECLARE_DYNCREATE(CColorDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CColorDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CColorDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORDOC_H__2566B10B_2681_11D3_BAAA_444553540000__INCLUDED_)
