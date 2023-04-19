
// MFCAppWmCopydataTestView.cpp : CMFCAppWmCopydataTestView クラスの実装
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS は、プレビュー、縮小版、および検索フィルター ハンドラーを実装している ATL プロジェクトで定義でき、
// そのプロジェクトとのドキュメント コードの共有を可能にします。
#ifndef SHARED_HANDLERS
#include "MFCAppWmCopydataTest.h"
#endif

#include "MFCAppWmCopydataTestDoc.h"
#include "MFCAppWmCopydataTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCAppWmCopydataTestView

IMPLEMENT_DYNCREATE(CMFCAppWmCopydataTestView, CFormView)

BEGIN_MESSAGE_MAP(CMFCAppWmCopydataTestView, CFormView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCAppWmCopydataTestView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_BTN_SEND, &CMFCAppWmCopydataTestView::OnBnClickedBtnSend)
	ON_WM_COPYDATA()
END_MESSAGE_MAP()

// CMFCAppWmCopydataTestView コンストラクション/デストラクション

CMFCAppWmCopydataTestView::CMFCAppWmCopydataTestView() noexcept
	: CFormView(IDD_MFCAPPWMCOPYDATATEST_FORM)
{
	// TODO: 構築コードをここに追加します。

}

CMFCAppWmCopydataTestView::~CMFCAppWmCopydataTestView()
{
}

void CMFCAppWmCopydataTestView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CMFCAppWmCopydataTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CMFCAppWmCopydataTestView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CMFCAppWmCopydataTestView の印刷


void CMFCAppWmCopydataTestView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCAppWmCopydataTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CMFCAppWmCopydataTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CMFCAppWmCopydataTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}

void CMFCAppWmCopydataTestView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷用のコードをここに追加してください。
}

void CMFCAppWmCopydataTestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCAppWmCopydataTestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCAppWmCopydataTestView の診断

#ifdef _DEBUG
void CMFCAppWmCopydataTestView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFCAppWmCopydataTestView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFCAppWmCopydataTestDoc* CMFCAppWmCopydataTestView::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCAppWmCopydataTestDoc)));
	return (CMFCAppWmCopydataTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCAppWmCopydataTestView メッセージ ハンドラー


void CMFCAppWmCopydataTestView::OnBnClickedBtnSend()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CWnd* pWndTitle = GetDlgItem(IDC_EDT_WINTITLE);
	CWnd* pWndTitleSend = GetDlgItem(IDC_EDT_WINTITLESEND);
	CWnd* pWndSend = GetDlgItem(IDC_EDT_SEND);
	CWnd* pWndRecv = GetDlgItem(IDC_EDT_RECV);
	CString stTitle;
	CString stTitleSend;
	CString stSend;

	pWndTitle->GetWindowTextW(stTitle);
	pWndTitleSend->GetWindowTextW(stTitleSend);
	pWndSend->GetWindowTextW(stSend);

	GetDocument()->SetTitle(stTitle);

	CString stFindWindow;
	pWndTitleSend->GetWindowTextW(stTitleSend);

	stFindWindow = stTitleSend;
	stFindWindow += TEXT(" - MFCAppWmCopydataTest");
	CWnd* pWndCopyData = FindWindow(0, stFindWindow);

	if (pWndCopyData) {
		wchar_t* pBuf = new wchar_t[128];
		wcscpy_s(pBuf, 128, stSend);
		pWndCopyData->SendMessage(WM_COPYDATA, (WPARAM)this->GetSafeHwnd(), (LPARAM)1);
		delete[] pBuf;
	}



	if (pWndCopyData) {
#if 1
		CWnd *pWndEx = FindWindowEx(pWndCopyData->m_hWnd, NULL, TEXT("#32770"), NULL);
		if (pWndEx) {
			wchar_t* pBuf = new wchar_t[128];
			wcscpy_s(pBuf,128,stSend);
			pWndEx->SendMessage(WM_COPYDATA, (WPARAM)this->GetSafeHwnd(), (LPARAM)1);
			delete[] pBuf;
		}
#else 
		HWND hWnd = ::FindWindowEx(pWndCopyData->m_hWnd, NULL, TEXT("#32770"), NULL);
		if (hWnd) {
			wchar_t* pBuf = new wchar_t[128];
			wcscpy_s(pBuf,128,stSend);
			::SendMessage(hWnd,WM_COPYDATA, (WPARAM)this->GetSafeHwnd(), (LPARAM)pBuf);
			delete[] pBuf;
		}
#endif
	}

}


BOOL CMFCAppWmCopydataTestView::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。
	TRACE(TEXT("CMFCAppWmCopydataTestView::OnCopyData()\n"));
	return CFormView::OnCopyData(pWnd, pCopyDataStruct);
}
