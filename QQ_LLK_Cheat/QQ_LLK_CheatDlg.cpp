// QQ_LLK_CheatDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "QQ_LLK_Cheat.h"
#include "QQ_LLK_CheatDlg.h"
#include "HyperLink.h"

#define BLANK_STATE -1
#define NONE_BLANK_STATE 0 
#define LOCAL_DRAW_START_X 6
#define LOCAL_DRAW_START_Y 50

#define  UM_ICONNOTIFY WM_USER+1

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
   virtual BOOL OnInitDialog();
	// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	CHyperLink m_BlogLink;
public:
	CHyperLink m_mailLink;
public:
	CHyperLink m_ProductsLink;
public:

};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_FUYOUIT_COM, m_BlogLink);
	DDX_Control(pDX, IDC_STATIC_FUYOUIT_MAILE, m_mailLink);	
	DDX_Control(pDX, IDC_STATIC_Development, m_ProductsLink);

}
BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()
BOOL CAboutDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_BlogLink.SetURL(_T("http://www.FuyouIt.com"));
	m_mailLink.SetURL(_T("mailto:FuyouIt@gmail.com"));
	m_ProductsLink.SetURL(_T("http://www.FuyouIt.com/development"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


// CQQ_LLK_CheatDlg 对话框




CQQ_LLK_CheatDlg::CQQ_LLK_CheatDlg(CWnd* pParent /*=NULL*/)
: CDialog(CQQ_LLK_CheatDlg::IDD, pParent)
,m_map(NULL)
,bAuto(true)
,bMark(true)
//可销方块
,firstX(-1)
, firstY(-1)
, secondX(-1)
, secondY(-1)
//目标窗口名
,m_strWinName("QQ游戏 - 连连看角色版")
//方块大小
,BlockHeight (35)
,BlockWidth (31)
//方块个数 19 * 11
, m_nCol (21)
,m_nRow(13)
//	开始位置 14，181
,seekX(14)
,seekY(181)
//	游戏版大小 589 ， 385
,areaWidth(589)
,areaHeight(385)
, m_bShowMouseMove(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CQQ_LLK_CheatDlg::~CQQ_LLK_CheatDlg()
{

}
void CQQ_LLK_CheatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_SHOW_MOUSE_MOVE, m_bShowMouseMove);
}

BEGIN_MESSAGE_MAP(CQQ_LLK_CheatDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_DONE, &CQQ_LLK_CheatDlg::OnBnClickedButtonDone)
	ON_BN_CLICKED(IDC_BUTTON_REFRESH_DATA, &CQQ_LLK_CheatDlg::OnBnClickedButtonRefreshData)
	ON_WM_DESTROY()
	ON_MESSAGE(WM_HOTKEY,OnHotKey) //手动加入
	ON_BN_CLICKED(IDC_BUTTON_ABOUT, &CQQ_LLK_CheatDlg::OnBnClickedButtonAbout)
	ON_MESSAGE(UM_ICONNOTIFY, OnIconNotify)
	ON_COMMAND(ID_MENU_EXIT, &CQQ_LLK_CheatDlg::OnMenuExit)
	ON_COMMAND(ID_MENU_MAIN_WINDOW, &CQQ_LLK_CheatDlg::OnMenuMainWindow)
	ON_COMMAND(ID_MENU_ABOUT, &CQQ_LLK_CheatDlg::OnBnClickedButtonAbout)
	ON_BN_CLICKED(IDC_CHECK_SHOW_MOUSE_MOVE, &CQQ_LLK_CheatDlg::OnBnClickedCheckShowMouseMove)
	ON_COMMAND(ID_MENU_SHOW_MOUSE, &CQQ_LLK_CheatDlg::OnMenuShowMouse)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR_ALL, &CQQ_LLK_CheatDlg::OnBnClickedButtonClearAll)
END_MESSAGE_MAP()


// CQQ_LLK_CheatDlg 消息处理程序

