/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue Nov 12 14:38:28 2013
 */
/* Compiler settings for D:\test\ServiceModule\ServiceModule.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


#ifndef __ServiceModule_h__
#define __ServiceModule_h__

#include <atlbase.h>
#include <winsvc.h>

class CServiceModule : public CComModule
{
public:
	void Init(HINSTANCE h, LPCTSTR lpszServiceName, const GUID* plibid = NULL);
    void Start();
	void ServiceMain(DWORD dwArgc, LPTSTR* lpszArgv);
    void Handler(DWORD dwOpcode);
    void Run();
    BOOL IsInstalled();
    BOOL Install();
    BOOL Uninstall();
	LONG Unlock();
	void LogEvent(LPCTSTR pszFormat, ...);
    void SetServiceStatus(DWORD dwState);
    void SetupAsLocalServer();
	void SetTime(time_t start, time_t end);

//Implementation
private:
	static void WINAPI _ServiceMain(DWORD dwArgc, LPTSTR* lpszArgv);
    static void WINAPI _Handler(DWORD dwOpcode);

// data members
public:
    TCHAR m_szServiceName[256];
    SERVICE_STATUS_HANDLE m_hServiceStatus;
    SERVICE_STATUS m_status;
	DWORD dwThreadID;
	BOOL m_bService;
	time_t shutdowntime_start;
	time_t shutdowntime_end;
};

extern CServiceModule _Module;
#include <atlcom.h>


#endif
