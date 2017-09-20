#if !defined(AFX_TOOLBAREX_H__D152D63B_A5F3_4646_B062_D2D04653ED1B__INCLUDED_) 
#define AFX_TOOLBAREX_H__D152D63B_A5F3_4646_B062_D2D04653ED1B__INCLUDED_ 
 
#if _MSC_VER > 1000 
#pragma once 
#endif // _MSC_VER > 1000 
// FlyToolBar.h : header file 
// 
 
///////////////////////////////////////////////////////////////////////////// 
// CFlyToolBar window 
 
class CFlyToolBar : public CToolBar 
{ 
	DECLARE_DYNAMIC(CFlyToolBar) 
// Construction 
public: 
	CFlyToolBar(); 
 
// Attributes 
public: 
 
// Operations 
public: 
	BOOL LoadToolBar(UINT nIDResource); 
	void RepaintBackground(); 
	void DrawSeparators(); 
	void DrawSeparators(CClientDC* pDC); 
	void DrawGripper(CWindowDC *pDC, CRect& rectWindow); 
	BOOL PreTranslateMessage(MSG* pMsg); 
	void MouseHover(POINT pt); 
// Overrides 
	// ClassWizard generated virtual function overrides 
	//{{AFX_VIRTUAL(CFlyToolBar) 
	//}}AFX_VIRTUAL 
 
// Implementation 
public: 
	void OnBarStyleChange(DWORD dwOldStyle, DWORD dwNewStyle); 
	BOOL LoadBitmap(LPCTSTR); 
	void SetBKImage(UINT); 
	void SetBKImage(LPCTSTR); 
	void SetBKColor(COLORREF); 
	void EraseNonClient(); 
	virtual ~CFlyToolBar(); 
private: 
	LPBYTE m_pbtButtonStyle; 
	LPCTSTR m_lpszResourceName; 
	BOOL SetButtonEx(UINT); 
	BOOL SetButtonEx(LPCTSTR); 
	UINT m_nButtonCount; 
	UINT m_nSeparatorCount; 
	CSize m_ButtonSize; 
	CImageList m_imglstNormal; 
	CImageList m_imglstDisabled; 
	CImageList m_imglstHot; 
 
	UINT m_nButtonHeight; 
	UINT m_nButtonWidth; 
	WORD m_wToolBarBitCount; 
	CBrush m_bkbrush; 
	enum BackStyle{bs_ORG,bs_RGB,bs_BITMAP}; 
	BackStyle m_bBKStyle; 
	// Generated message map functions 
protected: 
	//{{AFX_MSG(CFlyToolBar) 
	afx_msg BOOL OnEraseBkgnd(CDC* pDC); 
	afx_msg void OnWindowPosChanging(WINDOWPOS FAR* lpwndpos); 
	afx_msg void OnPaint(); 
	//}}AFX_MSG 
 
	DECLARE_MESSAGE_MAP() 
}; 
 
///////////////////////////////////////////////////////////////////////////// 
 
//{{AFX_INSERT_LOCATION}} 
// Microsoft Visual C++ will insert additional declarations immediately before the previous line. 
 
#endif // !defined(AFX_TOOLBAREX_H__D152D63B_A5F3_4646_B062_D2D04653ED1B__INCLUDED_) 