BOOL CQQ_LLK_CheatDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	int nRet = RegisterHotKey(GetSafeHwnd(),0,MOD_CONTROL|MOD_SHIFT,'F'); //热键 ctrl + shift + f   
	if(!nRet)   
		AfxMessageBox(_T("RegisterHotKey ctrl + shift + f false"));   
	nRet = RegisterHotKey(GetSafeHwnd(),1,MOD_CONTROL|MOD_SHIFT,'D'); //热键 ctrl + shift + d   
	if(!nRet)   
		AfxMessageBox(_T("RegisterHotKey ctrl + shift + d false"));   
	nRet = RegisterHotKey(GetSafeHwnd(),2,MOD_CONTROL|MOD_SHIFT,'C'); //热键 ctrl + shift + C   
	if(!nRet)   
		AfxMessageBox(_T("RegisterHotKey ctrl + shift + c false"));   
	CDC* pWinDC=GetDC();
	m_MemDC.CreateCompatibleDC(pWinDC);
	m_memBitMap.CreateCompatibleBitmap(pWinDC, areaWidth , areaHeight );
	m_MemDC.SelectObject(&m_memBitMap);
	PostMessage(WM_SYSCOMMAND , SC_MINIMIZE);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CQQ_LLK_CheatDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else if (nID   ==   SC_MINIMIZE)
	{   
		ShowWindow(SW_HIDE);
		AddNotifyIcon();
	}  
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CQQ_LLK_CheatDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
		::BitBlt( GetDC()->Detach() , LOCAL_DRAW_START_X , LOCAL_DRAW_START_Y , areaWidth , areaHeight , m_MemDC, 0, 0,SRCCOPY);

		// 	for (int i=0 ; i<m_nCol ; i++ )
		// 	{
		// 		for (int  j=0 ; j<numY ; j++ )
		// 		{
		// 			if(m_map[i][j] != BLANK_STATE)
		// 			{
		// 					CString str;
		// 					str.Format("%d" , m_map[i][j]  );
		// 					GetDC()->TextOut( i*BlockWidth + LOCAL_DRAW_START_X , j*BlockHeight+LOCAL_DRAW_START_Y , str);
		// 			}
		// 		}
		// 	}


		if(bMark)
		{
			CBrush brush(RGB(255,0,0));
			int xx= (firstX-1) * BlockWidth + LOCAL_DRAW_START_X;
			int yy=	(firstY-1)*BlockHeight+LOCAL_DRAW_START_Y;
			int xx2=(secondX-1)*BlockWidth+LOCAL_DRAW_START_X;
			int yy2=(secondY-1)*BlockHeight+LOCAL_DRAW_START_Y;
			// 			m_MemDC.SelectObject(&brush);
			// 			m_MemDC.Ellipse(xx,yy,xx+20,yy+20);
			// 			m_MemDC.Ellipse(xx2,yy2,xx2+20,yy2+20);
			// 			Invalidate(false);
			// 			m_hHackDC=::GetDC(m_hwndHack);

			GetDC()->SelectObject(brush.m_hObject);
			GetDC()->Ellipse(xx,yy,xx+20,yy+20);
			GetDC()->Ellipse(xx2,yy2,xx2+20,yy2+20);
		}
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
//
HCURSOR CQQ_LLK_CheatDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CQQ_LLK_CheatDlg::OnBnClickedButtonDone()
{
	firstX =-1;
	firstY = -1;
	secondX =-1;
	secondY=-1;
	bool bOk=Find2Rect( firstX , firstY , secondX , secondY );
	if( bOk )
	{
		TRACE( "%d %d  === %d %d\n" ,firstX , firstY , secondX , secondY );
		if ( bAuto)
		{	
			m_map[ firstY*m_nCol+firstX ] = BLANK_STATE;
			m_map[ secondY*m_nCol+secondX ] = BLANK_STATE;
			RemoteButtonKick( firstX-1 , firstY-1 ,secondX -1,secondY -1);
		}
	}
	else
	{	
		TRACE( " Not Found!\n " );
	}
	Invalidate( ) ;
}



