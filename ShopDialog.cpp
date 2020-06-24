

#include "stdafx.h"
#include "Project.h"
#include "ShopDialog.h"
#include "afxdialogex.h"
#include "ProjectView.h"




// CShopDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(CShopDialog, CDialog)

CShopDialog::CShopDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_SHOP, pParent)
{
	m_pView = (CProjectView*)AfxGetMainWnd();
	font.CreatePointFont(100,_T("210 동화책 L"));
}

CShopDialog::~CShopDialog()
{
}

void CShopDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, fish1);
	DDX_Control(pDX, IDC_BUTTON2, fish2);
	DDX_Control(pDX, IDC_BUTTON3, fish3);
	DDX_Control(pDX, IDC_BUTTON4, fish4);
	DDX_Control(pDX, IDC_BUTTON5, fish5);
	DDX_Control(pDX, IDC_BUTTON6, fish6);
	DDX_Control(pDX, IDC_BUTTON7, fish7);
	DDX_Control(pDX, IDC_BUTTON8, fish8);

	CBitmap bf1, bf2, bf3, bf4, bf5, bf6, bf7, bf8;
	bf1.LoadBitmapW(IDB_FISH_1);
	fish1.SetBitmap(bf1);
	bf2.LoadBitmapW(IDB_FISH_2);
	fish2.SetBitmap(bf2);
	bf3.LoadBitmapW(IDB_FISH_3);
	fish3.SetBitmap(bf3);
	bf4.LoadBitmapW(IDB_FISH_4);
	fish4.SetBitmap(bf4);
	bf5.LoadBitmapW(IDB_FISH_5);
	fish5.SetBitmap(bf5);
	bf6.LoadBitmapW(IDB_FISH_6);
	fish6.SetBitmap(bf6);
	bf7.LoadBitmapW(IDB_FISH_7);
	fish7.SetBitmap(bf7);
	bf8.LoadBitmapW(IDB_FISH_8);
	fish8.SetBitmap(bf8);


	coinnum = m_pView->coin;

	data = _T("");
	have = _T("");

	data = _T("이름:플라운더\n특징:소심하지만 인어공주 에리얼을 늘 도와주려고 노력하는 꼬마 물고기\n가격:10코인");
	SetDlgItemText(IDC_DATA, data);
	have = _T("구매완료");
	SetDlgItemText(IDC_HAVE, have);

	fish = (LPCTSTR)IDB_FISH_1;
	SetDlgItemText(IDC_DATA, data);
	str.Format(_T("coin: %d"), coinnum);
	SetDlgItemText(IDC_COIN, str);
	SetDlgItemText(IDC_HAVE, have);
	GetDlgItem(IDC_HAVE)->SetFont(&font);
	GetDlgItem(IDC_COIN)->SetFont(&font);
	GetDlgItem(IDC_DATA)->SetFont(&font);
	GetDlgItem(IDC_APPLY)->SetFont(&font);
	GetDlgItem(IDC_CANCLE)->SetFont(&font);
	GetDlgItem(IDC_BUY)->SetFont(&font);
	
	//	f1 = TRUE, f2 = FALSE, f3 = FALSE, f4 = FALSE, f5 = FALSE, f6 = FALSE, f7 = FALSE, f8 = FALSE;
	bt1 = FALSE, bt2 = FALSE, bt3 = FALSE, bt4 = FALSE, bt5 = FALSE, bt6 = FALSE, bt7 = FALSE, bt8 = FALSE;

	DDX_Control(pDX, IDC_APPLY, m_apply);
	DDX_Control(pDX, IDC_BUY, m_buy);
//	DDX_Control(pDX, IDC_DATA, m_data);
}


BEGIN_MESSAGE_MAP(CShopDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CShopDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CShopDialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CShopDialog::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CShopDialog::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CShopDialog::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CShopDialog::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CShopDialog::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CShopDialog::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUY, &CShopDialog::OnBnClickedBuy)
	ON_BN_CLICKED(IDC_APPLY, &CShopDialog::OnBnClickedApply)
	ON_BN_CLICKED(IDOK, &CShopDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CANCEL, &CShopDialog::OnBnClickedCancel)
