#include <wx/wx.h>
#include "GUIMyFrame1.h"
// UWAGA: TO JEST JEDYNY PLIK, KTORY NALEZY EDYTOWAC **************************
#include <vector>
#include <array>

float Shepard(int N, float d[100][3], float x, float y);

void GUIMyFrame1::DrawMap(int N, float d[100][3], bool Contour, int MappingType, int NoLevels, bool ShowPoints)
{
	wxMemoryDC memDC;
	memDC.SelectObject(MemoryBitmap);
	memDC.SetBackground(*wxWHITE_BRUSH);
	memDC.Clear();
	memDC.SetPen(*wxBLACK_PEN);
	memDC.SetBrush(*wxTRANSPARENT_BRUSH);

	auto values = new float[500][500];
	for (int y = 0; y < 500; y++)
		for (int x = 0; x < 500; x++)
			values[x][y] = Shepard(N, d, x / 100.0 - 2.5, -y / 100.0 + 2.5);

	float min = d[0][2], max = d[0][2];
	for (int i = 0; i < N; i++) {
		if (d[i][2] < min)
			min = d[i][2];
		if (d[i][2] > max)
			max = d[i][2];
	}

	// Mapa
	if (MappingType == 1) {
		unsigned char* data = new unsigned char[750000];
		for (int x = 0; x < 500; x++) {
			for (int y = 0; y < 500; y++) {
				float color = (values[x][y] - min) / (max - min);
				data[y * 500 * 3 + x * 3 + 0] = 255 - 255 * color;
				data[y * 500 * 3 + x * 3 + 1] = 0;
				data[y * 500 * 3 + x * 3 + 2] = 255 * color;
			}
		}
		memDC.DrawBitmap(wxBitmap(wxImage(500, 500, data)), 0, 0);
	}

	if (MappingType == 2) {
		unsigned char* data = new unsigned char[750000];
		for (int x = 0; x < 500; x++) {
			for (int y = 0; y < 500; y++) {
				float color = (values[x][y] - min) / (max - min);
				if (color < 0.5) {
					data[y * 500 * 3 + x * 3 + 0] = 255 - 2 * 255 * color;
					data[y * 500 * 3 + x * 3 + 1] = 2 * 255 * color;
					data[y * 500 * 3 + x * 3 + 2] = 0;
				}
				else {
					data[y * 500 * 3 + x * 3 + 0] = 0;
					data[y * 500 * 3 + x * 3 + 1] = 2 * (255 - 255 * color);
					data[y * 500 * 3 + x * 3 + 2] = 0.5 * 255 * color;
				}
			}
		}
		memDC.DrawBitmap(wxBitmap(wxImage(500, 500, data)), 0, 0);
	}

	if (MappingType == 3) {
		unsigned char* data = new unsigned char[750000];
		for (int x = 0; x < 500; x++) {
			for (int y = 0; y < 500; y++) {
				float color = (values[x][y] - min) / (max - min);
				data[y * 500 * 3 + x * 3 + 0] = 255 * color;
				data[y * 500 * 3 + x * 3 + 1] = 255 * color;
				data[y * 500 * 3 + x * 3 + 2] = 255 * color;
			}
		}
		memDC.DrawBitmap(wxBitmap(wxImage(500, 500, data)), 0, 0);
	}

	// Kontur
	if (Contour) {
		std::vector<std::array<wxPoint, 2>> contours;
		for (int i = 1; i <= NoLevels; i++) {
			float threshold = min + i * (max - min) / (float)(NoLevels + 1);
			for (int x = 1; x < 499; x++) {
				for (int y = 1; y < 499; y++) {
					int code = (values[x - 1][y + 1] > threshold ? 1 : 0) +
						(values[x + 1][y + 1] > threshold ? 1 : 0) * 2 +
						(values[x + 1][y - 1] > threshold ? 1 : 0) * 4 +
						(values[x - 1][y - 1] > threshold ? 1 : 0) * 8;

					if (values[x][y] < threshold) {
						if (code == 5)
							code = 10;
						if (code == 10)
							code = 5;
					}

					switch (code) {
					case 1:
					case 14:
						contours.push_back(std::array<wxPoint, 2> { wxPoint(x - 1, y), wxPoint(x, y + 1) });
						break;
					case 2:
					case 13:
						contours.push_back(std::array<wxPoint, 2> { wxPoint(x + 1, y), wxPoint(x, y + 1) });
						break;
					case 3:
					case 12:
						contours.push_back(std::array<wxPoint, 2> { wxPoint(x - 1, y), wxPoint(x + 1, y) });
						break;
					case 4:
					case 11:
						contours.push_back(std::array<wxPoint, 2> { wxPoint(x, y - 1), wxPoint(x + 1, y) });
						break;
					case 5:
						contours.push_back(std::array<wxPoint, 2> { wxPoint(x + 1, y), wxPoint(x, y + 1) });
						contours.push_back(std::array<wxPoint, 2> { wxPoint(x - 1, y), wxPoint(x, y - 1) });
						break;
					case 10:
						contours.push_back(std::array<wxPoint, 2> { wxPoint(x - 1, y), wxPoint(x, y + 1) });
						contours.push_back(std::array<wxPoint, 2> { wxPoint(x + 1, y), wxPoint(x, y - 1) });
						break;
					case 6:
					case 9:
						contours.push_back(std::array<wxPoint, 2> { wxPoint(x, y - 1), wxPoint(x, y + 1) });
						break;
					case 7:
					case 8:
						contours.push_back(std::array<wxPoint, 2> { wxPoint(x - 1, y), wxPoint(x, y - 1) });
						break;
					}
				}
			}
			for (auto& item : contours)
				memDC.DrawLine(item[0], item[1]);
		}
	}

	// Punkty
	if (ShowPoints) {
		int x, y;
		for (int i = 0; i < N; i++) {
			x = (d[i][0] + 2.5) * 100;
			y = (2.5 - d[i][1]) * 100;
			memDC.DrawLine(x, y + 3, x, y - 4);
			memDC.DrawLine(x - 3, y, x + 4, y);
		}
	}
}

float Shepard(int N, float d[100][3], float x, float y) {
	float sumUpper = 0, sumLower = 0, wk = 0, xk, yk;
	for (int i = 0; i < N; i++) {
		xk = d[i][0];
		yk = d[i][1];
		wk = 1.0 / abs((x - xk) * (x - xk) + (y - yk) * (y - yk));
		sumUpper += wk * d[i][2];
		sumLower += wk;
	}
	return sumUpper / sumLower;
}
