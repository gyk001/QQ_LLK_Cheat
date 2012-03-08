// QQ_LLK_CheatDlg.h : 头文件
//

#pragma once


// CQQ_LLK_CheatDlg 对话框
class CQQ_LLK_CheatDlg : public CDialog
{
// 构造
public:
	CQQ_LLK_CheatDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CQQ_LLK_CheatDlg();
// 对话框数据
	enum { IDD = IDD_QQ_LLK_CHEAT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	//自动销块
	bool bAuto;
	//标记可销方块
	bool bMark;
	//可销方块
	int firstX , firstY , secondX  , secondY;
	//地图
	int *m_map;

	//方块大小 31*35
	int BlockHeight ;
	int BlockWidth;
	
	//方块个数 19 * 11
	int m_nCol ;
	int m_nRow;
	//	开始位置 14，181
	int seekX;
	int seekY;
	//	游戏版大小 589 ， 385
	int areaWidth;
	int areaHeight;
	//游戏窗口名
	CString m_strWinName;
	//目标窗口实际大小
	CRect m_DestClientRect;
	CWnd * m_pWndHack;
	// 目标程序的设备环境句柄
	//HDC m_hHackDC;
	// 目标程序窗口句柄
	//HWND m_hwndHack;
	// 本地游戏区域内存设备环境
	CDC m_MemDC;
	// 本地游戏区域内存位图(窗口实际大小)
	CBitmap m_memBitMap;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LONG OnHotKey(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonDone();
	bool HackIn( );
	void GetMap(void);
	int GetRectData(int x, int y);
	bool Find2Rect(int& x1, int& y1, int& x2, int& y2);
	bool IsLink(int x1, int y1, int x2, int y2);
	bool X1_Link_X2(int x, int y1, int y2);
	bool Y1_Link_Y2(int x1, int x2, int y);
	bool OneCornerLink(int x1, int y1, int x2, int y2);
	bool TwoCornerLink(int x1, int y1, int x2, int y2);
	void RemoteButtonKick(int x1, int y1, int x2, int y2);
public:
	afx_msg void OnBnClickedButtonRefreshData();
	afx_msg LRESULT OnIconNotify(WPARAM wParam, LPARAM lParam);
	void DeleteIcon(void);
	void AddNotifyIcon(void);
public:
	afx_msg void OnDestroy();
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
public:
	afx_msg void OnBnClickedButtonAbout();
public:
	afx_msg void OnMenuExit();
public:
	afx_msg void OnMenuMainWindow();
public:
	afx_msg void OnBnClickedCheckShowMouseMove();
public:
	BOOL m_bShowMouseMove;
public:
	afx_msg void OnMenuShowMouse();
public:
	afx_msg void OnBnClickedButtonClearAll();
};
