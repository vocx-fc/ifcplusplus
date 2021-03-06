#pragma once

#include "ViewTree.h"

#define WM_FLOAT_CTRL WM_USER+2002

class BuildingTreeCtrl : public CTreeCtrl
{
public:
	BuildingTreeCtrl();
	virtual ~BuildingTreeCtrl();
	bool m_internal_call_to_select = false;

protected:
	virtual BOOL PreCreateWindow( CREATESTRUCT& cs );
	afx_msg void OnItemexpanding( NMHDR* pNMHDR, LRESULT* pResult );
	afx_msg void OnClick( NMHDR* pNMHDR, LRESULT* pResult );
	afx_msg void OnDblclk( NMHDR* pNMHDR, LRESULT* pResult );
	afx_msg void OnLButtonUp( UINT nFlags, CPoint point );
	afx_msg int OnCreate( LPCREATESTRUCT lpCreateStruct );
	afx_msg void OnSelchanging( NMHDR *pNMHDR, LRESULT *pResult );
	afx_msg void OnSelChangedTreeCtrl( NMHDR* pNMHDR, LRESULT* pResult );

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTvnSelchanged( NMHDR *pNMHDR, LRESULT *pResult );
};