END_MESSAGE_MAP()

// CShopDialog 메시지 처리기입니다.




void CShopDialog::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	bt1 = TRUE, bt2 = FALSE, bt3 = FALSE, bt4 = FALSE, bt5 = FALSE, bt6 = FALSE, bt7 = FALSE, bt8 = FALSE;


	data = _T("이름:플라운더\n특징:소심하지만 인어공주 에리얼을 늘 도와주려고 노력하는 꼬마 물고기이다.\n가격:10코인");
	SetDlgItemText(IDC_DATA, data);
	if (coinnum >= 0) {
		m_buy.EnableWindow(TRUE);
	}
	else {
		m_buy.EnableWindow(FALSE);
	}
	if (f1 == TRUE) {
		m_apply.EnableWindow(TRUE);
		m_buy.EnableWindow(FALSE);
		have = _T("구매완료");
		SetDlgItemText(IDC_HAVE, have);
	}
	else {
		m_apply.EnableWindow(FALSE);
		have = _T("");
		SetDlgItemText(IDC_HAVE, have);
		if (coinnum >= 0) {
			m_buy.EnableWindow(TRUE);
		}
		else {
			m_buy.EnableWindow(FALSE);
		}
	}



}


void CShopDialog::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	bt1 = FALSE, bt2 = TRUE, bt3 = FALSE, bt4 = FALSE, bt5 = FALSE, bt6 = FALSE, bt7 = FALSE, bt8 = FALSE;

	data = _T("이름:유령 물고기\n특징: 유령처럼 뼈마디마디가 보인다. 이미 포식자에게 먹혀 뼈만 남았지만 죽지못하고 다시 살아났다.\n가격:10코인");
	SetDlgItemText(IDC_DATA, data);

	if (coinnum >= 10) {
		m_buy.EnableWindow(TRUE);
	}
	else {
		m_buy.EnableWindow(FALSE);
	}

	if (f2 == TRUE) {
		m_apply.EnableWindow(TRUE);
		m_buy.EnableWindow(FALSE);
		have = _T("구매완료");
		SetDlgItemText(IDC_HAVE, have);
	}
	else {
		m_apply.EnableWindow(FALSE);
		have = _T("");
		SetDlgItemText(IDC_HAVE, have);
		if (coinnum >= 10) {
			m_buy.EnableWindow(TRUE);
		}
		else {
			m_buy.EnableWindow(FALSE);
		}
	}

}


void CShopDialog::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	bt1 = FALSE, bt2 = FALSE, bt3 = TRUE, bt4 = FALSE, bt5 = FALSE, bt6 = FALSE, bt7 = FALSE, bt8 = FALSE;

	data = _T("이름:포세이돈\n특징:크로노스의 아들이자 제우스의 형제인 포세이돈, 그가 물고기의 형태를 취했을때의 모습이다.\n가격:10코인");
	SetDlgItemText(IDC_DATA, data);
	if (coinnum >= 10) {
		m_buy.EnableWindow(TRUE);
	}
	else {
		m_buy.EnableWindow(FALSE);
	}

	if (f3 == TRUE) {
		m_apply.EnableWindow(TRUE);
		m_buy.EnableWindow(FALSE);
		have = _T("구매완료");
		SetDlgItemText(IDC_HAVE, have);
	}
	else {
		m_apply.EnableWindow(FALSE);
		have = _T("");
		SetDlgItemText(IDC_HAVE, have);
		if (coinnum >= 10) {
			m_buy.EnableWindow(TRUE);
		}
		else {
			m_buy.EnableWindow(FALSE);
		}
	}
}