bool CQQ_LLK_CheatDlg::HackIn()
{
	m_pWndHack=FindWindow(NULL,m_strWinName);
	if ( m_pWndHack ==NULL)
	{
		AfxMessageBox("无法定位目标窗口，请确认QQ连连看已经运行！");
		return false;
	}
	CRect gameAreaRC;
	m_pWndHack->SetForegroundWindow();
	m_pWndHack->ClientToScreen( gameAreaRC );
	//	m_hHackDC = m_pWndHack->GetDC()->Detach();
	CDC * pHackDC =	m_pWndHack->GetDC();
	m_MemDC.BitBlt( 0 , 0 , areaWidth , areaHeight , pHackDC, seekX, seekY,SRCCOPY);
	return true;

}


void CQQ_LLK_CheatDlg::GetMap(void)
{
	if (m_map!=NULL)
	{
		delete[] m_map;
		m_map = NULL;
	}
	m_map=new int[m_nCol*m_nRow] ;
	for (int i=0 ; i<m_nCol*m_nRow ; i++)
	{
		m_map[i]=NONE_BLANK_STATE;
	}


	for (int i=1;i<m_nCol-1;i++)
	{
		for(int j=1;j<m_nRow-1;j++)
		{
			m_map[j*m_nCol+i]=GetRectData(i-1,j-1);
		}
	}
	// FILE*pf=fopen("a.txt","wt");
	// 
	// 	for(int j=0;j<m_nRow;j++)
	// 	{
	// 		for (int i=0;i<m_nCol;i++)
	// 		{
	// 		fprintf(pf,"%20d",m_map[j*m_nCol+i]);
	// 	}
	// 	fputc('\n',pf);
	// }
	// fclose(pf);

}

int CQQ_LLK_CheatDlg::GetRectData(int x, int y)
{
	int tmp=3;
	CPoint aPos[5];
	COLORREF colorArray[5];
	int colorData=0;
	int baseX,baseY;
	int BlockSeekx=BlockWidth/4;
	int BlockSeeky=BlockHeight/4;
	baseX=x*BlockWidth+BlockWidth/2;
	baseY=y*BlockHeight+BlockHeight/2;

	aPos[0].x=baseX;
	aPos[0].y=baseY;

	aPos[1].x=baseX+BlockSeekx;
	aPos[1].y=baseY;

	aPos[2].x=baseX-BlockSeekx;
	aPos[2].y=baseY;

	aPos[3].x=baseX;
	aPos[3].y=baseY+BlockSeeky;

	aPos[4].x=baseX;
	aPos[4].y=baseY-BlockSeeky;

	for (int i=0;i<5;i++)
	{
		colorArray[i]=GetPixel(m_MemDC,aPos[i].x,aPos[i].y);
	}
	int SameCount=0;
	for (int i=0;i<4;i++)
	{
		colorData+=colorArray[i];
		if (colorArray[i]==colorArray[i+1]/*&&colorArray[i]==RGB(0,0,0)*/)
			SameCount++;
	}
	colorData+=colorArray[4];
	tmp=1;
	if (SameCount>=3)
	{
		return BLANK_STATE;
	}
	return colorData;
}

void CQQ_LLK_CheatDlg::OnBnClickedButtonRefreshData()
{
	if ( HackIn())
	{
		GetMap();
		firstX = -1;
		firstY = -1;
		secondX =-1;
		secondY=-1;
		::BitBlt( GetDC()->Detach() , LOCAL_DRAW_START_X , LOCAL_DRAW_START_Y , areaWidth , areaHeight , m_MemDC, 0, 0,SRCCOPY);
	}

}

