// CallMeSleepDlg.h : header file
//

#if !defined(AFX_CALLMESLEEPDLG_H__4CC8CCC2_7165_40DE_96A2_413EE681F6C9__INCLUDED_)
#define AFX_CALLMESLEEPDLG_H__4CC8CCC2_7165_40DE_96A2_413EE681F6C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCallMeSleepDlg dialog

class CCallMeSleepDlg : public CDialog
{
// Construction
public:
	CCallMeSleepDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCallMeSleepDlg)
	enum { IDD = IDD_CALLMESLEEP_DIALOG };
	COleDateTime	m_tmShutdownTime;
	COleDateTime	m_tmShutdownTimeEnd;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCallMeSleepDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
	DWORD ExecuteCMD(const char* szCommand);
	void ShowResultBox(DWORD dwResult) ;

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCallMeSleepDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButtonUninstall();
	afx_msg void OnButtonInstall();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALLMESLEEPDLG_H__4CC8CCC2_7165_40DE_96A2_413EE681F6C9__INCLUDED_)
