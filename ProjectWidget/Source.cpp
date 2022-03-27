#define _USE_ANTIALIASING
#include <wx/wxprec.h>
#include <wx/panel.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/filedlg.h>
#include <wx/checkbox.h>
#include <wx/scrolbar.h>
#include <wx/gauge.h>
#include <wx/colordlg.h>
#include <wx/textctrl.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/dcbuffer.h>
#include <wx/dcgraph.h>

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

	wxButton* BtnSave;
	wxButton* BtnColor;
	wxCheckBox* WxCheckBox1;
	wxStaticText* WxStaticText1;
	wxScrollBar* WxScrollBar1;
	wxComboBox* Choose;
	wxTextCtrl* WxText;
	wxString Text = "tekst";

	wxBoxSizer* WxBoxSizer2;
	wxPanel* WxPanel1;
	wxBoxSizer* WxBoxSizer1;
	wxBoxSizer* WxBoxSizer3;
	int m_shapeChoise;
	wxBitmap buffer;
	wxColour m_shapeColour;
	wxImage  image;
	wxBitmap bananImg;
	wxBitmap m_banan;
	wxGauge* greenFrame;




	void WxCheckBox1_Click(wxCommandEvent& e);
	void WxScrollBar1_Scroll(wxScrollEvent& e);
	void Form_Paint(wxPaintEvent& e);
	void Form_Update(wxUpdateUIEvent& e);
	void Draw();
	void WxComboBox_Choise(wxCommandEvent& e);
	void DrawText(wxCommandEvent& e);
	void BtnChooseColor(wxCommandEvent& e);
	void BtnSaveFile(wxCommandEvent& e);
	

	enum
	{
		ID_CHOOSE = 1003,
		ID_WXSCROLLBAR1 = 1004,
		ID_GREENFRAME = 1006,
		ID_WXCOMBOBOX = 1007,
		ID_TEXT = 1008,
		ID_BTNCHOOSECOLOR = 1009,
		ID_BTNSAVEFILE = 1010
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
	this->SetSizeHints(wxSize(600, 400), wxDefaultSize);


	SetIcon(wxNullIcon);
	SetSize(8, 8, 600, 500);
	Center();

	WxBoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer3 = new wxBoxSizer(wxVERTICAL);

	WxPanel1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	WxPanel1->SetBackgroundColour(wxColour(255, 255, 255));
	WxBoxSizer2->Add(WxPanel1, 1, wxEXPAND | wxALL, 5);
	WxBoxSizer1->Add(WxBoxSizer2, 1, wxEXPAND, 5);

	WxBoxSizer3->SetMinSize(wxSize(196, 350));
	WxBoxSizer1->Add(WxBoxSizer3, 0, wxEXPAND, 5);

	
	BtnSave = new wxButton(this, ID_BTNSAVEFILE, _("Zapis do pliku"), wxPoint(419, 15), wxSize(113, 27), 0, wxDefaultValidator, _("WxButton1"));
	WxBoxSizer3->Add(BtnSave, 0, wxALIGN_CENTER | wxALL, 5);

	WxCheckBox1 = new wxCheckBox(this, ID_CHOOSE, _("Banan"), wxPoint(450, 57), wxSize(105, 19), 0, wxDefaultValidator, _("WxCheckBox1"));
	WxBoxSizer3->Add(WxCheckBox1, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar1 = new wxScrollBar(this, ID_WXSCROLLBAR1, wxPoint(400, 92), wxSize(150, 18), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar1"));
	WxScrollBar1->SetScrollbar(10, 15, 100, 10);
	WxScrollBar1->Enable(false);
	WxBoxSizer3->Add(WxScrollBar1, 0, wxALIGN_CENTER | wxALL, 5);

	greenFrame = new wxGauge(this, ID_GREENFRAME, 99, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL);
	greenFrame->SetValue(0);
	WxBoxSizer3->Add(greenFrame, 0, wxALL | wxEXPAND, 5);

	BtnColor = new wxButton(this, ID_BTNCHOOSECOLOR, _("Kolor gwiazki"), wxPoint(419, 140), wxSize(113, 27), 0, wxDefaultValidator);
	WxBoxSizer3->Add(BtnColor, 0, wxALIGN_CENTER | wxALL, 5);
	m_shapeColour = wxColour(*wxBLACK);

	WxText = new wxTextCtrl(this, ID_TEXT, _("tekst"), wxPoint(410, 182), wxSize(131, 30), 0, wxDefaultValidator, _("WxEdit1"));
	WxBoxSizer3->Add(WxText, 0, wxALIGN_CENTER | wxALL, 5);

	wxArrayString arrayStringFor_WxChoice1;
	Choose = new wxComboBox(this, ID_CHOOSE, "gwiazdka", wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_DROPDOWN | wxCB_READONLY);
	

	Choose->Append("gwiazdka");
	Choose->Append("ksiê¿yc");
	Choose->Append("s³onko");
	Choose->SetSelection(0);
	WxBoxSizer3->Add(Choose, 0, wxALIGN_CENTER | wxALL, 5);
	
	
	this->SetSizer(WxBoxSizer1);
	this->Layout();
	this->Centre(wxBOTH);





	Bind(wxEVT_BUTTON, &MyFrame::BtnSaveFile, this, ID_BTNSAVEFILE);
	Bind(wxEVT_TEXT, &MyFrame::DrawText, this, ID_TEXT);
	Bind(wxEVT_CHECKBOX, &MyFrame::WxCheckBox1_Click, this, ID_CHOOSE);
	Bind(wxEVT_SCROLL_THUMBTRACK, &MyFrame::WxScrollBar1_Scroll, this, ID_WXSCROLLBAR1);
	Bind(wxEVT_PAINT, &MyFrame::Form_Paint, this);
	Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
	Bind(wxEVT_UPDATE_UI, &MyFrame::Form_Update, this);
	Bind(wxEVT_COMBOBOX, &MyFrame::WxComboBox_Choise, this, ID_CHOOSE);
	Bind(wxEVT_BUTTON, &MyFrame::BtnChooseColor, this, ID_BTNCHOOSECOLOR);

	wxImage banan = wxImage();
	banan.AddHandler(new wxPNGHandler);
	banan.LoadFile("banan.png", wxBITMAP_TYPE_PNG);
	bananImg = wxBitmap(banan);

	
}
void MyFrame::OnExit(wxCommandEvent& event)
{
	Close(true);
}

void MyFrame::BtnSaveFile(wxCommandEvent& WXUNUSED(e)) {
	wxFileDialog saveFileDialog(this, "Choose a file", "", "", "BMP files (*.bmp)|*.bmp|JPG files (*.jpg)|*.jpg|PNG files (*.png)|*.png", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (saveFileDialog.ShowModal() == wxID_CANCEL)
		return;
	image = buffer.ConvertToImage();
	image.AddHandler(new wxJPEGHandler);
	image.AddHandler(new wxPNGHandler);
	image.SaveFile(saveFileDialog.GetPath());

}

void MyFrame::WxCheckBox1_Click(wxCommandEvent& e)
{
	WxScrollBar1->Enable(WxCheckBox1->IsChecked());
}

void MyFrame::WxScrollBar1_Scroll(wxScrollEvent& e)
{
	greenFrame->SetValue(WxScrollBar1->GetThumbPosition());
	Draw();
}

void MyFrame::WxComboBox_Choise(wxCommandEvent& WXUNUSED(e)) {
	m_shapeChoise = Choose->GetSelection();
}

void MyFrame::DrawText(wxCommandEvent& WXUNUSED(e)) {
	Text = WxText->GetValue();
}

void MyFrame::BtnChooseColor(wxCommandEvent& WXUNUSED(e)) {
	wxColourDialog chooseColourDialog(this, nullptr);
	if (chooseColourDialog.ShowModal() == wxID_CANCEL)
		return;
	m_shapeColour = chooseColourDialog.GetColourData().GetColour();
}

void MyFrame::Draw() {
	wxClientDC __MyDC(WxPanel1);
	buffer = wxBitmap(WxPanel1->GetSize().x, WxPanel1->GetSize().y);
	wxBufferedDC _MyDC(&__MyDC, buffer);
#ifdef _USE_ANTIALIASING
	wxGCDC MyDC(_MyDC);
#else
#define MyDC _MyDC
#endif

	wxSize XY = WxPanel1->GetSize();
	int x = (XY.x - 377) / 2;
	int y = (XY.y - 346) / 2;

	MyDC.SetBackground(*wxWHITE_BRUSH);
	MyDC.Clear();


	if (WxCheckBox1->IsChecked()) {
		MyDC.DrawBitmap(bananImg, x + 149 - bananImg.GetWidth() / 2, y + 192 - 0.38 * greenFrame->GetValue() - bananImg.GetHeight() / 2);
	}

	MyDC.DrawCircle(x + 188, y + 143, 20);
	MyDC.DrawEllipse(x + 176, y + 135, 10, 7);

	if (WxCheckBox1->IsChecked()) {
		MyDC.DrawEllipticArc(x + 177, y + 144, 22, 10, 180, 360);
		MyDC.DrawEllipse(x + 191, y + 135, 10, 7);
		MyDC.DrawEllipticArc(x + 175, y + 144, 7, 5, 180, 360);
		MyDC.DrawEllipticArc(x + 196, y + 144, 7, 5, 180, 360);
	}
	else {
		MyDC.DrawEllipticArc(x + 174, y + 148, 26, 10, 10, 180);
		MyDC.DrawEllipse(x + 191, y + 133, 6, 11);
	}

	MyDC.DrawLine(x + 188, y + 164, x + 188, y + 234);
	MyDC.DrawLine(x + 188, y + 234, x + 159, y + 262);
	MyDC.DrawLine(x + 188, y + 234, x + 217, y + 262);
	MyDC.DrawLine(x + 188, y + 173, x + 227, y + 192);
	MyDC.DrawLine(x + 188, y + 173, x + 149, y + 192 - 0.38 * greenFrame->GetValue());

	wxString text1(Text);
	MyDC.SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, "Calibri"));
	MyDC.DrawText(text1, x + 98, y + 253);
	wxString text2(Text);
	MyDC.SetFont(wxFont(30, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, "Comic Sans MS"));
	MyDC.DrawRotatedText(Text, x + 239, y + 263, 90);

	if (m_shapeChoise == 0) {
		MyDC.SetBrush(wxBrush(m_shapeColour));
		MyDC.SetPen(wxPen(m_shapeColour));
		wxPoint points[5] = {
			wxPoint(125, 80),
			wxPoint(153, 135),
			wxPoint(98 , 103),
			wxPoint(160, 103),
			wxPoint(106, 135)
		};
		MyDC.DrawPolygon(5, points, x, y);
	}
	else if (m_shapeChoise == 1) {
		MyDC.SetBrush(*wxLIGHT_GREY_BRUSH);
		MyDC.SetPen(*wxLIGHT_GREY_PEN);
		MyDC.DrawCircle(x + 118, y + 103, 20);
		MyDC.SetBrush(*wxWHITE_BRUSH);
		MyDC.SetPen(*wxWHITE_PEN);
		MyDC.DrawCircle(x + 108, y + 93, 20);
		MyDC.SetBrush(*wxBLACK_BRUSH);
		MyDC.SetPen(*wxBLACK_PEN);
		MyDC.DrawCircle(x + 128, y + 103, 2);
		MyDC.DrawLine(x + 118, y + 110, x + 123, y + 113);
	}
	else if (m_shapeChoise == 2) {
		MyDC.SetBrush(*wxYELLOW_BRUSH);
		MyDC.SetPen(*wxYELLOW_PEN);
		MyDC.DrawCircle(x + 118, y + 103, 20);
	}

	wxPoint pointsT[3] = {
	wxPoint(188, 143),
	wxPoint(208, 100),
	wxPoint(228 , 143)
	};
	MyDC.SetBrush(wxBrush(m_shapeColour));
	MyDC.SetPen(wxPen(m_shapeColour));
	MyDC.DrawPolygon(3, pointsT, x-19, y-15);
}


void MyFrame::Form_Paint(wxPaintEvent& event)
{
	Draw();
}

void MyFrame::Form_Update(wxUpdateUIEvent& WXUNUSED(e)) {
	Draw();
}