/*
bool CQQ_LLK_CheatDlg::X1_Link_X2(int x, int y1, int y2)
{
//将y2调成大数
if ( y1 > y2 )
{
int n = y1;
y1=y2;
y2=n;
}

if (y2-y1==1)
{
//y1、y2 左右相邻
return true;
}
else
{//y1、y2 不相邻
int n=y1+1;
for (int i=n;i<y2;i++)
{
if (m_map[i][x]!=BLANK_STATE)
break;
n++;
}
if (n==y2)
return true;
}
return false;
}

bool CQQ_LLK_CheatDlg::Y1_Link_Y2(int x1, int x2, int y)
{

if (x1>x2)
{
int n=x1;
x1=x2;
x2=n;
}
if (x2-x1==1)
return true;
else
{

int n=x1+1;
for (int i=n;i<x2;i++)
{

if (m_map[y][i] !=BLANK_STATE)
break;
n++;
}
if (n==x2)
return true;
}

return false;
}

bool CQQ_LLK_CheatDlg::OneCornerLink(int x1, int y1, int x2, int y2)
{

if (m_map[y1][x2]==BLANK_STATE)//(x2,y1)
{
if (X1_Link_X2(x2,y1,y2)&&Y1_Link_Y2(x1,x2,y1))
return true;

}
if (m_map[y2][x1]==BLANK_STATE)
{
if(X1_Link_X2(x1,y1,y2)&&Y1_Link_Y2(x1,x2,y2))
return true;
}
return false;
}

bool CQQ_LLK_CheatDlg::TwoCornerLink(int x1, int y1, int x2, int y2)
{

for (int i=0;i<m_nCol;i++)
{
if (i!=x1&&i!=x2)
{
if (m_map[y1][i]==BLANK_STATE&&m_map[y2][i]==BLANK_STATE)
{

if (X1_Link_X2(i,y1,y2)&&Y1_Link_Y2(i,x2,y2)&&Y1_Link_Y2(i,x1,y1))
return true;

}
else
continue;
}
}
for (int i=0;i<m_nRow;i++)
{
if (i!=y1&&i!=y2)
{
if (m_map[i][x1]==BLANK_STATE&&m_map[i][x2]==BLANK_STATE)
{

if (Y1_Link_Y2(x1,x2,i)&&X1_Link_X2(x1,i,y1)&&X1_Link_X2(x2,i,y2))
return true;
}
else
continue;
}
}
return false;
}

bool CQQ_LLK_CheatDlg::IsLink(int x1, int y1, int x2, int y2)
{

if (x1==x2)
{
if (X1_Link_X2(x1,y1,y2))
return true;
}
else if (y1==y2)
{
if (Y1_Link_Y2(x1,x2,y1))
return true;
}
if(OneCornerLink(x1,y1,x2,y2))
return true;
else if (TwoCornerLink(x1,y1,x2,y2))
return true;

return false;
}

bool CQQ_LLK_CheatDlg::Find2Rect(int& x1, int& y1, int& x2, int& y2)
{
int pMap[ 19 ][ 11 ];
for (int i=0 ; i<m_nCol ; i++)
{
for( int j=0 ; j< m_nRow; j++)	
{
pMap[ i ][ j ] = m_map[ i ][ j ];
}
}
for (int i=0;i<numX*m_nRow;i++)
{

for ( int j=0 ; j<m_nRow ; j++)
{
if (pMap[ i ][ j ]==BLANK_STATE)
{
continue;
}
for ( int ii=0 ; ii<m_nCol ; ii++ )
{
for ( int jj=0 ; jj<m_nRow ; jj++)
{
if ( pMap[ i ][ j ] == pMap[ ii ][ jj ] )
{
if (IsLink( i , j, ii, jj))
{
x1 = i ;
y1 = j;
x2 = ii;
y2 = jj;
return true;
}
}
}
}
}

// 		if (pMap[i]==BLANK_STATE)
// 			continue;
// 		for(int j=i+1;j<numX*numY;j++)
// 		{
// 			if (pMap[j]==pMap[i])
// 			{
// 				x1=i%numX;
// 				y1=i/numX;
// 				x2=j%numX;
// 				y2=j/numX;
// 				if (IsLink(x1,y1,x2,y2))
// 				{
// 					return true;
// 				}
// 			}
// 		}
}
return false;
}
*/

