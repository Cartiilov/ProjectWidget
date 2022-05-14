///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Window.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer(wxVERTICAL);

	m_panel3 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_panel3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));

	bSizer30->Add(m_panel3, 5, wxALL | wxEXPAND, 5);


	bSizer2->Add(bSizer30, 30, wxEXPAND, 5);

	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer(wxVERTICAL);

	m_staticText20 = new wxStaticText(this, wxID_ANY, wxT("Rotacja"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText20->Wrap(-1);
	m_staticText20->SetFont(wxFont(12, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Cambria")));

	bSizer36->Add(m_staticText20, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);


	bSizer38->Add(bSizer36, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer(wxVERTICAL);

	m_staticText21 = new wxStaticText(this, wxID_ANY, wxT("Oś X"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText21->Wrap(-1);
	m_staticText21->SetFont(wxFont(12, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Cambria")));

	bSizer40->Add(m_staticText21, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);


	bSizer33->Add(bSizer40, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer(wxVERTICAL);

	m_slider6 = new wxSlider(this, wxID_ANY, 0, 0, 360, wxDefaultPosition, wxSize(-1, -1), wxSL_HORIZONTAL | wxSL_VALUE_LABEL);
	m_slider6->SetMaxSize(wxSize(300, -1));

	bSizer42->Add(m_slider6, 0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL | wxEXPAND, 5);


	bSizer33->Add(bSizer42, 0, wxEXPAND, 5);


	bSizer32->Add(bSizer33, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer(wxVERTICAL);

	m_staticText22 = new wxStaticText(this, wxID_ANY, wxT("Oś Y"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText22->Wrap(-1);
	m_staticText22->SetFont(wxFont(12, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Cambria")));

	bSizer34->Add(m_staticText22, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	m_slider7 = new wxSlider(this, wxID_ANY, 0, 0, 360, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL | wxSL_VALUE_LABEL);
	m_slider7->SetMaxSize(wxSize(300, -1));

	bSizer34->Add(m_slider7, 0, wxALIGN_CENTER_HORIZONTAL | wxALL | wxEXPAND, 5);


	bSizer32->Add(bSizer34, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer(wxVERTICAL);

	m_staticText23 = new wxStaticText(this, wxID_ANY, wxT("Oś Z"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText23->Wrap(-1);
	m_staticText23->SetFont(wxFont(12, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Cambria")));

	bSizer35->Add(m_staticText23, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	m_slider8 = new wxSlider(this, wxID_ANY, 0, 0, 360, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL | wxSL_VALUE_LABEL);
	m_slider8->SetMaxSize(wxSize(300, -1));

	bSizer35->Add(m_slider8, 0, wxALIGN_CENTER_HORIZONTAL | wxALL | wxEXPAND, 5);


	bSizer32->Add(bSizer35, 1, wxEXPAND, 5);


	bSizer38->Add(bSizer32, 0, wxEXPAND, 5);


	bSizer37->Add(bSizer38, 3, wxEXPAND, 5);


	bSizer2->Add(bSizer37, 0, wxEXPAND, 5);


	bSizer1->Add(bSizer2, 7, wxALIGN_RIGHT | wxEXPAND, 5);

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer(wxVERTICAL);

	m_staticText17 = new wxStaticText(this, wxID_ANY, wxT("Parametry"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText17->Wrap(-1);
	m_staticText17->SetFont(wxFont(16, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Cambria")));

	bSizer4->Add(m_staticText17, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer(wxVERTICAL);

	m_staticText19 = new wxStaticText(this, wxID_ANY, wxT("Oś X"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText19->Wrap(-1);
	m_staticText19->SetFont(wxFont(14, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Cambria")));

	bSizer9->Add(m_staticText19, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer(wxHORIZONTAL);

	m_staticText5 = new wxStaticText(this, wxID_ANY, wxT("A"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText5->Wrap(-1);
	m_staticText5->SetFont(wxFont(14, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Cambria")));

	bSizer10->Add(m_staticText5, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	m_textCtrl3 = new wxTextCtrl(this, wxID_ANY, wxT("1"), wxDefaultPosition, wxSize(-1, -1), 0);
	bSizer10->Add(m_textCtrl3, 5, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);


	bSizer9->Add(bSizer10, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer101;
	bSizer101 = new wxBoxSizer(wxHORIZONTAL);

	m_staticText51 = new wxStaticText(this, wxID_ANY, wxT("θ"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText51->Wrap(-1);
	m_staticText51->SetFont(wxFont(14, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Cambria")));

	bSizer101->Add(m_staticText51, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	m_textCtrl31 = new wxTextCtrl(this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer101->Add(m_textCtrl31, 5, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);


	bSizer9->Add(bSizer101, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer102;
	bSizer102 = new wxBoxSizer(wxHORIZONTAL);

	m_staticText52 = new wxStaticText(this, wxID_ANY, wxT("φ"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText52->Wrap(-1);
	m_staticText52->SetFont(wxFont(14, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Cambria")));

	bSizer102->Add(m_staticText52, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	m_textCtrl32 = new wxTextCtrl(this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer102->Add(m_textCtrl32, 5, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);


	bSizer9->Add(bSizer102, 0, wxEXPAND, 5);


	bSizer4->Add(bSizer9, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer91;
	bSizer91 = new wxBoxSizer(wxVERTICAL);

	m_staticText18 = new wxStaticText(this, wxID_ANY, wxT("Oś Y"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText18->Wrap(-1);
	m_staticText18->SetFont(wxFont(14, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Cambria")));

	bSizer91->Add(m_staticText18, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	wxBoxSizer* bSizer103;
	bSizer103 = new wxBoxSizer(wxHORIZONTAL);

	m_staticText53 = new wxStaticText(this, wxID_ANY, wxT("A"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText53->Wrap(-1);
	m_staticText53->SetFont(wxFont(14, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Cambria")));

	bSizer103->Add(m_staticText53, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	m_textCtrl33 = new wxTextCtrl(this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer103->Add(m_textCtrl33, 5, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);


	bSizer91->Add(bSizer103, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer1011;
	bSizer1011 = new wxBoxSizer(wxHORIZONTAL);

	m_staticText511 = new wxStaticText(this, wxID_ANY, wxT("θ"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText511->Wrap(-1);
	m_staticText511->SetFont(wxFont(14, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Cambria")));

	bSizer1011->Add(m_staticText511, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	m_textCtrl311 = new wxTextCtrl(this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer1011->Add(m_textCtrl311, 5, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);


	bSizer91->Add(bSizer1011, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer1021;
	bSizer1021 = new wxBoxSizer(wxHORIZONTAL);

	m_staticText521 = new wxStaticText(this, wxID_ANY, wxT("φ"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText521->Wrap(-1);
	m_staticText521->SetFont(wxFont(14, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Cambria")));

	bSizer1021->Add(m_staticText521, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	m_textCtrl321 = new wxTextCtrl(this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer1021->Add(m_textCtrl321, 5, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);


	bSizer91->Add(bSizer1021, 1, wxEXPAND, 5);


	bSizer4->Add(bSizer91, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer92;
	bSizer92 = new wxBoxSizer(wxVERTICAL);

	m_staticText4 = new wxStaticText(this, wxID_ANY, wxT("Oś Z"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText4->Wrap(-1);
	m_staticText4->SetFont(wxFont(14, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Cambria")));

	bSizer92->Add(m_staticText4, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	wxBoxSizer* bSizer104;
	bSizer104 = new wxBoxSizer(wxHORIZONTAL);

	m_staticText54 = new wxStaticText(this, wxID_ANY, wxT("A"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText54->Wrap(-1);
	m_staticText54->SetFont(wxFont(14, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Cambria")));

	bSizer104->Add(m_staticText54, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	m_textCtrl34 = new wxTextCtrl(this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer104->Add(m_textCtrl34, 5, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);


	bSizer92->Add(bSizer104, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer1012;
	bSizer1012 = new wxBoxSizer(wxHORIZONTAL);

	m_staticText512 = new wxStaticText(this, wxID_ANY, wxT("θ"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText512->Wrap(-1);
	m_staticText512->SetFont(wxFont(14, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Cambria")));

	bSizer1012->Add(m_staticText512, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	m_textCtrl312 = new wxTextCtrl(this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer1012->Add(m_textCtrl312, 5, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);


	bSizer92->Add(bSizer1012, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer1022;
	bSizer1022 = new wxBoxSizer(wxHORIZONTAL);

	m_staticText522 = new wxStaticText(this, wxID_ANY, wxT("φ"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText522->Wrap(-1);
	m_staticText522->SetFont(wxFont(14, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Cambria")));

	bSizer1022->Add(m_staticText522, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	m_textCtrl322 = new wxTextCtrl(this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer1022->Add(m_textCtrl322, 5, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);


	bSizer92->Add(bSizer1022, 1, wxEXPAND | wxALIGN_RIGHT, 5);


	bSizer4->Add(bSizer92, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer(wxHORIZONTAL);

	wxString m_radioBox1Choices[] = { wxT("Linie"), wxT("Punkty") };
	int m_radioBox1NChoices = sizeof(m_radioBox1Choices) / sizeof(wxString);
	m_radioBox1 = new wxRadioBox(this, wxID_ANY, wxT("Rodzaj rysowania"), wxDefaultPosition, wxDefaultSize, m_radioBox1NChoices, m_radioBox1Choices, 1, wxRA_SPECIFY_COLS);
	m_radioBox1->SetSelection(0);
	m_radioBox1->SetFont(wxFont(10, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Cambria")));

	bSizer27->Add(m_radioBox1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);


	bSizer4->Add(bSizer27, 1, wxEXPAND, 5);


	bSizer1->Add(bSizer4, 1, wxALIGN_LEFT | wxEXPAND, 5);


	this->SetSizer(bSizer1);
	this->Layout();

	this->Centre(wxBOTH);
}

MyFrame1::~MyFrame1()
{
}
