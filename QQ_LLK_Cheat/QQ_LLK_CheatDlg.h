// QQ_LLK_CheatDlg.h : ͷ�ļ�
//

#pragma once


// CQQ_LLK_CheatDlg �Ի���
class CQQ_LLK_CheatDlg : public CDialog
{
// ����
public:
	CQQ_LLK_CheatDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CQQ_LLK_CheatDlg();
// �Ի�������
	enum { IDD = IDD_QQ_LLK_CHEAT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	//�Զ�����
	bool bAuto;
	//��ǿ�������
	bool bMark;
	//��������
	int firstX , firstY , secondX  , secondY;
	//��ͼ
	int *m_map;

	//�����С 31*35
	int BlockHeight ;
	int BlockWidth;
	
	//������� 19 * 11
	int m_nCol ;
	int m_nRow;
	//	��ʼλ�� 14��181
	int seekX;
	int seekY;
	//	��Ϸ���С 589 �� 385
	int areaWidth;
	int areaHeight;
	//��Ϸ������
	CString m_strWinName;
	//Ŀ�괰��ʵ�ʴ�С
	CRect m_DestClientRect;
	CWnd * m_pWndHack;
	// Ŀ�������豸�������
	//HDC m_hHackDC;
	// Ŀ����򴰿ھ��
	//HWND m_hwndHack;
	// ������Ϸ�����ڴ��豸����
	CDC m_MemDC;
	// ������Ϸ�����ڴ�λͼ(����ʵ�ʴ�С)
	CBitmap m_memBitMap;

	// ���ɵ���Ϣӳ�亯��
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