bool CQQ_LLK_CheatDlg::X1_Link_X2(int x, int y1, int y2)
{
	if (y1>y2)
	{
		int n=y1;
		y1=y2;
		y2=n;
	}
	if (y2-y1==1)
		return true;
	else
	{

		int n=y1+1;
		for (int i=n;i<y2;i++)
		{

			if (m_map[i*m_nCol+x]!=BLANK_STATE)
				break;
			n++;
		}
		if (n==y2)
			return true;
	}
	return false;
}

bool CQQ_LLK_CheatDlg::Y1_Link_Y2(int x1, int x2, int y)
{
	if (x1>x2)
	{
		int n=x1;
		x1=x2;
		x2=n;
	}
	if (x2-x1==1)
		return true;
	else
	{

		int n=x1+1;
		for (int i=n;i<x2;i++)
		{

			if (m_map[y*m_nCol+i]!=BLANK_STATE)
				break;
			n++;
		}
		if (n==x2)
			return true;
	}
	return false;
}

bool CQQ_LLK_CheatDlg::OneCornerLink(int x1, int y1, int x2, int y2)
{
	if (m_map[y1*m_nCol+x2]==BLANK_STATE)//(x2,y1)
	{
		if (X1_Link_X2(x2,y1,y2)&&Y1_Link_Y2(x1,x2,y1))
			return true;

	}
	if (m_map[y2*m_nCol+x1]==BLANK_STATE)
	{
		if(X1_Link_X2(x1,y1,y2)&&Y1_Link_Y2(x1,x2,y2))
			return true;
	}
	return false;
}

bool CQQ_LLK_CheatDlg::TwoCornerLink(int x1, int y1, int x2, int y2)
{
	for (int i=0;i<m_nCol;i++)
	{
		if (i!=x1&&i!=x2)
		{
			if (m_map[y1*m_nCol+i]==BLANK_STATE&&m_map[y2*m_nCol+i]==BLANK_STATE)
			{

				if (X1_Link_X2(i,y1,y2)&&Y1_Link_Y2(i,x2,y2)&&Y1_Link_Y2(i,x1,y1))
					return true;

			}
			else
				continue;
		}
	}
	for (int i=0;i<m_nRow;i++)
	{
		if (i!=y1&&i!=y2)
		{
			if (m_map[i*m_nCol+x1]==BLANK_STATE&&m_map[i*m_nCol+x2]==BLANK_STATE)
			{

				if (Y1_Link_Y2(x1,x2,i)&&X1_Link_X2(x1,i,y1)&&X1_Link_X2(x2,i,y2))
					return true;
			}
			else
				continue;
		}
	}

	return false;
}

bool CQQ_LLK_CheatDlg::IsLink(int x1, int y1, int x2, int y2)
{
	if (x1==x2)
	{
		if (X1_Link_X2(x1,y1,y2))
			return true;
	}
	else if (y1==y2)
	{
		if (Y1_Link_Y2(x1,x2,y1))
			return true;
	}
	if(OneCornerLink(x1,y1,x2,y2))
		return true;
	else if (TwoCornerLink(x1,y1,x2,y2))
		return true;
	return false;
}

bool CQQ_LLK_CheatDlg::Find2Rect(int& x1, int& y1, int& x2, int& y2)
{
	if ( !m_map )
	{
		return false;
	}
	//	bool bFound=false;
	int * pMap=m_map;
	for (int i=0;i<m_nCol*m_nRow;i++)
	{
		if (pMap[i]==BLANK_STATE || pMap[i] == NONE_BLANK_STATE)
			continue;
		for(int j=i+1;j<m_nCol*m_nRow;j++)
		{
			if (pMap[j]==pMap[i])
			{
				x1=i%m_nCol;
				y1=i/m_nCol;
				x2=j%m_nCol;
				y2=j/m_nCol;
				if (IsLink(x1,y1,x2,y2))
				{
					return true;
				}
			}



		}
	}
	return false;
}


