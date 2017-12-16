
// 8puzzleDlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include<string>

// CMy8puzzleDlg dialog
class CMy8puzzleDlg : public CDialogEx
{
// Construction
public:
	CMy8puzzleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MY8PUZZLE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	void check(int set,int loc);
	void thread1();
	static UINT MyThreadProc( LPVOID pParam );

	void action_take(int loc,CMFCButton & panel0,CMFCButton & panel1,CMFCButton & panel2,CMFCButton & panel3,CMFCButton & panel4,CMFCButton & panel5,CMFCButton & panel6,CMFCButton & panel7,CMFCButton & panel8);
	//CAnimateCtrl pn1;
//	afx_msg void OnAcnStartAnimate1();
	CMFCButton panel1;	
	CMFCButton panel2;
	CMFCButton panel3;
	CMFCButton panel4;
	CMFCButton panel5;
	CMFCButton panel6;
	CMFCButton panel7;
	CMFCButton panel8;
	CMFCButton panel0;

	afx_msg void OnBnClickedOk2();
	
	afx_msg void OnBnClickedOk3();
	afx_msg void OnBnClickedOk4();
	afx_msg void OnBnClickedButton10();
	CMFCButton stateinfo;
};
