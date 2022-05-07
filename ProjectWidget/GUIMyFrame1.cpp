#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{
 m_staticText1->SetLabel(_(L"Jasno\u015B\u0107"));
 m_b_threshold->SetLabel(_(L"Pr\u00F3g 128"));
 this->SetBackgroundColour(wxColor(192, 192, 192));
 m_scrolledWindow->SetScrollbars(25, 25, 52, 40);
 m_scrolledWindow->SetBackgroundColour(wxColor(192, 192, 192));
}

void GUIMyFrame1::m_scrolledWindow_update( wxUpdateUIEvent& event )
{
 Repaint();
}

void GUIMyFrame1::m_b_grayscale_click( wxCommandEvent& event )
{
	Img_Cpy = Img_Org.ConvertToGreyscale();
	m_scrolledWindow->ClearBackground();
}

void GUIMyFrame1::m_b_blur_click( wxCommandEvent& event )
{
	Img_Cpy = Img_Org.Blur(5);
	m_scrolledWindow->ClearBackground();
}

void GUIMyFrame1::m_b_mirror_click( wxCommandEvent& event )
{
	Img_Cpy = Img_Org.Mirror();
	m_scrolledWindow->ClearBackground();
}

void GUIMyFrame1::m_b_replace_click( wxCommandEvent& event )
{
	Img_Cpy = Img_Org;
	Img_Cpy.Replace(254, 0, 0, 0, 0, 255);
	m_scrolledWindow->ClearBackground();
}

void GUIMyFrame1::m_b_rescale_click( wxCommandEvent& event )
{
	Img_Cpy = Img_Org;
	Img_Cpy.Rescale(320, 240);
	m_scrolledWindow->ClearBackground();
 // TO DO: Zmiana rozmiarow do 320x240
}

void GUIMyFrame1::m_b_rotate_click( wxCommandEvent& event )
{
	Img_Cpy = Img_Org.Rotate(M_PI/6, wxPoint(Img_Org.GetSize().x, Img_Org.GetSize().y));
	m_scrolledWindow->ClearBackground();
 // TO DO: Obrot o 30 stopni
}

void GUIMyFrame1::m_b_rotate_hue_click( wxCommandEvent& event )
{
	Img_Cpy = Img_Org;
	Img_Cpy.RotateHue(0.5);
	m_scrolledWindow->ClearBackground();
 // TO DO: Przesuniecie Hue o 180 stopni
}

void GUIMyFrame1::m_b_mask_click( wxCommandEvent& event )
{
	Img_Cpy = Img_Org;
	Img_Cpy.SetMaskFromImage(Img_Mask, 0, 0, 0);
	m_scrolledWindow->ClearBackground();
}

void GUIMyFrame1::m_s_brightness_scroll( wxScrollEvent& event )
{
// Tutaj, w reakcji na zmiane polozenia suwaka, wywolywana jest funkcja
// Brightness(...), ktora zmienia jasnosc. W tym miejscu nic nie
// zmieniamy. Do uzupelnienia pozostaje funkcja Brightness(...)
Brightness(m_s_brightness->GetValue() - 100);
Repaint();
}

void GUIMyFrame1::m_s_contrast_scroll( wxScrollEvent& event )
{
// Tutaj, w reakcji na zmiane polozenia suwaka, wywolywana jest funkcja
// Contrast(...), ktora zmienia kontrast. W tym miejscu nic nie
// zmieniamy. Do uzupelnienia pozostaje funkcja Contrast(...)
Contrast(m_s_contrast->GetValue() - 100);
Repaint();
}

void GUIMyFrame1::m_b_prewitt_click( wxCommandEvent& event )
{
	Img_Cpy = Img_Org.Copy();

	int temp = 0;
	int width = Img_Cpy.GetSize().x;
	int height = Img_Cpy.GetSize().y;
	int data = width * height * 3;

	unsigned char* point = Img_Cpy.GetData();
	unsigned char* back = new unsigned char[data];

	for (int i = 0; i < data; i++)
		back[i] = point[i];
	for (int i = 1; i < height - 1; i++)
	{
		for (int j = 1; j < width - 1; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				temp = 0;
				temp += back[k + i * 3 * width + 3 * (j + 1)];
				temp -= back[k + i * 3 * width + 3 * (j - 1)];
				temp += back[k + (i + 1) * 3 * width + 3 * (j + 1)];
				temp -= back[k + (i + 1) * 3 * width + 3 * (j - 1)];
				temp += back[k + (i - 1) * 3 * width + 3 * (j + 1)];
				temp -= back[k + (i - 1) * 3 * width + 3 * (j - 1)];
				point[k + i * 3 * width + 3 * j] = fabs(temp) / 3.0;
			}
		}
	}

	delete[] back;
}

void GUIMyFrame1::m_b_threshold_click( wxCommandEvent& event )
{
	Img_Cpy = Img_Org.Copy();
	unsigned char* point = Img_Cpy.GetData();
	for (int i = 0; i < Img_Cpy.GetSize().x * Img_Cpy.GetSize().y * 3; i++)
	{
		if (point[i] < 128)
			point[i] = 0;
		else
			point[i] = 255;
	}
}


void GUIMyFrame1::Contrast(int value)
{
	double c = (100.0 + static_cast<double>(value)) / (101.0 - static_cast<double>(value));
	double temp;

	Img_Cpy = Img_Org.Copy();
	unsigned char* point = Img_Cpy.GetData();
	int data = Img_Cpy.GetSize().x * Img_Cpy.GetSize().y * 3;

	for (int i = 0; i < data; i++)
	{
		temp = c * (point[i] - 127) + 127;

		if (temp > 255)
			point[i] = 255;
		else if (temp < 0)
			point[i] = 0;
		else
			point[i] = static_cast<char>(temp);
	}

}

void GUIMyFrame1::Repaint()
{
 wxBitmap bitmap(Img_Cpy);          // Tworzymy tymczasowa bitmape na podstawie Img_Cpy
 wxClientDC dc(m_scrolledWindow);   // Pobieramy kontekst okna
 m_scrolledWindow->DoPrepareDC(dc); // Musimy wywolac w przypadku wxScrolledWindow, zeby suwaki prawidlowo dzialaly
 dc.DrawBitmap(bitmap, 0, 0, true); // Rysujemy bitmape na kontekscie urzadzenia
}

void GUIMyFrame1::Brightness(int value)
{
 // TO DO: Zmiana jasnosci obrazu. value moze przyjmowac wartosci od -100 do 100
	Img_Cpy = Img_Org.Copy();
	unsigned char* point = Img_Cpy.GetData();
	int data = Img_Cpy.GetSize().x * Img_Cpy.GetSize().y * 3;
	int temp;
	for (int i = 1; i < data; i++)
	{
		temp = point[i] + value;
		if (temp > 255)
			temp = 255;
		else if (temp < 0)
			temp = 0;
		point[i] = temp;
	}
}