void CQQ_LLK_CheatDlg::RemoteButtonKick(int x1, int y1, int x2, int y2)
{
	int DestX,DestY;
	DestX=x1*BlockWidth+BlockWidth/2 + seekX;
	DestY=y1*BlockHeight+BlockHeight/2 + seekY;

	CPoint curPt;
	CPoint pt ( DestX ,DestY );
	int tmpX;
	int tmpY;
	if(m_bShowMouseMove)
	{
		::GetCursorPos( &curPt );

		m_pWndHack->ClientToScreen( &pt );
		tmpX = ( pt.x+curPt.x ) /2;
		tmpY = ( pt.y + curPt.y )/2;
		::SetCursorPos( tmpX , tmpY );	
		Sleep( 50 );
		::SetCursorPos( pt.x , pt.y );	
	}
	LPARAM lParam=MAKELPARAM(DestX,DestY);
	m_pWndHack-> SendMessage(WM_LBUTTONDOWN,MK_LBUTTON,lParam);
	m_pWndHack-> SendMessage(WM_LBUTTONUP,MK_LBUTTON,lParam);


	DestX=x2*BlockWidth+BlockWidth/2 + seekX;
	DestY=y2*BlockHeight+BlockHeight/2 +seekY;
	lParam=MAKELPARAM(DestX,DestY);
	m_pWndHack-> SendMessage(WM_LBUTTONDOWN,MK_LBUTTON,lParam);
	m_pWndHack-> SendMessage(WM_LBUTTONUP,MK_LBUTTON,lParam);
	if (m_bShowMouseMove)
	{
		Sleep( 50 );
		pt.x = DestX;
		pt.y = DestY;
		m_pWndHack->ClientToScreen( &pt );
		tmpX = ( pt.x+curPt.x ) /2;
		tmpY = ( pt.y + curPt.y )/2;
		::SetCursorPos( tmpX , tmpY );	
		Sleep( 50 );
		pt.x = DestX;
		pt.y = DestY;
		m_pWndHack->ClientToScreen( &pt );
		::SetCursorPos( pt.x ,pt.y );  
	}
	Invalidate(false);

}
void CQQ_LLK_CheatDlg::OnDestroy()
{
	CDialog::OnDestroy();

	if ( m_map != NULL)
	{
		delete []m_map;
		m_map =NULL;
	}
}

BOOL CQQ_LLK_CheatDlg::PreTranslateMessage(MSG* pMsg)
{
	return CDialog::PreTranslateMessage(pMsg);
}

LONG CQQ_LLK_CheatDlg::OnHotKey(WPARAM   wParam,LPARAM   lParam)   
{   
	UINT fuModifiers = (UINT) LOWORD(lParam);  // key-modifier flags    
	UINT uVirtKey = (UINT) HIWORD(lParam);     // virtual-key code    

	//判断响应了什么热键   
	if( (MOD_CONTROL|MOD_SHIFT )== fuModifiers && 'D' == uVirtKey )   
	{   
		OnBnClickedButtonDone();

	}   
	else if(  (MOD_CONTROL|MOD_SHIFT)== fuModifiers && 'F' == uVirtKey )   
	{   
		OnBnClickedButtonRefreshData(); 
	}  
	else if(  (MOD_CONTROL|MOD_SHIFT)== fuModifiers && 'C' == uVirtKey )   
	{   
		OnBnClickedButtonClearAll(); 
	}   
	else  
		AfxMessageBox(_T("你按下了未知热键"));     
	return TRUE;

} 


void CQQ_LLK_CheatDlg::OnBnClickedButtonAbout()
{
	CAboutDlg dlg;
	dlg.DoModal();
}

