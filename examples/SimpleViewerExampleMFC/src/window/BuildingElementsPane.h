// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// https://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

#pragma once

#include <ifcpp/model/BasicTypes.h>
#include <ifcpp/model/BuildingModel.h>
#include "BuildingTreeCtrl.h"

class CClassToolBar : public CMFCToolBar
{
	virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler)
	{
		CMFCToolBar::OnUpdateCmdUI((CFrameWnd*) GetOwner(), bDisableIfNoHndler);
	}

	virtual BOOL AllowShowOnList() const { return FALSE; }
};

	
class BuildingElementsPane : public CDockablePane
{
public:
	BuildingElementsPane();
	virtual ~BuildingElementsPane();

	void AdjustLayout();
	void OnChangeVisualStyle();
	void setBuildingModel( shared_ptr<BuildingModel> ifc_model );
	void updateBuildingElementsTreeView();
	void updateBuildingElementsTreeViewDummy();
	void clearBuildingElementsTreeView();
	void setEntitySelected( int entity_id );
	void unselectAllEntities();

	bool m_internal_call_to_select = false;

protected:
	CClassToolBar m_wndToolBar;
	BuildingTreeCtrl m_wndBuildingElmentsTree;
	CImageList m_cImageList;
	UINT m_nCurrSort;
	shared_ptr<BuildingModel> m_ifc_model;
	std::map<int, HTREEITEM> m_map_id_item;

// Overrides
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnClassAddMemberFunction();
	afx_msg void OnClassAddMemberVariable();
	afx_msg void OnClassDefinition();
	afx_msg void OnClassProperties();
	afx_msg void OnNewFolder();
	afx_msg void OnPaint();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg LRESULT OnChangeActiveTab(WPARAM, LPARAM);
	afx_msg void OnSort(UINT id);
	afx_msg void OnUpdateSort(CCmdUI* pCmdUI);

	//

	DECLARE_MESSAGE_MAP()
};

