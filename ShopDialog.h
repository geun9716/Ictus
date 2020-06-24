
#pragma once
#include "afxwin.h"
#pragma comment(lib, "winmm")
#include <mmsystem.h>
		// CShopDialog 
class CProjectView;
class CShopDialog : public CDialog
{
		DECLARE_DYNAMIC(CShopDialog)

	public:
		CShopDialog(CWnd* pParent = NULL);   // 
		virtual ~CShopDialog();

		// 
#ifdef AFX_DESIGN_TIME
		enum { IDD = IDD_SHOP };
#endif

	protected:
		virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 

		DECLARE_MESSAGE_MAP()
	public:

		CString str;
		int coinnum, index;
		CProjectView* m_pView;
		CString data, have;
		CButton fish1, fish2, fish3, fish4, fish5, fish6, fish7, fish8;
		BOOL f1, f2, f3, f4, f5, f6, f7, f8;
		BOOL bt1, bt2, bt3, bt4, bt5, bt6, bt7, bt8;
		LPCTSTR fish;
		LPCTSTR fish_S;
		CFont font;
		afx_msg void OnBnClickedButton1();
		afx_msg void OnBnClickedButton2();
		afx_msg void OnBnClickedButton3();
		afx_msg void OnBnClickedButton4();
		afx_msg void OnBnClickedButton5();
		afx_msg void OnBnClickedButton6();
		afx_msg void OnBnClickedButton7();
		afx_msg void OnBnClickedButton8();
		virtual BOOL OnInitDialog();
		CButton m_apply;
		afx_msg void OnBnClickedBuy();
		afx_msg void OnBnClickedApply();
		//CStatic m_coin;
		CButton m_buy;
		virtual void OnCancel();
		virtual void PostNcDestroy();
		//CStatic m_data;
		afx_msg void OnBnClickedOk();
		afx_msg void OnBnClickedCancel();
};

