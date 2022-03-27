#include <wx/wxprec.h>

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
	MyFrame();
private:
	void OnExit(wxCommandEvent& event);

	wxButton* WxButton1;
	wxButton* BtnColor;
	wxTextCtrl* WxEdit1;
	wxCheckBox* WxCheckBox1;
	wxStaticText* WxStaticText1;
	wxScrollBar* WxScrollBar1;
	wxChoice* WxChoice1;

	wxBoxSizer* WxBoxSizer2;
	wxPanel* WxPanel1;
	wxBoxSizer* WxBoxSizer1;
	wxBoxSizer* WxBoxSizer3;



	void WxButton1_Click(wxCommandEvent& e);
	void WxEdit1_Updated(wxCommandEvent& e);
	void WxCheckBox1_Click(wxCommandEvent& e);
	void WxScrollBar1_Scroll(wxScrollEvent& e);
	void Form_Paint(wxPaintEvent& e);

	enum
	{
		ID_WXBUTTON1 = 1001,
		ID_WXEDIT1 = 1002,
		ID_WXCHECKBOX1 = 1003,
		ID_WXSCROLLBAR1 = 1004,
		ID_BTNCOLOR = 1005
	};
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	MyFrame* frame = new MyFrame();
	frame->Show(true);
	return true;
}

MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, "GFK Lab03")
{
	wxMenu* menuFile = new wxMenu;
	menuFile->Append(wxID_EXIT);

	wxMenuBar* menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");

	SetMenuBar(menuBar);

	SetIcon(wxNullIcon);
	SetSize(8, 8, 600, 500);
	Center();

	WxBoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	this->SetSizer(WxBoxSizer1);
	this->SetAutoLayout(true);

	WxPanel1 = new wxPanel(this, wxID_ANY, wxPoint(5, 39), wxSize(213, 47));
	WxPanel1->SetBackgroundColour(wxColour(255, 255, 255));

	WxBoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxPanel1, 1, wxEXPAND | wxALL, 5);

	
	WxBoxSizer1->Add(WxBoxSizer2, 1, wxEXPAND | wxALL, 5);

	WxBoxSizer3 = new wxBoxSizer(wxVERTICAL);
	WxBoxSizer3->SetMinSize(wxSize(196, 350));
	WxBoxSizer1->Add(WxBoxSizer3, 0, wxEXPAND, 5);

	

	WxButton1 = new wxButton(this, ID_WXBUTTON1, _("Zapis do pliku"), wxPoint(419, 15), wxSize(113, 27), 0, wxDefaultValidator, _("WxButton1"));
	WxBoxSizer3->Add(WxButton1, 0, wxALIGN_CENTER | wxALL, 5);

	WxCheckBox1 = new wxCheckBox(this, ID_WXCHECKBOX1, _("Banan"), wxPoint(450, 57), wxSize(105, 19), 0, wxDefaultValidator, _("WxCheckBox1"));
	WxBoxSizer3->Add(WxCheckBox1, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar1 = new wxScrollBar(this, ID_WXSCROLLBAR1, wxPoint(400, 92), wxSize(150, 18), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar1"));
	WxScrollBar1->SetScrollbar(10, 15, 100, 10);
	WxScrollBar1->Enable(false);
	WxBoxSizer3->Add(WxScrollBar1, 0, wxALIGN_CENTER | wxALL, 5);

	BtnColor = new wxButton(this, ID_BTNCOLOR, _("Kolor gwiazki"), wxPoint(419, 140), wxSize(113, 27), 0, wxDefaultValidator);
	WxBoxSizer3->Add(BtnColor, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit1 = new wxTextCtrl(this, ID_WXEDIT1, _("tekst"), wxPoint(410, 182), wxSize(131, 30), 0, wxDefaultValidator, _("WxEdit1"));
	WxBoxSizer3->Add(WxEdit1, 0, wxALIGN_CENTER | wxALL, 5);

	wxArrayString arrayStringFor_WxChoice1;
	WxChoice1 = new wxChoice(this, wxID_ANY, wxPoint(447, 21), wxSize(234, 30), arrayStringFor_WxChoice1, 0, wxDefaultValidator, _("WxChoice1"));
	WxBoxSizer3->Add(WxChoice1, 0, wxALIGN_CENTER | wxALL, 5);

	WxChoice1->Append("gwiazdka");
	WxChoice1->Append("ksi�yc");
	WxChoice1->Append("s�onko");
	WxChoice1->SetSelection(0);
	
	
	this->SetSizer(WxBoxSizer1);
	this->Layout();
	this->Centre(wxBOTH);





	Bind(wxEVT_BUTTON, &MyFrame::WxButton1_Click, this, ID_WXBUTTON1);
	Bind(wxEVT_TEXT, &MyFrame::WxEdit1_Updated, this, ID_WXEDIT1);
	Bind(wxEVT_CHECKBOX, &MyFrame::WxCheckBox1_Click, this, ID_WXCHECKBOX1);
	Bind(wxEVT_SCROLL_THUMBTRACK, &MyFrame::WxScrollBar1_Scroll, this, ID_WXSCROLLBAR1);
	Bind(wxEVT_PAINT, &MyFrame::Form_Paint, this);
	Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
	
}
void MyFrame::OnExit(wxCommandEvent& event)
{
	Close(true);
}

void MyFrame::WxButton1_Click(wxCommandEvent& e)
{
	wxMessageDialog(NULL, "Wci?ni?to przycisk", "Uwaga", wxOK).ShowModal();
}

void MyFrame::WxEdit1_Updated(wxCommandEvent& e)
{
	if (WxEdit1) WxStaticText1->SetLabel("Wpisano: " + WxEdit1->GetValue());
}

void MyFrame::WxCheckBox1_Click(wxCommandEvent& e)
{
	if (WxScrollBar1->IsEnabled()) WxScrollBar1->Enable(false); else WxScrollBar1->Enable(true);
}

void MyFrame::WxScrollBar1_Scroll(wxScrollEvent& e)
{
	//WxStaticText1->SetLabel(wxString::Format("%d", WxScrollBar1->GetThumbPosition()));
}



void MyFrame::Form_Paint(wxPaintEvent& event)
{
	int i, j;
	wxPoint pts[5], ptsB[4];
	wxPen MyPen;

	pts[0] = wxPoint(200, 40);
	pts[1] = wxPoint(220, 60);
	pts[2] = wxPoint(240, 50);
	pts[3] = wxPoint(260, 60);
	pts[4] = wxPoint(280, 40);
	ptsB[0] = wxPoint(400, 90);
	ptsB[1] = wxPoint(415, 240);
	ptsB[2] = wxPoint(480, 90);
	ptsB[3] = wxPoint(520, 140);

	wxPaintDC* MyDC;
	MyDC = new wxPaintDC(this);


	MyDC->DrawCircle(50, 260, 40);



	delete (MyDC);
}