
// MFCAppWmCopydataTestView.h : CMFCAppWmCopydataTestView クラスのインターフェイス
//

#pragma once


class CMFCAppWmCopydataTestView : public CFormView
{
protected: // シリアル化からのみ作成します。
	CMFCAppWmCopydataTestView() noexcept;
	DECLARE_DYNCREATE(CMFCAppWmCopydataTestView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCAPPWMCOPYDATATEST_FORM };
#endif

// 属性
public:
	CMFCAppWmCopydataTestDoc* GetDocument() const;

// 操作
public:

// オーバーライド
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	virtual void OnInitialUpdate(); // 構築後に初めて呼び出されます。
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// 実装
public:
	virtual ~CMFCAppWmCopydataTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnSend();
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
};

#ifndef _DEBUG  // MFCAppWmCopydataTestView.cpp のデバッグ バージョン
inline CMFCAppWmCopydataTestDoc* CMFCAppWmCopydataTestView::GetDocument() const
   { return reinterpret_cast<CMFCAppWmCopydataTestDoc*>(m_pDocument); }
#endif