void CShopDialog::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	bt1 = FALSE, bt2 = FALSE, bt3 = FALSE, bt4 = TRUE, bt5 = FALSE, bt6 = FALSE, bt7 = FALSE, bt8 = FALSE;

	data = _T("이름:아귀\n특징:특유의 입이 크고 흉측한 생김새 때문에 아귀라고 불린다. 머리위의 불빛으로 낚시를 즐긴다.\n가격:10코인");
	SetDlgItemText(IDC_DATA, data);
	if (coinnum >= 10) {
		m_buy.EnableWindow(TRUE);
	}
	else {
		m_buy.EnableWindow(FALSE);
	}

	if (f4 == TRUE) {
		m_apply.EnableWindow(TRUE);
		m_buy.EnableWindow(FALSE);
		have = _T("구매완료");
	SetDlgItemText(IDC_HAVE, have);
	}
	else {
		m_apply.EnableWindow(FALSE);
		have = _T("");
		SetDlgItemText(IDC_HAVE, have);
		if (coinnum >= 10) {
			m_buy.EnableWindow(TRUE);
		}
		else {
			m_buy.EnableWindow(FALSE);
		}
	}
}


void CShopDialog::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	bt1 = FALSE, bt2 = FALSE, bt3 = FALSE, bt4 = FALSE, bt5 = TRUE, bt6 = FALSE, bt7 = FALSE, bt8 = FALSE;

	data = _T("이름:우파루파\n특징:본명은 아홀로톨, 도룡뇽으로 분류된다. 애완용으로 많이 기르지만 최초의 용도는 식용이라고 전해진다\n가격:10코인");
	SetDlgItemText(IDC_DATA, data);
	if (coinnum >= 10) {
		m_buy.EnableWindow(TRUE);
	}
	else {
		m_buy.EnableWindow(FALSE);
	}

	if (f5 == TRUE) {
		m_apply.EnableWindow(TRUE);
		m_buy.EnableWindow(FALSE);
		have = _T("구매완료");
		SetDlgItemText(IDC_HAVE, have);
	}
	else {
		m_apply.EnableWindow(FALSE);
		have = _T("");
		SetDlgItemText(IDC_HAVE, have);
		if (coinnum >= 10) {
			m_buy.EnableWindow(TRUE);
		}
		else {
			m_buy.EnableWindow(FALSE);
		}
	}
}


void CShopDialog::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	bt1 = FALSE, bt2 = FALSE, bt3 = FALSE, bt4 = FALSE, bt5 = FALSE, bt6 = TRUE, bt7 = FALSE, bt8 = FALSE;

	data = _T("이름:봄\n특징: 마치 누군가가 기르는 듯한 올블랙의 귀여운 고양이, 호기심이 많아 바닷속에 뛰어들었다!\n가격:10코인");
	SetDlgItemText(IDC_DATA, data);
	if (coinnum >= 10) {
		m_buy.EnableWindow(TRUE);
	}
	else {
		m_buy.EnableWindow(FALSE);
	}

	if (f6 == TRUE) {
		m_apply.EnableWindow(TRUE);
		m_buy.EnableWindow(FALSE);
		have = _T("구매완료");
		SetDlgItemText(IDC_HAVE, have);
	}
	else {
		m_apply.EnableWindow(FALSE);
		have = _T("");
		SetDlgItemText(IDC_HAVE, have);
		if (coinnum >= 10) {
			m_buy.EnableWindow(TRUE);
		}
		else {
			m_buy.EnableWindow(FALSE);
		}
	}
}


void CShopDialog::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	bt1 = FALSE, bt2 = FALSE, bt3 = FALSE, bt4 = FALSE, bt5 = FALSE, bt6 = FALSE, bt7 = TRUE, bt8 = FALSE;

	data = _T("이름:니모\n특징:종류는 흰동가리, 광대 물고기라고도 불린다. 치과에 있는 어항에서 빠져나온 채 위험한 바다를 헤매고 있다.\n가격:20코인");
	SetDlgItemText(IDC_DATA, data);
	if (coinnum >= 20) {
		m_buy.EnableWindow(TRUE);
	}
	else {
		m_buy.EnableWindow(FALSE);
	}

	if (f7 == TRUE) {
		m_apply.EnableWindow(TRUE);
		m_buy.EnableWindow(FALSE);
		have = _T("구매완료");
		SetDlgItemText(IDC_HAVE, have);
	}
	else {
		m_apply.EnableWindow(FALSE);
		have = _T("");
		SetDlgItemText(IDC_HAVE, have);
		if (coinnum >= 20) {
			m_buy.EnableWindow(TRUE);
		}
		else {
			m_buy.EnableWindow(FALSE);
		}
	}
}


