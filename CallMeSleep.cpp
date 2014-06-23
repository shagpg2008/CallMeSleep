// CallMeSleep.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "CallMeSleep.h"
#include "CallMeSleepDlg.h"
#include "ServiceModule.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCallMeSleepApp

BEGIN_MESSAGE_MAP(CCallMeSleepApp, CWinApp)
	//{{AFX_MSG_MAP(CCallMeSleepApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCallMeSleepApp construction

CCallMeSleepApp::CCallMeSleepApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CCallMeSleepApp object

CCallMeSleepApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CCallMeSleepApp initialization

BOOL CCallMeSleepApp::InitInstance()
{
	AfxEnableControlContainer();


	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	if(*m_lpCmdLine != 0) {
		int hour = 0;
		int min = 0;
		int sec = 0;
		_stscanf(m_lpCmdLine, _T("%d:%d:%d"), &hour, &min, &sec);
		_Module.Init(m_hInstance, _T("CallMeSleep"), NULL);
		_Module.m_bService = TRUE;
		_Module.SetTime(hour, min, sec);
		_Module.Start();
	} else {
		CCallMeSleepDlg dlg;
		m_pMainWnd = &dlg;
		int nResponse = dlg.DoModal();
		if (nResponse == IDOK)
		{
			// TODO: Place code here to handle when the dialog is
			//  dismissed with OK
		}
		else if (nResponse == IDCANCEL)
		{
			// TODO: Place code here to handle when the dialog is
			//  dismissed with Cancel
		}
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
