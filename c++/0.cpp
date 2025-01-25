// MyMFCDlg.h
#pragma once

class CMyMFCDlg : public CDialogEx
{
public:
    CMyMFCDlg(CWnd* pParent = nullptr);

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_MYMFC_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

protected:
    HICON m_hIcon;

    virtual BOOL OnInitDialog();
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButtonHello();
};

// MyMFCDlg.cpp
#include "pch.h"
#include "framework.h"
#include "MyMFC.h"
#include "MyMFCDlg.h"
#include "afxdialogex.h"

CMyMFCDlg::CMyMFCDlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_MYMFC_DIALOG, pParent)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyMFCDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyMFCDlg, CDialogEx)
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON_HELLO, &CMyMFCDlg::OnBnClickedButtonHello)
END_MESSAGE_MAP()

BOOL CMyMFCDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    SetIcon(m_hIcon, TRUE);
    SetIcon(m_hIcon, FALSE);

    return TRUE;
}

void CMyMFCDlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this);
        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialogEx::OnPaint();
    }
}

HCURSOR CMyMFCDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

void CMyMFCDlg::OnBnClickedButtonHello()
{
    AfxMessageBox(_T("Hello, MFC!"));
}