void CShopDialog::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	bt1 = FALSE, bt2 = FALSE, bt3 = FALSE, bt4 = FALSE, bt5 = FALSE, bt6 = FALSE, bt7 = FALSE, bt8 = TRUE;

	data = _T("이름:크리스마스 물고기\n특징:크리스마스를 기념해 루돌프 분장을 한 물고기, 스킨을 착용하면 특별한 일이 벌어진다!\n가격:60코인");
	SetDlgItemText(IDC_DATA, data);

	if (coinnum >= 60) {
		m_buy.EnableWindow(TRUE);
	}
	else {
		m_buy.EnableWindow(FALSE);
	}
	if (f8 == TRUE) {
		m_apply.EnableWindow(TRUE);
		m_buy.EnableWindow(FALSE);
		have = _T("구매완료");
		SetDlgItemText(IDC_HAVE, have);
	}
	else {
		m_apply.EnableWindow(FALSE);
		have = _T("");
		SetDlgItemText(IDC_HAVE, have);
		if (coinnum >= 60) {
			m_buy.EnableWindow(TRUE);
		}
		else {
			m_buy.EnableWindow(FALSE);
		}
	}
}


BOOL CShopDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CShopDialog::OnBnClickedBuy()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (f1 == FALSE&&bt1 == TRUE) {
		f1 = TRUE;
		coinnum -= 0;
		m_buy.EnableWindow(FALSE);
		m_apply.EnableWindow(TRUE);
		have = _T("구매완료");
		SetDlgItemText(IDC_HAVE, have);
	}
	if (f2 == FALSE&&bt2 == TRUE) {
		f2 = TRUE;
		coinnum -= 10;
		m_buy.EnableWindow(FALSE);
		m_apply.EnableWindow(TRUE);
		have = _T("구매완료");
		SetDlgItemText(IDC_HAVE, have);
	}
	if (f3 == FALSE&&bt3 == TRUE) {
		f3 = TRUE;
		coinnum -= 10;
		m_buy.EnableWindow(FALSE);
		m_apply.EnableWindow(TRUE);
		have = _T("구매완료");
		SetDlgItemText(IDC_HAVE, have);
	}
	if (f4 == FALSE&&bt4 == TRUE) {
		f4 = TRUE;
		coinnum -= 10;
		m_buy.EnableWindow(FALSE);
		m_apply.EnableWindow(TRUE);
		have = _T("구매완료");
		SetDlgItemText(IDC_HAVE, have);
	}
	if (f5 == FALSE&&bt5 == TRUE) {
		f5 = TRUE;
		coinnum -= 10;
		m_buy.EnableWindow(FALSE);
		m_apply.EnableWindow(TRUE);
		have = _T("구매완료");
		SetDlgItemText(IDC_HAVE, have);
	}
	if (f6 == FALSE&&bt6 == TRUE) {
		f6 = TRUE;
		coinnum -= 10;
		m_buy.EnableWindow(FALSE);
		m_apply.EnableWindow(TRUE);
		have = _T("구매완료");
		SetDlgItemText(IDC_HAVE, have);
	}
	if (f7 == FALSE&&bt7 == TRUE) {
		f7 = TRUE;
		coinnum -= 20;
		m_buy.EnableWindow(FALSE);
		m_apply.EnableWindow(TRUE);
		have = _T("구매완료");
		SetDlgItemText(IDC_HAVE, have);
	}
	if (f8 == FALSE&&bt8 == TRUE) {
		f8 = TRUE;
		coinnum -= 60;
		m_buy.EnableWindow(FALSE);
		m_apply.EnableWindow(TRUE);
		have = _T("구매완료");
		SetDlgItemText(IDC_HAVE, have);
	}
	str.Format(_T("coin: %d"), coinnum);
	SetDlgItemText(IDC_COIN, str);
}