void CQQ_LLK_CheatDlg::AddNotifyIcon(void)
{
	NOTIFYICONDATA nid;
	nid.cbSize = sizeof(nid);
	nid.hWnd = m_hWnd; 
	nid.uID = IDR_MAINFRAME; 
	nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP|NIF_INFO;
	nid.dwInfoFlags = NIIF_USER| NIIF_NOSOUND;
	nid.uCallbackMessage = UM_ICONNOTIFY;
	nid.hIcon =  theApp.LoadIcon( IDR_MAINFRAME );

	CString str = "yisufuyou提示";
	lstrcpyn(nid.szTip, (LPCSTR)str, 
		sizeof(nid.szTip) / sizeof(nid.szTip[0]));
	lstrcpyn(nid.szInfoTitle, (LPCSTR)str, 
		sizeof(nid.szInfoTitle) / sizeof(nid.szInfoTitle[0]));
	str ="Ctrl+Shilft+F 刷新地图\r\nCtrl+Shilft+D:销块\r\nCtrl+Shilft+C:清除全部\r\n学习作品，请勿用于非法用途！";
	lstrcpyn(nid.szInfo, (LPCSTR)str, 
		sizeof(nid.szInfo) / sizeof(nid.szInfo[0]));
	Shell_NotifyIcon(NIM_ADD, &nid);
}


void CQQ_LLK_CheatDlg::DeleteIcon(void)
{
	NOTIFYICONDATA nid;
	nid.cbSize = sizeof(nid);
	nid.hWnd = m_hWnd;
	nid.uID = IDR_MAINFRAME;
	Shell_NotifyIcon(NIM_DELETE, &nid);
}


LRESULT CQQ_LLK_CheatDlg::OnIconNotify(WPARAM wParam, LPARAM lParam)
{
	switch ((UINT)lParam)
	{
		// 鼠标单击操作
	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:
		{
			// 装入图标操作菜单
			CMenu menu;
			menu.LoadMenu(IDR_MENU_NOTIFIY);
			CMenu *pPopup=menu.GetSubMenu(0);
			if (m_bShowMouseMove)
			{
				pPopup->CheckMenuItem( ID_MENU_SHOW_MOUSE ,MF_BYCOMMAND|MF_CHECKED );
			} 
	
			// 鼠标单击位置
			CPoint point;
			GetCursorPos(&point);

			// 将背景窗口激活
			SetForegroundWindow();
			// 显示图标菜单
			pPopup->TrackPopupMenu(TPM_LEFTBUTTON|TPM_RIGHTBUTTON|TPM_VERTICAL, 
				point.x, point.y, this, NULL); 

			// 增加一个额外消息，使菜单操作正确
			PostMessage(WM_USER, 0, 0);
			break;
		}
	case WM_LBUTTONDBLCLK:
		OnMenuMainWindow();
		break;
	}
	return 0;
}


void CQQ_LLK_CheatDlg::OnMenuExit()
{
	PostQuitMessage(0);
}

void CQQ_LLK_CheatDlg::OnMenuMainWindow()
{
	DeleteIcon();
	ShowWindow(SW_SHOW);
}

void CQQ_LLK_CheatDlg::OnBnClickedCheckShowMouseMove()
{
	UpdateData();
}

void CQQ_LLK_CheatDlg::OnMenuShowMouse()
{
	m_bShowMouseMove = ! m_bShowMouseMove;
	UpdateData( FALSE );
}

void CQQ_LLK_CheatDlg::OnBnClickedButtonClearAll()
{
	firstX =-1;
	firstY = -1;
	secondX =-1;
	secondY=-1;
	bool bOk = false;
	do 
	{
		bOk=Find2Rect( firstX , firstY , secondX , secondY );
		if( bOk )
		{
			TRACE( "%d %d  === %d %d\n" ,firstX , firstY , secondX , secondY );
			if ( bAuto)
			{	
				m_map[ firstY*m_nCol+firstX ] = BLANK_STATE;
				m_map[ secondY*m_nCol+secondX ] = BLANK_STATE;
				RemoteButtonKick( firstX-1 , firstY-1 ,secondX -1,secondY -1);
			}
		}
	} while (bOk);

}
