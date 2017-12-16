
// 8puzzleDlg.cpp : implementation file
//
#define _AFXDLL //<<===notice this

#include <sstream>
#include<string>
#include<vector>
#include "stdafx.h"
#include "8puzzle.h"
#include "8puzzleDlg.h"
#include "afxdialogex.h"
#include "Source.h"
#include <afxwin.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy8puzzleDlg dialog




CMy8puzzleDlg::CMy8puzzleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy8puzzleDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	 panel1.SetFaceColor(RGB(0,191,255),true);
     panel2.SetFaceColor(RGB(0,191,255),true);
	 panel3.SetFaceColor(RGB(0,191,255),true);
     panel4.SetFaceColor(RGB(0,191,255),true);
	 panel5.SetFaceColor(RGB(0,191,255),true);
     panel6.SetFaceColor(RGB(0,191,255),true);
	 panel7.SetFaceColor(RGB(0,191,255),true);
     panel8.SetFaceColor(RGB(0,191,255),true);
	 panel0.SetFaceColor(RGB(250, 128, 114),true);
}

void CMy8puzzleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_BUTTON1, panel1);
	DDX_Control(pDX, IDC_BUTTON2, panel2);
	DDX_Control(pDX, IDC_BUTTON3, panel3);
	DDX_Control(pDX, IDC_BUTTON4, panel4);
	DDX_Control(pDX, IDC_BUTTON5, panel5);
	DDX_Control(pDX, IDC_BUTTON6, panel6);
	DDX_Control(pDX, IDC_BUTTON7, panel7);
	DDX_Control(pDX, IDC_BUTTON8, panel8);
	DDX_Control(pDX, IDC_BUTTON9, panel0);
	DDX_Control(pDX, IDC_BUTTON10, stateinfo);
}

BEGIN_MESSAGE_MAP(CMy8puzzleDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMy8puzzleDlg::OnBnClickedOk)
	//ON_ACN_START(IDC_ANIMATE1, &CMy8puzzleDlg::OnAcnStartAnimate1)
	ON_BN_CLICKED(IDOK2, &CMy8puzzleDlg::OnBnClickedOk2)

	ON_BN_CLICKED(IDC_BUTTON10, &CMy8puzzleDlg::OnBnClickedButton10)
END_MESSAGE_MAP()


// CMy8puzzleDlg message handlers

BOOL CMy8puzzleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMy8puzzleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMy8puzzleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