void CShopDialog::OnBnClickedApply()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (f1 == TRUE&&bt1 == TRUE) {
		fish = (LPCTSTR)IDB_FISH_1;
		fish_S = (LPCTSTR)IDB_FISH1_REVERSE;
		m_pView->christmas = FALSE;
	}
	if (f2 == TRUE&&bt2 == TRUE) {
		fish = (LPCTSTR)IDB_FISH_2;
		fish_S = (LPCTSTR)IDB_FISH2_REVERSE;
		m_pView->christmas = FALSE;
	}
	if (f3 == TRUE&&bt3 == TRUE) {
		fish = (LPCTSTR)IDB_FISH_3;
		fish_S = (LPCTSTR)IDB_FISH3_REVERSE;
		m_pView->christmas = FALSE;
	}
	if (f4 == TRUE&&bt4 == TRUE) {
		fish = (LPCTSTR)IDB_FISH_4;
		fish_S = (LPCTSTR)IDB_FISH4_REVERSE;
		m_pView->christmas = FALSE;
	}

	if (f5 == TRUE&&bt5 == TRUE) {
		fish = (LPCTSTR)IDB_FISH_5;
		fish_S = (LPCTSTR)IDB_FISH5_REVERSE;
		m_pView->christmas = FALSE;
	}

	if (f6 == TRUE&&bt6 == TRUE) {
		fish = (LPCTSTR)IDB_FISH_6;
		fish_S = (LPCTSTR)IDB_FISH6_REVERSE;
		m_pView->christmas = FALSE;
	}

	if (f7 == TRUE&&bt7 == TRUE) {
		fish = (LPCTSTR)IDB_FISH_7;
		fish_S = (LPCTSTR)IDB_FISH7_REVERSE;
		m_pView->christmas = FALSE;
	}

	if (f8 == TRUE&&bt8 == TRUE) {
		fish = (LPCTSTR)IDB_FISH_8;
		fish_S = (LPCTSTR)IDB_FISH8_REVERSE;
		m_pView->christmas = TRUE;
	}


	m_pView->f1 = f1;
	m_pView->f2 = f2;
	m_pView->f3 = f3;
	m_pView->f4 = f4;
	m_pView->f5 = f5;
	m_pView->f6 = f6;;
	m_pView->f7 = f7;
	m_pView->f8 = f8;
	m_pView->coin = coinnum;
	m_pView->fish = fish;
	m_pView->fish2 = fish_S;
	SetDlgItemText(IDC_DATA, data);
}


void CShopDialog::OnCancel()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	UpdateData(TRUE);
	m_pView->f1 = f1;
	m_pView->f2 = f2;
	m_pView->f3 = f3;
	m_pView->f4 = f4;
	m_pView->f5 = f5;
	m_pView->f6 = f6;;
	m_pView->f7 = f7;
	m_pView->f8 = f8;
	m_pView->coin = coinnum;
	m_pView->Invalidate();
	//DestroyWindow();
	CDialog::OnCancel();
}


void CShopDialog::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	//m_pView->m_pDlg = NULL;
//	delete this;
	CDialog::PostNcDestroy();
}


void CShopDialog::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_pView->f1 = f1;
	m_pView->f2 = f2;
	m_pView->f3 = f3;
	m_pView->f4 = f4;
	m_pView->f5 = f5;
	m_pView->f6 = f6;;
	m_pView->f7 = f7;
	m_pView->f8 = f8;
	m_pView->coin = coinnum;
	m_pView->Invalidate();
}



void CShopDialog::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_pView->f1 = f1;
	m_pView->f2 = f2;
	m_pView->f3 = f3;
	m_pView->f4 = f4;
	m_pView->f5 = f5;
	m_pView->f6 = f6;;
	m_pView->f7 = f7;
	m_pView->f8 = f8;
	m_pView->coin = coinnum;
	m_pView->Invalidate();
	//DestroyWindow();
	CDialog::OnCancel();
}