string goalstate;
string given;
void CMy8puzzleDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	given="";
	srand(time(0));
	vector<int>vall;
		while(1)
		{
			int ps=	(rand()%9);

		if(	std::find(vall.begin(), vall.end(), ps) != vall.end() )
			continue;
		vall.push_back(ps);
		
	
			 CString a;
			a.Format(_T("%d"), ps);
			

			CT2CA pszConvertedAnsiString (a);
			string strStd (pszConvertedAnsiString);
				//
		given = given+strStd;
		Sleep(100);
		check(0,ps);
			if (vall.size()>8)
				break;
							

		}
		
	

		string s;
		s=(1, given.at(0));
		GetDlgItem(IDC_BUTTON8)->SetWindowText((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str()); 
		s=(1, given.at(1));
		GetDlgItem(IDC_BUTTON1)->SetWindowText((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str()); 
		s=(1, given.at(2));
		GetDlgItem(IDC_BUTTON2)->SetWindowText((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str()); 
		s=(1, given.at(3));
		GetDlgItem(IDC_BUTTON3)->SetWindowText((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str()); 
		s=(1, given.at(4));
		GetDlgItem(IDC_BUTTON4)->SetWindowText((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str()); 
		s=(1, given.at(5));
		GetDlgItem(IDC_BUTTON5)->SetWindowText((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str()); 
		s=(1, given.at(6));
		GetDlgItem(IDC_BUTTON6)->SetWindowText((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str()); 
		s=(1, given.at(7));
		GetDlgItem(IDC_BUTTON7)->SetWindowText((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str()); 
		s=(1, given.at(8));
		GetDlgItem(IDC_BUTTON9)->SetWindowText((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str()); 
				check(0,given.find('0'));
	

}
void  CMy8puzzleDlg::check(int set,int loc)
{
			 panel1.SetFaceColor(RGB(0,191,255),true);
			 panel2.SetFaceColor(RGB(0,191,255),true);
			 panel3.SetFaceColor(RGB(0,191,255),true);
			 panel4.SetFaceColor(RGB(0,191,255),true);
			 panel5.SetFaceColor(RGB(0,191,255),true);
			 panel6.SetFaceColor(RGB(0,191,255),true);
			 panel7.SetFaceColor(RGB(0,191,255),true);
			 panel8.SetFaceColor(RGB(0,191,255),true);
			 panel0.SetFaceColor(RGB(0, 191, 255),true);
			  string s;
			  s=" ";
				if(set==0 && loc==1)
				{   panel0.SetFaceColor(RGB(250, 128, 114),true);
					panel0.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());

				}else	if(set==0 && loc==6)
				{
					 panel6.SetFaceColor(RGB(250, 128, 114),true);
					 	panel6.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
				}else	if(set==0 && loc==2)
				{
					 panel2.SetFaceColor(RGB(250, 128, 114),true);
					 	panel2.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
				}else	if(set==0 && loc==3)
				{
					 panel3.SetFaceColor(RGB(250, 128, 114),true);
					 	panel3.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
				}else	if(set==0 && loc==4)
				{
					 panel4.SetFaceColor(RGB(250, 128, 114),true);
					 	panel4.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
				}else if(set==0 && loc==5)
				{
						 panel5.SetFaceColor(RGB(250, 128, 114),true);
						 	panel5.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
				}else if(set==0 && loc==7)
				{	
					panel7.SetFaceColor(RGB(250, 128, 114),true);
					panel7.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
				}
				else if(set==0 && loc==8)
				{	 panel8.SetFaceColor(RGB(250, 128, 114),true);
					panel8.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
				}
				else if(set==0 && loc==0)
				{
					 panel0.SetFaceColor(RGB(250, 128, 114),true);
					 	panel0.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
					
			
				}
}

void CMy8puzzleDlg::thread1() 
{
 		CMy8puzzleDlg	fata(GetDlgItem(1006));//->SetWindowText((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str()); 
		string s="";
		
	if (given=="")
	{
		string s;
		s="Please Click on Randomly Generate Puzzle";
		GetDlgItem(IDC_STATIC)->SetWindowText((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str()); 

	
		
		
	}else
	{

	Search execute;

	string s;

		s="8puzzle solver using A* Algorithm evaluating actions";
		GetDlgItem(IDC_STATIC)->SetWindowText((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str()); 
		execute.Astar("123456780",given,panel0,panel1,panel2,panel3,panel4,panel5,panel6,panel7,panel8,stateinfo);	}
	s="Exit";
	 stateinfo.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
}
UINT CMy8puzzleDlg::MyThreadProc( LPVOID pParam)
{


	CMy8puzzleDlg* dlg = (CMy8puzzleDlg*)pParam;
	dlg->thread1(); 
	    return 0;

}
void CMy8puzzleDlg::OnBnClickedOk2()
{
		
	
AfxBeginThread( MyThreadProc,this,THREAD_PRIORITY_NORMAL,0,0,NULL); 


	
 
	// TODO: Add your control notification handler code here
}
void CMy8puzzleDlg::action_take(int loc,CMFCButton & panel0,CMFCButton & panel1,CMFCButton & panel2,CMFCButton & panel3,CMFCButton & panel4,CMFCButton & panel5,CMFCButton & panel6,CMFCButton & panel7,CMFCButton & panel8)
{
			 panel1.SetFaceColor(RGB(0,191,255),true);
			 panel2.SetFaceColor(RGB(0,191,255),true);
			 panel3.SetFaceColor(RGB(0,191,255),true);
			 panel4.SetFaceColor(RGB(0,191,255),true);
			 panel5.SetFaceColor(RGB(0,191,255),true);
			 panel6.SetFaceColor(RGB(0,191,255),true);
			 panel7.SetFaceColor(RGB(0,191,255),true);
			 panel8.SetFaceColor(RGB(0,191,255),true);
			 panel0.SetFaceColor(RGB(0, 191, 255),true);
			string s;
			  s=" ";

				if(loc==0)
				{   
					panel8.SetFaceColor(RGB(250, 128, 114),true);
					panel8.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());

				}else	if(loc==1)
				{
					 panel1.SetFaceColor(RGB(250, 128, 114),true);
					 	panel1.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
				}else	if(loc==2)
				{
					 panel2.SetFaceColor(RGB(250, 128, 114),true);
					 	panel2.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
				}else	if(  loc==3)
				{
					 panel3.SetFaceColor(RGB(250, 128, 114),true);
					 	panel3.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
				}else	if(  loc==4)
				{
					 panel4.SetFaceColor(RGB(250, 128, 114),true);
					 	panel4.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
				}else if(  loc==5)
				{
						 panel5.SetFaceColor(RGB(250, 128, 114),true);
						 	panel5.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
				}else if(loc==6)
				{
					 panel6.SetFaceColor(RGB(250, 128, 114),true);
					 	panel6.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
				}
				else if(  loc==7)
				{	 panel7.SetFaceColor(RGB(250, 128, 114),true);
					panel7.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
				}
				else if(  loc==8)
				{	 panel0.SetFaceColor(RGB(250, 128, 114),true);
					panel0.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
				}
				
}





void CMy8puzzleDlg::OnBnClickedButton10()
{
	CMy8puzzleDlg::DestroyWindow();
	// TODO: Add your control notification handler code here
}
